// WORD PATTERN

/*  PROBLEM:
    Given a pattern and a string str, find if str follows the same pattern.

    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

    Note:
    You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

/*  EXAMPLES:

    Input: pattern = "abba", str = "dog cat cat dog"
    Output: true

    Input:pattern = "abba", str = "dog cat cat fish"
    Output: false

    Input: pattern = "aaaa", str = "dog cat cat dog"
    Output: false

    Input: pattern = "abba", str = "dog dog dog dog"
    Output: false
*/

/*  APPROACH: Two Hash Maps - O(n)
    1. Initialize a hash map to store a character-word pair and another hash map to store a word-character pair.
    2. If the pattern string is not empty, iteratively get each word from the input string and store it in a variable.
    3. Check the character map to see if the pattern character key exists and matches the corresponding word value.
    4. Check the word map to see if the word key exists and matches the corresponding pattern character value.
    5. If the character or word has not been encountered before, add them to their respective hash maps.
    6. If the characters in the pattern string match the corresponding values of words from the input string, return true.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> char_map;
        unordered_map<string, char> word_map;
        int pattern_len = pattern.size(), str_len = str.size();
        int i = 0, j = 0;
        string word = "";
        while(i < pattern_len) {
            // Input string is empty
            if(j > str_len) {
                return false;
            }
            // Get each word from the input string and store it in a variable
            while(str[j] != ' ' && str[j] != '\0') {
                word += str[j++];
            }
            // Check if a pattern-word pair matches
            if(char_map.find(pattern[i]) != char_map.end() && char_map[pattern[i]] != word) {
                return false;
            }
            // Check if the word-patten pair matches
            if(word_map.find(word) != word_map.end() && word_map[word] != pattern[i]) {
                return false;
            }
            // Map each unseen pattern character to an unseen word
            char_map[pattern[i]] = word;
            // Map each unseen word to an unseen pattern character
            word_map[word] = pattern[i];
            i++;
            j++;
            // Reset the variable to store the words
            word = "";
        }
        // Pattern string is empty
        if(j <= str_len) {
            return false;
        }
        return true;
    }
};
