/* 
[치킨 배달]
- date: 24.09.07
- date2: 25.02.04
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, board[51][51];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) houses.emplace_back(i,j);
			else if (board[i][j] == 2) chickens.emplace_back(i,j);
		}
	}

	// M개만 폐업 안함
	vector<bool> isClosed(M, 0);
	isClosed.resize(chickens.size(), 1);

	int minCityDiff = 0x7fffffff;
	do {
		int cityDiff = 0;
		for (auto h : houses) {
			int diff = 0x7fffffff;
			// 각 치킨집과 거리를 계산해 치킨거리 갱신
			for (int i = 0; i < chickens.size(); i++) {
				if (isClosed[i]) continue;
				diff = min(diff, abs(h.X - chickens[i].X) + abs(h.Y - chickens[i].Y));
			}
			cityDiff += diff;
		}

		minCityDiff = min(minCityDiff, cityDiff);

	} while (next_permutation(isClosed.begin(), isClosed.end()));

	cout << minCityDiff;

	return 0;
}