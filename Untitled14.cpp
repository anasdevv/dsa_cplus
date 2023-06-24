#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> obj;
        vector<int> res;
        for(int i = 0 ; i <nums.size() ; i++)
            obj[nums[i]] = i;
        for(int i = 0 ; i < nums.size() ; i++){
            int num = target - nums[i];
            cout << num << endl;
            cout << obj[num] << endl;
            if(obj[num]){
            	if(obj[num] == i)
            		continue;
                res.push_back(obj[num]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
int main(){
	vector<int> a{1,3,4,2};
	vector<int> res;
	res = twoSum(a,6);
	for(int i = 0 ; i < res.size() ; i++){
		cout << res[i] << " ";
	}
	return 0;
}   
