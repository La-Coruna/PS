/* 
[01타일]
- date: 0904
- 분류: dp
- 소감:
    이런 문제는 변수 3개로도 충분히 될 것 같아서.
 */

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N < 3) {
        cout << N << endl;
        return 0;
    }

    int a = 1; // N = 1
    int b = 2; // N = 2

    for (int i = 3; i <= N; i++) {
        int temp = (a + b) % 15746;
        a = b;
        b = temp;
    }

    cout << b << endl;

    return 0;
}
