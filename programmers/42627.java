/*
[디스크 컨트롤러]
- date: 2026-07-21
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42627
*/

/*
작업의 번호
작업의 요청 시각
작업의 소요 시간

소요 시간 짧은 것, 요청 시각이 빠른 것, 작업 번호가 작은 것
*/
import java.util.*;
class Solution {
    public record Task(int number, int request, int duration){}
    
    public int solution(int[][] jobs) {
        ArrayList<Task> tasks = new ArrayList<>();
        for(int i = 0; i < jobs.length; i++){
            tasks.add(new Task(i,jobs[i][0],jobs[i][1]));
        }
        tasks.sort(Comparator.comparingInt(Task::request));
        
        PriorityQueue<Task> pq = new PriorityQueue<>(
            Comparator.comparingInt(Task::duration)
                      .thenComparingInt(Task::request)
                      .thenComparingInt(Task::number)
        );
        
        int cur_time = 0, task_request_cnt = 0, total_turnaround_time = 0, task_clear_cnt = 0;
        while(task_clear_cnt < tasks.size()){
            // 들어와있는 요청도 없고, 다음 요청까지 시간이 붕 뜨면, 시간을 당김
            if(pq.isEmpty() && cur_time < tasks.get(task_request_cnt).request())
                cur_time = tasks.get(task_request_cnt).request();
            
            // 지금 시간이 되기전에 들어온 요청이 있으면 모두 받기
            while(task_request_cnt < tasks.size() && cur_time >= tasks.get(task_request_cnt).request()){
                pq.offer(tasks.get(task_request_cnt));
                task_request_cnt++;
            }
            
            // 대기중인 작업 처리하고 시간 당기기
            if(!pq.isEmpty()){
                Task cur_task = pq.poll();
                cur_time += cur_task.duration(); // 작업을 처리하고 시간을 그만큼 당김
                total_turnaround_time += cur_time - cur_task.request(); // 반환시간 추가
                task_clear_cnt++; // 완료 횟수                
            }
        }
        
        return total_turnaround_time / task_clear_cnt;
    }
}
