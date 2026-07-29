/*
[N으로 표현]
- date: 2026-07-20
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42895
*/

/*
32000 = 3*10^4

s[i] : i개 써서 만들 수 있는 숫자들
*/
import java.util.*;
class Solution {
    public int solution(int N, int number) {
        Set<Integer>[] s = new HashSet[9];
        for(int i = 1; i <= 8; i++){
            s[i] = new HashSet<>();
        }
        
        // 초기값 설정
        s[1].add(N);
        s[2].add(N+N);
        s[2].add(N*N);
        s[2].add(N/N);
        s[2].add(N*11);
        
        // 초기 탈출
        if(N == number) return 1;
        if(s[2].contains(number)) return 2;
        
        int one = 11;
        for(int i = 3; i <= 8; i++){
            one = one*10+1;
            s[i].add(N*one);
            
            for(int j = 1; j <= i/2; j++){
                // s[j]와 s[i-j]에 있는 원소들로 사칙연산
                for(int a : s[j]){
                    for(int b : s[i-j]){
                        int[] result = {a+b, Math.abs(a-b), a*b, (a>=b) ? a/b : b/a};
                        for(int r: result){
                            if(r <= 0) continue;
                            boolean isExisted = false;
                            for(int k = 1; k < i; k++){
                                if(s[k].contains(r)){
                                    isExisted = true;
                                    break;
                                }
                            }
                            if(!isExisted) s[i].add(r);
                        }
                        
                    }
                }
            }
            if(s[i].contains(number)) return i;
        }
        
        return -1;
    }
}
