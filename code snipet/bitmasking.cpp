/* 
어떤 숫자를 1씩 빼면서 원래 자기 값과 &를 하면, 모든 부분 집합을 구할 수 있음.
<관련 문제>
- [염기서열 커버] https://softeer.ai/practice/6249
 */

#include<bits/stdc++.h>
using namespace std;

int main(void){

    int index = 0b10101;
    for (int number1 = (index - 1) & index; number1 > (index / 2); number1 = (number1 - 1) & index){
        int number2 = index - number1;

        bitset<5> a(number1);
        bitset<5> b(number2);
        cout << a.to_string() << " : " << b.to_string() << '\n';
    }

    cout << '\n';
    for (int number1 = (index - 1) & index; number1 > 0; number1 = (number1 - 1) & index){

        bitset<5> a(number1);
        cout << a.to_string() << " : " << number1 << '\n';
    }

    return 0;
}