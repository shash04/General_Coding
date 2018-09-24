#include <iostream>
#include <stack>

using namespace std;

bool isCorrectClosing(char open, char closing)
{
    if(open == '{' && closing == '}')
        return true;
    if(open == '[' && closing == ']')
        return true;
    if(open == '(' && closing == ')')
        return true;
    return false;
}

bool isBalanced(string s) {
    stack<char> s1;

    for(int i=0; i<s.length(); i++)
    {
        // If open Parenthesis, push in stack
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            s1.push(s[i]);

        // if closing parenthesis, check if empty stack or latest correct opening parenthesis
        if(s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if(s1.empty() || !isCorrectClosing(s1.top(), s[i]))
                return false;
            s1.pop();
        }
    }
    // if stack is not empty, return false
    if(!s1.empty())
        return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        bool result = isBalanced(s);
        (result)? cout<< "YES": cout<< "NO" ;
        cout<<endl;
    }
    return 0;
}