// ALL ELEMENTS IN TWO BINARY SEARCH TREES

/*  PROBLEM:
    Given two binary search trees root1 and root2.

    Return a list containing all the integers from both trees sorted in ascending order.
*/

/*  EXAMPLE:

        2       1
       / \     / \
      1   4   0   3
    Input: root1 = [2,1,4], root2 = [1,0,3]
    Output: [0,1,1,2,3,4]

    Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
    Output: [-10,0,0,1,2,5,7,10]

    Input: root1 = [], root2 = [5,1,7,0,2]
    Output: [0,1,2,5,7]

    Input: root1 = [0,-10,10], root2 = []
    Output: [-10,0,10]

        1       8
         \     / 
          8   1   
    Input: root1 = [1,null,8], root2 = [8,1]
    Output: [1,1,8,8]
*/

/*  APPROACH: Inorder Traversal and Merge Sort - O(n)
    1. Create a helper function to perform inorder traversal of the trees.
    2. Initialize two vectors to store the elements in each tree and one resultant vector.
    3. Perform inorder traversal for each tree and store the elements in their respective vectors.
    4. Merge and sort the elements in both arrays and push the sorted elements into the resultant vector.
    5. If elements remain in the first or second vector after the merge sort process, append it to the resultant vector.
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2, res;
        // Inorder traversal for tree1
        inorder(root1, tree1);
        // Inorder traversal for tree2
        inorder(root2, tree2);
        int i = 0, j = 0;
        // Merge and sort the elements in the tree1 array and tree2 array
        while(i < tree1.size() && j < tree2.size()) {
            tree1[i] < tree2[j] ? res.push_back(tree1[i++]) : res.push_back(tree2[j++]);
        }
        // If elements still remain in the first array, append it to the resultant array
        while(i < tree1.size()) {
            res.push_back(tree1[i++]);
        }
        // If elements still remain in the second array, append it to the resultant array
        while(j < tree2.size()) {
            res.push_back(tree2[j++]);
        }
        return res;
    }

    // Helper function for inorder traversal
    void inorder(TreeNode* root, vector<int> &elements) {
        if(!root) {
            return;
        }
        // Store the elements of the tree in an array
        inorder(root->left, elements);
        elements.push_back(root->val);
        inorder(root->right, elements);
    }
};
