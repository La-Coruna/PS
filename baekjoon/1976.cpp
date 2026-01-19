/*
[여행 가자] 
- date: 26.01.18
*/
#include <bits/stdc++.h>
using namespace std;

int p[201];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void uni(int u, int v){
    u = find(u), v = find(v);

    if(u == v) return;

    if(p[v] < p[u]) swap(u,v);
    else if(p[v] == p[u]) p[u]--;
    p[v] = u;

    return;
}

bool isUni(int u, int v){
    return find(u) == find(v);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    fill(p+1, p+1+N, -1);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            bool isAdj;
            cin >> isAdj;
            if(isAdj) uni(i,j);
        }
    }

    bool canGo = true;
    int cur, nxt;
    cin >> cur;
    while(cin >> nxt){
        if(!isUni(cur,nxt)){
            canGo = false;
            break;
        }
        cur = nxt;
    }

    if(canGo) cout << "YES";
    else cout << "NO";

    return 0;
}