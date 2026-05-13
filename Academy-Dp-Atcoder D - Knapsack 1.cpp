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
const int N = 105;
ll dp[N][100005], weight[N], value[N];

ll knapsack(int indx , int max_weight){


	if(indx < 0 || max_weight == 0)
		return 0;

	if(dp[indx][max_weight] != -1)
		return dp[indx][max_weight];

	ll ans = knapsack(indx - 1, max_weight);

	if(max_weight - weight[indx] >= 0){

		ans = max(ans, knapsack(indx - 1, max_weight - weight[indx])+ value[indx]) ;
	}

	return dp[indx][max_weight] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n, w;

    cin >> n >> w;

    memset(dp , -1 , sizeof dp);

    for(int i = 0; i < n; i++){
    	cin >> weight[i] >> value[i];
    }

    cout << knapsack(n-1, w) << endl;
    return 0 ;
}
