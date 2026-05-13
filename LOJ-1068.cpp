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

int dp[12][2][100][100], k;
string num;

int digit_dp(int pos, bool is_last, int dig_sum, int div){

	if(pos == num.size()){
		if(dig_sum == 0 && div == 0)
			return 1;
		return 0;
	}
	if(dp[pos][is_last][dig_sum][div] != -1)
		return dp[pos][is_last][dig_sum][div];

	int limit = is_last ? num[pos] - '0' : 9;

	ll ans = 0;

	for(int dig = 0; dig <= limit; dig++){
		ans += digit_dp(pos + 1, (is_last & (dig == (num[pos] - '0'))), (dig_sum + dig) % k, ((div * 10) + dig) % k);
	}

	return dp[pos][is_last][dig_sum][div] = ans;


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
    	int a, b;
    	cin >> a >> b >> k;

    	cout << "Case " << cs++ << ": " ; 

    	if(k > 90){
    		cout << 0 << endl;
    		continue;
    	}
    	num = to_string(a - 1);
    	memset(dp, -1, sizeof dp);
    	int l = digit_dp(0, 1, 0, 0);
    	num = to_string(b);
    	memset(dp, -1, sizeof dp);
    	int r = digit_dp(0, 1, 0, 0);

    	cout << r - l << endl;




    }
    return 0 ;

    runtime();

}
