#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        int n ;

        cin>>n ;

        int  arr[n] ;

        for(int i=0 ; i<n ; i++){
        	cin>>arr[i] ;
        }

        sort(arr, arr+n) ;

        int b[n] ; ll sum=0 ;

        b[0]=1 ;

        for(int i=1 ; i<n ; i++){

            b[i]=min(b[i-1]+1 , arr[i]) ;
        }

        for(int i=0 ; i<n ; i++){

            sum+=arr[i]-b[i] ;
            
        }

        cout<<sum<<endl;
    }
    return 0 ;
}
