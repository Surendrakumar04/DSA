/*

Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 
Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"

*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0;
        int r = n-1;
        char res = letters[0];
        while(l <= r){
            int mid = l + (r-l)/2;
            if(target < letters[mid]){
                res = letters[mid];
                r = mid-1;
                
            }
            else
                l = mid + 1;
        }
        return res;        
    }
};