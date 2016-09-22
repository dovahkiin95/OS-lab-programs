#include <stdio.h>
struct Interval{
//This structure to store results in local mim and max
 int buy;
 int sell;
};
 
void stockBuySell(int price[], int n)
{
 if (n < 1)
 return;
 
 int countSol = 0; 
 //count of total solutions
 
 Interval solution[n/2 + 1]; //sol
 // solution vector
 int i = 0;
 while (i < n-1)
 {
 // Find Local Minima.
 while ((i < n-1) && (price[i+1] <= price[i]))
 i++;
 
 // If we reached the end, break as no further solution possible
 if (i == n-1)
 break;
 
 // Store the index of minima
 solution[countSol].buy = i++;
 
 // Find Local Maxima.
 while ((i < n) && (price[i] >= price[i-1]))
 i++;
 
 // Store the index of maxima
 solution[countSol].sell = i-1;
 
 // Increment count of buy/sell pairs
 countSol++;
 }
 
 int totalProfit=0;
 //Calculate total Profit
 
 if (countSol == 0)
 printf("Sorry NO Profit Possibe\n");
 else
 {
 for (int i = 0; i < countSol; i++){
 totalProfit += price[solution[i].sell]-price[solution[i].buy];
 printf("Buy on day: %d\t Sell on day: %d Profit %d : \n", solution[i].buy, solution[i].sell, price[solution[i].sell]-price[solution[i].buy] );
 }
 printf("Total Profit %d",totalProfit);
 }
 
 return;
}
int main()
{
 int price[] = {2, 9, 10, 50, 47, 500, 100000};
 int n = sizeof(price)/sizeof(price[0]);
 stockBuySell(price, n);
 return 0;
}
