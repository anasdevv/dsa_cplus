#include<iostream>
using namespace std;

int main(){
    int maze[4][4] = {{0,1,1,1},
                    {0,1,1,1},
                    {0,0,1,1},
                    {1,0,0,2}};
    int lastX=0,lastY=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(maze[i][j]==0 || maze[i][j]==2){
                if(i>=lastX && j>=lastY){
                    if(maze[i+1][j]==0){
                        cout<<"i: "<<i<<" j: "<<j<<endl;
                        lastX=i;
                        lastY=j;
                    }else if(maze[i][j+1]==0 || maze[i][j+1] == 2){
                        cout<<"i: "<<i<<" j: "<<j<<endl;
                        lastX = i;
                        lastY = j;
                    }else{
                        break;
                    }
                }
            }
        }
    }
}