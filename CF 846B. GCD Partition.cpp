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
    	int n;

    	cin>>n ;
    	vector<ll>a(n+1,0) , pref(n+1,0);

    	for(int i=1; i<=n ; i++){
    		cin>>a[i] ;
    	}

    	for(int i=1 ; i<=n ; i++){
    		pref[i]=pref[i-1]+a[i] ;
    	}

    	

    	ll ans= -1 ;

    	for(int i=1 ; i<n ;i++){
    		ll f = pref[i]-pref[0];
    		ll l = pref[n] - pref[i] ;

    		ll gcd = __gcd(f,l) ;
    		ans = max(ans ,gcd );
    	}

    	cout<<ans<<endl;
        
    }
    return 0 ;
}
