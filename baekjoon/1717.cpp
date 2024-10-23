/*
[집합의 표현]
- date:24.10.23
- Graph, Union Find
*/
#include <bits/stdc++.h>
using namespace std;

int p[1'000'001];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(p[x] < p[y]) p[y] = x;
    else p[x] = y;
    return;
}

bool isUnion(int x, int y){
    return find(x) == find(y);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    while(m--){
        int c, a, b;
        cin >> c >> a >> b;
        if(c==0)
            merge(a, b);
        else{
            if(isUnion(a,b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}