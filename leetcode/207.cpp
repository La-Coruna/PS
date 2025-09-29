/*
[Course Schedule] 
- date: 25.09.26
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> adj[2000];
    int indeg[2000] = {0};
    queue<int> Q;
    int cnt = 0;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int>& p: prerequisites){
            int &x = p[0], &y = p[1];
            adj[y].emplace_back(x);
            indeg[x]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) {
                Q.emplace(i);
                cnt++;
            }
        }

        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int nxt: adj[cur]){
                if(--indeg[nxt] != 0) continue;
                Q.emplace(nxt);
                cnt++;
            }
        }

        if(cnt == numCourses) return true;
        else return false;
    }
};