/* 
[보석 도둑]
- date: 24.07.29
- 분류: Binary Search Tree
 */
#include <bits/stdc++.h>
using namespace std;
#define V first
#define M second
int N, K, input;
long long answer = 0;
pair<int,int> J[300000];
multiset<int> C;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int m,v;
    for(int i = 0; i < N; i++){
        cin >> m >> v;
        J[i] = make_pair(v,m);
    }
    for(int i = 0; i < K; i++){
        cin >> input;
        C.insert(input);
    }

    sort(J, J+N);

    // 보석을 가격이 높은 순으로 탐색
    for(int i = N-1; i >= 0; i--){
        if(C.empty()) continue;
        int curM = J[i].M, curV = J[i].V;
        auto bagIt =C.lower_bound(curM);
        if(bagIt == C.end()) continue; // 현재 보석을 담을 수 있는 가방이 없는 경우
        C.erase(bagIt);
        answer += curV;
    }

    cout << answer;

    return 0;
}