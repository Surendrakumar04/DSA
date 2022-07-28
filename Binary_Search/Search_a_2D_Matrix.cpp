/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

matrix = [  [1, 3,  5, 7],
            [10,11,16,20],
            [23,30,34,60]
        ]
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while(i >= 0 && i < m && j >=0 && j < n){
            if(matrix[i][j] == target) // found
                return true;
            else if(matrix[i][j] > target) // move towards left
                j--;
            else if(matrix[i][j] < target) // move towards right
                i++;    
        }
        return false;
            
        
    }
};