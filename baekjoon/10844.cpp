/* 
날짜: 230814
깨달은 점: 값이 금방 커질 것 같은 곳은 꼼꼼히 모듈러 연산을 붙여주자. 이걸로 5번 틀림 ㅋㅋ
 */
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<int> v(10, 1);
    int N;
    int res = 0;

    cin >> N;

    v[0] = 0;

    for(int i = 1; i < N; i++){

        // calculate next level(tmp) with now level(v)
        int tmp[10] = {0};
        tmp[0] = v[1];
        for(int i = 1; i < 9; i++){
            tmp[i] = (v[i-1] + v[i+1]) % 1000000000;
        }
        tmp[9] = v[8];

        // update now level(v) into next level(tmp)
        for(int i = 0; i < 10; i++){
            v[i] = tmp[i];
        }
    }
    
    for(int i = 0; i < 10; i++){
        res = (res % 1000000000) + v[i];
    }

    cout << res % 1000000000;

    return 0;
}