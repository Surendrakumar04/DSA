/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        if(n == 1)
            return nums[0];
        // if the last element is greater than the first element then there is no
        // rotation.
        // e.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
        // Hence the smallest element is first element. A[0]
        if(nums[0] < nums[right])
            return nums[0];
        
        while(left < right){
            int mid = left + (right - left)/2;
            
            // if the mid element is greater than its next element then mid+1 element is the
            // smallest
            // This point would be the point of change. From higher to lower value.
            if(nums[mid] > nums[mid + 1])
                return nums[mid+1];
            
            // if the mid element is lesser than its previous element then mid element is
            // the smallest            
            if(nums[mid-1] > nums[mid])
                return nums[mid];
            
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
 
        
    }
};