// PARTITION LABELS

/*  PROBLEM:
    A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter 
    appears in at most one part, and return a list of integers representing the size of these parts.
*/

/*  EXAMPLE:

    Input: S = "ababcbacadefegdehijhklij"
    Output: [9,7,8]
    Explanation:
    The partition is "ababcbaca", "defegde", "hijhklij".
    This is a partition so that each letter appears in at most one part.
    A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/

/*  APPROACH: Two-Pass Greedy - O(n)
    1. Initialize a vector to store the lengths of the resultant partitions and another vector to store the last position of each character in the string.
    2. Iterate through the string and track the last position of each character. Update the position when a new occurrence of the character is encountered.
    3. Iterate through the string and track the maximum position seen so far for each character and update it whenever a new character is encountered.
    4. If all the letters in the current partition [j, anchor] occur only in the current partition, append the length of this partition to the result.
    5. Move the anchor to index (i + 1) to start the new partition.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res, last_pos(26, 0);
        int len = S.size();
        // Track the last position of each character
        for(int i = 0; i < len; i++) {
            last_pos[S[i] - 'a'] = i;
        }
        int j = 0, anchor = 0;
        for(int i = 0; i < len; i++) {
            // Store the maximum position seen so far for each character
            j = max(j, last_pos[S[i] - 'a']);
            // All the letters in the current partition [j, anchor] occur only in the current partition
            if(i == j) {
                // Append the length of the current partition to the result
                res.push_back(i - anchor + 1);
                // New partition starts at position (i + 1)
                anchor = i + 1;
            }
        }
        return res;
    }
};
