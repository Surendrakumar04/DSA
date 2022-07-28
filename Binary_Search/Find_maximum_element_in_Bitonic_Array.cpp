/*
Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.

Example 1:
Input: 
n = 9
arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45
Explanation: Maximum element is 45.
*/

class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // like peak element
	    int l = 0;
	    int r = n-1;
	    
	    while(l <= r){
	        int mid = l + (r-l)/2;
	        
	        if(mid > 0 && mid < n-1){
	            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])
	                return arr[mid];
	            else if(arr[mid-1] > arr[mid]) // move towards greater part
	                r = mid-1;
                else                          // here also move towards greater part 
                    l = mid + 1;
	        }
	        else if(mid == 0){
	            if(arr[mid] > arr[1])
	                return arr[mid];
                else
                    return arr[1];
	        }
	        else if(mid == n-1){
	            if(arr[n-1] > arr[n-2])
	                return arr[n-1];
                else
                    return arr[n-2];
	        }
	    }
	    return 0;
	    
	    
	   
	}
};