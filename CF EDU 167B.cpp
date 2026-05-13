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

const int N = 105;
string a, b, s;
int dp[N][N];
int lcs(int i, int j) {
  if (i >= a.size() or j >= b.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = lcs(i + 1, j);
  if (a[i] == b[j]) {
    ans = max(ans, lcs(i + 1, j + 1) + 1);
  }
  return dp[i][j] = ans;
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
        cin >> a >> b;
        memset(dp, -1, sizeof dp);

        int ans = lcs(0, 0);
        for(int i = 0; i < b.size(); i++){
        	ans = max(ans, lcs(0, i));
        }
        ans = a.size() + b.size() - ans;
        
        cout << ans << endl;
    }
    return 0 ;
}
