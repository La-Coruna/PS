/* 
[최소 힙]
- date: 24.08.03
- 분류: priority queue, heap
 */
#include <bits/stdc++.h>
using namespace std;

int heap[100003];
int sz = 0;

void push(int x){
    int idx = ++sz;
    heap[idx] = x;
    while(idx != 1 && heap[idx] < heap[idx/2]){
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }
}

int top(){
    return heap[1];
}

void pop(){
    if(sz == 0) return;
    swap(heap[1], heap[sz--]);
    int idx = 1;
    while(true){
        int lc = idx*2, rc = idx*2+1;
        int min_child_idx = lc;
        if(rc <= sz && heap[rc] < heap[lc]) min_child_idx = rc;
        else if(lc > sz) break;
        if(heap[idx] > heap[min_child_idx]) swap(heap[idx], heap[min_child_idx]);
        idx = min_child_idx;
    }
}

void test(){
    int N, input;
    cin >> N;
    while(N--){
        cin >> input;
        if(input == 0){
            if(sz == 0) cout << 0 << '\n';
            else {cout << top() << '\n'; pop();}
        } else{
            push(input);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test();
    return 0;
}
