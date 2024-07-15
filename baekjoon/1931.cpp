/* 
[회의실 배정]
- date: 24.07.14
- 분류: Greedy
 */
#include <bits/stdc++.h>
using namespace std;
#define EndTime first
#define StartTime second
pair<int,int> input[100000];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, answer = 0, curTime = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input[i].StartTime >> input[i].EndTime;
    }
    sort(input, input + N);
    for(int i = 0; i < N; i++){
        if(curTime <= input[i].StartTime){
            answer++;
            curTime = input[i].EndTime;
        }
    }
    cout << answer;
    
    return 0;
}