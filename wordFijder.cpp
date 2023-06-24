#include <iostream>
#include <vector>
using namespace std;
vector<int> pairs;
bool isSafe(int rows,int cols,int size){
    if(rows>=0 && rows<size && cols >=0 && cols<size){
        return true;
    }else{
        return false;
    }
}
void findWord(char **arr,string required,int rows,int cols,char direction,int size){
    static string s = "";
    static int i=0;
    static bool found = false;
    if(required == s){
        found = true;
        cout<<pairs[0]<<" "<<((pairs[1]==-1)?0:pairs[1])<<" "<<direction<<endl;
        pairs.clear();
        return;
    }
    if(rows == size-1 && cols == size-1){
        if(!found){
            cout<<"N";
        }
        return;
        
    }
    if(cols == size){
        cols = 0;
        rows++;
    }
    if(rows == size){
        return;
    }
    //right movement
    if(isSafe(rows,cols,size)){

        if(isSafe(rows,cols+1,size) && arr[rows][cols+1] == required[i]){
            s+=required[i];
            i++;
            pairs.push_back(rows);
            pairs.push_back(cols);
            findWord(arr,required,rows,cols+1,'R',size);
            if(!found){
            pairs.clear();
            i--;
            s = s.substr(s.length()-2);
            }else{
                return;
            }
            
        }
        if(isSafe(rows,cols-1,size) && arr[rows][cols-1] == required[i]){
            s+=required[i];
            i++;
            pairs.push_back(rows);
            pairs.push_back(cols);
            findWord(arr,required,rows,cols-1,'L',size);
            if(!found){
            pairs.clear();
            i--;
            s = s.substr(s.length()-2);
            }else{
                return;
            }
        }
        if(isSafe(rows-1,cols,size) && arr[rows-1][cols] == required[i]){
            s+=required[i];
            i++;
            pairs.push_back(rows);
            pairs.push_back(cols);
            findWord(arr,required,rows-1,cols,'U',size);
            if(!found){
            pairs.clear();
            i--;
            s = s.substr(s.length()-2);
            }else{
                return;
            }
        }
        if(isSafe(rows+1,cols,size) && arr[rows+1][cols] == required[i]){
            s+=required[i];
            i++;
            pairs.push_back(rows);
            pairs.push_back(cols);
            findWord(arr,required,rows+1,cols,'D',size);
            if(!found){
            pairs.clear();
            i--;
            s = s.substr(s.length()-2);
            }else{
                return;
            }
        }
    }
    if(!found){
         findWord(arr,required,rows,cols+1,'0',size);
    }else{
        return;
    }
   

}
int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	int m,n;
	cin>>m>>n;
	char **arr;
	arr = new char*[m];
	for(int i=0;i<m;i++){
	    arr[i] = new char[n];
	}
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
	        cin>>arr[i][j];
	    }
	}
    int x;
    cin>>x;
    string *list = new string[x];
    for(int i=0;i<x;i++){
        cin>>list[i];
    }
    for(int i=0;i<x;i++){
        findWord(arr,list[i],0,0,'0',m);
    }
	return 0; // always return 0 from here
}
