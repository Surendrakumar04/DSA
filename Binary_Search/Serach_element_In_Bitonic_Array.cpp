/*
bitonic array is an array where the elements are in increasing order first and then decreasing order.
For example, the following array is a bitonic array:
{1,15,25,45,42,21,17,12,11}
approach:
1. find indexo f max element in bitonic array or bitonic point in the array.
2. now you have to subarray sepertated from bitonic point. one is increasing and other is decreasing.
3.Apply Binary search on both the subarrays to get index of key element.


remember:
you have to apply BS on Increasing subarray and Decreasing subarray.

*/
#include <iostream>
using namespace std;

// Function for binary search in ascending part
int ascendingBinarySearch(int arr[], int low,int high, int key){
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
// Function for binary search in
// descending part of array
int descendingBinarySearch(int arr[], int low,int high, int key){
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

// finding bitonic point
int findBitonicPoint(int arr[], int n,int l, int r){
    while(l <= r){
        int mid = l + (r-l)/2;
        if(mid > 0 && mid < n-1){
            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])
                return mid;
            else if(arr[mid-1] > arr[mid]) // move towards greater part
                r = mid-1;
            else                          // here also move towards greater part 
                l = mid + 1;
        }
        else if(mid == 0){
            if(arr[mid] > arr[1])
                return mid;
            else
                return 1;
        }
        else if(mid == n-1){
            if(arr[n-1] > arr[n-2])
                return n-1;
            else
                return n-2;
        }
    }
    return -1;
}

// Function to search key in
// bitonic array
int searchBitonic(int arr[], int n,int key, int index){
    if(key == arr[index])
        return index;
    int incSubArr = ascendingBinarySearch(arr,0,index-1,key);
    int decSubArr = descendingBinarySearch(arr,index+1,n-1,key);
    if(incSubArr != -1)
        return incSubArr;
    else if(decSubArr != -1)
        return decSubArr;
    else
        return -1;
	
}
// Driver code
int main()
{
	int arr[] = { -8, 1, 2, 3, 4, 5, -2, -3 };
	int key = 1;
	int n, l, r;
	n = sizeof(arr) / sizeof(arr[0]);
	l = 0;
	r = n - 1;
	int index;

	// Function call
	index = findBitonicPoint(arr, n, l, r);

	int x = searchBitonic(arr, n, key, index);

	if (x == -1)
		cout << "Element Not Found" << endl;
	else
		cout << "Element Found at index " << x << endl;
	return 0;
}

