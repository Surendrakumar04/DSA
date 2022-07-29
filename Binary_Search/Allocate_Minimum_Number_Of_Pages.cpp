// allocate minimum number of pages
/*
Given number of pages in n different books and m students. 
The books are arranged in ascending order of number of pages. 
Every student is assigned to read some consecutive books.
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. 
The student can start reading from any book and can read upto k pages at a time.

Input : pages[] = {12, 34, 67, 90} , m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed 
in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 
      '2' with 34 + 67 + 90 = 191 pages
      
    

  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student
      '2' with 67 + 90 = 157 pages 
        So the maximum number of pages is 157.
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 
      '1' with 12 + 34 + 67 = 113 pages
        So the maximum number of pages is 113.

Of the 3 cases, Option 3 has the minimum pages = 113. 

Approach:
The idea is to use Binary Search. We fix a value for the number of pages as mid of current minimum and maximum.
We initialize minimum and maximum as 0 Or max of all books and sum-of-all-pages respectively.
If a current mid can be a solution, then we search on the lower half, else we search in higher half.
Now the question arises, how to check if a mid value is feasible or not? Basically,
we need to check if we can assign pages to all students in a way that the maximum number doesn’t exceed current value. To do this,
we sequentially assign pages to every student while the current number of assigned pages doesn’t exceed the value. In this process,
if the number of students becomes more than m, then the solution is not feasible. Else feasible.
Below is an implementation of above idea.


*/


class Solution 
{
    public:
    
    bool isPossible(int* A,int N,int M, int mx){
        int pages = 0;
        int student = 1;
        for(int i = 0; i< N ; i++){
            pages += A[i];
            if(pages > mx){ // if pages exceed mx, then student can't read this book. so we need to assign this book to next student.
                student++; // new student
                pages = A[i];
            }
            if(student > M) // not possible
                return false;
        }
        return true; // possible
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int l = INT_MIN;
        int h = 0;
        int res = 0;
        //int sum = 0;
        for(int i = 0; i < N ; i++){
            l = max(l,A[i]); // find max of all books
            h += A[i]; // sum of all pages
        }
        // we have l and h --> it will minimise the maximum no of pages alloted to a student;
        // we have to find the minimum number of pages.
        while(l <= h){
            int mid = (l + h)/2;
            // if possible, then mid can be  the answer, 
            //but we need to find the minimum no of pages.
            //so continue to search in the range [mid+1,h]
            if(isPossible(A,N,M,mid)){ 
                res = mid;
                h = mid-1;
            }
            else
             l = mid+1; 
            
        }
        return res;
    }
};

/*
Time Complexity: O(N*log (M – max)), where N is the number of different books , 
max denotes the maximum number of pages from all the books and M denotes the sum of number of pages of all different books
Auxiliary Space: O(1)
*/