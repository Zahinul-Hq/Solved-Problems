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

const int N = 3e5 + 7;
vector<int>arr(N);
ll dp[N];
int n;
ll solve(int i){

	if(i == 0)
		return 0;

	if(dp[i] != low)
		return dp[i];

	ll ans = abs(solve(i - 1) + arr[i]) ;
	ans =  max(ans,solve(i - 1) + arr[i]);

	return dp[i] = ans;

}

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        

        ll sum = 0;
        bool all_neg = 1;
        cin >> n;

        for(int i = 0; i < n + 1; i++){
        	dp[i] = low;
        }

        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        	if(arr[i] > 0)
        		all_neg = 0;

        	sum += arr[i];

        }

        ll ans = solve(n);

        if(all_neg){
        	cout << abs(sum) << endl;
        	continue;
        }
        cout << ans << endl;
    }
    return 0 ;
}
