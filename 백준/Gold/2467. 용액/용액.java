import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // 용액의 개수 입력
        int n = scanner.nextInt();
        long[] solutions = new long[n]; // long 타입으로 변경
        
        // 용액 입력
        for (int i = 0; i < n; i++) {
            solutions[i] = scanner.nextLong(); // long으로 입력받기
        }
        
        // 용액을 정렬
        Arrays.sort(solutions);
        
        int left = 0;
        int right = n - 1;
        long minSum = Long.MAX_VALUE;  // 가장 가까운 합의 절댓값
        long[] result = new long[2]; // 결과를 저장할 배열

        // 투 포인터로 탐색
        while (left < right) {
            long sum = solutions[left] + solutions[right];

            // 합이 0에 가장 가까운 경우를 찾기
            if (Math.abs(sum) < Math.abs(minSum)) {
                minSum = sum;
                result[0] = solutions[left];
                result[1] = solutions[right];
            }

            // 합이 0보다 작으면 왼쪽 포인터를 증가
            if (sum < 0) {
                left++;
            } else { // 합이 0보다 크거나 같으면 오른쪽 포인터를 감소
                right--;
            }
        }

        // 결과 출력
        System.out.println(result[0] + " " + result[1]);
    }
}
