// LENGTH OF LAST WORD

/*  PROBLEM:
    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the 
    length of last word (last word means the last appearing word if we loop from left to right) in the 
    string. If the last word does not exist, return 0.

    Note: 
    A word is defined as a maximal substring consisting of non-space characters only.
*/

/*  EXAMPLE:

    Input: "Hello World"
    Output: 5
*/

/*  APPROACH: Iterative - O(n)
    1. Traverse through the string from right to left.
    2. If a space is encountered and the length of the word so far is greater than 0, this means that the last word has already been encountered, so break.
    3. If a space is encountered and the length of the word so far is 0, then a word has not been encountered, so continue.
    4. Otherwise, increment the length for each non-space character occurrence until the next space is encountered.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        // Iterate through every letter in the string from right to left
        for(int i = s.length() - 1; i >= 0; i--) {
            // Space is encountered but the length is > 0 since a word was previously encountered
            // Last word has been found
            if(s[i] == ' ' && length != 0) {
                break;
            }
            // Space is encountered but the length is 0
            else if(s[i] == ' ') {
                continue;
            }
            // Increment the length for each non-space character until the next space is encountered
            else {
                length++;
            }
        }
        return length;
    }
};
