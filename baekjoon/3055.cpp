/* 
[탈출]
- date: 25.02.03
- 분류: bfs
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int R, C;
int sX, sY;
string board[50];
int water[50][50];
int gosumVis[50][50];

void flood(){
	for (int t = 1; ; t++) {
		bool cantFloodMore = true;

		queue<pair<int, int>> Q;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (water[i][j] != t) // 가장 자리에 있는 물만 되게. 가장 자리 물은 t랑 같은 값일 거임.
					continue;

				cantFloodMore = false;

				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if (water[nx][ny] > 0 || board[nx][ny] != '.') continue; // 물이 이미 있거나 못가는 길일 때, 패스

					water[nx][ny] = t+1;
				}
			}
		}

		if (cantFloodMore) break;
	}
}

int GoSumdochi() {
	queue<pair<int, int>> Q;
	gosumVis[sX][sY] = 1;
	Q.emplace(sX, sY);
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (board[nx][ny] == 'D') {
				return gosumVis[cur.X][cur.Y];
			}
			if (gosumVis[nx][ny] > 0 || board[nx][ny] != '.') continue;
			if (water[nx][ny] > 0 && water[nx][ny] <= gosumVis[cur.X][cur.Y] + 1) continue;
			gosumVis[nx][ny] = gosumVis[cur.X][cur.Y] + 1;
			Q.emplace(nx, ny);
		}
	}
	return -1;
}

void PrintWater() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << water[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void PrintGosum() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << gosumVis[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> board[i];

		for (int j = 0; j < C; j++) {
			if (board[i][j] == '*') water[i][j] = 1;
			else if (board[i][j] == 'S') {
				sX = i;
				sY = j;
				board[i][j] = '.';
			}
		}
	}

	flood();

	int ans = GoSumdochi();

	//PrintWater();
	//PrintGosum();

	if (ans == -1) cout << "KAKTUS";
	else cout << ans;

	return 0;
}