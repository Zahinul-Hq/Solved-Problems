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
ll dp[20][2][20][2];

ll rec(string &s , int i, bool flag, int zero_cnt, bool digFound){
	if(i == (int)s.size()){
		return zero_cnt;
	}

	if(dp[i][flag][zero_cnt][digFound] != -1){
		return dp[i][flag][zero_cnt][digFound];
	}

	int limit = (flag == 1 ? s[i] - '0' : 9);
	ll ans = 0;

	for(int dig = 0; dig <= limit; dig++){
		
		ans += rec(s, i + 1, (flag & (dig == s[i] - '0')), zero_cnt + (!dig && digFound), (digFound || dig != 0)) ;
	}

	//debug(ans);

	return dp[i][flag][zero_cnt][digFound] = ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs =1  ;
    cin >> test_cases ;

    
    while (test_cases--)
    {
    	ll l, r;

    	cin >> l >> r;

    	bool f = (l == 0);

    	l = max(l - 1, 0LL);

    	string l_ = to_string(l);
    	string r_ =  to_string(r);
    	memset(dp, -1, sizeof dp);

    	ll rt = rec(r_, 0, 1, 0, 0);

    	
    	memset(dp, -1, sizeof dp);


    	ll lf = rec(l_, 0, 1, 0, 0);
    	
    	cout << "Case " << cs++ << ": " << rt - lf + f << endl;



    }
    return 0 ;

    runtime();

}
