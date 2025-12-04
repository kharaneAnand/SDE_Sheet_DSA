/*          78.search a element in the matrix 


You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include<iostream>
#include<vector>
using namespace std ;

class Solution{
    public :

    bool LinearSearch(vector<vector<int>>&matrix , int target){
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == target) return true ;
            }
        }
        return false ;
    }


    bool BinarySearch(vector<vector<int>>&matrix , int target){
         int m = matrix.size() ;
         int n = matrix[0].size() ;

         int l = 0 ;
         int r = m*n-1 ;

         while(l<=r){
            int mid = l + (r-l)/2 ;
            int val = matrix[mid/n][mid%n] ;

            if(val == target) return true ;
            else if(val < target) l = mid + 1 ;
            else r = mid - 1 ;
         }
         return false ;
    }
};

int main(){
    int m , n ;
    cout<<"Enter the number of rows :- " ;
    cin>>m; 
    cout<<"Enter the number of cols :- " ;
    cin>>n ;
    
    vector<vector<int>>matrix(m , vector<int>(n)) ;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>matrix[i][j] ;
        }
    }

    int target ;
    cout<<"Enter the Target :- " ;
    cin>>target ;

    Solution sol ;
    cout<<sol.LinearSearch(matrix ,target )<<endl ;
    cout<<sol.BinarySearch(matrix , target)<<endl ;


    return 0 ;
}