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
const int N = 405;

ll dp[N][N], pref_sum[N];
int a[N];

int getsum(int l , int r){
	return (pref_sum[r] - pref_sum[l-1]) % 100;
}

ll f(int l, int r){
	if(l == r)
		return 0;

	if(dp[l][r] != -1)
		return dp[l][r];

	ll sum = 0 , ans = inf ;

	for(int i = l;  i < r; i++){
		sum = getsum(l, i) * getsum(i+1 ,r);
		ans = min(ans, sum + f(l, i) + f(i + 1, r));
	}

	return dp[l][r] = ans ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n;

 
    while(cin >> n){

    	memset(dp, -1, sizeof dp);

	    for(int i = 1; i <= n; i++){
	    	cin >> a[i];
	    }

	    for(int i = 1; i <= n ; i++){
			pref_sum[i] = (a[i] + pref_sum[i - 1]) ;
		}

	    cout << f(1, n) << endl;
    }
    return 0 ;
}
