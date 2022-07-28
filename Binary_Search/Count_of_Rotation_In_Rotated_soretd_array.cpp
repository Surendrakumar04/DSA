/*
Given an array arr[] of size N having distinct numbers sorted in increasing order and the array has been right rotated
(i.e, the last element will be cyclically shifted to the starting position of the array) k number of times,
the task is to find the value of k

Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

Example 1:

Input:
N = 5
Arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4. 
The original sorted array is 1 2 3 4 5. 
We can see that the array was rotated 
1 times to the right.

*/
//Approach :
//1. Find the index of the smallest element in Rotated sorted array.
// now this index will be the nomber of times the array has been rotated.
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    
        //int n = nums.size();
        int left = 0;
        int right = n-1;
        
        if(n == 1)
            return 0;
        // if the last element is greater than the first element then there is no
        // rotation.
        // e.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
        // Hence the smallest element is first element. A[0]
        if(nums[0] < nums[right])
            return 0;
        
        while(left < right){
            int mid = left + (right - left)/2;
            
            // if the mid element is greater than its next element then mid+1 element is the
            // smallest
            // This point would be the point of change. From higher to lower value.
            if(nums[mid] > nums[mid + 1])
                return mid+1;
            
            // if the mid element is lesser than its previous element then mid element is
            // the smallest            
            if(nums[mid-1] > nums[mid])
                return mid;
            
            // if the mid elements value is greater than the 0th element this means
            // the least value is still somewhere to the right as we are still dealing with
            // elements
            // greater than nums[0]
            if(nums[mid] > nums[left])
                left = mid+1;
            
            // if nums[0] is greater than the mid value then this means the smallest value
            // is somewhere to
            // the left
             else if(nums[mid] < nums[right])
                right = mid-1;
        }
        
        return INT_MAX;
	    // code here
	}

};



