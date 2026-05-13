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

const int N = 3005;

int a[N];
ll dp[N][N][2];
ll turn(int i, int j, bool taro){

	if(i > j)
		return 0;

	ll ans = 0;

	if(dp[i][j][taro] != -1)
		return dp[i][j][taro];
	
	if(taro){

		ans = max(a[i] + turn(i + 1, j, 0), a[j] + turn(i, j - 1, 0));

	}else{

		ans = min(turn(i + 1, j, 1) - a[i], turn(i, j - 1, 1) - a[j]);

	}

	return dp[i][j][taro] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n; 

    cin >> n;

    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    cout << turn(1, n, 1) << endl;
    return 0 ;
}
