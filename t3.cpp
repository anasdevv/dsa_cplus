#include <iostream>
using namespace std;
void heapify(int array[], int s, int i)
{
 
    int largest = i;
    int right = 2 * i + 2;
 
 
    if (right < s && array[right] > array[largest])
        largest = right;
   
     int left = 2 * i + 1;
    if (left < s && array[left] > array[largest])
        largest = left;
 
    if (largest != i) {
        swap(array[i], array[largest]);
 
    
        heapify(array, s, largest);
    }
}
 
void heapSort(int arr[], int s)
{
 
    
    for (int i = s / 2 - 1; i >= 0; i--)
        heapify(arr, s, i);
    for (int i = s - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
 

void print(int arr[], int s)
{
    for (int i = 0; i < s; ++i)
        cout << arr[i] << " "<<endl;  
}
 

int main()
{
    int arr[] = { 7,5,1,4,9 };
    heapSort(arr, 5);
    cout << "After sorting array "<<endl;
    print(arr, 5);
}
