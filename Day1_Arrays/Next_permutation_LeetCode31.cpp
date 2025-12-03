/*      
                31. NEXT PERMUTATION 

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

*/

#include<bits/stdc++.h>
using namespace std ;


class Solution {
    public :
    void nextPermutation(vector<int>&nums){
        int n = nums.size() ;

        //step 01 :- find the pivot of the nums array ;
        int i = n-2 ;
        while(i>= 0 && nums[i] > nums[i+1]) i-- ;

        // step 02 :- find the larger ele in the right half plan and swap with it 
         if(i>= 0){
            int j = n-1 ;
            while(nums[i] >= nums[j]) j-- ;
            swap(nums[i] , nums[j]) ;
        }

        // step 03 :- reverse the suffix 
        reverse(nums.begin()+i+1 , nums.end()) ;
        return ;
    }
};

int main(){
    int n ;
    cout<<"Enter the size of the Array :- " ;
    cin>>n ;

    vector<int>nums(n) ;
    cout<<"Enter the elements in the array :- " ;
    for(int i=0 ; i<n ; i++){
        cin>>nums[i] ;
    }

    Solution sol ;
    sol.nextPermutation(nums) ;

    for(int i=0 ; i<n ; i++){
        cout<<nums[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}