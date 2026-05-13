#include<bits/stdc++.h>
using namespace std ;


int bin_search(int arr[] , int size_arr, int value){

    int right = size_arr-1 ;

    int left= 0 ;

    while(right-left>1){

        int mid= (left +right)/2 ;


        if(arr[mid]==value){

            return mid ;
        }else if(arr[mid]<value){

            left = mid +1 ;
        }else{

            right = mid- 1 ;
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;


    int n ;

    cin>> n  ;

    int arr[n] ;

    for(int i=0 ; i<n ; i++){
        cin>>arr[i] ;
    }

    int ser ;

    cin>>ser ;

    int res = bin_search(arr , n ,ser) ;

    cout<<res+1<<endl;

    return 0 ;
}
