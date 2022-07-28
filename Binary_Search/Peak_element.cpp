/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, 
an element is always considered to be strictly greater than a neighbor that is outside the array.

--> You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(mid > 0 && mid < n-1 ){
                if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                    return mid;
                    
                }
                else if(nums[mid + 1] > nums[mid]) // move towards greater part
                    l = mid + 1;
                else if(nums[mid-1] > nums[mid]) // move towards greate part
                    r = mid -1;     
            }
            
            // for corner cases nums[0] and nums[n-1] to be peak
            else if(mid == 0){
                if(nums[mid] > nums[1])
                    return 0;
                else
                    return 1;
            }      
            else if(mid == n-1){
                if(nums[n-1] > nums[n-2])
                    return n-1;
                else
                    return n-2;
            }
        }        
        return 0;
        
        
        
    }
};