// You are processing plane seat reservations. The plane has N rows of seats, numbered from 1 to N.
// There are ten seats in each row (labelled from A to K, with letter I omitted), as shown in the figure below:
//    A  B  C    D  E  F  G    H  J  K
// 1  _  _  _    _  _  _  _    _  _  _
// 2  _  _  _    _  _  _  _    _  _  _ 
// . 
// N  _  _  _    _  _  _  _    _  _  _

// Some of the seats are already reserved. The list of reserved seats is given as a string S (of length M) containing
// seat numbers separated by single spaces: for example, "1A 3C 2B 40G 5A". The reserved seats can be listed in S in any order.
// Your task is to allocate seats for as many four-person families as possible. A four-person family occupies four
// seats in one row, that are next to each other - seats across an aisle (such as 2C and 2D are not considered to be next to
// each other. It is permissible for the family to be separated by an aisle, but in this case exactly two people have to sit
// on each side of the aisle. Obviously, no seat can be allocated to more than one family.

// Write a function:
// class Solution { public int solution(int n, String s); }

// that, given the number of rows N and a list of reserved seats as string S, returns the maximum number of four-person
// families that can be seated in the remaining unreserved seats.
// For instance, given N = 2 and S = "1A 2F 1C", your function should return 2.
// The following figure shows one possible way of seating two families in the remaining seats:
//    A  B  C     D  E  F  G     H  J  K
// 1  X  _  X     *  *  *  *     _  _  _ 
// 2  _  *  *     *  *  X  _     _  _  _

// https://leetcode.com/discuss/interview-question/492652/


int charToIdx(const char& c)
{
    if(c > 'I')
        return c - 'A' + 1;

    return c - 'A';
}

void populateReservedSeats(vector<vector<bool>>& seatMap, const string& s)
{
    istringstream ss (s);
    string currSeat;

    while(getline(ss, currSeat, ' '))
    {
        // cout<<currSeat<<endl;
        char C = currSeat[currSeat.size()-1];
        string num = currSeat.substr(0, currSeat.size()-1);
        int seatNum = stoi(num) - 1;
        int seatChar = charToIdx(C);
        
        // cout<<seatNum<<" "<<seatChar<<endl;
        seatMap[seatNum][seatChar] = true;
    }
}

int maxNumFamilies(const int& N, const string& s)
{
    vector<vector<bool>> seatMap (N, vector<bool>(10, false));
    
    int ans_maxFam = 0;

    // Populate reserved seats
    populateReservedSeats(seatMap, s);

    for(int i=0; i < N; i++)
    {
        int aisleSeats = 0;
        int middleSeats = 0;
        // Case 1: B C and D E
        if(!seatMap[i][1] && !seatMap[i][2] && !seatMap[i][3] && !seatMap[i][4])
            aisleSeats++;
        // Case 2: D E F G
        if(!seatMap[i][3] && !seatMap[i][4] && !seatMap[i][5] && !seatMap[i][6])
            middleSeats++;
        // Case 3: F G and H J
        if(!seatMap[i][5] && !seatMap[i][6] && !seatMap[i][7] && !seatMap[i][8])
            aisleSeats++;
        
        ans_maxFam += max(aisleSeats, middleSeats);
    }

    return ans_maxFam;
}

int main() {
    string s = "1A 1C";
    int N = 2;
    int ans = maxNumFamilies(2, s);
    cout << ans << endl;
}