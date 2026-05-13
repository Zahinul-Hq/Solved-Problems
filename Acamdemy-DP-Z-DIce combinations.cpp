#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"


void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1e6 + 9 ;
const int mod = 1e9+7 ;
vector<ll>ways(N ,-1) ;
int count(int n){

	if(n==0 )
		return 1 ;
	if(ways[n]!=-1)
		return ways[n] ;
	ll ans = 0 ;

	int z ;

	if(n>6)
		z=6 ;
	else
		z=n ;

	for(int i=1 ; i<=z ; i++){

		ans = ans+ count (n-i) ;

		ans= ans%mod ;
	}

	return ways[n]=ans ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n ; 

    cin>>n ;

    int x = count(n) ;

    cout<<x<<endl ;

    return 0 ;
}
