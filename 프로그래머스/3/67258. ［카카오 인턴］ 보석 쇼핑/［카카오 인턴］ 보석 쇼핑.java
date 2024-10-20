import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2]; // 결과를 담을 배열
        
        // 1. 보석의 전체 종류 수 구하는 HashSet
        HashSet<String> gemTypes = new HashSet<>();
        for (String gem : gems) {
            gemTypes.add(gem);
        }
        int totalTypes = gemTypes.size();  // 보석의 전체 종류 수
        
        // 구간 내의 보석 종류와 개수를 저장할 HashMap
        HashMap<String, Integer> gemMap = new HashMap<>();
        
        int start = 0, end = 0, cnt = 0; 
        int minLength = 1000001; // gems 배열이 최대 100,000임

        while (end < gems.length) {
            // 보석 추가
            String gem = gems[end];
            if (gemMap.containsKey(gem)) {
                gemMap.put(gem, gemMap.get(gem) + 1);
            } else {
                gemMap.put(gem, 1);
                cnt++;  // 새로운 보석 종류가 추가됨
            }
            end++;

            // 모든 보석 종류가 포함된 경우
            while (cnt == totalTypes) {
                // 현재 구간의 길이가 더 작으면 업데이트
                if (end - start < minLength) {
                    minLength = end - start;
                    answer[0] = start + 1;  // 1-based 인덱스
                    answer[1] = end;        // 1-based 인덱스
                }

                // 구간의 시작 부분 보석을 제거
                String startGem = gems[start];
                gemMap.put(startGem, gemMap.get(startGem) - 1);
                if (gemMap.get(startGem) == 0) {
                    gemMap.remove(startGem);
                    cnt--;  // 보석 종류가 줄어듦
                }
                start++;
            }
        }

        return answer;
    }
}
