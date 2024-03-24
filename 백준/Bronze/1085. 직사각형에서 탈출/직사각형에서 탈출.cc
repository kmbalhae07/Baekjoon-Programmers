#include <cstdio>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

int x, y, w, h;
int x_dist[2];
int y_dist[2];
int main()
{
    scanf("%d %d %d %d", &x, &y, &w, &h);
    x_dist[0] = x;      x_dist[1] = w - x; 
    y_dist[0] = y;      y_dist[1] = h - y;  
    printf("%d", (min(min(x_dist[0], x_dist[1]), min(y_dist[0], y_dist[1]))));
}