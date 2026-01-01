/*
[소풍] 
- date: 26.01.01

- 어떻게 그래프 안에서 돤전 그래프들을 뽑아내지?
    - 백트래킹?
- 친구가 K-1 명이 없으면 그냥 빼버리기
*/
#include <bits/stdc++.h>
using namespace std;

bool isAdj[901][901];
int edgeCnt[901];

vector<int> s;
int K, N, F;

bool func(int trial, int nxt){
    if(trial == K){
        return true;
    }
    if(nxt > N) return false;
    for(int i = nxt; i <= N ; i++){
        if(edgeCnt[i] < K-1) continue;
        bool isAdjOthers = true;
        for(int& c: s){
            if(!isAdj[i][c]){
                isAdjOthers = false;
                break;
            }
        }
        if(!isAdjOthers) continue;
        s.emplace_back(i);
        if(func(trial+1, i+1)) return true;
        s.pop_back();
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N >> F;

    for(int i = 0; i < F; i++){
        int u, v;
        cin >> u >> v;
        isAdj[u][v] = true;
        isAdj[v][u] = true;
        edgeCnt[u]++;
        edgeCnt[v]++;
    }
    
    if(func(0, 1)){
        for(int& c: s)
            cout << c << '\n';
    }
    else
        cout << -1;

    return 0;
}