

struct PairString {
  string first;
  string second;

  PairString(string first, string second) : first(first), second(second) {}
};

class UnionFind {
public:
  UnionFind(vector<PairString> &ItemAssociation) {
    for (auto &IA : ItemAssociation) {
      parent[IA.first] = IA.first;
      parent[IA.second] = IA.second;
    }
  }

  // Use the smallest as root
  void unite(string x, string y) {
    auto px = find(x);
    auto py = find(y);
    if (px < py) {
      parent[py] = px;
    } else {
      parent[px] = py;
    }
  }

  string find(string x) {
    if (x == parent[x]) {
      return x;
    }

    return find(parent[x]);
  }

  void buildAssociation() {
    for (const auto &p : parent) {
      auto root = find(p.second);
      association[root].push_back(p.first);
    }

    for (const auto &ass : association) {
      cout << "root is : " << ass.first << endl;
      cout << "child is : ";
      for (const auto &child : ass.second) {
        cout << " " << child << " ";
      }
      cout << endl;
    }
    cout << endl << endl;
  }

  vector<string> findMaxAssociation() {
    size_t maxSize = 0;
    vector<string> res;
    for (const auto &a : association) {
      if (a.second.size() > maxSize) {
        maxSize = a.second.size();
        res = a.second;
      }
    }

    return res;
  }

private:
  map<string, string> parent;
  map<string, vector<string>> association; // root to its children
};

class Solution {
public:
  vector<string> largestItemAssociation(vector<PairString> &ItemAssociation) {
    UnionFind uf(ItemAssociation);
    for (const auto &IA : ItemAssociation) {
      uf.unite(IA.first, IA.second);
    }

    uf.buildAssociation();
    return uf.findMaxAssociation();
  }
};

static int i = 1;
void test(Solution &sol, vector<PairString> &itemAssociation,
          vector<string> &expected) {
  cout << "Run test case " << i++ << endl;
  auto res = sol.largestItemAssociation(itemAssociation);
  // for (auto &item : res)
  //   cout << item << " ";
  // cout << endl;
  assert(res == expected);
  cout << " The largest item association is : " << endl;
  for (auto &item : expected)
    cout << item << " ";
  cout << endl;
  cout << "Success!" << endl;
}

int main() {
  Solution sol;
  vector<PairString> itemAssociation = {
      PairString("item1", "item2"), PairString("item2", "item3"),
      PairString("item4", "item5"), PairString("item6", "item7"),
      PairString("item5", "item6"), PairString("item3", "item7")};
  vector<string> expected = {"item1", "item2", "item3", "item4",
                             "item5", "item6", "item7"};
  test(sol, itemAssociation, expected);

  vector<PairString> itemAssociation2 = {PairString("item1", "item2"),
                                         PairString("item3", "item4"),
                                         PairString("item4", "item5")};
  vector<string> expected2 = {"item3", "item4", "item5"};
  test(sol, itemAssociation2, expected2);

  vector<PairString> itemAssociation3 = {PairString("item1", "item2"),
                                         PairString("item3", "item4"),
                                         PairString("item5", "item6")};
  vector<string> expected3 = {"item1", "item2"};
  test(sol, itemAssociation3, expected3);

  vector<PairString> itemAssociation4 = {
      PairString("item1", "item2"), PairString("item2", "item3"),
      PairString("item4", "item5"), PairString("item5", "item6")};
  vector<string> expected4 = {"item1", "item2", "item3"};
  test(sol, itemAssociation4, expected4);
}