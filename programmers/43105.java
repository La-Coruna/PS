/*
[정수 삼각형]
- date: 2026-07-20
- url: https://school.programmers.co.kr/learn/courses/30/lessons/43105
*/

/*
i = 0      0
i = 1     0 1
i = 2    0 1 2
i = 3   0 1 2 3
i = 4  0 1 2 3 4
i = 5 0 1 2 3 4 5

d[i][j] : i번째 층에 j번째까지의 숫자의 합의 최대
d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j]
*/

import java.util.*;
class Solution {
    public int solution(int[][] triangle) {
        int[][] d = new int[triangle.length][triangle.length];
        
        d[0][0] = triangle[0][0];
        for(int i = 1; i < triangle.length; i++){
            d[i][0] = d[i-1][0] + triangle[i][0];
            d[i][i] = d[i-1][i-1] + triangle[i][i];
            for(int j = 1; j < i; j++){
                d[i][j] = Math.max(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
            }
        }
        
        int maxSum = Arrays.stream(d[triangle.length-1]).max().getAsInt();
        
        return maxSum;
    }
}
