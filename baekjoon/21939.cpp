/*
[문제 추천 시스템 Version 1] 
- date: 24.10.24
- 분류: BST
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int problem[100'001];
    set<int> S[101];

    string cmd;
    int N, M, P, L;
    cin >> N;
    while(N--){
        cin >> P >> L;
        problem[P] = L;
        S[L].insert(P);
    }
    cin >> M;
    while(M--){
        cin >> cmd;
        if(cmd == "recommend"){
            cin >> P;
            if(P == 1){
                int l = 101;
                while(l--){
                    if(S[l].empty()) continue;
                    cout << *(S[l].rbegin()) << '\n';
                    break;
                }
            }else{
                int l = 0;
                while(++l){
                    if(S[l].empty()) continue;
                    cout << *(S[l].begin()) << '\n';
                    break;
                }
            }
        }
        else if(cmd == "add"){
            cin >> P >> L;
            problem[P] = L;
            S[L].emplace(P);
        }
        else{
            cin >> P;
            S[problem[P]].erase(P);
        }
    }

    return 0;
}