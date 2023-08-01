#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int numOfCmd;
    int front_idx = 0;
    int back_idx = 0;
    char cmd[11];
    int deque[10000];

    scanf("%d", &numOfCmd);

    for (int i = 0; i < numOfCmd; i++)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push_front"))
        {
            if(--front_idx < 0)
                front_idx = 9999;
            scanf("%d",&deque[front_idx]);
        }
        else if (!strcmp(cmd, "push_back"))
        {
            scanf("%d",&deque[back_idx]);
            if(++back_idx > 9999)
                back_idx = 0;
        }
        else if (!strcmp(cmd, "pop_front"))
        {
            if(front_idx == back_idx)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n",deque[front_idx]);
            if(++front_idx > 9999)
                front_idx = 0;
        }
        else if (!strcmp(cmd, "pop_back"))
        {
            if(front_idx == back_idx)
            {
                printf("-1\n");
                continue;
            }
            if(--back_idx < 0)
                back_idx = 9999;
            printf("%d\n",deque[back_idx]);
        }
        else if (!strcmp(cmd, "size"))
        {
            int size = back_idx - front_idx;
            if(size < 0)
                size += 10000;
            printf("%d\n", size);
        }
        else if (!strcmp(cmd, "empty"))
        {
            printf("%d\n", !(back_idx - front_idx));

        }
        else if (!strcmp(cmd, "front"))
        {
            if(front_idx == back_idx)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n",deque[front_idx]);
        }
        else if (!strcmp(cmd, "back"))
        {
            if(front_idx == back_idx)
            {
                printf("-1\n");
                continue;
            }
            if(back_idx - 1 < 0)
                printf("%d\n",deque[9999]);
            else
                printf("%d\n",deque[back_idx - 1]);
        }
    }

    return 0;
}


/* 

 -----------------------------------------------------------
|    |                                                 |    |
 -----------------------------------------------------------
0    1                                               9999  10000


 */