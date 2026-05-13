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
const int N = 2005;
ll dp[N][N];
int  n, k, p;
ll solve(int i, int j, vector<int>&ppl, vector<int> &ky){
    if(i >= n)
        return inf;

    ll ans = inf;

    for(j = 0; j < k; j++){

        ans = min(ans , solve(i + 1,j, ppl, ky));
        ans = min(ans, max(solve(i + 1,j ppl, ky));

    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    

    cin >> n >> k >> p;

    ll people[n + 2], keys[k + 2];

    for(int i = 1; i <= n; i++){
    	cin >> people[i];
    }
    for(int i = 1; i <= k; i++){
    	cin >> keys[i];
    }

    sort(people, people + n);
    sort(keys, keys + k);

    for(int i = 0; i <= n; i++){
    	for(int j = 0; j <= k; j++){
    		dp[i][j] = inf;
    	}
    }

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
           dp[i][j - 1] = min(dp[i][j - 1], dp[i][j]);

           dp[i][j] = min
        }
    }



    //cout << dp[k][n] << endl;
    return 0 ;
}
