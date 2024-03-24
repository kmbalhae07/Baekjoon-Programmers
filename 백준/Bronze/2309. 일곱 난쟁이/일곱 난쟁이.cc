#include <stdio.h>

void findNanZang(int height[]) {
  int temp, k;
  int num = 9;

  //버블정렬로 오름차순 정렬
  for(k = num-1; k>0; k--) {
    for(int i=0; i<k; i++) {
      if(height[i] > height[i+1]) {
        temp = height[i];
        height[i] = height[i+1];
        height[i+1] = temp;
      }
    } 
  }

  // 아홉 난쟁이들 키 합 구하기
  int sum = 0;
  for(int h=0; h<num; h++) {
    sum += height[h];
  }
  int different = sum - 100;
  
  // 조건에 맞는 두 난쟁이 빼기
  int found = 0; 
  for(int p=0; p<num-1; p++) {
    for(int j=p+1; j<num; j++) { 
      if(height[p] + height[j] == different) {
        found = 1; 
        for(int w = j; w < num - 1; w++) {
          height[w] = height[w + 1];
        }
        for(int w = p; w < num - 2; w++) {
          height[w] = height[w + 1];
        }
        num -= 2; 
        break;
      }
    } 
    if (found) {
      break;
    }
  }

  for(int i=0; i<7; i++) {
    printf("%d\n", height[i]);    
  }
}

int main(void) {
  int height[10];
  int input;
  
  for(int i=0; i<9; i++) {
    scanf("%d", &input);
    height[i] = input;
  }

  findNanZang(height);
  
  return 0;
}
