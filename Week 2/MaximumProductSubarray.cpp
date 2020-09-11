// MAXIMUM PRODUCT SUBARRAY

/*  PROBLEM:
    Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
*/

/*  EXAMPLES:

    Input: [2,3,-2,4]
    Output: 6
    Explanation: [2,3] has the largest product 6.

    Input: [-2,0,-1]
    Output: 0
    Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

/*  APPROACH: Dynamic Programming - O(n)
    1. Initialize two variables to keep track of the minimum and maximum product values till the ith index of the array.
    2. If the ith array element is negative, swap the values of currentMax and currentMin. [+ve * -ve = -ve]
    3. Calculate the current maximum and current minimum values and compare it with the current array element to set the new values.
    4. The maximum possible product value is either the existing maximum product value or the current maximum value after every iteration.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0], currentMin = nums[0], maxProductValue = nums[0];
        if(nums.size() == 0) {
            return 0;
        }
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                // When multiplied by a negative number, the maximum so far becomes minimum and vice versa
                swap(currentMax, currentMin);
            }
            // currentMax and currentMin store the product of the subarray till nums[i]
            currentMax = max(nums[i], currentMax * nums[i]);
            currentMin = min(nums[i], currentMin * nums[i]);
            // Calculate the maximum possible value of the subarray
            maxProductValue = max(maxProductValue, currentMax);
        }
        return maxProductValue;
    }
};
