/*
[연속 부분 수열 합의 개수]
- date: 2026-07-24
- url: https://school.programmers.co.kr/learn/courses/30/lessons/131701
*/

/*
dp[i] : 크기가 i인 부분수열의 합

반복횟수 10^3 * 10^3 = 10^6
숫자크기 확인 : 10^3 * 10^3 < int 범위
*/
import java.util.*;
class Solution {
    public int solution(int[] elements) {
        int n = elements.length;
        Set<Integer> set = new HashSet<>();
        int dp[] = new int[n+1];
        
        // 0번째 원소를 기준으로 모든 크기의 부분수열의 합을 구함
        dp[1] = elements[0];
        set.add(dp[1]);
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + elements[i-1];
            set.add(dp[i]);
        }
        
        // 기준 원소를 0번째에서 n-1번째까지 돌림 (i: 기준원소)
        for(int i = 1; i < n; i++){
            // 모든 크기의 부분 수열을 다 함 (j: 크기)
            for(int j = 1; j <= n; j++){
                dp[j] -= elements[i-1]; // 기존 기준 원소 제거
                dp[j] += elements[(i+j-1)%n]; // 다음 원소의 위치는 현재 크기 다음 원소
                set.add(dp[j]);
            }
        }
        
        return set.size();
    }
}
