// SEQUENTIAL DIGITS

/*  PROBLEM:
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
*/

/*  EXAMPLES:

    Input: low = 100, high = 300
    Output: [123,234]

    Input: low = 1000, high = 13000
    Output: [1234,2345,3456,4567,5678,6789,12345]
*/

/*  APPROACH: Breadth-First-Search - O(log n)
    1. Initialize a queue with digits from 1 to 9.
    2. Initialize a vector to store the resultant values.
    3. Remove and process the first value from the queue in each iteration.
    4. If the value is between the given lower-bound and upper-bound values, add it to the resultant vector.
    5. Construct a sequential value using the current value removed from the queue as the first digit.
    6. Push the new value into the queue.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        // Queue of sequential numbers
        for(int i = 1; i <= 9; i++) {
            q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            // Evaluate each number in the queue in order
            int val = q.front();
            q.pop();
            // Check upper and lower bounds
            if(val >= low && val <= high) {
                // Add the value to the resultant vector
                res.push_back(val);
            }
            // Add the next sequentially constructed value to the queue
            int num = val % 10;
            if(num < 9) {
                q.push(val * 10 + (num + 1));
            }
        }
        return res;
    }
};
