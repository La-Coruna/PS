/*
[소셜 네트워킹 어플리케이션] 
- date: 25.10.08
*/
#include <bits/stdc++.h>
using namespace std;

int T, n, k, m, a, b;

int p[1'000'001];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool union_set(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;

    // 랭크가 높은 쪽이 부모. (즉, p[x]가 낮은 쪽이 부모)
    // 여기선 u가 부모가 되게 할 것임.
    if(p[v] < p[u]) swap(u,v);
    else if(p[u] == p[v]) p[u]--;

    p[v] = u;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int t = 1; t <= T; t++){
        cin >> n >> k;
        fill(p, p+1+n, -1);
        for(int i = 0; i < k; i++){
            cin >> a >> b;
            union_set(a,b);
        }
        cout << "Scenario " << t << ":\n";
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            cout << (find(a) == find(b)) << '\n';
        }
        cout << '\n';
    }

    return 0;
}