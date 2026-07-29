/*
[선인장 숨기기]
- date: 2026-07-24
- url: https://school.programmers.co.kr/learn/courses/30/lessons/468379
*/

/*
m개의 행, n개의 열
(0,0) - (m-1,n-1)

<처음 생각한 방식>
(i,j)에 비오면, 아래 칸에 선인장 맨 왼위칸이 있을 때, 비를 맞게 됨.
(i-h+1, j-w+1)  (i-h+1, j)
(i, j-w+1)      (i,j)

여기를 비의 역순으로 채워서 가장 비를 늦게 맞는 구역을 찾아보자.
-> 그러면 시간복잡도가 O(m*n*drops.length)인데, 이러면 O((m*n)^2)임.
m*n이 5*10^5이라 이 방법은 시간이 빡셈.

<모노토닉 덱>
이차원 배열의 정해진 구간 내에서 최소값을 찾음. 그리고 그 최소값이 최대가 되는 구간을 찾음.

1. 각 행마다 w길이의 구간에서의 최소 값을 구해 저장해둠. -> 모노토닉 덱으로 구현 시, 각 행마다 O(n)으로 구현 가능 -> 모든 행을 고려하면 O(mn)
2. 각 (i,j)를 기준으로 w*h 영역을 잡았을 때의 최소 값을 구함. 1번 단계에서 구한 값들을 이용해서 구하면 각 열마다 O(m)로 가능 -> 모든 행을 고려하면 O(mn)
3. 그리고 그 중에서 제일 높은 값 구함. -> O(mn)

최종 시간 복잡도 -> O(mn)
*/
import java.util.*;
class Solution {
    public int[] solution(int m, int n, int h, int w, int[][] drops) {
        // board 초기화
        int board[][] = new int [m][n];
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                board[i][j] = drops.length+1;
            }
        }
        int drop_cnt = 1;
        for(int[] drop: drops){
            board[drop[0]][drop[1]] = drop_cnt++;
        }
        
        int min_time_in_w[][] = new int[m][n-w+1];
        int min_time[][] = new int[m-h+1][n-w+1];

        // 각 행마다 w구간 만큼에서의 최소 값을 구함
        for(int row = 0; row < m ; row++){
            int[] cur_row = board[row];
            
            ArrayDeque<Integer> deque = new ArrayDeque<>();
            
            for(int i = 0; i < n; i++){
                // 현재 벗어난 구간 제거
                // i = w 일 때, 0번째 인덱스 제거 -> i - w + 1 보다 작은 인덱스 제거
                while(!deque.isEmpty() && deque.peekFirst() < i - w + 1 ){
                    deque.pollFirst();
                }

                // 뒤에 넣기 전에, 지금 값보다 더 큰 값들이 있으면 제거.
                // 어차피 구간 내 최소값을 볼 것이기 때문에, 나보다 앞의 더 큰 값은 볼 필요 없음.
                while(!deque.isEmpty() && cur_row[deque.peekLast()] > cur_row[i]){
                    deque.pollLast();
                }
                // 뒤에 현재 값 삽입
                deque.offerLast(i);
            
                // 현재 구간까지의 최소값을 기록
                // i = w-1 -> 0 ~ w-1 | i = w -> 1 ~ w
                // 기준은 w구간의 맨 앞이기 때문에 i-w+1
                if(i-w+1 >= 0) {
                    min_time_in_w[row][i-w+1] = cur_row[deque.peekFirst()];
                    //System.out.println(i-w+1 + ": " + cur_row[deque.peekFirst()]);            
                }
            }
        }

        // col은 min_time 배열을 갱신할 열
        for(int col = 0; col < min_time[0].length; col++){
            ArrayDeque<Integer> deque = new ArrayDeque<>();
            for(int row = 0; row < min_time_in_w.length; row++){
                // 구간의 시작은 'row = h-1 일 때 0'이므로 row - h + 1
                // 0보다 작을 수 있음을 주의
                int range_start = row - h + 1;
                
                // 구간을 벗어난 덱의 앞쪽 빼기
                while(!deque.isEmpty() && deque.peekFirst() < range_start){
                    deque.pollFirst();
                }
                    
                // 새로운 원소 삽입 전에, 덱안에 더 큰 값들 제거
                while(!deque.isEmpty() && min_time_in_w[row][col] < min_time_in_w[deque.peekLast()][col]){
                    deque.pollLast();
                }
                // 새로운 원소 삽입
                deque.offerLast(row);
                
                // min_time 갱신. 범위의 시작을 기준으로 갱신.
                if(range_start >= 0) min_time[range_start][col] = min_time_in_w[deque.peekFirst()][col];
            }
        }
        
        // 정답 구하기
        int x = 0, y = 0;
        for(int i = 0; i < min_time.length; i++){
            for(int j = 0; j < min_time[0].length; j++){
                if(min_time[i][j] > min_time[x][y]) {
                    x = i; y = j;
                }
            }
        }
        
        return new int[]{x,y};
    }
}
