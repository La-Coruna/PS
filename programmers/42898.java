/*
[등굣길]
- date: 2026-07-23
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42898
*/

/*
00 01
10 11
dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
*/
import java.util.*;
class Solution {
    public int solution(int m, int n, int[][] puddles) {
        Arrays.sort(puddles, Comparator.<int[]>comparingInt(arr -> arr[0])
                   .thenComparingInt(arr -> arr[1]));
        
        int[][] dp = new int[n+1][m+1];
        
        // 초기값 설정
        for(int i = 1; i <= n ; i++){
            dp[i][1] = 1;
        }
        
        for(int i = 1; i <= m ; i++){
            dp[1][i] = 1;
        }
        
        int k = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= m; j++){
                if (k < puddles.length && i == puddles[k][0] && j == puddles[k][1]) {
                    k++;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
            }
        }
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         System.out.print(dp[i][j]);
        //     }
        //     System.out.println();
        // }
        
        return dp[n][m];
    }
}
