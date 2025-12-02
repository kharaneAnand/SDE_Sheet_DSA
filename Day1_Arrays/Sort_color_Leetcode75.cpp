    /*Sort the color :- sort 0,1,2*/

    #include<bits/stdc++.h>
    using namespace std ;

    // first method :- by taraking the count easy approch 
    class solutionOne{
        public :
        void sortColor(vector<int>&nums){
            int zeros = 0 ;
            int once = 0 ;
            

            for(int i=0 ; i<nums.size() ; i++){
                if(nums[i]==0 ) zeros++ ;
                else if(nums[i]==1) once++ ;
            }

            for(int i=0 ; i<nums.size() ; i++){
                if(i<zeros) nums[i]=0 ;
                else if(i>=zeros && i<zeros+once) nums[i]= 1 ;
                else nums[i] = 2 ;
            }
        }
    };

    // second method :- Dutch-flag or 3 pointer approach 
    class solutionTwo{
        private:
            void swap(int &a , int &b){
                a = a+b ;
                b = a-b ;
                a = a-b ;
                return ;
            }
        public :
        void sortColor(vector<int>&nums){
            int lo=0 ;
            int hi =nums.size()-1;
            int mid = 0 ;

            while(mid<=hi){
                if(nums[mid]==0) {
                    swap(nums[lo] , nums[mid]) ;
                    mid++ ;
                    lo++ ;
                }
                else if(nums[mid] == 2){
                    swap(nums[mid] , nums[hi]) ;
                    hi-- ;
                }
                else mid++ ;
            }
            return ;
        }
    };

    int main(){
        int n ;
        cout<<"Enter the size of the Array :- " ;
        cin>>n ;

        vector<int>nums1(n) ;
        vector<int>nums2(n) ;
        for(int i=0 ; i<n ; i++){
            cin>>nums1[i] ;
        }

        for(int i=0 ; i<n ; i++){
            nums2[i] = nums1[i] ;
        }

        solutionOne sol ;
        sol.sortColor(nums1) ;

        solutionTwo s ;
        s.sortColor(nums2) ;

        for(int i=0 ; i<nums1.size() ; i++){
            cout<<nums1[i]<<" " ;
        }
        cout<<endl ;
        for(int  i=0 ; i<nums2.size() ; i++){
            cout<<nums2[i]<<" " ;
        }
        cout<<endl ;
        return 0 ;
    }
