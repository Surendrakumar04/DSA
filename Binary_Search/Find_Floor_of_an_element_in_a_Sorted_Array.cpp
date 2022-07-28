/*
Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.
Examples: 

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
Output : 2
2 is the largest element in 
arr[] smaller than 5.

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20
Output : 19
19 is the largest element in
arr[] smaller than 20.

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 0
Output : -1
Since floor doesn't exist,
output is -1.
*/

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find

    int findFloor(vector<long long> v, long long n, long long x){
        long long left = 0;
        long long right = n-1;
        long long res = -1;
        while(left <= right){
            long long mid = left + (right - left)/2;
            
            if(v[mid] == x)
                return mid;
            else if(x > v[mid]){
                res = mid;
                left = mid+1;
            }
            else
                right = mid - 1;
        }
        return res;
        
        // Your code here
        
    }
};

