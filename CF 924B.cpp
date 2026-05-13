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
        int n , cnt=1;

        cin>>n ;

        vector<ll>a(n,0) ,diff;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i];
        }

        sort(a.begin() ,a.end()) ;


        ll hi = 1e9 + 1e9 , lo = 1 ;

        while(hi>=lo){

        	ll mid  = (hi + lo) /2 ;


        	ll mx = a[n-1]+n  , up=0 , dw=0 ;


        	for(int i=0 ; i<n ; i++){
        		if(mx<a[i]+mid){
        			up++ ;
        		}else if(a[i]+mid <mx){
        			dw++ ;
        		}
        	}

        	if(up>dw){
        		lo = mid+1 ;
        	}
        } 

       
       while


        cout<<ans<<endl; 
    }
    return 0 ;
}
