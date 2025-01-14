/* 
[리모컨]
- date: 24.01.13
- 분류: Simulation
 */
#include <bits/stdc++.h>
using namespace std;

int N, M; // (0 ≤ N ≤ 500,000)
bool isBroken[10];
bool hasBigNum = true;
bool hasSmallNum = true;

bool hasBroken(int num){
    if(num == 0) return isBroken[0]; // 이거 빼먹어서 틀렸었음.
    while(num != 0){
        if(isBroken[(num % 10)])
            return true;
        num /= 10;
    }
    return false;
}

int FindBigger(int N){
    // 0번만 누를 수 있는 경우, 더 큰 숫자 못 만듬.
    if(M==9 && !isBroken[0]){
        hasBigNum = false;
        return -1;
    }
    while(hasBroken(N)) N++;
    return N;
}

int FindSmaller(int N){
    while(hasBroken(N) && N >=0) N--;
    if(N < 0){
        // 0까지 훑어봤는데, 가능한 숫자가 없음.
        hasSmallNum = false;
        return -1;
    }
    return N;
}

int CalDigits(int N){
    if(N==0) return 1;
    int i = 0;
    while(N!=0){
        N /= 10;
        i++;
    }
    return i;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    int directBtnCnt = abs(N - 100);
    if(M == 10){
        cout << directBtnCnt;
        return 0;
    }

    for(int i = 0; i < M; i++){
        int btn;
        cin >> btn;
        isBroken[btn] = true;
    }

    int bigNum = FindBigger(N);
    int smallNum = FindSmaller(N);

    int bigNumCnt = CalDigits(bigNum) + (bigNum - N);
    int smallNumCnt = CalDigits(smallNum) + (N - smallNum);

    int ans = directBtnCnt;
    if(hasBigNum) ans = min(ans, bigNumCnt);
    if(hasSmallNum) ans = min(ans, smallNumCnt);

    cout << ans;

    return 0;
}