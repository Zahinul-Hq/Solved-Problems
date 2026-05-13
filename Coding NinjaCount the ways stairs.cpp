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

const int N = 1e5+7 ;

ll dp[N] ;

ll f(ll n ){

	if(n<0)
		return 0 ;
	if(n==0)
		return 1 ;

	if(dp[n]!=-1)
		return dp[n] ;

	ll ans = f(n-1)+f(n-2) ;

	return dp[n]=ans ;
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
        memset(dp , -1 ,sizeof(dp)) ;

        ll x ;

        cin>>x ;

        cout<<f(x)<<endl;
    }
    return 0 ;
}
