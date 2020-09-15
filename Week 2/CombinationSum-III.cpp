// COMBINATION SUM III

/*  PROBLEM:
    Find all possible combinations of k numbers that add up to a number n, given that only numbers from 
    1 to 9 can be used and each combination should be a unique set of numbers.

    Note:
    All numbers will be positive integers.
    The solution set must not contain duplicate combinations.

*/

/*  EXAMPLES:

    Input: k = 3, n = 7
    Output: [[1,2,4]]

    Input: k = 3, n = 9
    Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

/*  APPROACH: Backtracking - O((9!⋅K)/(9−K)!)
    1. Initialize a two-dimensional vector to store the resultant combinations.
    2. Recursively populate the vector by calling a recursive function.
    3. In the recursive function, iterate through every digit from 1 to 9.
        a. Add the digit to the combination vector.
        b. Recursively find the next value that satisfies the condition of being less than n.
        c. Reset the combination vector when it has been completely filled up.
    4. If the maximum size of the combination vector has been reached and the values in the vector add up to n, push the vector into the resultant vector.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void findCombinations(int k, int n, vector<int> combination, int next, vector<vector<int>>& res) {
        // Base case: The largest possible size of one combination vector has been reached and the sum value has been reduced to 0
        // Add the combination vector to the resultant vector
        if(k == 0 && n == 0) {
            // One combination instance
            res.push_back(combination);
            return;
        }
        // Iterate through every digit from 1 to 9
        for(int i = next; i <= 9; i++) {
            // Add the digit to the combination vector
            combination.push_back(i);
            // Find the next value that satisfies the condition
            findCombinations(k - 1, n - i, combination, i + 1, res);
            // Reset
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // Container to store the resultant combinations
        vector<vector<int>> res;
        // Recursively populate the vector
        findCombinations(k, n, vector<int>(), 1, res);
        return res;
    }
};
