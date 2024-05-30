/*
[키로거]
- date: 24.05.29
- 분류: linked list
 */

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string input;

    cin >> n;
    while (n--)
    {
        list<char> text;
        list<char>::iterator cursor = text.end();

        cin >> input;
        for (char c : input)
        {
            if (c == '<')
            {
                if (cursor != text.begin())
                    cursor--;
            }
            else if (c == '>')
            {
                if (cursor != text.end())
                    cursor++;
            }
            else if (c == '-')
            {
                if (cursor != text.begin())
                    cursor = text.erase(--cursor);
            }
            else
            {
                cursor = ++(text.insert(cursor, c));
            }
        }
        for (char c : text)
            cout << c;
        cout << "\n";
    }

    return 0;
}
