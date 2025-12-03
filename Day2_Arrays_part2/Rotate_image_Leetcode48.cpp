/*                  48 . Rotate Image / Rotate matrix 

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/
#include<bits/stdc++.h>
using namespace std ;


class Solution {
    public :
    void rotate( vector<vector<int>>&matrix){
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        // step 01 :- take a transpose of the matrix ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(j>i) {
                    swap(matrix[i][j] , matrix[j][i]) ;
                }
            }
        }

        //step 02 :- reverse the matrix columns only 
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<(n/2) ; j++){
                swap(matrix[i][j] , matrix[i][n-1-j]) ;
            }
        }
        return ;
    }
};

int main(){
    int row , col ;
    cout<<"Enter the number of the rows :- " ;
    cin>>row ;
    cout<<"Enter the number of the col :- " ;
    cin>>col ;

    vector<vector<int>>matrix(row , vector<int>(col)) ;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>matrix[i][j] ;
        }
    }

    Solution sol ;
    sol.rotate(matrix);
    cout<<endl<<"the Roted matrix is :- " ;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<matrix[i][j]<<" " ;
        }
        cout<<endl ;
    }

    return 0 ;
}