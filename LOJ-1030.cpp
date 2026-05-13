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
const int N = 120;
int arr[N], n;
long double dp[N];
long double solve(int i){
	if(i > n)
		return 0;
	if(dp[i] >= 0)
		return dp[i];

	long double ans = arr[i];

	for(int j = 1; j <= 6; j++){

		if(i + j <= n)
			ans += (1.0 / min(6, n - i)) * (solve(i + j));
	}

	return dp[i] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin.ignore();
    	cin >> n;

    	memset(dp, -1, sizeof dp);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	cout << "Case "<< cs++ << ": " << fixed << setprecision(9) << solve(1) << endl;
    }
    return 0 ;

    runtime();

}
