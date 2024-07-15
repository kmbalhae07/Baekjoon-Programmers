class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2]; // 배열 크기 초기화
        
        // 노란색 가로:x 세로:y -> x*y = yellow 
        int x = 1;
        int y = 1;
        
        while (true) {
            for (y = 1; y <= x; y++) {
                if (x * y == yellow) {
                    if ((x + y + 2) == (brown / 2)) {
                        answer[0] = x + 2;
                        answer[1] = y + 2;
                        return answer;
                    }
                }
            }
            x++;
        }
    }
}
