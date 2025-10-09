/*
[내려가기]
- date: 25.02.09
- 분류: dp
- dp_max[2][0] = max(dp_max[1][0], dp_max[1][1]) + board[2][0]  
- dp_max[2][1] = max(dp_max[1][0], dp_max[1][1], dp_max[1][2]) + board[2][1]  
- dp_max[2][2] = max(dp_max[1][1], dp_max[1][2]) + board[2][2]  
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int board[100'000][3];

int prev_max[3];
int prev_min[3];
int cur_max[3];
int cur_min[3];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < 3; i++) {
		prev_max[i] = board[0][i];
		prev_min[i] = board[0][i];
	}

	int l, r;
	for (int i = 1; i < n; i++) {
		l = max(prev_max[0], prev_max[1]);
		r = max(prev_max[1], prev_max[2]);
		cur_max[0] = l + board[i][0];
		cur_max[1] = max(l, r) + board[i][1];
		cur_max[2] = r + board[i][2];

		l = min(prev_min[0], prev_min[1]);
		r = min(prev_min[1], prev_min[2]);
		cur_min[0] = l + board[i][0];
		cur_min[1] = min(l, r) + board[i][1];
		cur_min[2] = r + board[i][2];

		for (int i = 0; i < 3; i++) {
			prev_max[i] = cur_max[i];
			prev_min[i] = cur_min[i];
		}
	}

	cout << max(max(prev_max[0], prev_max[1]), prev_max[2]) << ' ' << min(min(prev_min[0], prev_min[1]), prev_min[2]);

	return 0;
}