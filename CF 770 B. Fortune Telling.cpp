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
const int N = 1e5 + 7;
vector<int>arr(N, 0);
ll n, y, _x;
map<pair<int,bool>, ll>dp;
ll solve(int i, bool x){
	if(i == n + 1){
		return 0;
	}

	if( dp.find({i, x}) != dp.end())
		return dp[{i, x}];

	ll ans = 0;
	ans = solve(i + 1 , 1) ^ arr[i];
	ans = solve(i + 1, 0) + arr[i];
	
	return dp[{i, x}] = ans;

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
        cin >> n >> _x >> y;

        arr[0] = _x;
        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }
        dp.clear();

        if(solve(0, 1)  == y || solve(0, 0) == y){
        	cout << "Bob" << endl;
        }else{
        	cout << "Alice" << endl;
        }
    }
    return 0 ;
}
