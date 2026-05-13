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

    map<ll, ll>mp;

    ll ans = 0;
    
    while (t--)
    {
        ll delicious, color;

        cin >> delicious >> color;

        if(mp[color] != 0)
        	mp[color] = min(mp[color], delicious);
        else
        	mp[color] = delicious;


    }

    for(auto i: mp){

    	ans = max(ans, i.second);
    }

    cout << ans << endl;



    return 0 ;
}
