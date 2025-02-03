/*
[수들의 합 2] 
- date: 25.02.03
- 분류: two pointers
*/
#include <bits/stdc++.h>
using namespace std;

int arr[10'000];
int N, M, ans = 0;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int st = 0, en = 0, sum = 0;
	while (st<=en) {
		while (sum < M && en < N) {
			sum	 += arr[en++];
		}
		if (sum == M) ans++;
		sum	 -= arr[st++];
	}
	cout << ans;

    return 0;
}