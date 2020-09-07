// IMAGE OVERLAP

/*  PROBLEM:
    Two images A and B are given, represented as binary, square matrices of the same size.
    (A binary matrix has only 0s and 1s as values.)

    We translate one image however we choose (sliding it left, right, up, or down any number of units), 
    and place it on top of the other image.  After, the overlap of this translation is the number of 
    positions that have a 1 in both images.

    (Note also that a translation does not include any kind of rotation.)

    What is the largest possible overlap?
*/

/*  EXAMPLE:

    Input: A = [[1,1,0],
                [0,1,0],
                [0,1,0]]
           B = [[0,0,0],
                [0,1,1],
                [0,0,1]]
    Output: 3
    Explanation: We slide A to right by 1 unit and down by 1 unit.
*/

/*  APPROACH: Shift and Count - O(n^4)
    1. Create a function to perform the shift and count operation, where matrix A is shifted with reference to matrix B with shifting coordinates.
    2. Iterate through all possible combinations of offset coordinates (x_shift, y_shift), where both coordinates are between the range (0, matrix_width - 1).
    3. In each iteration, the shift and count function is called once with matrix A as the reference and once with matrix B as the reference.
    4. In the overlapping region, count the number of ones using convolutional multiplication of matrices.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int count = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                // Find the maximum count among every shifting combination
                count = max({count, shiftCount(A, B, i, j), shiftCount(B, A, i, j)});
            }
        }
        return count;
    }
    
    // Shift each matrix by an x-coordinate offset and y-coordinate offset
    int shiftCount(vector<vector<int>>& A, vector<vector<int>>& B, int x_shift, int y_shift) {
        int count = 0;
        for(int i = x_shift; i < A.size(); i++) {
            for(int j = y_shift; j < A[0].size(); j++) {
                // Convolutional multiplication of matrices
                count += A[i][j] * B[i - x_shift][j - y_shift];
            }
        }
        return count;
    }
};
