import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        // 1. 숫자별 개수 세기
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int t : tangerine) {
            countMap.put(t, countMap.getOrDefault(t, 0) + 1);
        }
        
        // 2. 개수로 정렬
        List<Integer> counts = new ArrayList<>(countMap.values());
        counts.sort(Comparator.reverseOrder());
        
        // 3. 최대 개수부터 k를 만족할 때까지 추가
        for (int count : counts) {
            k -= count;
            answer++;
            if (k <= 0) break;
        }
        
        return answer;
    }
}
