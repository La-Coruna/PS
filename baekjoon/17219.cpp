/*
[비밀번호 찾기] 
- date: 24.10.24
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, string> m;
    string site, pw;

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> site >> pw;
        m.emplace(site,pw);
    }
    for(int i = 0; i < M; i++){
        cin >> site;
        cout << m[site] << '\n';
    }

    return 0;
}