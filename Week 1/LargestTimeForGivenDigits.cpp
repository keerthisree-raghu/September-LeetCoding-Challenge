// LARGEST TIME FOR GIVEN DIGITS

/*  PROBLEM:
    Given an array of 4 digits, return the largest 24 hour time that can be made.
    The smallest 24 hour time is 00:00, and the largest is 23:59.
    Starting from 00:00, a time is larger if more time has elapsed since midnight.
    Return the answer as a string of length 5.  If no valid time can be made, return an empty string.
*/

/*  EXAMPLES:

    Input: [1,2,3,4]
    Output: "23:41"

    Input: [5,5,5,5]
    Output: ""
*/

/*  APPROACH: Permutations - O(1)
    1. Sort the array in ascending order
    2. Check if the hour and minute conditions are satisfied.
        a. Hour < 24
        b. Minute < 60
    3. Construct the time using the array values by converting each value to string.
    4. Update the maximum time value if the current maximum is less than the new time.
    5. Iterate through the next permutation that satisfies the conditions.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string max_time = "";
        // Sort the array in ascending order
        sort(A.begin(), A.end());
        do {
            // Check if the hour and minute conditions are satisfied
            // Hour < 24 and Minute < 60
            if((A[0] == 2 && A[1] <= 3 || A[0] < 2) && A[2] <= 5) {
                // Construct the time using the array values 
                string new_time = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
                // Update the maximum time value if required
                max_time = new_time > max_time ? new_time : max_time;
            }
        }
        // Iterate through each possible permutation
        while(next_permutation(A.begin(), A.end()));
        return max_time;
    }
};
