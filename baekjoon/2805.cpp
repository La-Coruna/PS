/* 
[나무 자르기]
- date: 24.08.19
- 분류: 
 */
#include <bits/stdc++.h>
using namespace std;

long long N, M, tree[1'000'001], h;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> tree[i];
    }

    sort(tree, tree + N, greater<long long>());
    h = tree[0];
    tree[N] = 0;

    for(int i = 0; i < N; i++){
        long long diff_of_height = tree[i] - tree[i+1];
        long long cutTree = (i+1)*diff_of_height;
        if(M - cutTree <= 0){
            h -= M / (i+1);
            if(M % (i+1) != 0) h--;
            break;        
        }
        M -= cutTree;
        h -= diff_of_height;
    }

    cout << h;

    return 0;
}