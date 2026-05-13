#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
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

const int N  = 105;
ll dp[N][N];
int arr[N];

int sum (int start, int end){

	int ans = 0;

	for(int i = start; i <= end; i++){
		ans += arr[i];
		ans %= 100;
	}

	return ans;
}

ll solve(int i , int j){

	if(i == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	ll ans  = inf;

	for(int k = i ; k < j ; k++){

		ll temp_ans = (solve(i,k) + solve(k + 1, j)) + (sum(i, k) * sum(k + 1, j)); 
		ans = min ( ans, temp_ans);
	}

	return dp[i][j] = ans;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int n ;    
    while (cin >> n)
    {
        memset(dp, -1, sizeof dp);

        for(int  i = 0; i < n; i++){
        	cin >> arr[i];
        }

        ll ans = solve(0, n - 1);

        cout << ans << endl;
    }
    return 0 ;
}
