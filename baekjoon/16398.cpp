/*
[행성 연결] 
- date: 24.10.25
- 분류: Graph, MST
*/
#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edge;
vector<int> p(1001,-1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool unionSets(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return false;
    if(p[x] == p[y]) p[x]--;
    if(p[x] < p[y]) p[y] = x;
    else p[x] = y;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, c;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;
            if(j <= i) continue;
            edge.emplace_back(c,i,j);
        }
    }

    sort(edge.begin(), edge.end());
    int cnt = 0;
    long long ans = 0;
    for(auto e : edge){
        int c, u, v;
        tie(c,u,v) = e;
        if(!unionSets(u,v)) continue;
        cnt++;
        ans+=c;
        if(cnt == N-1) break;
    }

    cout << ans;

    return 0;
}