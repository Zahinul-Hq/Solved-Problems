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
const int mod=1e9+7 ;
const int N=2e6+7 ;
ll f[N];
ll bin_exp ( int b, int p ) {
    ll res = 1 % mod, x = b % mod;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}
void factorial(){

	f[0]=1 ;

	for(int i=1 ;i <=N ;i++){
		f[i]=((f[i-1]%mod)*(i%mod))%mod ;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
	factorial() ;

    int t , i=1 ;
    cin>>t ;
    
    while (t--)
    {
        ll n , k ;

        cin>>n>>k ;

        

        ll denom= (f[n]%mod)*(f[k-1]%mod)%mod ;



        ll ans= (1LL*f[n+k-1]*bin_exp(denom ,mod-2))%mod;

        cout<<"Case "<<i++<<": "<<ans<<endl;

    }
    return 0 ;
}
