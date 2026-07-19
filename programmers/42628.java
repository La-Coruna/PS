/*
[이중우선순위큐]
- date: 2026-07-18
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42628
*/

/*
10^6

힙 : 삽입 logN, 한쪽 끝 삭제 logN
레드블랙트리 : 삽입 logN, 양쪽 끝 삭제 logN

원래 TreeSet으로 구현했지만, 중복처리를 위해서 TreeMap으로 변경
*/
import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for(String operation : operations){
            String[] tokens = operation.split(" ");
                
            if(tokens[0].equals("I")){
                int num = Integer.parseInt(tokens[1]);                
                map.put(num, map.getOrDefault(num,0)+1);
            } else{
                if(tokens[1].equals("1")){
                    if(map.isEmpty()) continue;
                    else {
                        Map.Entry<Integer,Integer> last = map.lastEntry();
                        if(last.getValue()==1) map.pollLastEntry();
                        else map.put(last.getKey(), last.getValue()-1);
                    }
                }else{
                    if(map.isEmpty()) continue;
                    else {
                        Map.Entry<Integer,Integer> first = map.firstEntry();
                        if(first.getValue()==1) map.pollFirstEntry();
                        else map.put(first.getKey(), first.getValue()-1);
                    }
                }
            }
        }
        
        return (map.isEmpty()) ? new int[]{0,0} : new int[]{map.lastEntry().getKey(),map.firstEntry().getKey()};
    }
}
