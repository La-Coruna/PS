/* 
[합이 0인 네 정수]
- date: 25.02.09
- 분류: binary search, two pointers, meet in the middle
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int A[4000], B[4000], C[4000], D[4000];
int AB[16'000'000], CD[16'000'000];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int n2 = n * n;

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB[i*n + j] = A[i] + B[j];
			CD[i*n + j] = C[i] + D[j];
		}
	}

	sort(AB, AB + n2);
	sort(CD, CD + n2);

	long long cnt = 0;
	for (int i = 0; i < n2; i++) {
		//cout << AB[i] << " " << CD[i] << '\n';
		int* l = lower_bound(CD, CD + n2, -AB[i]);
		int* u = upper_bound(l, CD + n2, -AB[i]);
		cnt += u-l;
	}

	cout << cnt;

	return 0;
}