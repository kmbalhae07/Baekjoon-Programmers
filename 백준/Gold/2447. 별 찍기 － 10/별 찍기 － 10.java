import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static char[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        // N x N 크기의 2차원 배열 초기화
        map = new char[N][N];
        
        // 재귀 함수 호출하여 별 채우기
        fillPattern(0, 0, N, false);
        
        // 결과 출력
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(map[i][j]);
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }

    // 재귀적으로 별 채우는 함수
    static void fillPattern(int x, int y, int size, boolean blank) {
        // 공백인 경우
        if (blank) {
            for (int i = x; i < x + size; i++) {
                for (int j = y; j < y + size; j++) {
                    map[i][j] = ' ';
                }
            }
            return;
        }

        // size가 1인 경우 별 하나 채우기
        if (size == 1) {
            map[x][y] = '*';
            return;
        }

        int newSize = size / 3; // 새로운 블록 크기
        int count = 0; // 블록 카운트

        for (int i = x; i < x + size; i += newSize) {
            for (int j = y; j < y + size; j += newSize) {
                count++;
                // 5번째 블록 (가운데 블록)은 공백 처리
                fillPattern(i, j, newSize, count == 5);
            }
        }
    }
}
