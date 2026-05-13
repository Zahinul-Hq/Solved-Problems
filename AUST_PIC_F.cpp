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

const int N = 1e3 + 7;

ll arr[N][3];

ll dp[N][N] ;



ll possible_value(int i, int k, ll x, ll y, ll z){


	if( i == 0)
		return 0 ;


	if(dp[i][k] != -1)
		return dp[i][k];

	ll ans = possible_value(i - 1, k, x , y , z );

	//x += arr[i][0] , y += arr[i][1], z += arr[i][2];


	if(k > 0)
		ans = max(ans, possible_value(i - 1, k - 1, x + arr[i][0], y + arr[i][1], z + arr[i][2]) + abs(x + arr[i][0]) + abs(y + arr[i][1]) + abs(z + arr[i][2]));

	return dp[i][k] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n , k;

    cin >> n >> k;

    memset(dp, -1, sizeof dp);


    for(int i = 1; i <= n ; i++){
    	cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    cout << possible_value(n, k, 0, 0, 0) << endl;
    return 0 ;
}
