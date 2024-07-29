/* 
[이중 우선순위 큐]
- date: 24.07.29
- 분류: Binary Search Tree
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, K, input;
    char cmd;
    cin >> T;
    while(T--){
        multiset<int> S;
        cin >> K;
        while(K--){
            cin >> cmd >> input;
            if(cmd == 'I'){
                S.insert(input);
            } else if (cmd == 'D'){
                if(S.empty()) continue;
                if(input == -1) S.erase(S.begin());
                else S.erase(prev(S.end()));
            }
        }
        if(S.empty()) cout << "EMPTY\n";
        else cout << *(S.rbegin()) << ' ' << *(S.begin()) << '\n';
    }

    return 0;
}