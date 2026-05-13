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


int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	cin >> n;
	vector<int>C(n + 1, 0);
	vector<int>A(n + 1, 0);

	for(int i = 1; i < n; i++){
		cin >> C[i];
	}
	for(int j = 1; j < n; j++){
		cin >> A[j];
	}

	C[n] = n;


	vector<int>dp(n +1, INT_MAX);
	dp[0] = 0;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			if(j - C[j] <= i){
				dp[j] = min(dp[j], dp[i] + 1);
			}
			if(A[j] == 1)
				break;
		}
	}

	cout << dp[n] - 1<< endl;

    return 0 ;

    runtime();

}
