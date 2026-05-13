#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N  = 3000;
vector<double>pb(N, 0.0);
double dp[N][N];
int n;
double solve(int i, int tail, int head, double ans){
	if(i == 0){
		if(head > tail)
			return ans;
		return 0.0;
	}

	if(dp[i][head] > -1.0)
	 	return dp[i][head];

	double sum = solve(i - 1, tail + 1, head, ans * (1.0 - pb[i]));
	sum += solve(i - 1, tail, head + 1, ans * (pb[i]));

	return dp[i][head] = sum;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    cin >> n;
    double x;
    for(int i = 1; i <= n ; i++){
    	cin >> x;
    	pb[i] = x;
    }

    for(int i = 0; i < N; i++){
    	for(int j = 0; j < N; j++){
    		dp[i][j] = -1.0;
    	}
    }

    cout << solve(n, 0, 0, 1.0) << endl;

    for(int i = 0; i <= 3; i++){
    	for(int j = 0; j <= 3; j++){
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }
    return 0 ;
}
