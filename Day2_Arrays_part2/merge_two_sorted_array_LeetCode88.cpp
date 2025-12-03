/*                  88 . Merge Sorted Array 

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/


#include<iostream>
#include<vector>
using namespace std ;

class Solution {
    public:
    void merge(vector<int>&nums1 , int m , vector<int>&nums2 , int n){
        int i=m-1 ;
        int j=n-1 ;
        int k=n+m-1 ;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--] ;
            else nums1[k--]=nums2[j--];
        }

        // remaining elements in the nums2 ;
        while(j>=0){
            nums1[k--] = nums2[j--] ;
        }
        return ;
    }
};

int main(){
    int m , n ;
    cout<<"Enter the  size of the nums1 :- " ;
    cin>>m ;
    cout<<"Enter the size of  the nums2:- " ;
    cin>>n ;
    
    vector<int>nums1(n+m , 0) ;
    for(int i=0 ; i<m ; i++){
        int x ;
        cin>>x ;
        nums1[i] = x ;
    }

    vector<int>nums2(n);
    for(int i=0 ; i<n ; i++){
        cin>>nums2[i] ;
    }

    Solution sol ;
    sol.merge(nums1 , m , nums2 , n) ;

    for(int i=0 ; i<m+n ; i++){
        cout<<nums1[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}