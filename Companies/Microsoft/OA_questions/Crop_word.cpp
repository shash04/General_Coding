// Implement algorithm to crop msgs that are too long. Rules to follow :
// 1. Don't crop away part of word
// 2. Output msg shouldn't end with space
// 3. Output msg shouldn't exceed K-char limit
// 4. Output msg should be as long as possible

// https://leetcode.com/discuss/interview-question/507367/

string limitKCharactersPerEntry(const string& s, const int& K)
{
    string res;
    int spaceIndex = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(i < K)
        {
            // Avoid cases like s = "Codility we          test coders" and K = 14
            if(i > 0 && s[i] == ' ' && s[i-1] == ' ')
                continue;
            if(s[i] == ' ')
                spaceIndex = i;
        }
        else
            break;
    }

    res = s.substr(0, spaceIndex);
    return res;
}

int main() {
    string s = "Codility we          test coders";
    int K = 14;
    string ans = limitKCharactersPerEntry(s, K);
    cout << ans << endl << ans.size() << endl;
}