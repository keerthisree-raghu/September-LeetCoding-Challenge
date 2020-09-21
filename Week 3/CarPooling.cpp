// CAR POOLING

/*  PROBLEM:
    You are driving a vehicle that has capacity empty seats initially available for passengers.
    The vehicle only drives east (ie. it cannot turn around and drive west.)

    Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the 
    i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off. 
    The locations are given as the number of kilometers due east from your vehicle's initial location.

    Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 
*/

/*  EXAMPLES:

    Input: trips = [[2,1,5],[3,3,7]], capacity = 4
    Output: false

    Input: trips = [[2,1,5],[3,3,7]], capacity = 5
    Output: true

    Input: trips = [[2,1,5],[3,5,7]], capacity = 3
    Output: true

    Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
    Output: true
*/

/*  APPROACH: Bucket Sort - O(n)
    1. Initialize an array of size 1001, to represent 1001 buckets.
    2. Iterate through each trip and add the number of passengers in each stop to the corresponding buckets.
    3. Iterate through each stop to calculate the total number of occupied seats.
    4. If the total capacity has been exceeded, return false.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // There can only be 1001 stops
        int stops[1001] = {};
        // Process each trip
        for(auto trip : trips) {
            // Add passengers to the start location
            stops[trip[1]] += trip[0];
            // Remove passengers from the end location
            stops[trip[2]] -= trip[0];
        }
        int occupied = 0;
        // Calculate the total number of occupied seats
        for(auto passengers : stops) {
            occupied += passengers;
            // Exceeding maximum capacity
            if(occupied > capacity) {
                return false;
            }
        }
        // Within maximum capacity
        return true;
    }
};
