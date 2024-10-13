import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // N: 이미 가지고 있는 랜선의 개수, K: 만들어야 할 랜선의 개수
        int K = sc.nextInt();
        int N = sc.nextInt();
        
        // 랜선 길이 배열 선언
        int[] lanCables = new int[K];
        long maxLen = 0;

        // 랜선 길이 입력 및 가장 긴 랜선 길이 저장
        for (int i = 0; i < K; i++) {
            lanCables[i] = sc.nextInt();
            if (lanCables[i] > maxLen) {
                maxLen = lanCables[i];
            }
        }

        // 이분 탐색 범위 설정
        long left = 1;  // 랜선 길이는 최소 1
        long right = maxLen;  // 가장 긴 랜선의 길이까지 가능
        long result = 0;  // 최종 답

        // 이분 탐색 시작
        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;

            // 각 랜선을 mid 길이로 잘라서 몇 개의 랜선을 만들 수 있는지 계산
            for (int i = 0; i < K; i++) {
                count += lanCables[i] / mid;
            }

            // 만든 랜선의 개수가 N개 이상이면 더 긴 길이에서 시도
            if (count >= N) {
                result = mid;  // 가능한 길이 저장
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // 결과 출력
        System.out.println(result);
    }
}
