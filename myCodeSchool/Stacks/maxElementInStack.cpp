///////////////////////////////////////////////////////////////////////
// HackerRank - Maximum Element
// https://www.hackerrank.com/challenges/maximum-element/problem
///////////////////////////////////////////////////////////////////////
// You have an empty sequence, and you will be given N queries.
// Each query is one of these three types:
// 1 - Push the element x into the stack.
// 2 - Delete the element present at the top of the stack.
// 3 - Print the maximum element in the stack.
// INPUT =  The first line of input contains an integer, N.
//          The next N lines each contain an above mentioned query.
//          It is guaranteed that each query is valid.
// OUTPUT = For each type 3 query, print the max element in the stack.

#include <iostream>
#include <stack>
using namespace std;

void deleteElementFromStackTop(stack<int> &s1, stack<int> &s_max)
{
    if (s1.empty() || s_max.empty())
        return;
    int top = s1.top();
    if (top == s_max.top())
        s_max.pop();
    s1.pop();
}

void addElementToStack(stack<int> &s1, stack<int> &s_max, int number)
{
    s1.push(number);
    if (s_max.empty())
        s_max.push(number);
    else if (s_max.top() <= number)
        s_max.push(number);
}

void printMaxElementInStack(stack<int> &s_max)
{
    if (s_max.empty())
        return;
    cout << s_max.top() << endl;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, type, number;
    cin >> N;
    stack<int> s1;
    stack<int> s_max;
    for (int i = 0; i < N; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> number;
            addElementToStack(s1, s_max, number);
        }
        else if (type == 2)
        {
            deleteElementFromStackTop(s1, s_max);
        }
        else if (type == 3)
        {
            printMaxElementInStack(s_max);
        }
    }
    return 0;
}