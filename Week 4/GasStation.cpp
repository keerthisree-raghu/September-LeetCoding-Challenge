// GAS STATION

/*  PROBLEM:
    There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
    its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
    Return the starting gas station's index if you can travel around the circuit once in the clockwise 
    direction, otherwise return -1.
    
    Note:
    If there exists a solution, it is guaranteed to be unique.
    Both input arrays are non-empty and have the same length.
    Each element in the input arrays is a non-negative integer.
*/

/*  EXAMPLES:

    Input: gas  = [1,2,3,4,5], cost = [3,4,5,1,2]
    Output: 3
    Explanation:
    Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
    Travel to station 4. Your tank = 4 - 1 + 5 = 8
    Travel to station 0. Your tank = 8 - 2 + 1 = 7
    Travel to station 1. Your tank = 7 - 3 + 2 = 6
    Travel to station 2. Your tank = 6 - 4 + 3 = 5
    Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
    Therefore, return 3 as the starting index.
    
    Input: gas  = [2,3,4], cost = [3,4,3]
    Output: -1
    Explanation:
    You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
    Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
    Travel to station 0. Your tank = 4 - 3 + 2 = 3
    Travel to station 1. Your tank = 3 - 3 + 3 = 3
    You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
    Therefore, you can't travel around the circuit once no matter where you start.
*/

/*  APPROACH: One-Pass Iterative - O(n)
    1. Initialize three variables to store the total gas value, minimum gas value, and start index.
    2. Traverse through the arrays and calculate the total gas value at each station.
    3. If the current total gas value is smaller than the current minimum gas value
        a. Update the minimum gas value.
        b. Calculate the index value for the start of the circuit to start at the station with the minimum gas value.
    4. If the remaining total gas value after the completion of a full circuit is negative, a full circuit cannot be completed without running out of gas.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), startIndex = 0;
        int totalGas = 0, minimumGas = INT_MAX;
        // Calculate the value of the total gas that is being carried when entering each station
        for(int i = 0; i < n; i++) {
            totalGas += gas[i] - cost[i];
            // Update minimum gas value
            if(totalGas < minimumGas) {
                // Set the minimum gas amount as the minimum value between minimumGas and totalGas 
                minimumGas = totalGas;
                // Re-calculate the starting index value for the circuit
                startIndex = (i + 1) % n;
            }
        }
        // If the remaining gas after a full circuit is negative, making the circuit without running out of gas is impossible
        return totalGas < 0 ? -1 : startIndex;
    }
};
