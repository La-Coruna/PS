/*
[할인 행사]
- date: 2026-07-24
- url: https://school.programmers.co.kr/learn/courses/30/lessons/131127
*/

/*
discount의 길이: 10^5
want: 10

10^5길이의 배열을 탐색하며, HashMap을 갱신하고, 총 10개의 조건 판별
-> 10^6 -> 1초안에 통과
*/
import java.util.*;
class Solution {
    public boolean canRegister(Map<String, Integer> map, String[] want, int[] number){
        for(int i = 0; i < want.length; i++){
            if (map.getOrDefault(want[i],0) < number[i]) return false;
        }
        return true;
    }
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        Map<String, Integer> map = new HashMap<>();
        
        // 첫 10일동안
        for(int i = 0; i < 10; i++){
            String item = discount[i];
            map.put(item, map.getOrDefault(item,0)+1);
            
            if(canRegister(map, want, number)) answer++;
        }

        // 이후
        for(int i = 10; i < discount.length; i++){
            String prev_item = discount[i-10];
            map.put(prev_item, map.getOrDefault(prev_item,0)-1);
            
            String new_item = discount[i];
            map.put(new_item, map.getOrDefault(new_item,0)+1);
            
            if(canRegister(map, want, number)) answer++;
        }
        
        return answer;
    }
}
