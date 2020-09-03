// CONTAINS DUPLICATE III

/*  PROBLEM:
    Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between 
    nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
*/

/*  EXAMPLES:

    Input: nums = [1,2,3,1], k = 3, t = 0
    Output: true

    Input: nums = [1,0,1,1], k = 1, t = 2
    Output: true

    Input: nums = [1,5,9,1,5,9], k = 2, t = 3
    Output: false
*/

/*  APPROACH: Two-Pointer - O(n^2)
    1. Initialize a vector pair to store the value and index of each element as a key-value pair.
    2. Store the value of the element in the first position of the pair and the index of the element in the second position of the pair.
    3. Sort the vector pair in ascending order.
    4. Iterate through each element in the vector using two pointers.
    5. Check if the absolute difference between a pair of values is at most equal to t.
        a. Check if the absolute difference between the indexes of the pair of values is at most equal to k.
        b. Return true.
    6. Return false if the condition is not satisfied.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        vector<pair<int,int>> v(len);
        // Store the key-value pair of each element in the array as value-index
        for(int i = 0; i < len; i++) {
            // Value
            v[i].first = nums[i];
            // Index
            v[i].second = i;
        }
        // Sort the vector elements
        sort(v.begin(), v.end());
        int i = 0;
        int j = v.size() - 1;
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                // Check if the absolute difference between the pair of values is at most equal to t
                if(v[i].first + t >= v[j].first) {
                    // Check if the absolute difference between the pair of indexes is at most equal to k
                    if(abs(v[i].second - v[j].second) <= k) {
                        return true;
                    }
                }
                else {
                    break;
                }
            }
        }
        return false;
    }
};
