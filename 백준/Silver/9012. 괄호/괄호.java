import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine(); // 버퍼를 비우기 위해 필요

        for(int i = 0; i < T; i++) {
            Stack<Character> stack = new Stack<>(); 
            String input = sc.nextLine();
            boolean isValid = true; 

            for(int k = 0; k < input.length(); k++) {
                char ch = input.charAt(k); 

                if(ch == '(') {
                    stack.push(ch);
                } else if(ch == ')') {
                    if(stack.isEmpty()) {
                        isValid = false;
                        break;
                    } else {
                        stack.pop();
                    }
                }
            }

            if(isValid && stack.isEmpty()) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
