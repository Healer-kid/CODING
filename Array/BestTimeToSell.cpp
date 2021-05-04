 Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.





METHOD -1
BRUTE FORCE
TIME:O(N^2)

IDEA:
find two elements with maximum difference provided that the first element should be smaller.



  int maxprofit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }


METHOD -2
USING KADANE (maximum subarray)
LOGIC:
 --> calculate the difference (maxCur += prices[i] - prices[i-1]) of the original array, and find a contiguous subarray giving maximum profit. If the difference falls below 0, reset it to zero.
--> By reseting maxCur to 0, essentially it means that we have found a point i where the price[i] is lower than the time we bought, and that we should then try to buy at point i to see if we can achieve a bigger gain. Because maxCur is recording the difference, the difference between price[i] and itself should be 0.


WHY KADANE( MAX SUBARRAY ) FOR THIS PROBLEM?


*maxCur = current maximum value
*maxSoFar = maximum value found so far

A more clear explanation on why sum of subarray works.:

Suppose we have original array:
[a0, a1, a2, a3, a4, a5, a6]

what we are given here(or we calculate ourselves) is:
[b0, b1, b2, b3, b4, b5, b6]

where,
b[i] = 0, when i == 0
b[i] = a[i] - a[i - 1], when i != 0

suppose if a2 and a6 are the points that give us the max difference (a2 < a6)
then in our given array, we need to find the sum of sub array from b3 to b6.

b3 = a3 - a2
b4 = a4 - a3
b5 = a5 - a4
b6 = a6 - a5

adding all these, all the middle terms will cancel out except two
i.e.

b3 + b4 + b5 + b6 = a6 - a2

a6 - a2 is the required solution.

so we need to find the largest sub array sum to get the most profit




int maxProfit(vector<int>& prices) {
        int globmax=0,localmax=0;
         for (int i = 1; i < prices.size(); i++) {
            localmax=max(0,localmax+=prices[i]-prices[i-1]);
             globmax=max(globmax,localmax);
        }
        return globmax;
    }
