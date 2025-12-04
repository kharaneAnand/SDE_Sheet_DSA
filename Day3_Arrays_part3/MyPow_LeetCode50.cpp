/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

#include<iostream>
#include<math.h>
using namespace std ;


class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1;
        if(n < 0) return 1 / myPow(x, -n);

        if(n % 2 == 0) 
            return myPow(x * x, n / 2);
        else 
            return x * myPow(x * x, n / 2);
    }
};

int main(){
    double x ;
    cin>>x ;

    long long n ;
    cin>>n ;

    Solution sol ;
   cout<<sol.myPow(x , n) ;
   return 0 ;
}
