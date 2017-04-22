/*
 * Kevin Takano 21/04/2017
 *
 * HeapSort - 1.0 version
 * 
 * It's my fist program using the vim text editor
 *
 * TODO LIST:
 *
 * 1) Create printing function to print in tree format.
 * 2) Create debug mode step-by-step.
 * */

#include <iostream>
#define MAX 1000

using namespace std;

void swap( int *a , int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}

class Heap
{
public:
	Heap()
	{

	}

	Heap(int arr[], int n)
	{
		build_maxHeapify(arr,n);
	}

	~Heap()
	{

	}

	inline int leftChild(int c)
	{
		return 2*c + 1;
	}

	inline int rightChild(int c)
	{
		return 2*c + 2;
	}

	inline bool nodeIsInTheLimits(int c, int n)
	{
		return c < n and c >= 0;
	}

	inline int getLargerChild(int left_child, int right_child, int father, int arr[], int n)
	{
		int largest = father;
		if(nodeIsInTheLimits(left_child, n))
		{
			if(arr[left_child] > largest)
			{
				largest = left_child;
			}
		}
		if(nodeIsInTheLimits(right_child, n))
		{
			if(arr[right_child] > largest)
			{
				largest = right_child;
			}
		}
		return largest;
	}

	inline bool fatherisNotTheLargest(int largest, int father)
	{
		return largest != father;
	}

	void heapify(int arr[], int n, int father) // c variable is the current node, he is the father
	{	
		int largest = father;
		int left_child = leftChild(father);
		int right_child = rightChild(father);

		largest = getLargerChild(left_child,right_child, father, arr, n);

		if(fatherisNotTheLargest(largest,father))
		{
			swap(&arr[father],&arr[largest]);
			heapify(arr,n,largest);
		}	
	}

	void build_maxHeapify(int arr[], int n) 
	{
		for(int i = (n/2) + 1; i >= 0; i--)
		{
			heapify(arr, n, i);
		}
	}

        void print() //TODO
	{
		
	}
	

};

void heapSort(int arr[], int n)
{
	Heap heap(arr,n);

	for(int i = n - 1; i >= 0;i--)
	{
		swap(&arr[0],&arr[i]);
		heap.heapify(arr,i,0);
	}
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    int arr[] = {1,26,3,15,12,55,4,6,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Unsorted array: ";
    printArray(arr,n);


    heapSort(arr, n);
 
    cout << "Sorted array: ";
    printArray(arr, n);
}		

