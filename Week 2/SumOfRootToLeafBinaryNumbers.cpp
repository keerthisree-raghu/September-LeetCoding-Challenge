// SUM OF ROOT TO LEAF BINARY NUMBERS

/*  PROBLEM:
    Given a binary tree, each node has value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
    For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
    Return the sum of these numbers.
*/

/*  EXAMPLE:

    Input: [1,0,1,0,1,0,1]
         1
       /   \
      0     1
     / \   / \
    0   1 0   1
    Output: 22
    Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
*/

/*  APPROACH: Recursive Preorder DFS - O(n)
    1. Initialize a global variable to keep track of the total sum.
    2. Begin the DFS traversal at the root node, with an initial local sum of 0.
    3. Calculate the local sum at each level of the subtree by shifting the current number to the left and adding the next number.
    4. Calculate the global sum by adding it to the current sum.
    5. Perform preorder traversal for the left subtree.
    6. Perform preorder traversal for the right subtree.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Tree definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Keep track of the total sum
    int sum = 0;
    // DFS Preorder Traversal Helper Function
    void PreorderDFS(TreeNode* root, int currentNum) {
        if(root) {
            // Local sum at each level can be calculated by shifting the current number to the left and adding the next digit
            currentNum = (currentNum << 1) | root->val;
            // Calculate the global sum
            if(root->left == NULL && root->right == NULL) {
                sum += currentNum;
            }
            // Continue preorder traversal for left subtree
            PreorderDFS(root->left, currentNum);
            // Continue preorder traversal for right subtree
            PreorderDFS(root->right, currentNum);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        // Begin the DFS traversal at the root node with an initial sum value of 0
        PreorderDFS(root, 0);
        return sum;
    }
};
