import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int time = 0; 
        int totalWeight = 0; 
        
        Queue<Integer> bridge = new LinkedList<>(); 
        
        // 다리 공간 다 0으로 설정
        for(int i = 0; i < bridge_length; i++){
            bridge.offer(0);
        }
        
        //다리 길이 1 or 트럭 개수 1개 -> 바로 return
        if(bridge_length == 1) { 
            return truck_weights.length+1;
        }
        if(truck_weights.length == 1) {
            return bridge_length+1;
        }
        
        int index = 0; 
        while (index < truck_weights.length) {
            totalWeight -= bridge.poll();
            time++;
            
            // 대기 트럭이 다리에 갈 수 있는지
            if (totalWeight + truck_weights[index] <= weight) {
                // 올라간 경우
                bridge.add(truck_weights[index]);
                totalWeight += truck_weights[index];
                index++;
            } else {
                bridge.offer(0);
            }
        }
        answer = time + bridge_length;
        return answer;
    }
}
