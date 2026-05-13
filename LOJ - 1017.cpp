#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 105;
int n, w, k;
ll dp[N][N];
ll rec(int i, int left, vector<int>&arr){
	if(i >= n || left == 0)
		return 0;

	if(dp[i][left] != -1)
		return dp[i][left];
	ll ans = 0;
	ans = max(ans, rec(i + 1, left, arr));
	int pos = upper_bound(arr.begin(), arr.end(), arr[i] + w) - arr.begin();
	ans = max(ans, rec(pos, left - 1, arr) + pos - i);

	return dp[i][left] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;

    int cs = 0;
    
    while (test_cases--)
    {
    	cin.ignore();
    	cin >> n >> w >> k;
    	vector<int>arr(n, 0);
    	int x;
    	memset(dp, -1, sizeof dp);

    	for(int i = 0; i < n; i++){
    		cin >> x >> arr[i];
    	}

    	sort(arr.begin(), arr.end());

    	cout << "Case " << ++cs << ": " << rec(0, k, arr) << endl;

    }
    return 0 ;

    runtime();

}
