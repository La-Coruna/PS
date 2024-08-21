/* 
[터렛]
- date: 24.08.20
- 분류: Math, Geometry
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int answer;
        int x1,y1,r1,x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        // 두 원이 겹치는 경우
        if(x1 == x2 && y1 == y2 && r1 == r2){
            cout << -1 << '\n';
            continue;
        }

        int d_sqr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int r_sum_sqr = (r1 + r2) * (r1 + r2);
        int r_diff_sqr = (r1 - r2) * (r1 - r2);
        // 두 원이 한 점에서 만나는 경우
        if(d_sqr == r_sum_sqr || d_sqr == r_diff_sqr){
            cout << 1 << '\n';
            continue;
        }
        // 두 원이 두 점에서 만나는 경우
        if(d_sqr < r_sum_sqr && d_sqr > r_diff_sqr){
            cout << 2 << '\n';
            continue;
        }
        // 안 만나는 경우 (d_sqr > r_sum_sqr || d_sqr < r_diff_sqr)
        cout << 0 << '\n';
    }

    return 0;
}