#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int max = root; //largest number is in the root
   int left = 2*root + 1;
   int right = 2*root + 2;

   if (left < n && arr[left] > arr[max])
		max = left; //if left is greater

	if (right < n && arr[right] > arr[max])
		max = right; //if right is greater


	if (max != root) {
		swap(arr[root], arr[max]);
		heapify(arr, n, max);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); //to maintain the heap
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
  
// main program
int main()
{
    int n;
	cout << "Enter number of elements in the array: ";
	cin >> n;
	int heap_arr[n];
	cout << "\nEnter Input array:" << endl;
	for (int i = 0; i < n; i++){ //getting the inputs from the user
		cin >> heap_arr[i];
	}

	heapSort(heap_arr, n);

	cout << "\nSorted array:"<<endl;
	displayArray(heap_arr, n);
}