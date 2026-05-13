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
const int N = 1e5 +7 , mod = 1e9 + 7;
int m, a[N], n;
ll dp[N][105];
ll array_description(int i, int last_value){

	if(i == n + 1 )
		return 1;

	if(dp[i][last_value] != -1)
		return dp[i][last_value];
	int start = 1, end = m;

	if(a[i]){
		start = end = a[i];
	}else{
		if(i != 1){
			start = max(1,last_value - 1);
			end = min(last_value + 1 , m);
		}
	}

	ll ans = 0 ;

	for(int current_value = start; current_value <= end; current_value++){

		if( i == 1 || abs(last_value - current_value) <= 1){
			ans += array_description(i + 1, current_value) ;

			ans %= mod;
		}
	}

	return dp[i][last_value] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    cin >> n >> m;

    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    cout << array_description(1, 0) << endl;
    return 0 ;
}
