/*
date: 24.05.31
분류: stack
 */

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> s;
    string cmd;
    int N, num;

    cin >> N;
    while (N--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            s.push(num);
        }
        else if (cmd == "pop")
        {
            if (s.empty())
            {
                cout << -1;
            }
            else
            {
                cout << s.top();
                s.pop();
            }
            cout << "\n";
        }
        else if (cmd == "size")
        {
            cout << s.size();
            cout << "\n";
        }
        else if (cmd == "empty")
        {
            if (s.empty())
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
            cout << "\n";
        }
        else if (cmd == "top")
        {
            if (s.empty())
            {
                cout << -1;
            }
            else
            {
                cout << s.top();
            }
            cout << "\n";
        }
    }
    return 0;
}