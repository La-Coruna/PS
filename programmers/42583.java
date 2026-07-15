/*
[다리를 지나는 트럭]
- date: 2026-07-15
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42583
*/

import java.util.*;

class Solution {
    public record Truck(int weight, int exit_time){}
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Deque<Truck> q = new ArrayDeque<>();
        int cur_time = 0;
        int cur_total_weight = 0;
        
        // truck 입장
        for(int truck_weight : truck_weights){
            // 시간 흐름
            cur_time++;

            // 새로 트럭이 못들어 오는 경우
            while(cur_total_weight + truck_weight > weight){
                Truck front_truck = q.poll();
                
                // 가장 먼저 들어간 차량이 나오기 위해서 얼마나 시간이 더 걸리는지 계산
                int remain_time = front_truck.exit_time() - cur_time;
                
                // 바로 나올 수 없으면, 그만큼 시간 이동
                if(remain_time > 0) cur_time += remain_time;
                
                // 트럭 다리 건넘
                cur_total_weight -= front_truck.weight();
            }
            
            // 새 트럭 들어옴
            q.offer(new Truck(truck_weight,cur_time+bridge_length));
            cur_total_weight += truck_weight;
        }
        
        // 다리에 남아 있는 트럭 전부 빼기
        int answer = q.getLast().exit_time();
        
        return answer;
    }
}
