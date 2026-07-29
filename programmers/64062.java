/*
[징검다리 건너기]
- date: 2026-07-24
- url: https://school.programmers.co.kr/learn/courses/30/lessons/64062
*/

/*
stones에서 가장 작은 값으로 전부 빼서 하나를 0으로 만들어.
그리고 건널 수 있는지 확인.
이걸 반복하면 2*10^5 * 2*10^5 안에는 답을 구할 수 있음. 그러나 그럼 시간초과

<깨달음을 얻기까지>
어떨 때부터 건널 수 없게 되지? -> 0이 된 돌이 k개가 연속으로 생기는 순간
각 돌이 몇 번째에 0이 되는지는 알 수 있음.

징검다리들을 길이가 k인 구간들에서 최대값을 구함.
그 최대값 중에 최소값인돌이 0이 되는 순간 건널 수 없는 구간이 생기는 거임.

5 3 3 3 5 k=3인 경우, 4번째부터는 못 건너게 됨.
*/
import java.util.*;
class Solution {
    public int solution(int[] stones, int k) {
        int[] max_values_in_k = new int[stones.length-(k-1)];
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        for(int i = 0; i < stones.length; i++){
            // 구간의 끝이 i일 때, 구간의 시작점은 i - k + 1 [i-k+1, i]
            // i가 k-1일 때, [0,k-1]
            // 0 보다 작을 경우를 주의!
            int range_start = i-k+1;
            
            // 구간을 벗어난 deque의 앞 부분 빼기
            while(!deque.isEmpty() && deque.peekFirst() < range_start){
                deque.pollFirst();
            }
            
            // 뒤에 새 원소 넣기 전에 현재 값보다 작은 값들은 다 빼기. (최대값만 필요하니까.)
            while(!deque.isEmpty() && stones[deque.peekLast()] < stones[i]){
                deque.pollLast();
            }
            deque.offerLast(i);
            
            // 구간 내 최대값 기록
            if(range_start >= 0) max_values_in_k[range_start] = stones[deque.peekFirst()];
        }
        
        return Arrays.stream(max_values_in_k).min().orElse(-1);
    }
}
