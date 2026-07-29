/*
[양과 늑대]
- date: 2026-07-25
- url: https://school.programmers.co.kr/learn/courses/30/lessons/92343
*/

/*
각 양 위치마다 몇개의 늑대를 먹게되는지 확인 -> 개수로 관리하면, 같은 늑대를 중복해서 먹을 수도 있음. -> 어떤 늑대를 먹게 되는지도 비트마스킹으로 관리..?

노드 개수는 최대 17개. (n=17)
-> 비트마스킹으로 표현하면 2^17이 되는데, int는 2^32까지 표현이 가능함.

모든 양들을 조사해서, 거치게 되는 늑대를 비트마스킹으로 표현. -> O(n+n-1) = O(n)
모든 양들을 돌아서 이 양을 모으러갈 수 있는지 판단 -> O(n^2)

- 비트마스킹에 늑대만 기록할 것인가, 양도 기록할 것인가.
- 양을 모으는 순서에 따라 최대 양 수가 달라지나?
    -> 그럴 것 같음. 양5 늑대2인 상황에서, 늑대 2마리 먹으면 1개 얻을 수 있는 선택지와
       늑대 2마리 먹으면 2게 얻을 수 있는 상황. 이때는 두 선택지 모두 할 수 없음.
- 결국 이것도 가능 모든 경우의 수를 고려해봐야 함.... 백트래킹..
    -> 그러면 백트래킹할 때의 상태 저장을 비트마스킹 해야 할 듯.
*/
import java.util.*;
class Solution {
    public void dfs(int cur, ArrayList<Integer>[] adj, int[] info, int[] wolfMask, ArrayList<Integer> sheeps){
        // 늑대면 비트마스킹 추가
        if(info[cur] == 1) wolfMask[cur] |= (1 << cur);
        
        // 양이면 양 그룹에 추가 (0노드의 양은 빼둘거임.)
        else if(cur != 0) sheeps.add(cur);

        for(int child: adj[cur]){
            // 자식한테 내 bitMask 물려줌.
            wolfMask[child] = wolfMask[cur];
            dfs(child, adj, info, wolfMask, sheeps);
        }
        return;
    }
    
    public int getWolfCnt(int wolfMask){
        return Integer.bitCount(wolfMask);
    }
    
    public int getWolfDiff(int curState, int wolfMask){
        return getWolfCnt(wolfMask & ~curState);
    }
    
    public int backtracking(int curState, int wolfCnt, int sheepCnt, int[] wolfMask, ArrayList<Integer> sheeps, Map<Integer, Integer> memo){
        // 이미 계산했던 경우면
        if(memo.containsKey(curState)){
            return memo.get(curState);
        }        
        
        int maxSheepCnt = sheepCnt;
        for(int sheep: sheeps){
            // 이미 모은 양이면 패스
            if((curState & (1 << sheep)) != 0) continue;
            
            // 이 양을 모을 수 있는지 확인
            int neededWolfCnt = getWolfDiff(curState,wolfMask[sheep]);
            
            if(sheepCnt > wolfCnt + neededWolfCnt){
                // 새로운 상태 갱신 (현재 상태 + 양 + 늑대)
                int nextState = curState | (1 << sheep) | wolfMask[sheep];
                
                // 그 진행했을 때의 최대 양 개수 갱신
                int maxNextCnt = backtracking(nextState, wolfCnt+neededWolfCnt, sheepCnt+1, wolfMask, sheeps, memo);

                maxSheepCnt = Math.max(maxSheepCnt, maxNextCnt);
            }
        }
        
        memo.put(curState, maxSheepCnt);
        return maxSheepCnt;
    }
    
    public int solution(int[] info, int[][] edges) {
        ArrayList<Integer>[] adj = new ArrayList[info.length];
        ArrayList<Integer> sheeps = new ArrayList<>();
        int[] wolfMask = new int[info.length];
        
        for(int i = 0; i < info.length; i++){
            adj[i] = new ArrayList<Integer>();
        }
        
        // adj 기록
        for(int[] edge : edges){
            adj[edge[0]].add(edge[1]);
        }
        
        // 비트마스킹
        dfs(0,adj,info,wolfMask,sheeps);
        
        // 양 모으기 시작
        Map<Integer, Integer> memo = new HashMap<>();
        int curState = 1;
        int answer = backtracking(curState, 0, 1, wolfMask, sheeps, memo);
        
        return answer;
    }
}
