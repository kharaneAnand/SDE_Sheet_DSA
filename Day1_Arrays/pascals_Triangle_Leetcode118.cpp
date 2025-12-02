/* genarate the  pascals Triangles for the given numRows  */
// Constraints: 1 <= numRows <= 30 ;

#include<bits/stdc++.h>
using namespace std ;

class solution {
    public :
     vector<vector<int>>generate(int numRows){

         vector<vector<int>>mat(numRows) ;
         // edge case 
         if (numRows == 0) return mat;

         // first element of the triangle is always 1 ;
         mat[0].push_back(1) ;


        // for other rows greater than 1 ;
         for(int i = 1 ; i<numRows ; i++){

            //first element is always 1 ;
            mat[i].push_back(1);

            //middle elements 
            for(int j=1 ; j<i ; j++){
                mat[i].push_back(mat[i-1][j-1] + mat[i-1][j]) ;
            }

            // last ele is always 1 
            mat[i].push_back(1) ;
         }
         return mat ;
     }
};

int main(){
    int numRows ;
    cout<<"Enter the NumRows :- " ;
    cin>>numRows ;

    solution sol ;
    vector<vector<int>>res = sol.generate(numRows) ;

    for(int i=0 ; i<res.size() ; i++){
        for(int j=0 ; j<res[i].size() ; j++){
            cout<<res[i][j]<<" " ;
        }
        cout<<endl ;
    }
    return 0 ;
}