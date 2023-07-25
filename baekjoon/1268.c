#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int N;
    int input[1000][5] = {0};
    int cnt[1000] = {0};
    
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&input[i][j]);
        }
    }

    //비교 시작
    for(int sid1 = 0; sid1 < N-1; sid1++){
        for (int sid2 = sid1+1; sid2 < N; sid2++ ){
            for(int y=0; y<5; y++){
                if(input[sid1][y] == input[sid2][y]){
                    cnt[sid1]++;
                    cnt[sid2]++;
                    break;
                }
            }
        }
    }
    
    //최대 비교
    int maxID = 0;
    for (int i = 0; i < N; i++){
        if( cnt[maxID] < cnt[i] )
            maxID = i;
    }
    printf("%d",maxID+1);

	return 0;
}
