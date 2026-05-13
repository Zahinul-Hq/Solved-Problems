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

string a, b;
int n, m;

int dp[3005][3005];

int solve(int i, int j){

	if(i == n ){
		if(j == m)
			return 0;

		return n - j;
	}

	if(j == m)
		return m - i;

	if(dp[i][j] != -1)
		return dp[i][j];


	int ans = INT_MAX;

	if(a[i] == b[j]){
		
		ans = min(ans,solve(i + 1, j + 1));
	}

	ans = min(ans, 1 + solve(i + 1, j + 1));
	ans = min(ans, 1 + solve(i + 1, j));
	ans = min(ans, 1 + solve(i, j + 1));


	return dp[i][j] = ans;
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
        memset(dp, -1, sizeof dp);


        cin >> a >> b;

        n = a.size();
        m = b.size();

        int ans = solve(0,0);

        cout <<  ans << endl;
    }
    return 0 ;
}
