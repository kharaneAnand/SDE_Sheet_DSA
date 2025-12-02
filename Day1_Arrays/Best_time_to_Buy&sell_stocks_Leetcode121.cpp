/* Best Time to Buy and Sell Stock : -
            
        Leetcode 121 :- Best Time to Buy and sell Stocks 

Q) You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> nextmx(n);
        int i = n - 1;
        nextmx[i] = 0;
        i--;
        int mx = prices[n - 1];

        while (i >= 0) {       
            nextmx[i] = mx;
            mx = max(mx, prices[i]);
            i--;
        }

        mx = 0;
        for (int i = 0; i < prices.size(); i++) {
            int a = nextmx[i] - prices[i];
            mx = max(mx, a);
        }
        return mx;
    }
};


int main(){
    int n;
    cin>>n ;

    vector<int>prices(n) ;
    for(int i=0 ; i<n ; i++){
        cin>>prices[i] ;
    }

    Solution sol ;
    cout<<sol.maxProfit(prices) ; 

    return  ;
}