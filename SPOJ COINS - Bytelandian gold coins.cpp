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
map<ll,ll>mp;
ll solve(ll n){

	if(n < 12)
		return n;

	if(mp[n] != 0)
		return mp[n];

	return mp[n] = max(n, solve(n/2) + solve(n/3) + solve(n/4));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    ll n ;    

    while (cin >> n)
    {
        ll ans = solve(n);

        cout << ans << endl;

        mp.clear();
    }
    return 0 ;
}
