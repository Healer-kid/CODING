Maximum profit by buying and selling a share at most twice

In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

Examples: 

Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80


LOGIC:
-->maintain a profit array which holds the profit at any point i
-->lets do two traversal,one from left and other from right
-->for right 
	-->maintain a max element and find the profit 
-->for left
	-->maintain a min element and find the profit
	--> add the profit of the previous traversal (since twice we have to buy and sell)


{
int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;
 
    
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
       
        if (price[i] > max_price)
            max_price = price[i];
 
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }
 
    
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
       
        if (price[i] < min_price)
            min_price = price[i];
 
        
        profit[i] = max(profit[i - 1],profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];
 	return result;
}












METHOD-2
METHOD:VALLEY PEAK
TIME :O(n) ,SPACE:O(1)

NOTE: IT DOESNT WORK FOR ALL CASES 
FOR EG) 2,4,2,6,2,3 (HERE IT WILL GIVE THE ANSWER WITHH 3 TRANSACTION)

int profit = 0;
   
    // Initializing variable
    // valley-peak approach
    /*
                       80
                       /
        30            /
       /  \          25
      /    15       /
     /      \      /
    2        10   /
               \ /
                8
     */
    for (int i = 1; i < n; i++)
    {
       
        // traversing through array from (i+1)th
        // position
        int sub = price[i] - price[i - 1];
        if (sub > 0)
            profit += sub;
    }
 