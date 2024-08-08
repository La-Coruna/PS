/* 
[트리 순회]
- date: 24.08.07
- 분류: Tree
 */
#include <bits/stdc++.h>
using namespace std;

int N;
int lc[26], rc[26];

void preorder_traversal(int cur){
    cout << (char)(cur + 'A');
    if(lc[cur] != -19) preorder_traversal(lc[cur]);
    if(rc[cur] != -19) preorder_traversal(rc[cur]);
    return;
}

void inorder_traversal(int cur){
    if(lc[cur] != -19) inorder_traversal(lc[cur]);
    cout << (char)(cur + 'A');
    if(rc[cur] != -19) inorder_traversal(rc[cur]);
    return;
}

void postorder_traversal(int cur){
    if(lc[cur] != -19) postorder_traversal(lc[cur]);
    if(rc[cur] != -19) postorder_traversal(rc[cur]);
    cout << (char)(cur + 'A');
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        char cur, l, r;
        cin >> cur >> l >> r;
        lc[cur - 'A'] = l-'A';
        rc[cur - 'A'] = r-'A';
    }

    // for(int i = 0; i < N; i++){
    //     cout << (char)(i + 'A') << ' ' << (char)(lc[i] + 'A') << ' ' << (char)(rc[i] + 'A') << '\n';
    // } 

    preorder_traversal(0);
    cout << '\n';
    inorder_traversal(0);
    cout << '\n';
    postorder_traversal(0);

    return 0;
}