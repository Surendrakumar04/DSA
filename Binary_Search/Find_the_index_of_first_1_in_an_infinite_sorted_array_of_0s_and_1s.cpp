/*
Given an infinite sorted array consisting 0s and 1s.
The problem is to find the index of first ‘1’ in that array.
As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

Examples:
Input : arr[] = {0, 0, 1, 1, 1, 1} 
Output : 2

Input : arr[] = {1, 1, 1, 1,, 1, 1}
Output : 0

Approach: The problem is closely related to the 
problem of finding position of an element in a sorted array of infinite numbers.
As the array is infinite,
therefore we do not know the upper and lower bounds between which we have to find the occurrence of first ‘1’. 
*/

// C++ implementation to find the index of first 1
// in an infinite sorted array of 0's and 1's
#include <bits/stdc++.h>
using namespace std;

// function to find the index of first '1'
// binary search technique is applied
int indexOfFirstOne(int arr[], int low, int high)
{
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;

		// if true, then 'mid' is the index of first '1'
		if (arr[mid] == 1 &&
			(mid == 0 || arr[mid - 1] == 0))
			break;

		// first '1' lies to the left of 'mid'
		else if (arr[mid] == 1)
			high = mid - 1;

		// first '1' lies to the right of 'mid'
		else
			low = mid + 1;
	}
	// required index
	return mid;
}

// function to find the index of first 1 in
// an infinite sorted array of 0's and 1's
int posOfFirstOne(int arr[])
{
	// find the upper and lower bounds between
	// which the first '1' would be present
	int l = 0, h = 1;

	// as the array is being considered infinite
	// therefore 'h' index will always exist in
	// the array
	while (arr[h] == 0) {

		// lower bound
		l = h;

		// upper bound
		h = 2 * h;
	}
	// required index of first '1'
	return indexOfFirstOne(arr, l, h);
}
// Driver program to test above
int main()
{
	int arr[] = { 0, 0, 1, 1, 1, 1 };
	cout << "Index = "
		<< posOfFirstOne(arr);
	return 0;
}
