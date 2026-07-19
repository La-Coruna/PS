/*
[카펫]
- date: 2026-07-17
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42842
*/

/*
단순한 이차 연립 방정식
2(w+h) - 4 = brown 개수
(w-2)*(h-2) = yellow 개수

h = brown/2 + 2 - w;
(w-2)*(brown/2 - w) = yellow;

3 <= 카펫 한쪽 변의 길이 <= (5000-2)/2 = 2499
* 가로가 더 길다. ( w >= h )
w >= brown/4 + 1
brown/4 + 1 <= w <= brown/2 - 1
*/

class Solution {
    // w가 커질수록 전체 넓이가 줄어 들음.
    // w가 작을 수록 (w-2)*(brown/2 - w) - yellow 가 양수
    private boolean func(int w, int brown, int yellow){
        return (w-2)*(brown/2 - w) - yellow > 0;
    }
    public int[] solution(int brown, int yellow) {
        int s = brown/4 + 1;
        if((brown%4)>0) s += 1;
        int e = brown/2 - 1;
        
        while(s<e){
            int mid = (s+e)/2;
            // w를 더 키워
            if(func(mid, brown, yellow)){
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        
        return new int[]{e, brown/2 + 2 - e};
    }
}
