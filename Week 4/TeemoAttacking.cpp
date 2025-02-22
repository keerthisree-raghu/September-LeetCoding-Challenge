// TEEMO ATTACKING

/*  PROBLEM:
    In LOL world, there is a hero called Teemo and his attacking can make his enemy Ashe be in poisoned 
    condition. Now, given the Teemo's attacking ascending time series towards Ashe and the poisoning 
    time duration per Teemo's attacking, you need to output the total time that Ashe is in poisoned condition.

    You may assume that Teemo attacks at the very beginning of a specific time point, and makes Ashe be 
    in poisoned condition immediately.
    
    Note:
    You may assume the length of given time series array won't exceed 10000.
    You may assume the numbers in the Teemo's attacking time series and his poisoning time duration per 
    attacking are non-negative integers, which won't exceed 10,000,000.
*/

/*  EXAMPLES:

    Input: [1,4], 2
    Output: 4
    Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately. 
    This poisoned status will last 2 seconds until the end of time point 2. 
    And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds. 
    So you finally need to output 4.
    
    Input: [1,2], 2
    Output: 3
    Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned. 
    This poisoned status will last 2 seconds until the end of time point 2. 
    However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status. 
    Since the poisoned status won't add up together, though the second poisoning attack will still work at time point 2, it will stop at the end of time point 3. 
    So you finally need to output 3.
*/

/*  APPROACH: One-Pass Iterative - O(n)
    1. Iterate through the first (n - 1) elements in the time series array.
    2. Find the cumulative duration by adding the minimum value between (next_element - current_element) and the duration.
    3. For the last element in the array, add the duration value to the current total duration value.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int totalDuration = 0;
        if(n == 0) {
            return 0;
        }
        // Accumulate the total duration while considering overlaps
        for(int i = 0; i < timeSeries.size() - 1; i++) {
            totalDuration += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        // Add the duration value for the last iteration
        return totalDuration + duration;
    }
};
