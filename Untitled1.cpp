#include<iostream>		
#include<bits/stdc++.h>
using namespace std;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int firstRow = 0 , lastRow = matrix.size() - 1;
        while(firstRow < lastRow){
            int leftCol = 0 , rightCol = matrix[0].size() - 1;
            int midRow = firstRow + (lastRow - firstRow) / 2;
        	cout << "outerloop  : row : " << firstRow << "  col : " << lastRow   << " mid : " << midRow <<  endl;
            while(leftCol <  rightCol){
                int midCol = leftCol + (rightCol - leftCol) / 2;
                cout << "innerloop  : row : " << leftCol << "  col : " << rightCol << " mid : " << midCol <<  endl;
                if(matrix[midRow][midCol] == target)
                    return true;
                else if(matrix[midRow][midCol] < target )
                    leftCol = midCol + 1;
                else 
                    rightCol = midCol - 1;
            }
            if(matrix[midRow][0] > target){
                lastRow = midRow - 1;
            }
            else
                firstRow = midRow + 1;
        }
        return false;
    }
int main(){
	int i = -1;
	vector<vector<int>> arr = {
								{1,3,5,7},
								{10,11,16,20},
								{23,30,34,60},
							   };
	
	cout << endl << searchMatrix(arr,3);
}


