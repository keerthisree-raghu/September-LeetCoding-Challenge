// WORD BREAK

/*  PROBLEM:
    Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

    Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.
*/

/*  EXAMPLES:

    Input: s = "leetcode", wordDict = ["leet", "code"]
    Output: true
    Explanation: Return true because "leetcode" can be segmented as "leet code".

    Input: s = "applepenapple", wordDict = ["apple", "pen"]
    Output: true
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
                Note that you are allowed to reuse a dictionary word.

    Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output: false
*/

/*  APPROACH: Dynamic Programming - O(n^2)
    1. Initialize an unordered set to extract the unique words from the input word dictionary.
    2. Initialize a boolean vector to check if a valid word exists or not.
    3. If a valid word ends at index i, set dp[i] as true.
    4. For each index position i, look back at each character from the previous position till the beginning of the string.
    5. If dp[j] is true and a substring is found in the dictionary, set dp[i] as true and break.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j] == true && words.find(s.substr(j, i - j)) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
