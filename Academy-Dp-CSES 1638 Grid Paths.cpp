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
const int N=1005;
int mod = 1e9+7 ;
int n ;
int dp[N][N];
char a[N][N] ;

ll paths(int left, int down){
	
	if(a[left][down] == '*')
		return 0;
	if(left == n && down == n){
		return 1;
	}

	if(left > n || down > n){
		return 0;
	}


	if(dp[left][down] != -1)
		return dp[left][down];

	ll ans = 0; 


	if(a[left + 1][down] != '*')
		ans += paths(left + 1, down) % mod;

	if(a[left][down + 1] != '*')
		ans += paths(left, down + 1) % mod;

	return dp[left][down] = ans % mod;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    cin >> n ;

    for(int i = 1; i <= n ;i++){
    	for(int j = 1; j <= n; j++){
    		cin >> a[i][j];
    	}
    }

    memset(dp, -1, sizeof dp);

    int ans  = paths(1, 1);

    cout << ans << endl;
    return 0 ;
}
