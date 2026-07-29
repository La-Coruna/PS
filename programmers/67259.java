/*
[경주로 건설]
- date: 2026-07-25
- url: https://school.programmers.co.kr/learn/courses/30/lessons/67259
*/

/*
이게 멀리 돌아가더라도 비용이 적을 수가 있음.
즉 bfs로 가장 적은 거리를 간 게 최소 비용이 아님.
비용이 음수가 아니고, 엣지마다 다르니까 다익스트라가 잘 어울림.
다만 이전 방향을 고려해야 함.
*/
import java.util.*;
class Solution {
    public static final int MAX_COST = 600*30*30;
    // 이론상 25칸이 600원으로 다 찬게 최대값이겠지.
    
    public int[] dx = {1,0,-1,0};
    public int[] dy = {0,1,0,-1};
    
    public record State(int x, int y, int dir, int dist){}
    
    public int solution(int[][] board) {
        int n = board.length;
        int[][][] distance = new int[n][n][4];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                Arrays.fill(distance[i][j], MAX_COST);
            }
        }
        PriorityQueue<State> pq = new PriorityQueue<>(
            Comparator.comparing(State::dist)
        );
        
        // 초기값
        Arrays.fill(distance[0][0], 0);
        
        // 처음에 벽인지 확인해야 함
        if(board[1][0] == 0) distance[1][0][0] = 100;
        if(board[0][1] == 0) distance[0][1][1] = 100;
        
        // pq에 초기 원소 삽입
        pq.offer(new State(1,0,0,distance[1][0][0]));
        pq.offer(new State(0,1,1,distance[0][1][1]));
        
        while(!pq.isEmpty()){
            State curState = pq.poll();
            int curX = curState.x();
            int curY = curState.y();
            int curDir = curState.dir();
            int curDist = curState.dist();
            
            // old value면 pass
            if(distance[curX][curY][curDir] < curDist) continue;
            for(int k = 0; k < 4; k++){
                // 후진은 제외
                if((k+2)%4 == curDir) continue;
                
                int nx = curX + dx[k];
                int ny = curY + dy[k];
                // 범위 밖이거나 벽이면 패스
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1) continue;
                
                int nDist = curDist + ((k == curDir) ? 100 : 600);
                // 갱신할 대상이 아니면 pass
                if(distance[nx][ny][k] < nDist) continue;
                
                // 갱신 + pq에 추가
                distance[nx][ny][k] = nDist;
                pq.offer(new State(nx,ny,k, nDist));
            }
        }
       
        int answer = Arrays.stream(distance[n-1][n-1]).min().orElse(-1);
        return answer;
    }
}
