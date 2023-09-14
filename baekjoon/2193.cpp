/* 
date: 230814
깨달은 점: 자료형의 크기에 유의하자.
 */
#include <iostream>

using namespace std;

int main(void){
    int N;
    long long now_0 = 0;
    long long now_1 = 1;
    long long next_0, next_1;

    cin >> N;

    for(int i = 1; i < N; i++){
        // calculate
        next_0 = now_0 + now_1;
        next_1 = now_0;

        // update
        now_0 = next_0;
        now_1 = next_1;
    }

    cout << now_0 + now_1;
    
    return 0;
}