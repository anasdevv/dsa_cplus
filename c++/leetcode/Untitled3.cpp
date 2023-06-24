#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[6][6] = {
				{-9 ,-9, -9,  1, 1, 1 },
 				{0 ,-9  ,0  ,4 ,3 ,2},
				{-9 ,-9, -9,  1, 2, 3},
				{0 , 0  ,8  ,6 ,6 ,0},
				{0  ,0  ,0 ,-2 ,0 ,0},
				{0 , 0 , 1,  2, 4, 0},
				};
int sum(int stx , int sty){
    return arr[stx][sty] + arr[stx][sty+1] + arr[stx][sty+2] + arr[stx+1][sty+1] + arr[stx+2][sty] + arr[stx+2][sty+1] + arr[stx+2][sty+2];
    
}
int main() {
    int ans = -100;
   /* for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            cin >> arr[i][j];
        }
    }
    */
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            ans = max(ans , sum(i,j));
        }
    }
    
    cout << ans << endl;
    return 0;
}

