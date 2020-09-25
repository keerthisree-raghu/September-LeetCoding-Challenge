// LARGEST NUMBER

/*  PROBLEM:
    Given a list of non negative integers, arrange them such that they form the largest number.
    
    Note: 
    The result may be very large, so you need to return a string instead of an integer.
*/

/*  EXAMPLES:

    Input: [10,2]
    Output: "210"

    Input: [3,30,34,5,9]
    Output: "9534330"
*/

/*  APPROACH: Custom Comparison Sorting - O(n logn)
    1. Create a custom comparison function to use as the third argument in the sorting function.
        a. Concatenate two integers, 'a' and 'b' as 'ab' and 'ba'.
        b. If 'ab' is greater than 'ba', return 1. Otherwise, return 0.
    2. Sort the array of numbers using the custom comparison function.
    3. Construct the largest possible number by concatenating each value in the sorted numbers array.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Create custom comparison function to use as the third argument in the sorting function
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string res;
        // Construct the resultant string
        for(int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        return res[0] == '0' ? "0" : res;
    }
};
