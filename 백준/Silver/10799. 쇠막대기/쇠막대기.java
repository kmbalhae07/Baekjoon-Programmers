import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        
        Stack<Character> stack = new Stack<>();
        int totalPieces = 0;  

        for (int i = 0; i < input.length(); i++) {
            char current = input.charAt(i);

            if (current == '(') {
                stack.push(current);  
            } else {
                stack.pop();  // 쇠막대기의 끝 또는 레이저의 끝이므로 스택에서 팝
                
                // 레이저인 경우
                if (input.charAt(i - 1) == '(') {
                    totalPieces += stack.size();  // 스택의 크기만큼 조각 추가
                } else {
                    // 쇠막대기의 끝인 경우
                    totalPieces += 1;  // 하나의 조각이 추가됨
                }
            }
        }

        System.out.println(totalPieces);
    }
}
