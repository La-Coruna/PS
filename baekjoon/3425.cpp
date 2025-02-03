/*
[고스택] 
- date: 25.02.03
- 분류: simulation
*/
#include <bits/stdc++.h>
using namespace std;

void func(vector<string> &p, int v);

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string cmd;
		cin >> cmd;
		// 종료
		if (cmd == "QUIT") {
			return 0;
		}
		
		// 프로그램 입력 받음
		vector<string> p;
		while (cmd != "END") {
			p.emplace_back(cmd);
			cin >> cmd;
		}

		int N; // 실행 횟수
		cin >> N;
		while (N--) {
			int v;
			cin >> v;
			func(p, v);
		}
		cout << '\n';
	}

	return 0;
}

void func(vector<string> &p, int v) {
	stack<long long> s;
	s.emplace(v);

	for(int i = 0; i < (int)(p.size()); i++) {
		string cmd = p[i];
		if (cmd == "NUM") {
			long long num = stoi(p[++i]);
			s.emplace(num);
		}
		else if (cmd == "POP") {
			if (s.empty()) { cout << "ERROR\n"; return; }
			s.pop();
		}
		else if (cmd == "INV") {
			if (s.empty()) { cout << "ERROR\n"; return; }
			long long tmp = s.top(); s.pop();
			s.emplace(-tmp);
		}
		else if (cmd == "DUP") {
			if (s.empty()) { cout << "ERROR\n"; return; }
			s.emplace(s.top());
		}
		else if (cmd == "SWP") {
			if (s.size()<2) { cout << "ERROR\n"; return; }
			long long tmp1 = s.top(); s.pop();
			long long tmp2 = s.top(); s.pop();
			s.emplace(tmp1);
			s.emplace(tmp2);
		}
		else if (cmd == "ADD") {
			if (s.size() < 2) { cout << "ERROR\n"; return; }
			long long tmp1 = s.top(); s.pop();
			long long tmp2 = s.top(); s.pop();
			long long res = tmp2 + tmp1;
			if( abs(res) > 1'000'000'000) { cout << "ERROR\n"; return; }
			s.emplace(res);
		}
		else if (cmd == "SUB") {
			if (s.size() < 2) { cout << "ERROR\n"; return; }
			long long tmp1 = s.top(); s.pop();
			long long tmp2 = s.top(); s.pop();
			long long res = tmp2 - tmp1;
			if (abs(res) > 1'000'000'000) { cout << "ERROR\n"; return; }
			s.emplace(res);
		}
		else if (cmd == "MUL") {
			if (s.size() < 2) { cout << "ERROR\n"; return; }
			long long tmp1 = s.top(); s.pop();
			long long tmp2 = s.top(); s.pop();
			long long res = tmp2 * tmp1;
			if (abs(res) > 1'000'000'000) { cout << "ERROR\n"; return; }
			s.emplace(tmp2 * tmp1);
		}
		else if (cmd == "DIV") {
			if (s.size() < 2) { cout << "ERROR\n"; return; }
			long long tmp1 = s.top(); s.pop();
			long long tmp2 = s.top(); s.pop();
			if (tmp1==0) { cout << "ERROR\n"; return; }
			long long res = abs(tmp2) / abs(tmp1);
			if (abs(res) > 1'000'000'000) { cout << "ERROR\n"; return; }
			if (((tmp1 < 0) && (tmp2 > 0)) || ((tmp1 > 0) && (tmp2 < 0))) res *= -1;
			s.emplace(res);
		}
		else if (cmd == "MOD") {
			if (s.size() < 2) { cout << "ERROR\n"; return; }
			long long tmp1 = s.top(); s.pop();
			long long tmp2 = s.top(); s.pop();
			if (tmp1 == 0) { cout << "ERROR\n"; return; }
			long long res = abs(tmp2) % abs(tmp1);
			if (abs(res) > 1'000'000'000) { cout << "ERROR\n"; return; }
			if (tmp2 < 0) res *= -1;
			s.emplace(res);
		}
		else if (cmd == "END") {
			break;
		}
	}

	if (s.size() != 1)
		cout << "ERROR\n";
	else
		cout << s.top() <<'\n';
	return;
}