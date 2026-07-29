/*
[주식가격]
- date: 2026-07-19
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42584
*/

/*
10^5
처음에는 가격이 다시 복구되면 그 기간은 빼줘야 하는 줄 알고, 이게 n^2 말고 구현이 되나? 싶었는데, 알고보니까 한번 떨어지면 그 이후에 다시 올라도 신경 안 쓰는 거였음.

문제 왤케 헷갈리냐
*/
import java.util.*;
class Solution {
    public record Stock(int price, int time){}
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        ArrayDeque<Stock> q = new ArrayDeque<>();

        for(int i = 0; i < prices.length ; i++){
            while(!q.isEmpty() && prices[i] < q.peek().price()){
                Stock s = q.poll();
                answer[s.time()] = i - s.time();
            }
            q.push(new Stock(prices[i],i));
        }
        
        while(!q.isEmpty()){
            Stock s = q.poll();
            answer[s.time()] = (prices.length - 1 ) - s.time();
        }
        
        return answer;
    }
}
