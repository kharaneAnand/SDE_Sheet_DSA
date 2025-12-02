/* question is :- find the zeros and then convert row and coloumn of that zeros to zero  */
#include<bits/stdc++.h>
using namespace std ;


class solution {
    public :
    void setZeros(vector<vector<int>>&matrix){
        int m = matrix.size() ;
        int n = matrix[0].size() ;


// step 01 :- finding the position of the zeros ;

        set<pair<int , int >>s ;
        for(int i=0 ; i<m ; i++){
            for (int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0 ){
                    s.insert({i , j}) ;
                }
            }
        }

// step 02 :- converting the rows and coloumns of the zeros to zero ;
        for(auto ele : s){
            int row = ele.first ;
            int col = ele.second ;

            for(int i=0 ; i<m ; i++){
                matrix[i][col] = 0 ;
            }
            for(int j=0 ; j<n ; j++){
                matrix[row][j] = 0 ;
            }
        }
         return ;
    }
};

int main (){
    int rows , cols ;
    cout<<"Enter the number of rows " << endl;
    cin>>rows ;

    cout<<"Enter the number of cols"<<endl ;
    cin>>cols ;

    vector<vector<int>>mat(rows , vector<int>(cols)) ;
    cout<<"Enter the elements of the matrix "<< endl;

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            cin>>mat[i][j] ;
        }
    }
    solution obj ;
    obj.setZeros(mat) ;
    cout<<"The modified matrix is "<< endl;
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){    
            cout<<mat[i][j] <<" " ;
        }
        cout<<endl ;    
    }
    return 0 ;
}   

// time complexity is O(m*n) ;
// space complexity is O(k) where k is the number of zeros in the matrix ;
