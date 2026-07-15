/*
[모의고사]
- date: 26.07.15
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42840
*/
import java.util.*;
import java.util.stream.IntStream;

class Solution {
    private static final int[][] rules = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    public int[] solution(int[] answers) {
        int scores[] = {0,0,0};
        for(int i = 0; i < answers.length; i++){
            for(int j = 0; j < 3; j++){
                if(rules[j][i % rules[j].length] == answers[i]) scores[j]++;
            }
        }

        int max_score = Arrays.stream(scores).max().orElse(0);
                
        int[] winners = IntStream.range(0,3).filter(i -> scores[i] == max_score).map(i -> i+1).toArray();
        
        return winners;
    }
}