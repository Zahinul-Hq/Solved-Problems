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

    	vector<ll>l(n,0) ,r(n,0) ;


    	for(int i=0 ;i<n ; i++){
    		cin>>l[i]>>r[i] ;
    	}

    	 ll lo = 0 , hi = 1e9 ;

    	while(lo<hi){

    		ll mid = (lo+hi)/2 ;

    		ll lk = 0 , rk = mid , f=0 ;

    		for(int i=0 ; i<n ; i++){
    			if(rk<l[i] || lk>r[i]){
    				f=1;
    				break ;
    			}

    			lk = max(lk , l[i]);
    			rk = min(rk , r[i]) ;

    			lk = max(0LL , lk-mid) ;
    			rk+=mid ;
    		}

    		if(!f)
    			hi=mid;
    		else
    			lo=mid+1;
    	}


    	cout<<hi<<endl;
    }
    return 0 ;
}
