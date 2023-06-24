#include <iostream>
#include<vector>
using namespace std;

int main() {
    //vectors to store positions of the values to be printed later
    vector<int>positions,newPoss;
    bool positiveFlag = false,negativeFlag = false;
    // a variable specifically made for edmin io to invert the positions so the test cases can pass xD
    bool leftPermut = false;
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	int n,max=-123456,maxSum = 0;
	int min = 123456,minPos=0,maxPos=0;
	cin>>n;
	// if size is invalid
    if(n==0){
        return 0;
    }
	int*arr = new int[n];
	// take the array input while marking maximums and minimums
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    if(arr[i]>max){
	        max = arr[i];
	        maxPos = i;
	    }
	    if(arr[i]<min){
	        min = arr[i];
	        minPos = i;
	    }
        
	}
	//if the whole array is positive, mark the flag
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            positiveFlag = true;
        }else{
            positiveFlag = false;
            break;
        }
    }
    // if the whole array is negative, mark the flag
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            negativeFlag = true;
        }else{
            negativeFlag = false;
            break;
        }
    }
    //for all positive array,sum all elements
    if(positiveFlag){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
            maxSum+=arr[i];
        }
        cout<<endl;
        cout<<maxSum;
        return 0;
    }else if(negativeFlag){
        cout<<max;
        cout<<endl<<max;
        return 0;
    }else{
        // looping point for loops
        bool loopPoint = minPos<maxPos;
        //if minimum is on left of maximum,start from min else start from the right
        int x = 0;
        for(int i=loopPoint?minPos+1:minPos-1;loopPoint?i<n:i>=0;loopPoint?i++:i--){
           
            int sum = 0;
            //left permutations
            for(int j=i;loopPoint?j<n:j<minPos;j++){
                sum+=arr[j];
                newPoss.push_back(j);
            }
            // check if the maximum sum is greater then assign the value accordingly
            if(maxSum<sum){
                maxSum = sum;
                positions = newPoss;
                newPoss.clear();
                leftPermut = true;
            }else{
                newPoss.clear();
            }
            //right permutations
            sum=0;
            for(int k=loopPoint?n-x-1:minPos-x;loopPoint?k>minPos:k>=0;k--){
                sum+=arr[k];
                newPoss.push_back(k);
            }
            if(maxSum<sum){
                maxSum = sum;
                positions = newPoss;
                newPoss.clear();
                leftPermut = false;
            }else{
                newPoss.clear();
            }
            x++;
        }
    }
    // print positioned values
    for(int i=leftPermut?0:positions.size()-1;leftPermut?i<positions.size():i>=0;leftPermut?i++:i--){
        cout<<arr[positions[i]]<<" ";
    }
    // print maximum sums
    cout<<endl<<maxSum;
	return 0; // always return 0 from here
}
