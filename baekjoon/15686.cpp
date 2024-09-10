/* 
[치킨 배달]
- date: 24.09.07
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, input, min_city_chk_dst = 0x7fffffff;
    vector<pair<int,int>> house;
    vector<pair<int,int>> chicken;
    vector<bool> isFired;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            if(input == 1) house.emplace_back(i,j);
            else if(input == 2) chicken.emplace_back(i,j);
        }
    }

    int c = chicken.size();
    while(isFired.size() != M)
        isFired.emplace_back(0);
    while(isFired.size() != c)
        isFired.emplace_back(1);
    
    do{
        int city_chk_dst = 0;
        for(auto h : house){
            int h_chk_dst = 0x7fffffff;
            for(int i = 0; i < c; i++){
                if(isFired[i]) continue;
                int dist = abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y);
                h_chk_dst = min(h_chk_dst, dist);
            }
            city_chk_dst += h_chk_dst;
        }
        min_city_chk_dst = min(city_chk_dst, min_city_chk_dst);
    } while(next_permutation(isFired.begin(), isFired.end()));

    cout << min_city_chk_dst;

    return 0;
}