Function to find Number of customers who could not get a computer

Write a function “runCustomerSimulation” that takes following two inputs
a) An integer ‘n’: total number of computers in a cafe and a string:
b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer.

A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times.
Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.

For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.

runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0

runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer

LOGIC:

1) Initialize result as 0.

2) Traverse the given sequence. While traversing, keep track of occupied computers (this can be done by keeping track of characters which have appeared only once and a computer was available when they appeared). At any point, if count of occupied computers is equal to ‘n’, and there is a new customer, increment result by 1.

The important thing is to keep track of existing customers in cafe in a way that can indicate whether the customer has got a computer or not. Note that in sequence “ABCBCADEED”, customer ‘B’ did not get a seat, but still in cafe as a new customer ‘C’ is next in sequence

int runCustomerSimulation(int n, const char *seq)
{
    // seen[i] = 0, indicates that customer 'i' is not in cafe
    // seen[i] = 1, indicates that customer 'i' is in cafe but
    //              computer is not assigned yet.
    // seen[i] = 2, indicates that customer 'i' is in cafe and
    //              has occupied a computer.
    char seen[MAX_CHAR] = {0};
  
    // Initialize result which is number of customers who could
    // not get any computer.
    int res = 0;
  
    int occupied = 0;  // To keep track of occupied computers
  
    // Traverse the input sequence
    for (int i=0; seq[i]; i++)
    {
        					// Find index of current character in seen[0...25]
        int ind = seq[i] - 'A';
  
       					 // If First occurrence of 'seq[i]'
        if (seen[ind] == 0)
        {
            				// set the current character as seen
            seen[ind] = 1;
  
           					 // If number of occupied computers is less than
            					// n, then assign a computer to new customer
            if (occupied < n)
            {
                occupied++;
  
                // Set the current character as occupying a computer
                seen[ind] = 2;
            }
  
           			 // Else this customer cannot get a computer,
            			// increment result
            else
                res++;
        }
  
       				 // If this is second occurrence of 'seq[i]'
        else
        {
           			// Decrement occupied only if this customer
           			// was using a computer
           if (seen[ind] == 2)
               occupied--;
           seen[ind] = 0;
        }
    }
    return res;
}
  