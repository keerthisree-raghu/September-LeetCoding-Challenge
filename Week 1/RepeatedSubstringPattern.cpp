// REPEATED SUBSTRING PATTERN

/*  PROBLEM:
    Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple
    copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
*/

/*  EXAMPLES:

    Input: "abab"
    Output: True
    Explanation: It's the substring "ab" twice.

    Input: "aba"
    Output: False

    Input: "abcabcabcabc"
    Output: True
    Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

/*  APPROACH 1: String Manipulation - O(n)
    [string = "abab"]
    1. Concatenate the string to itself.
    [doubledString ="abababab"]
    2. From the doubled string, remove the first and last characters.
    [newString = "bababa"]
    3. If the original string can be found in this new string, return true.
    ["b abab a"] -> The original string is found in the new string
*/

// SOLUTION 1:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // Concatenate the input string with itself
        string doubledString = s + s;
        // Remove the first and last character from the doubled string
        string newString = doubledString.substr(1, 2 * s.size() - 2);
        // Check if the original string can be found in the new string
        return newString.find(s) != -1;
    }
};

/*  APPROACH 2: KMP Pattern Searching Algorithm - O(n)
    1. Initialize two pointers to track the previous and next characters in the string as 0 and 1 respectively.
    2. Initialize the KMP array of size n = size of the string.
    3. Build the KMP array using the input string by comparing the next and previous characters.
        a. If the next and previous characters are equal, set KMP[next] as (prev + 1). Increment both pointers.
        b. If the characters are not equal and the previous pointer is greater than 0, set prev as KMP[prev - 1].
        c. Otherwise, increment the next pointer.
    4. If the last index in the KMP array is 0, a repeated substring does not exist.
    5. If the size of the last substring can evenly divide the last element in the KMP array, a repeated substring exists.
*/

// SOLUTION 2:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // Next character pointer
        int next = 1;
        // Previous character pointer
        int prev = 0;
        int n = s.size();
        // Initialize KMP array
        vector<int> KMP(n, 0);
        // Build the KMP array using the input string
        while(next < n) {
            if(s[next] == s[prev]) {
                KMP[next] = prev + 1;
                next++;
                prev++;
            }
            else if(prev != 0) {
                prev = KMP[prev - 1];
            }
            else {
                next++;
            }
        }
        int KMP_size = KMP.size() - 1;
        // If the last index is zero, a repeated substring does not exist
        if(KMP[KMP_size] == 0) {
            return false;
        }
        // Get the size of the last substring
        int lastSubstring = n - KMP[KMP_size];
        // If the size of the last substring can evenly divide the last element in the KMP array, a repeated substring exists
        if(KMP[KMP_size] % lastSubstring == 0) {
            return true;
        }
        return false;
    }
};
