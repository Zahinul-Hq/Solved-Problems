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
map<int,int>mp;
const int N = 5005, mod = 1e9 + 7;
ll dp[N][N], n;
vector<ll>arr;
ll possible(int i, ll mx){

	if( i >= arr.size() )
		return 0;
	

	if(dp[i][mx] != -1)
		return dp[i][mx];


	ll ans = possible(i + 1, mx);

	ans += possible(i + 1, max(mx, arr[i])) + arr[i];

	cout << i << " " << mx << " " << ans << endl;


	return dp[i][mx] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    

    cin >> n;

    int x;

    for(int i = 0; i < n; i++){
    	cin >> x;
    	mp[x]++;	
    }

    for(auto i : mp)
    	arr.pb(i.F);

    sort(arr.begin(), arr.end());



    memset(dp, -1, sizeof dp);

    ll ans = possible(0 , 0);

    cout << ans << endl;

    //ans = 0;


    for(int i = 1; i <= 2; i++){
    	for(int j = 1; j <= 2; j++){

    		if(dp[i][j] != -1){
    			int sum = ceil(1.00 * i / 2.00);
    			ans += 1LL * (max(sum, j)) * dp[i][j];

    			ans %= mod;
    		}

    		cout << dp[i][j] << " ";

    	}

    	cout << endl;
    }

    cout << ans << endl;

    return 0 ;
}
