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

   
    	int n , q ;

    	cin>>n>>q ;

    	int a[n] ;
    	vector<int>sum(n+1) ;

    	for(int i=0 ; i<n ; i++)
    		cin>>a[i] ;


    	int cnt = 1 ;

    	for(int i = 1 ; i<n-1 ; i++){

    		int  down = a[i-1]>=a[i] && a[i]>=a[i+1] ;
    		sum[i]=sum[i-1]+down ;

    	}

    	while(q--){

    		int l , r ;

    		cin>>l>>r ;

    		 r-- ;
    		 l-- ;

    		if(l==r)
    			cout<<1<<endl;
    		else{
    			
    			int ans = (r-l+1) - sum[r-1]+sum[l] ;
    			cout<<ans<<endl;
    		}
    	}

	return 0 ;
    	    
}


