// COMPARE VERSION NUMBERS

/*  PROBLEM:
    Compare two version numbers version1 and version2.
    If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

    You may assume that the version strings are non-empty and contain only digits and the . character.

    The . character does not represent a decimal point and is used to separate number sequences.
    For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

    You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 
    and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.
*/

/*  EXAMPLES:

    Input: version1 = "0.1", version2 = "1.1"
    Output: -1

    Input: version1 = "1.0.1", version2 = "1"
    Output: 1

    Input: version1 = "7.5.2.4", version2 = "7.5.3"
    Output: -1

    Input: version1 = "1.01", version2 = "1.001"
    Output: 0
    Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”

    Input: version1 = "1.0", version2 = "1.0.0"
    Output: 0
    Explanation: The first version number does not have a third level revision number, which means its third level
*/

/*  APPROACH: Iterative - O(n)
    1. Initialize a variable to store the numeric value of each given string.
    2. Iterate through every dot-separated number in both versions.
    3. Convert the string value into an integer value.
    4. Build the resultant number by multiplying it with 10 in each iteration until a dot is encountered.
    5. Check which of the given conditions are satisfied and return the appropriate result.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = version1.size(), v2 = version2.size();
        int i = 0, j = 0;
        // Convert the string values into integers
        while(i < v1 || j < v2) {
            int value1 = 0, value2 = 0;
            // Iterate through every dot separated number in version 1
            while(i < v1 && version1[i] != '.') {
                // Convert the string value to integer and build the resultant number by multiplying with 10
                value1 = value1 * 10 + version1[i] - '0';
                i++;
            }
            // Iterate through every dot separated number in version 2
            while(j < v2 && version2[j] != '.') {
                // Convert the string value to integer and build the resultant number by multiplying with 10
                value2 = value2 * 10 + version2[j] - '0';
                j++;
            }
            // Check conditions
            if(value1 > value2) {
                return 1;
            }
            else if(value1 < value2) {
                return -1;
            }
            // Move to next dot separated value
            i++;
            j++;
        }
        return 0;
    }
};
