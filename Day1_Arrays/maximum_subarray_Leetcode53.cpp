/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
                    Kadens Algorithm 
*/

#include<iostream>
#include<vector>
using namespace std ;


// kadens Algorithm 
class Solution{
    public :
    int maxSubArray(vector<int>&nums){
        int n = nums.size() ;
        int currentsum = nums[0];
        int maxsum = nums[0] ;

        for(int i=1 ; i<n ; i++){
            currentsum = max(nums[i] , currentsum+nums[i]) ;
            maxsum = max(maxsum , currentsum) ;
        }
        return maxsum ;
    }
};

int main(){
    int n ;
    cout<<"Enter the size of the Array :- " ;
    cin>>n ;

    vector<int>nums(n) ;
    for(int i=0 ; i<n ; i++){
        cin>>nums[i] ;
    }

    Solution sol ;
    cout<<sol.maxSubArray(nums) ;
    return 0 ;
}