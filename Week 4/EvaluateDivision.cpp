// EVALUATE DIVISION

/*  PROBLEM:
    You are given equations in the format A / B = k, where A and B are variables represented as strings, 
    and k is a real number (floating-point number). Given some queries, return the answers. If the answer 
    does not exist, return -1.0.

    The input is always valid. You may assume that evaluating the queries will result in no division by 
    zero and there is no contradiction.
*/

/*  EXAMPLES:

    Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
    Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
    Explanation: 
    Given: a / b = 2.0, b / c = 3.0
    queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
    return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

    Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
    Output: [3.75000,0.40000,5.00000,0.20000]

    Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
    Output: [0.50000,2.00000,-1.00000,-1.00000]
*/

/*  APPROACH: Depth-First-Search - O(V + E)
    1. Construct an adjacency matrix for an equation "a / b = x", such that there are two edges formed: a->b and b->a, corresponding to the values x and 1/x, respectively.
    2. Iterate through each query and call a DFS function on the current node and target node being the first and second values in the query, respectively.
    3. If a path is found between the current node and target node, multiply the values along the path to get the result.
    4. If no path is found, return -1.0.

    Reference: https://leetcode.com/problems/evaluate-division/discuss/455817/C++-DFS-solution
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // DFS Helper Function
    bool DFS(string currentNode, string targetNode, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited, double& val) {
        // The node is not found in the graph
        if(!adj.count(currentNode) || !adj.count(targetNode)) {
            return false;
        }
        // The required value has been found in the graph
        else if(currentNode == targetNode) {
            return true;
        }
        // Continue searching the graph
        else {
            // Mark as visited
            visited.insert(currentNode);
            for(auto node : adj[currentNode]) {
                if(!visited.count(node.first)) {
                    double lastVal = val;
                    // Multiply the values along the path
                    val *= node.second;
                    if(DFS(node.first, targetNode, adj, visited, val)) {
                        return true;
                    }
                    val = lastVal;
                }
            }
            // No path found
            return false;
        }
    }
    // Calculate equation
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        // Construct adjacency matrix for the graph
        for(int i = 0; i < equations.size(); i++) {
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            double result = values[i];
            // Adjacency matrix for numerator
            if(!adj.count(numerator)) {
                adj[numerator] = vector<pair<string, double>>();
            }
            adj[numerator].push_back(make_pair(denominator, result));
            // Adjacency matrix for denominator
            if(!adj.count(denominator)) {
                adj[denominator] = vector<pair<string, double>>();
            }
            adj[denominator].push_back(make_pair(numerator, 1.0 / result));
        }
        vector<double> res;
        // Process each query through DFS
        for(auto q : queries) {
            unordered_set<string> visited;
            double val = 1.0;
            // Result is found
            if(DFS(q[0], q[1], adj, visited, val)) {
                res.push_back(val);
            }
            // Result is not found
            else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
