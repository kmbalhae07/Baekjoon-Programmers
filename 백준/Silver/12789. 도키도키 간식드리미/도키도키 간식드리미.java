import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();
        int lineNum = 1; // 입장해야 하는 순서
        boolean isBoolean = true;
        
        int N = sc.nextInt();
        for(int i = 0; i < N; i++) {
            int student = sc.nextInt();

            // 줄서있는 곳에서 들어갈 타이밍일 때
            if(student == lineNum) {
                lineNum++;

                // 한명씩 설 수 있는 공간에서 들어갈 타이밍일 때
                while(!stack.isEmpty() && isBoolean) {
                    if(stack.peek() == lineNum) {
                        stack.pop();
                        lineNum++;
                    } else {
                        isBoolean = false;
                    }
                }
            } else {
                stack.push(student);
            }

            isBoolean = true;
        }

        if(stack.isEmpty()) {
            System.out.println("Nice");
        } else {
            System.out.println("Sad");
        }
    }
}
