
/* 
[����Լ��� ������?]
- date: 24.07.19
- �з�: Recursion
 */
#include <bits/stdc++.h>
using namespace std;
int N;

void Answer(int i){
    for(int j = 0; j < i; j++) cout << "____";
    cout << "\"����Լ��� ������?\"\n";
    if(i==N) {
        for(int j = 0; j < i; j++) cout << "____";
        cout<< "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for(int j = 0; j < i; j++) cout << "____";
        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    for(int j = 0; j < i; j++) cout << "____";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for(int j = 0; j < i; j++) cout << "____";
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for(int j = 0; j < i; j++) cout << "____";
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    Answer(i+1);
    for(int j = 0; j < i; j++) cout << "____";
    cout << "��� �亯�Ͽ���.\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    Answer(0);
    return 0;
}