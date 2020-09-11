// BULLS AND COWS

/*  PROBLEM:
    You are playing the following Bulls and Cows game with your friend: You write down a number and ask your 
    friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates 
    how many digits in said guess match your secret number exactly in both digit and position (called "bulls") 
    and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend 
    will use successive guesses and hints to eventually derive the secret number.

    Write a function to return a hint according to the secret number and friend's guess, use A to indicate the 
    bulls and B to indicate the cows. 

    Please note that both secret number and friend's guess may contain duplicate digits.

    Note: 
    You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/

/*  EXAMPLES:

    Input: secret = "1807", guess = "7810"
    Output: "1A3B"
    Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.

    Input: secret = "1123", guess = "0111"
    Output: "1A1B"
    Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
*/

/*  APPROACH: Iterative - O(n)
    1. Initialize two vectors to count the occurrences of each number in the secret string and guess string.
    2. Iterate through both strings and if the exact positions of the characters match in both strings, increment the value of bulls.
    3. Increment the count of each encountered number.
    4. Initialize a variable cow = -bull to compensate for the repeating characters counted by the bulls variable already.
    5. Iterate through every possible number and check if it has occurred in either of the strings.
    6. Accumulate the value of cows by adding the minimum count of the number occurring at each index position.
    7. Construct the return string in the format specified.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secret_count(10, 0), guess_count(10, 0);
        int bulls = 0;
        for(int i = 0; i < secret.size(); i++) {
            // If the exact position of the characters match in both strings, increment bulls
            if(secret[i] == guess[i]) {
                bulls++;
            }
            // Count the occurrences of each number in both strings
            secret_count[secret[i] - '0']++;
            guess_count[guess[i] - '0']++;
        }
        // Initialize cows = -bulls to compensate for repeating characters from bulls count
        int cows = -bulls;
        // Calculate the number of common characters in both strings
        for(int i = 0; i < 10; i++) {
            cows += min(secret_count[i], guess_count[i]);
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
