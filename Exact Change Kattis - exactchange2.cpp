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

const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 10001;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int val, n, x ;
    	cin >> val >> n;

    	vector<ll>dp(N + 1, INT_MAX);

    	dp[0] = 0;

    	for(int i = 0; i < n; i++){
    		cin >> x;
    		for(int j = N - x; j >= 0; j--){
    			dp[j + x] = min(dp[j + x], dp[j] + 1);
    		} 
    	}

    	for(int i = val; i <= N; i++){
    		if(dp[i] < INT_MAX){
    			cout << i << " " << dp[i] << endl;
    			break;
    		}

    	}
    }
    return 0 ;

    runtime();

}
