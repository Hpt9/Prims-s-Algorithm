#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int mat[4][4] = {
  {0,2,1,5},
  {2,0,0,3},
  {1,0,0,4},
  {5,3,4,0}};  
  int e,v_array[4];
  memset(v_array, false, sizeof(v_array));
  e = 0;
  v_array[0] = true;
  int x,y;
  while (e < 3)/* vertices-1=3*/{
    int min = 9999999 /*represents infinity*/;
    x = 0,y = 0;
    for (int i = 0; i < 4; i++) {
      if (v_array[i]) {
        for (int j = 0; j < 4; j++) {
          if (!v_array[j] && mat[i][j]) {
            if (min > mat[i][j]) {
              min = mat[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << "-" << y << ": Weight is " << mat[x][y]<<'\n';
    v_array[y] = true;
    e++;
  }
  return 0;
}