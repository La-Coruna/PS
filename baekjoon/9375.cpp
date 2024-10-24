/*
[패션왕 신해빈] 
- date: 24.10.24

*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    cin >> T;
    while(T--){
        map<string, int> M;
        cin >> n;
        while(n--){
            string kind;
            cin >> kind >> kind;
            if(M.find(kind) == M.end()) M[kind] = 1;
            else M[kind]++;
        }
        int cnt = 1;
        for(auto i : M){
            cnt *= (i.second+1);
        }
        cout << --cnt << '\n';
    }

    return 0;
}