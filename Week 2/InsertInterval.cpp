// INSERT INTERVAL

/*  PROBLEM:
    Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
    You may assume that the intervals were initially sorted according to their start times.
*/

/*  EXAMPLES:

    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]

    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

/*  APPROACH: Iterative - O(n)
    1. Check if there are intervals which exist before the new interval, with no overlap and add them to the resultant vector.
    2. Check if there are intervals which exist after the new interval, with no overlap, and add them to the resultant vector.
    3. If an intersection is encountered and the two intervals must be merged
        a. Compare the upperbound of the current interval with the lowerbound of the new interval.
        b. Compare the lowerbound of the current interval with the upperbound of the new interval.
    4. To find the upperbound and lowerbound of the new interval
        a. Lower-bound is the minimum value between the lower-bound of the new interval and the current interval.
        b. Upper-bound is the minimum value between the upper-bound of the new interval and the current interval.
    5. Iterate through the resultant array and construct the intervals in the correct order.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++) {
            // If there are intervals before the new interval (no intersection), add them to the resultant vector
            if(intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            }
            // If there are intervals after the new interval (no intersection), add them to the resultant vector
            if(intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            }
            // When there is an intersection, and the intervals must be merged, compare the upperbound and lowerbound values
            if(intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1]) {
                // Calculate new upperbound and lowerbound of new interval
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        // Store the current size of the resultant vector
        int n = res.size();
        // Construct the new intervals in the correct order
        for(int i = 0; i < res.size(); i++) {
            if(res[i][0] > newInterval[1]) {
                res.insert(res.begin() + i, newInterval);
                break;
            }
        }
        if(res.size() == n) {
            res.push_back(newInterval);
        }
        return res;
    }
};
