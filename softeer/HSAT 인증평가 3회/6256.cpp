/*
[교차로] 
- date: 24.11.09
- url: https://softeer.ai/practice/6256

<오답노트>
- 전부 비어 있는 상태도 deadlock 상태라고 판단해서 조기 종료 했었음
    반례
    2
    10 A
    20 A

- 시간 공백이 너무 길 때 시간초과 일어났었음.
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, t, curCarIdxToEnter = 0;
char w;

vector<pair<int,char>> arr;
vector<int> leaveTime;
queue<int> waiting[4];

void Enter(int curTime){
    int t; char dir;
    if(curCarIdxToEnter >= N) return;
    tie(t, dir) = arr[curCarIdxToEnter];

    if(curTime != t) return;

    waiting[(dir-'A')].emplace(curCarIdxToEnter);
    
    // cout << "curCarIdxToEnter : " << curCarIdxToEnter << '\n';
    // for(int i = 0; i < 4; i++){
    //         if(waiting[i].empty()) continue;
    //     cout << (char)('A'+i) << " : " << waiting[i].front() << '\n';
    // }

    curCarIdxToEnter++;
    Enter(curTime);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t >> w;
        arr.emplace_back(t,w);
    }
    leaveTime.resize(N,-1);

    int curTime = arr[0].X;
    
    for(int passedCarNum = 0; passedCarNum < N;){
        Enter(curTime);
        
        // cout << "before Leave curTime : " << curTime << '\n';
        // for(int i = 0; i < 4; i++){
        //     if(waiting[i].empty()) continue;
        //     cout << (char)('A'+i) << " : " << waiting[i].front() << '\n';
        // }

        bool noOutCar = true;
        vector<bool> isOut(4, false);
        for(int d = 1; d <= 4; d++){
            if(!waiting[d-1].empty()|| waiting[(d%4)].empty()) continue;
            int curCarIdx = waiting[(d%4)].front();
            isOut[(d%4)] = true;
            leaveTime[curCarIdx] = curTime;
            passedCarNum++;
            noOutCar = false;
        }
        for(int d = 0; d < 4; d++)
            if(isOut[d]) waiting[(d%4)].pop();


        // cout << "after Leave curTime : " << curTime << '\n';
        // for(int i = 0; i < 4; i++){
        //     if(waiting[i].empty()) continue;
        //     cout << (char)('A'+i) << " : " << waiting[i].front() << '\n';
        // }

        curTime++;

        if(noOutCar){
            bool isAllEmpty = true;
            for(int i = 0; i < 4; i++)
                isAllEmpty &= waiting[i].empty();
            if(isAllEmpty) curTime = arr[curCarIdxToEnter].X;
            else break;
        }
    }

    for(int lt: leaveTime)
        cout << lt << '\n';

    return 0;
}