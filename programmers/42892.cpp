/*
[길 찾기 게임]
- date: 24.12.02
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42892
*/

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int id;
    int x;
    int y;
    Node* lc;
    Node* rc;
};

bool cmp(const Node& A, const Node& B){
    if(A.y > B.y) return true;
    else if(A.y == B.y && A.x < B.x) return true;
    else return false;
}

void Make_Tree(Node* parent, Node* child){
    if(child->x < parent->x){
        if(parent->lc == 0) parent->lc = child;
        else Make_Tree(parent->lc,child);
    } else{
        if(parent->rc == 0) parent->rc = child;
        else Make_Tree(parent->rc, child);
    }
}

vector<vector<int>> answer(2);

void preorder(Node* root){
    if(root == 0) return;
    answer[0].emplace_back(root->id);
    preorder(root->lc);
    preorder(root->rc);
}

void postorder(Node* root){
    if(root == 0) return;
    postorder(root->lc);
    postorder(root->rc);
    answer[1].emplace_back(root->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    // 1. node 형태로 정리
    vector<Node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++){
        nodes.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1],0,0});
    }
    sort(nodes.begin(),nodes.end(),cmp);
    
    // 2. root 설정
    Node* root = &(nodes[0]);
    
    // 3. root부터 자식들 설정.
    for(int i = 1; i < nodeinfo.size(); i++){
        Make_Tree(root,&nodes[i]);
    }
    
    preorder(root);
    postorder(root);
    
    return answer;
}