#include <iostream>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

// Function used in building a heap
void Heapify(int* H, int i, int N)
{
    int l= i*2;
    int r= i*2 +1;
    int smallest;
    if (l < N and H[l]<H[i] )
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }
    
    if (r < N and H[r]<H[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(H[i], H[smallest]);
        Heapify(H, smallest, N);
    }
}

//Builds a heap from a dataArray with size N
void BuildHeap(int* H,int N)
{
    for (int i=N/2; i>0; i--)
    {
        Heapify(H, i, N);
    }
}
// short integer random number generator from stdlib
int rand(void); 

int main()
{ 
  int size=8;
  cout << endl << "How many elements in the input array ";  cin >> size;
  int* dataArray = new int [size + 1];   // get array of right size (with invisible 0th element)
  
  // fill array -- fill 0th element but don't show it.
  for (int k=0; k< size+1 ; k++)  dataArray[k] = rand();
    
  cout<<"Input array:\n";
  for (int k=1; k<size+1; k++)
    cout<<dataArray[k]<<" ";
  cout<<endl;
  // ============= implement your code here or call it as a function======
  // you may assume that the variable size is the correct size of the array
  // (even though it's not) for heap-building purposes
  // build a heap for dataArray
    BuildHeap(dataArray, size+1);
      
  //show heap (but not ignored 0th element)
  cout<<"Heap built from the input array:\n";
  for (int k=1; k<size+1; k++)
    cout<<dataArray[k]<<" ";
  cout<<endl;
    
  delete[] dataArray;
}
