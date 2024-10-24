/* 
[물대기]
- date: 24.10.24
- 분류: Graph, MST, Graph Modeling
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> p(301, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool unionSets(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return false;
    if(p[x] == p[y]) p[x]--;
    if(p[x] < p[y]) p[y] = x;
    else p[x] = y;
    return true;
}

vector<tuple<int,int,int>> edges;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, c;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> c;
        edges.emplace_back(c,0,i);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> c;
            if(j <= i) continue;
            edges.emplace_back(c,i,j);;
        }
    }

    sort(edges.begin(), edges.end());
    int cnt = 0;
    int ans = 0;
    for(auto e : edges){
        int c, u, v;
        tie(c, u, v) = e;
        if(!unionSets(u,v)) continue;
        ans += c;
        cnt++;
        if(cnt == N) break;
    }

    cout << ans;

    return 0;
}