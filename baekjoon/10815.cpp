#include <cstdio>
#include <set>

using namespace std;

int main(void){
    int N, M;
    int input;
    
    set<int> S;

    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &input);
        S.insert(input);
    }

    scanf("%d", &M);
    for(int i = 0; i<M; i++){
        scanf("%d", &input);
        if(S.find(input) != S.end() )
            printf("1 ");
        else
            printf("0 ");
    }
    
    return 0;
}