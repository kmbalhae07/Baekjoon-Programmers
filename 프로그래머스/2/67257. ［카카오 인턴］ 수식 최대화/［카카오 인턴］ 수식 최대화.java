import java.util.ArrayList;
import java.util.List;

public class Solution {
    private static final String[] OPERATORS = {"+", "-", "*"};
    private static long maxResult = 0;

    public long solution(String expression) {
        // 1. 연산자 우선순위 순열 생성 및 결과 초기화
        List<String> priorities = new ArrayList<>();
        permute(new boolean[3], new StringBuilder(), priorities);

        // 2. 각 우선순위에 따른 계산 수행
        for (String priority : priorities) {
            maxResult = Math.max(maxResult, Math.abs(evaluate(expression, priority)));
        }

        return maxResult;
    }

    // 연산자 우선순위 순열 생성
    private void permute(boolean[] visited, StringBuilder sb, List<String> priorities) {
        if (sb.length() == 3) {
            priorities.add(sb.toString());
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sb.append(OPERATORS[i]);
                permute(visited, sb, priorities);
                sb.deleteCharAt(sb.length() - 1);
                visited[i] = false;
            }
        }
    }

    // 특정 우선순위로 표현식을 평가하는 메소드
    private long evaluate(String expression, String priority) {
        List<Long> numbers = new ArrayList<>();
        List<String> ops = new ArrayList<>();

        // 1. 숫자와 연산자를 분리하여 저장
        int idx = 0;
        for (int i = 0; i < expression.length(); i++) {
            if (expression.charAt(i) == '+' || expression.charAt(i) == '-' || expression.charAt(i) == '*') {
                numbers.add(Long.parseLong(expression.substring(idx, i)));
                ops.add(String.valueOf(expression.charAt(i)));
                idx = i + 1;
            }
        }
        numbers.add(Long.parseLong(expression.substring(idx)));

        // 2. 우선순위에 따른 계산
        for (char op : priority.toCharArray()) {
            for (int i = 0; i < ops.size(); i++) {
                if (ops.get(i).equals(String.valueOf(op))) {
                    long result = calculate(numbers.remove(i), numbers.remove(i), op);
                    numbers.add(i, result);
                    ops.remove(i);
                    i--; // 연산 후 리스트 크기 감소로 인한 인덱스 조정
                }
            }
        }
        return numbers.get(0);
    }

    // 주어진 연산자로 두 숫자를 계산하는 메소드
    private long calculate(long a, long b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
        }
        throw new IllegalArgumentException("Invalid operator: " + op);
    }
}
