// MAXIMUM XOR OF TWO NUMBERS IN AN ARRAY

/*  PROBLEM:
    Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

    Follow up: Could you do this in O(n) runtime?
    */

/*  EXAMPLE:

    Input: nums = [3,10,5,25,2,8]
    Output: 28
    Explanation: The maximum result is 5 XOR 25 = 28.

    Input: nums = [0]
    Output: 0

    Input: nums = [2,4]
    Output: 6

    Input: nums = [8,10,2]
    Output: 10

    Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
    Output: 127
*/

/*  APPROACH: 
    Constructing the Trie

    1. An integer can be converted into a bit string incrementally, with a maximum of 32 bits.
    2. Iteratively convert the decimal integer into its equivalent binary bit string representation from the most significant bit to the least significant bit.
    3. If the bit is 0, insert the bit into the left sub-trie and create a new trie node if one does not already exist.
    4. If the bit is 1, insert it into the right sub-trie and create a new trie node if one does not already exist.
    
    Calculate the Maximum XOR

    1. To get the maximum XOR value for a given bit, we must choose to investigate the branch with the opposite bit value at every iteration. This is because the XOR operation returns the value 1 only when the two bits being compared do not match.
    2. Iterate through every integer in the array.
    3. Iteratively convert each encountered decimal integer into its equivalent binary bit string representation from the most significant bit to the least significant bit.
    4. If the current bit is 0, check the right sub-trie to look for a 1 bit in the same position. 
        a. If the bit is found, calculate the cumulative XOR.
        b. If the bit is not found, check the right sub-trie.
    5. If the current bit is 1, check the left sub-trie to look for a 0 bit in the same position.
        a. If the bit is found, calculate the cumulative XOR.
        b. If the bit is not found, check the right sub-trie.
    6. Update the maximum XOR value using the obtained cumulative XOR value thus far.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Trie Definition
class trieNode{
public:
    trieNode* left;
    trieNode* right;
};

class Solution {
public:
    // Insert the bits into the trie from the most to least significant bit
    trieNode* constructTrie(int num, trieNode* head) {
        trieNode* currentNode = head;
        for(int i = 31; i >= 0; i--) {
            // Convert the decimal integer to binary
            int bit = (num >> i) & 1;
            // If the bit is 0, insert into the left subtrie
            if(bit == 0) {
                if(!currentNode->left) {
                    currentNode->left = new trieNode();
                }
                currentNode = currentNode->left;
            }
            // If the bit is 1, insert into the right subtrie
            else {
                if(!currentNode->right) {
                    currentNode->right = new trieNode();
                }
                currentNode = currentNode->right;
            }
        }
        return head;
    }
    // Calculate the maximum XOR value
    int calculateMaxXOR(trieNode* head, vector<int> nums) {
        int maxXOR = INT_MIN;
        // Iterate through every integer in the array
        for(int i = 0; i < nums.size(); i++) {
            trieNode* currentNode = head;
            int num = nums[i];
            int currentXOR = 0;
            // Iterate through every bit in the integer
            for(int j = 31; j >= 0; j--) {
                // Convert each decimal integer to binary 
                int bit = (num >> j) & 1;
                // The current bit is 0
                if(bit == 0) {
                    // Check the right subtrie to search for a 1 in that place to maximize the XOR value
                    // 0 ^ 1 = 1
                    if(currentNode->right) {
                        // Calculate the cumulative XOR value
                        currentXOR += pow(2, j);
                        currentNode = currentNode->right;
                    }
                    // Check the left subtrie if there are no more values in the right subtrie
                    else {
                        currentNode = currentNode->left;
                    }
                }
                // The current bit is 1
                else {
                    // Check the right subtrie to search for a 0 in that place to maximize the XOR value
                    // 1 ^ 0 = 1
                    if(currentNode->left) {
                        // Calculate the cumulative XOR value
                        currentXOR += pow(2, j);
                        currentNode = currentNode->left;
                    }
                    // Check the right subtrie if there are no more values in the left subtrie
                    else {
                        currentNode = currentNode->right;
                    }
                }
            }
            // Update the maximum XOR value
            maxXOR = max(maxXOR, currentXOR);
        }
        return maxXOR;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        trieNode* head = new trieNode();
        // Construct the trie
        for(int i = 0; i < nums.size(); i++) {
            head = constructTrie(nums[i], head);
        }
        // Calculate the maximum XOR value
        return calculateMaxXOR(head, nums);
    }
};
