/* 
[암호 만들기]
- date: 25.02.04
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> spell;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		spell.emplace_back(c);
	}
	sort(spell.begin(), spell.end());

	vector<bool>isUnselected(L, 0);
	isUnselected.resize(C, 1);

	do {
		bool hasMother = false;
		int hasSon = 0;

		// 단어 생성
		string pw = "";
		for (int i = 0; i < spell.size(); i++) {
			if (isUnselected[i]) continue;

			// 자모음 확인
			if (spell[i] == 'a' || spell[i] == 'e' || spell[i] == 'i' || spell[i] == 'o' || spell[i] == 'u')
				hasMother = true;
			else
				hasSon++;

			pw += spell[i];
		}

		if (hasMother && hasSon >= 2) cout << pw << '\n';
	} while (next_permutation(isUnselected.begin(), isUnselected.end()));

	return 0;
}