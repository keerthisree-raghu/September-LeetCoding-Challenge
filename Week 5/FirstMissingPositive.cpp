// FIRST MISSING POSITIVE

/*  PROBLEM:
    Given an unsorted integer array, find the smallest missing positive integer.

    Follow up:
    Your algorithm should run in O(n) time and uses constant extra space.
*/

/*  EXAMPLES:

    Input: [1,2,0]
    Output: 3

    Input: [3,4,-1,1]
    Output: 2

    Input: [7,8,9,11,12]
    Output: 1
*/

/*  APPROACH: Two-Pass Swapping - TC: O(n), SC: O(1)
    1. Iterate through the input array and move each element to its correct index position by swapping.
    2. Iterate through the sorted array and if the missing number is found to be at some position i, between 1 and n, return i + 1.
    3. If current array does not have the missing number within it, the next positve number after the last element must be returned.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Move each element in the array to its correct position
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } 
        }
        // Case 1: The missing element is between [1...n]
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        // Case 2: The missing element is the next positive number after the last element
        return n + 1;
    }
};
