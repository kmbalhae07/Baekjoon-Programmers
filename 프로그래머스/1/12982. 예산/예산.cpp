#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end(), compare);
    
    for(int i=0; i<d.size(); i++) {
       if(budget >= d[i]) {
           budget -= d[i];
           answer++;
       }
    }
    return answer;
}