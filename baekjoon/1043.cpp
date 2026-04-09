/*
[거짓말] 
- date: 0409 
*/
#include <bits/stdc++.h>
using namespace std;

//bool knowsTruth[51];
//set<int> adj[51];
int N, M, T, t, firstTruth, oneOfPartyMembers[50], ans;

int p[51];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u); v = find(v);

    if(u == v) return false;
    if(p[u] > p[v]) swap(u, v);
    else if(p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    // 진실을 아는 사람이 없다면 조기 종료
    if(T == 0) {
        cout << M;
        return 0;
    }

    // 부모 배열 초기화
    fill(p, p+N+1, -1);
    
    // 진실을 아는 사람끼리 union
    cin >> firstTruth;
    for(int i = 1; i < T; i++){
        cin >> t;
        uni(firstTruth,t);
    }

    // 파티 같이 갔으면 union하기
    for(int i = 0; i < M; i++){
        cin >> T;
        cin >> oneOfPartyMembers[i];
        for(int j = 1; j < T; j++){
            cin >> t;
            uni(oneOfPartyMembers[i], t);
        }
    }

    // 진실을 아는 사람이랑 연결 안된 파티 수 찾기
    for(int i = 0; i < M; i++){
        if(find(oneOfPartyMembers[i]) != find(firstTruth)) ans++;
    }

    cout << ans;

    return 0;
}