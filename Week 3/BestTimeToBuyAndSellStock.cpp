// BEST TIME TO BUY AND SELL STOCK

/*  PROBLEM:
    Say you have an array for which the ith element is the price of a given stock on day i.
    If you were only permitted to complete at most one transaction (i.e., buy one and sell 
    one share of the stock), design an algorithm to find the maximum profit.

    Note that you cannot sell a stock before you buy one.
*/

/*  EXAMPLES:

    Input: [7,1,5,3,6,4]
    Output: 5
    Explanation: 
    Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Not 7-1 = 6, as selling price needs to be larger than buying price.

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*  APPROACH: One-Pass Iterative - O(n)
    1. Initialize two variables to track the lowest price seen so far in the array and the maximum profit obtained.
    2. Iterate through each element in the array and find the lowest price in the array.
    3. In every iteration, update the maximum profit value if the difference between the current value and the minimum price is greater than the maximum profit so far.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // minPrice corresponds to the lowest price so far
        int minPrice = 99999;
        // maxprofit = selling price - minPrice
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            // Find the lowest price in the array
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Maximum profit can be obtained only from a value after the minimum price value index
            else if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            } 
        }
        return maxProfit;
    }
};
