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
class Safe2DArr{
    private:
       int* arr;
		int size, row_size, col_size;
    public:
        Safe2DArr(int r,int c,int *a = 0){
           row_size = r;
			col_size = c;
			size = row_size*col_size;
			arr = new(nothrow) int[size];
			
			for (int i=0;i<size;i++){
				arr[i] = a[i];
			}
        }
        ~Safe2DArr(){
            delete[] arr;
        }
        int& operator()(int row_index, int col_index){
            try{
			if ((row_index < 0 || row_index >= row_size) &&
				(col_index < 0 || col_index >= col_size)){
				throw MyException("Range Error: Index out of bounds.");
			}
			if (row_index < 0 || row_index >= row_size){
				throw MyException("Range Error: Index out of bounds.");
			}
			if(col_index < 0 || col_index >= col_size){
				throw MyException("Range Error: Index out of bounds.");
			}
            }
            catch(MyException &e){
                e.what();
            }
			return arr[row_index*col_size + col_index];
		}
        int get(int row_index, int col_index){
            try{
			if ((row_index < 0 || row_index >= row_size) &&
				(col_index < 0 || col_index >= col_size)){
				throw MyException("Range Error: Index out of bounds.");
			}
			if (row_index < 0 || row_index >= row_size) {
				throw MyException("Range Error: Index out of bounds.");
			}
			if(col_index < 0 || col_index >= col_size){
				throw MyException("Range Error: Index out of bounds.");
			}
            }catch(MyException &e){
                e.what();
            }
			return arr[row_index*col_size + col_index];
		}
        int set(int row_index, int col_index,int val){
            try{
			if ((row_index < 0 || row_index >= row_size) &&
				(col_index < 0 || col_index >= col_size)){
				throw MyException("Range Error: Index out of bounds.");
			}
			if (row_index < 0 || row_index >= row_size) {
				throw MyException("Range Error: Index out of bounds.");
			}
			if(col_index < 0 || col_index >= col_size){
				throw MyException("Range Error: Index out of bounds.");
			}
            }catch(MyException &e){
                e.what();
            }
			 arr[row_index*col_size + col_index] = val;
		}
        void pushBackCol(int val[], int val_size){
            try{
			if (val_size != row_size){
				throw MyException("Excception: input array size is not same as the row size!");
			}
            }catch(MyException &e){
                e.what();
            }
			int* arr_new = new int[size + row_size];
			
			int row=0;
			for (int i=0; i<size+row_size;i++){
				if (((i+1)%(col_size+1))==0){
					arr_new[i] = val[row];
					row++;
				}
				else{
					arr_new[i] = arr[i-row];
				}
			}
			delete [] arr;
			arr = arr_new;
			col_size++;
			size +=row_size;
		}
        void pushBackRow(int val[], int val_size){
            try{
			if (val_size != col_size){
				throw MyException("Excception: input array size is not same as the col size!");
			}
            }catch(MyException &e){
                e.what();
            }
			
			int *arr_new = new int[size+col_size];
			for(int i=0; i<size;i++){
				arr_new[i] = arr[i];
			}
			for(int i=size; i<size+col_size;i++){
				arr_new[i] = val[i-size];
			}
			delete [] arr;
			arr = arr_new;
			row_size++;
			size +=col_size;
		}
        void printArray(){
			for (int i=0;i< size;i++){
				if ((i%col_size) == 0){
					cout<<endl;
				}
				cout<<arr[i]<<",";
			}
			cout<<endl;
		}
        int getRowSize(){
			return row_size;
		}
		int getColSize(){
			return col_size;
		}
};
int main()
{
	int rows=3;
	int cols=4;
	int *arr = new int[rows*cols];
	for (int i=0;i<rows*cols;i++){
		arr[i] = i+1;
	}
	
	Safe2DArr darr(3,4,arr);
	darr.printArray();
	
	int a[3] = {1,2,3};
	int n = sizeof(a) / sizeof(a[0]);
	darr.pushBackCol(a,n);
	darr.printArray();
	cout<<darr.getRowSize()<<" "<<darr.getColSize()<<endl;
	
	int b[5] = {1,2,3,4,5};
	n = sizeof(b) / sizeof(b[0]);
	darr.pushBackRow(b,n);
	darr.printArray();
	cout<<darr.getRowSize()<<" "<<darr.getColSize()<<endl;
}
