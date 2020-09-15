// HOUSE ROBBER

/*  PROBLEM:
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
    the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
    it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
    money you can rob tonight without alerting the police.
*/

/*  EXAMPLES:

    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                 Total amount you can rob = 1 + 3 = 4.

    Input: nums = [2,7,9,3,1]
    Output: 12
    Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
                 Total amount you can rob = 2 + 9 + 1 = 12.
*/

/*  APPROACH: Dynamic Programming - Time: O(n), Space: O(1)
    1. Initialize two variables to track the previous house value and the previous alternate house value.
    2. Initialize a temporary variable to perform swapping in each iteration.
    3. In every iteration, we have two choices:
        a. Choose the current house and add it to the previous alternate house value.
        b. Select the previous maximum value.
    4. Calculate the maximum profit obtained between the two choices in the previous step.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        // Previous house
        int prev1 = 0;
        // Previous alternate house
        int prev2 = 0;
        int temp;
        // Option 1: Rob current house and house before previous house
        // Option 2: Rob previous house
        for(int num : nums) {
            temp = prev1;
            // Find the maximum value of profit
            prev1 = max(prev2 + num, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};
