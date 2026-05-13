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
const int N = 2e5 + 7;
ll up[N], down[N];
int n;
ll dp[N][2];
ll solve(int i , bool u){
	if(i == n){
		return 0;
	}
	if(dp[i][u] != -1)
		return dp[i][u];
	ll ans = inf;
	if(!u){
		ans = min(ans, solve(i + 1, 1) + (up[i] * up[i + 1]));
		ans = min(ans, solve(i + 1, 0) + (up[i] * down[i + 1]));
	}else{
		ans = min(ans, solve(i + 1, 1) + (down[i] * up[i + 1]));
		ans = min(ans, solve(i + 1, 0) + (down[i] * down[i + 1]));
	}

	return dp[i][u] = ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int  x, s;
        cin >> n >> s;

        for(int i = 0; i <= n + 1; i++){
        	dp[i][0] = dp[i][1] = -1;
        }

        for(int i = 1; i <= n; i++){
        	cin >> x;
        	if(i == 1 || i == n)
        		up[i] = down[i] = x;
        	else{
        		if(s >= x){
        			up[i] = x;
        			down[i] = 0;
        		}else{
        			up[i] = s;
        			down[i] = x - s;
        		}
        	}
        }
        /*for(int i = 1; i <= n; i++){
        	cout << up[i] << " " << down[i] << endl;
        }*/

        ll total = max(solve(0 , 0), solve(0 , 1));

        cout << total << endl;
    }
    return 0 ;
}
