/* 
[최소 스패닝 트리]
- date: 24.10.23
- 분류: Graph, MST
 */
#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> edge[100'000];

vector<int> p(10'001, -1);

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

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge[i] = {c,u,v};
    }

    sort(edge, edge+E);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < E; i++){
        int c, u, v;
        tie(c, u, v) = edge[i];
        if(!unionSets(u,v)) continue;
        ans += c;
        cnt++;
        if(cnt == V-1) break;
    }

    cout << ans;

    return 0;
}