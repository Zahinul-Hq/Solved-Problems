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

string s;

ll dp[5005];

ll solve(int i, int n){

	if(i == n)
		return 1;
	if(s[i] == '0')
		return 0;

	if(dp[i] != -1)
		return dp[i];


	ll ans =  solve(i + 1, n);

	if(i + 1 < n ){

		int x = 0;

		x = (s[i] -'0') * 10 + (s[i + 1] - '0');
		if(x >= 10 && x <= 26)
			ans+= solve (i + 2, n);
	}


	return dp[i] = ans;



}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    
    
    while (cin >> s && s != "0")
    {
        memset(dp, -1, sizeof dp);

        ll ans = solve(0, s.size());

        cout << ans << endl;
    }
    return 0 ;
}
