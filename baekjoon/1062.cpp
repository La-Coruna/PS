/* 
[가르침]
- date: 25.02.04
- 분류: backtracking
*/
#include <bits/stdc++.h>
using namespace std;

int N, K;
string words[50];
bool canRead[26];
int maxCnt = 0;

void func(int k, int idx) {
	if (k == K-5) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			bool canReadWord = true;
			for (char c : words[i]) {
				if (canRead[c-'a']) continue;
				canReadWord = false;
				break;
			}
			if (canReadWord) cnt++;
		}
		maxCnt = max(maxCnt, cnt);
		if (maxCnt == N) {
			cout << maxCnt;
			exit(0);
		}
		return;
	}
	for(int i = idx; i < 26; i++){
		if (canRead[i]) continue;
		canRead[i] = true;
		func(k + 1, i);
		canRead[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	// 하나도 못 읽는 경우
	if (K < 5) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> words[i];
		words[i] = words[i].substr(4, words[i].size() - 8);
	}

	canRead['a' - 'a'] = true;
	canRead['c' - 'a'] = true;
	canRead['i' - 'a'] = true;
	canRead['n' - 'a'] = true;
	canRead['t' - 'a'] = true;

	func(0,1);

	cout << maxCnt;

	return 0;
}