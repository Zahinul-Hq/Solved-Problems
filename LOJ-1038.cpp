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
const int N = 1e5 + 7;
double eps = .00000001;
vector<int>divisors[N];
double dp[N];
void precalculate(){
	for(int i = 1; i < N; i++){
		dp[i] = -1.0;
	}
}

double rec(int n){
	if(n == 1)
		return 0.0;

	if(dp[n] != -1.0)
		return dp[n];

	vector<int>divs;
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			divs.push_back(i);
			if((n / i) != i){
				divs.push_back(n / i);
			}
		}
	}
	int k = divs.size();

	double ans = 0.0;

	for(int i = 1; i < k; i++){
		ans += (1.00 + rec(n / divs[i]));
	}
	debug(ans, n);

	k--;
	ans = ans / (1.00 * k);
	
	return dp[n] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


	
    int test_cases, cs = 1 ;
    cin >> test_cases ;

    precalculate();
    
    while (test_cases--)
    {

    	int n;
    	cin >> n;
    	
    	cout << "Case " << cs++ << ": ";

    	if(n == 1)
    		cout << 0.0000 << endl;
    	else{
    		cout << fixed << setprecision(10) << rec(n) + 1 << endl;
    	}
    	

    }
    return 0 ;

    runtime();

}
