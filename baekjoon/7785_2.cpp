/* 
[회사에 있는 사람]
- date: 24.07.26
- 분류: Hash
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<string> S;

    int n;
    cin >> n;
    while(n--){
        string name, log;
        cin >> name >> log;

        if(log == "enter") S.insert(name);
        else S.erase(name);
    }

    for(set<string>::reverse_iterator i = S.rbegin(); i != S.rend(); i++)
        cout << *i << '\n';

    return 0;
}