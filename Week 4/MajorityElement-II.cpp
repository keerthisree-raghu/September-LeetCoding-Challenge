// MAJORITY ELEMENT II

/*  PROBLEM:
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Note: The algorithm should run in linear time and in O(1) space.
*/

/*  EXAMPLES:

    Input: [3,2,3]
    Output: [3]

    Input: [1,1,1,3,3,2,2,2]
    Output: [1,2]
*/

/*  APPROACH 1: Hash Map - TC: O(n), SC: O(n)
    1. Initialize an unordered map to store the element and its frequency.
    2. Iterate through each element and increment the count for each occurrence of the element.
    3. Iterate through each element in the map and if its frequency is greater than n/3, push it into the resultant vector.
*/

// SOLUTION 1:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        // Increment the count for each occurrence of an element
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        int frequency = nums.size() / 3;
        // Iterate through each element in the map
        for(auto i : m) {
            // The frequency of the element is greater than n / 3
            if(i.second > frequency) {
                // Push the element into the resultant vector
                res.push_back(i.first);
            }
        }
        return res;
    }
};

/*  APPROACH 2: Boyer-Moore Voting Algorithm - TC: O(n), SC: O(1)
    1. Initialize two candidate variables as -1 and two counter variables as 0.
    2. In the first pass, iterate through each element in the array:
        a. If the element has not been encountered and count1 = 0, set count1 = 1 and the value of candidate1 as the element's value.
        b. If the element has not been encountered and count2 = 0, set count2 = 1 and the value of candidate2 as the element's value.
        c. If the value set as candidate1 is the same as an encountered element, increment count1.
        d. If the value set as candidate2 is the same as an encountered element, increment count2.
    3. In the second pass, reset the counter values and iterate through each element in the array:
        a. Recount the frequency of the values set as candidate1 and candidate2 at the end of the first pass.
        b. If the frequency of the count is greater than n/3, push it to the resultant vector.
*/

// SOLUTION 2:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, candidate1 = -1, candidate2 = -1;
        // Find the value of n/3
        int size = nums.size() / 3;
        for(int n : nums) {
            // If the element is the same as the first candidate, increment count1
            if(n == candidate1) {
                count1++;
            }
            // If the element is the sme as the second candidate, increment count2
            else if(n == candidate2) {
                count2++;
            }
            // Set the first candidate's value as the element's value and initialize count1 as 1
            else if(count1 == 0) {
                candidate1 = n;
                count1 = 1;
            }
            // Set the second candidate's value as the element's value and initialize count2 as 1
            else if(count2 == 0) {
                candidate2 = n;
                count2 = 1;
            }
            // Decrement both counters when a new element is encountered
            else {
                count1--;
                count2--;
            }
        }
        vector<int> res;
        // Reset the counter values
        count1 = 0;
        count2 = 0;
        // Recount the frequency to confirm the count values
        for(int n : nums) {
            if(n == candidate1) {
                count1++;
            }
            else if(n == candidate2) {
                count2++;
            }
        }
        // Check if the frequency is greater than n/3
        if(count1 > size) {
            res.push_back(candidate1);
        }
        if(count2 > size) {
            res.push_back(candidate2);
        }
        return res;
    }
};
