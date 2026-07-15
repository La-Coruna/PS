/* 
[최소직사각형]
- date: 26.07.15
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42840
*/
class Solution {
    public int solution(int[][] sizes) {
        int max_longSide = 0, max_shortSide = 0;   
        
        for(int[] size : sizes){
            int cur_longSide = Math.max(size[0],size[1]);
            int cur_shortSide = Math.min(size[0],size[1]);
            
            max_longSide = Math.max(max_longSide, cur_longSide);
            max_shortSide = Math.max(max_shortSide, cur_shortSide);
        }

        return max_longSide*max_shortSide;
    }
}