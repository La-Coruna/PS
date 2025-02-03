/*
[후보 추천하기]
- date: 25.02.03
- 분류: simulation
*/
#include <bits/stdc++.h>
using namespace std;

int N, M, c;
int cnt[101];
int c_time[101];
vector<int> arr;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	arr.reserve(N);

	for (int t = 0; t < M; t++) {
		cin >> c;
		// 이미 있음
		if (cnt[c] != 0) cnt[c]++;
		// 새로 추가
		else {
			// 칸 있음
			if (arr.size() < N) arr.push_back(c);
			// 칸 부족
			else {
				int minCnt = 0x7fffffff, minCntIdx = 0;
				for (int j = 0; j < N; j++) {
					if (cnt[arr[j]] > minCnt ) continue;
					if (cnt[arr[j]] == minCnt && c_time[arr[j]] > c_time[arr[minCntIdx]]) continue;
					minCntIdx = j;
					minCnt = cnt[arr[j]];
				}
				cnt[arr[minCntIdx]] = 0;
				arr[minCntIdx] = c;
			}
			cnt[c]++;
			c_time[c] = t;
		}
	}
	
	sort(arr.begin(), arr.end());
	for (int a : arr)
		cout << a << ' ';

	return 0;
}