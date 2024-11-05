/*
[업무 처리] 
- date: 24.11.05
- url: https://softeer.ai/practice/6251
*/
#include <bits/stdc++.h>
using namespace std;

queue<int> jobL[2048]; // 말단 업무는 왼쪽에 넣어줌
queue<int> jobR[1024];
int ans;

void DoLeftJob(int idx){
    if(jobL[idx].empty()) return;
    int cur = jobL[idx].front();
    
    // 부서장
    if(idx == 1){
        ans += cur;
    }
    // 상사
    else{
        if(idx%2 == 0) jobL[idx/2].emplace(cur);
        else jobR[idx/2].emplace(cur);
    }
    jobL[idx].pop();
    return;
}


void DoRightJob(int idx){
    if(jobR[idx].empty()) return;
    int cur = jobR[idx].front();
    
    // 부서장
    if(idx == 1){
        ans += cur;
    }
    // 상사
    else{
        if(idx%2 == 0) jobL[idx/2].emplace(cur);
        else jobR[idx/2].emplace(cur);
    }
    jobR[idx].pop();
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int H, K, R; // 조직 높이, 업무 개수, 날짜
    cin >> H >> K >> R; 

    int numLeaf = 1 << H;
    for(int i = numLeaf; i < numLeaf*2; i++){
        for(int j = 0; j < K; j++){
            int jobNo;
            cin >> jobNo; 
            jobL[i].emplace(jobNo);
        }
    }
    // job 잘 들어갔는지 확인
    // for(int i = numLeaf; i < numLeaf*2; i++){
    //     cout << i << ") ";
    //     for(int a: job[i])
    //         cout << a << ' ';
    //     cout << '\n';
    // }

    for(int day = 1; day <= R; day++){
        // 부서장 & 상사
        for(int i = 1; i < numLeaf; i++){
            if(day % 2) DoLeftJob(i);
            else DoRightJob(i);
        }

        // 말단
        for(int i = numLeaf; i < numLeaf*2; i++){
            DoLeftJob(i);
        }

        //cout << "DAY " << day << " : " << ans <<'\n';
    }

    cout << ans;

    return 0;
}