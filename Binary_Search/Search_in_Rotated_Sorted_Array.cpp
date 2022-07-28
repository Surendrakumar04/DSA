/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/
class Solution {
public:
    
    int BS(vector<int>& nums, int target,int left, int right){
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                right = mid-1;
            else
                left = mid +1;
            
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        /* hence array is left rotated acc to question , so find the index of pivot element , 
        i.e index of smallest
        element in rotated sorted array
        now we have to sorted array , one before pivot and one after pivot element,
        apply Binary search in both sorted array to find target element
        */
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int pivot = 0;
        if(n == 1){
            if(target == nums[0])
                return 0;
            else
                return -1;
        }
        if(nums[0] < nums[right])
            return BS(nums,target,left,right);
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(nums[mid] > nums[mid+1]){
                pivot = mid+1;
                break;
            }
            if(nums[mid-1] > nums[mid]){
                pivot = mid;
                break;
            }
            if(nums[left] < nums[mid])
                left = mid+1;
            else
                right = mid-1;
                
                
        }
        int leftRes = BS(nums,target,0,pivot-1);
        int rightRes = BS(nums,target,pivot,n-1);
        
        if(leftRes == -1)
            return rightRes;
        else
            return leftRes;
        
        return -1;
        
    }
};