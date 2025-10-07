/* 
[부분합]
- date: 25.02.04
- 분류: Two Pointers
*/
#include <bits/stdc++.h>
using namespace std;

int N, S, arr[100'000];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int st = 0, en = 0, sum = 0, minLen = 0x7fffffff;
	while(st <= en){
		while (en < N && sum < S) {
			sum += arr[en++];
		}
		if (sum >= S) { minLen = min(en - st, minLen); }
		sum -= arr[st++];
	}

	if (minLen == 0x7fffffff) cout << 0;
	else cout << minLen;

	return 0;
}