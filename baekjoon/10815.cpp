#include <cstdio>
#include <map>

using namespace std;

int main(void){
    int N, M;
    int input;
    
    map<int, bool> myMap;

    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &input);
        myMap.insert(std::make_pair(input, true));
    }

    scanf("%d", &M);
    for(int i = 0; i<M; i++){
        scanf("%d", &input);
        if(myMap.find(input) != myMap.end() )
            printf("1 ");
        else
            printf("0 ");
    }
    
    return 0;
}