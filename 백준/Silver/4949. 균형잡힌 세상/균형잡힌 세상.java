import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (true) {
            String input = sc.nextLine();
            
            // 입력이 "." 이면 반복 종료
            if (input.equals(".")) {
                break;
            }

            Stack<Character> stack = new Stack<>();
            boolean isValid = true;
            
            for(int i=0; i<input.length(); i++) {
                char ch = input.charAt(i);

                //[ 혹은 ( 일 경우 push
                if(ch == '[' || ch == '(') {
                    stack.push(ch);
                // ]인 경우
                } else if(ch == ']') {
                    if(!stack.isEmpty() && stack.peek() == '[') {
                        stack.pop();
                    } else {
                        isValid = false;
                        break;
                    }
                // ) 인 경우
                } else if(ch == ')') {
                    if(!stack.isEmpty() && stack.peek() == '(') {
                        stack.pop();
                    } else {
                        isValid = false;
                        break;
                    }
                }
            }

            if(stack.isEmpty() && isValid) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
