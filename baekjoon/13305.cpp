/*
[주유소]
- date: 24.10.04
- 분류: Greedy
*/
#include <bits/stdc++.h>
using namespace std;

int price[100'001];
int dist[100'001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long totalCost = 0;
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        cin >> dist[i];
    }
    for(int i = 0; i < N; i++){
        cin >> price[i];
    }

    int minPrice = price[0];
    for(int i = 0; i < N-1; i++){
        minPrice = min(minPrice, price[i]);
        totalCost += (long long) minPrice * dist[i];
    }

    cout << totalCost;

    return 0;
}