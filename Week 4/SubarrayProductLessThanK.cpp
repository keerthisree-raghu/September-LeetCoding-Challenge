// EVALUATE DIVISION

/*  PROBLEM:
    You are given an array of positive integers nums.

    Count and print the number of (contiguous) subarrays where the product of all the elements in 
    the subarray is less than k.
*/

/*  EXAMPLE:

    Input: nums = [10, 5, 2, 6], k = 100
    Output: 8
    Explanation: 
    The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
    Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/

/*  APPROACH: Sliding Window - O(n)
    1. Create a sliding window wherein the product of all the elements in the window is always less than k.
    2. Initialize a variable to point to the left-most element in the window and the right-most element in the window.
    3. For every increment of the right pointer, check if the product is still strictly less than k.
        a. If the product is greater than or equal to k, increment the left pointer and remove the value of that element from the current product.
        b. If the product is less than k, increment the count of the number of subarrays which satisfy the condition.
    
    Every time a new element is introduced to a subarray of size n = (right - left + 1), n new subarrays are generated.
    In a window [1, 3, 4], if 4 accepted as a new element, there are three new possible subarrays:
    [4], [3, 4], [1, 3, 4]
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) {
            return 0;
        }
        int product = 1, count = 0, left = 0;
        for(int right = 0; right < nums.size(); right++) {
            // Calculate the product value
            product *= nums[right];
            // Shift the sliding window when the product value becomes greater than k
            while(product >= k) {
                // Remove the previous left value from the product
                product /= nums[left++];
            }
            // Count the number of intervals with a product less than k
            count += right - left + 1;
        } 
        return count;
    }
};
