#include <cstdio>
#include <cstring>

using namespace std;

int main(void){
    int queue[10000];
    int numOfCmd;
    int front_idx=0;
    int back_idx=0;
    char cmd[6];

    scanf("%d", &numOfCmd);

    for(int i = 0; i < numOfCmd; i++){
        scanf("%s", cmd);
        if(!strcmp( cmd, "push")){
            scanf("%d", &queue[back_idx++]);
        } else if(!strcmp( cmd, "pop")){
            if(front_idx == back_idx)
                printf("-1\n");
            else
                printf("%d\n", queue[front_idx++]);

        } else if(!strcmp( cmd, "size")){
            printf("%d\n", back_idx - front_idx);
        } else if(!strcmp( cmd, "empty")){
            if(front_idx == back_idx)
                printf("1\n");
            else
                printf("0\n");
        } else if(!strcmp( cmd, "front")){
            if(front_idx == back_idx)
                printf("-1\n");
            else
                printf("%d\n", queue[front_idx]);
        } else if(!strcmp( cmd, "back")){
            if(front_idx == back_idx)
                printf("-1\n");
            else
                printf("%d\n", queue[back_idx-1]);
        }
    return 0;
}