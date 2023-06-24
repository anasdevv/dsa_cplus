#include <iostream>
#include <conio.h>
using namespace std;
void minheap(int *array, int m, int n){
   int j, t;
   t= array[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && array[j+1] < array[j])
         j = j + 1;
      if (t < array[j])
         break;
      else if (t >= array[j]) {
         array[j/2] = array[j];
         j = 2 * j;
      }
   }
   array[j/2] = t;
   return;
}
void maxheap(int *array, int m, int n) {
   int j, t;
   t = array[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && array[j+1] > array[j])
         j = j + 1;
      if (t > array[j])
         break;
      else if (t <= array[j]) {
         array[j / 2] = array[j];
         j = 2 * j;
      }
   }
   array[j/2] = t;
   return;
}
void buildminheap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      minheap(a,k,n);
   }
}
void buildmaxheap(int *a,int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      maxheap(a,k,n);
   }
}
 void Maxheapsort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
   int n, i;
   cout<<"Enter number of elements";
   cin>>n;
   int a[30];
   for (i = 1; i <= n; i++) {
      cout<<"Enter element"<<" "<<(i)<<endl;
      cin>>a[i];
   }
   buildminheap(a, n);
   cout<<"Min Heap"<<endl;
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<endl;
   }
    buildmaxheap(a, n);
   cout<<"Max Heap"<<endl;
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<endl;
   }
   bubbleSort(a,n);
   cout<<"Sorted max heap";
   for(i=1;i<=n;i++)
   {
   	cout<<a[i]<<endl;
   }
  
}
