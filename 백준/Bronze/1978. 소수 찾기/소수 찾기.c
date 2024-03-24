#include <stdio.h>

void primeNum(int list[], int N) {
  int num = 0;
  
  for(int i = 0; i < N; i++) {
    int a = 0;
    int k = 2;

    if(list[i] == 1) {
      continue;
    } else {
      while(k < list[i]) {
        if(list[i] % k == 0) {
          a++;
          break;
        }
        k++;
      }
      if(a == 0) {
      num++;
      } 
    }
  }
  
  printf("%d", num);
}

int main() {
  int N, i;
  scanf("%d", &N);

  int list[N];
  for(i = 0; i < N; i++) {
    scanf("%d", &list[i]);
  }

  primeNum(list, N);
  
  return 0;
 }