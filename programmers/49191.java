/*
[순위]
- date: 2026-07-20
- url: https://school.programmers.co.kr/learn/courses/30/lessons/49191
*/

/*
위상정렬하면서 순서가 안바뀌는 것들의 개수
A -> B : A가 B를 이김

내가 이기는 사람 + 내가 지는 사람 = 전체수 - 나 면 순위 확실.
즉 재귀적인 win[i] + lose[i] == n-1 이면 내 순위 확실.

처음에는 위상정렬로 순서 정한다음에, 위처럼 승리랑 패배 개수 비교 하면 될 줄 알았는데, 그러기 힘들 듯.
결국 내가 다른 선수들이랑의 순위 관계를 아는지 중요해서, 단순히 승리 패배 수가 아니라 누구한테 이겼고 졌는지도 저장해야 할 것 같은데, 그럼 set으로 가야하나..?
*/
import java.util.*;
import java.util.stream.*;
class Solution {
    public int solution(int n, int[][] results) {
        int[] indegree = new int[n+1], outdegree = new int[n+1];
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        ArrayList<Integer>[] adj2 = new ArrayList[n+1];
        Set<Integer>[] win = new Set[n+1], lose = new Set[n+1];
        for(int i = 1; i <= n; i++){
            adj[i] = new ArrayList<>();
            adj2[i] = new ArrayList<>();
            win[i] = new HashSet<>();
            lose[i] = new HashSet<>();
        }
        ArrayDeque<Integer> q = new ArrayDeque<>();
        boolean[] vis = new boolean[n+1];    
        
        
        for(int[] result: results){
            int A = result[0];
            int B = result[1];
            indegree[B]++;
            outdegree[A]++;
            adj[A].add(B);
            adj2[B].add(A);
        }
        
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0) q.offer(i);
        }
        
        // lose 갱신
        while(!q.isEmpty()){
            int cur = q.poll();
            for(int nxt: adj[cur]){
                for(int k: lose[cur]){
                    lose[nxt].add(k);
                }
                lose[nxt].add(cur);
                if(--indegree[nxt] == 0) q.offer(nxt);
            }
        }
        
        
        for(int i = 1; i <= n; i++){
            if(outdegree[i] == 0) q.offer(i);
        }
        
        while(!q.isEmpty()){
            int cur = q.poll();
            for(int nxt: adj2[cur]){
                for(int k: win[cur]){
                    win[nxt].add(k);
                }
                win[nxt].add(cur);
                if(--outdegree[nxt] == 0) q.offer(nxt);
            }
        }
        
        int answer = 0;
        for(int i = 1; i <= n; i++){
            if(win[i].size() + lose[i].size() == n-1) answer++;
        }
        
        return answer;
    }
}
