#include <cstdio>
#include <cstring>

using namespace std;

int main(void){
    int stack[10000];
    int index = -1;
    int numOfCmd;
    char cmd[6];

    scanf("%d", &numOfCmd);

    for(int i = 0; i < numOfCmd; i++){
        scanf("%s", cmd);
        if(!strcmp( cmd, "push")){
            scanf("%d", &stack[++index]);
        } else if(!strcmp( cmd, "pop")){
            if(index == -1)
                printf("-1\n");
            else
                printf("%d\n", stack[index--]);

        } else if(!strcmp( cmd, "size")){
            printf("%d\n", index + 1);
        } else if(!strcmp( cmd, "empty")){
            if(index == -1)
                printf("1\n");
            else
                printf("0\n");
        } else if(!strcmp( cmd, "top")){
            if(index == -1)
                printf("-1\n");
            else
                printf("%d\n", stack[index]);
        }
    }

    return 0;
}

/* 
    #include <iostream>
    #include <string>
    c++의 라이브러리를 사용하니까 시간초과가 일어났다.
    그래서 c라이브러리를 사용하여 다시 짰다.
 */