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
ll root(ll val){

	ll hi= 2e9 , lo= 0;

	while(hi-lo>1){

		ll mid = (hi+lo)>>1 ;

		if(mid*mid>=val){
			hi = mid ;
		}else
			lo = mid ;
	}

	return hi;
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
        ll n ;

        cin>>n ;

       

        ll ans= root(n)-1 ;

        cout<<ans<<endl; 
    }
    return 0 ;
}
