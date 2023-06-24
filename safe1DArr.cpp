#include<iostream>

using namespace std;

class MyException{
    private:
        string s;
    public:
        MyException(string s){
            this->s = s;
        }
        void what(){
            cout<<s<<endl;
        }
};
class Safe1DArr{
    private:
        int *arr;
        int size;
    public:
        Safe1DArr(int size){
            this->size = size;
            arr = new int[this->size];
        }
        Safe1DArr(){
            delete[] arr;
        }
        void push_back(int data,int index){
            try{
                if(index<0 || index>=size){
                    throw MyException("Range Error: Index out of bounds.");
                }
            }catch(MyException &e){
                e.what();
            }
            arr[index] = data;
        }
        void printArr(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Safe1DArr a1(5);
    a1.push_back(1,0);
    a1.push_back(2,1);
    a1.push_back(3,2);
    a1.push_back(4,3);
    a1.push_back(5,4);
    a1.push_back(6,5);
    a1.printArr();

}