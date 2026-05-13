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
double power(double base, int exp) {
    double result = 1.0;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;



    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	string digs;
    	cin >> digs;

    	ll  permutation_size = 1;

    	for(int i = 1; i <= digs.size(); i++){
    		permutation_size *= i;
    	}

		vector<string>numbers;

		int cnt = 0;

		while(next_permutation(digs.begin(), digs.end())){
			cnt++;
		}
		long double tot = 1.0 / permutation_size, ans = 0.0, pref = 1.0 / permutation_size, x = 1.0 / permutation_size;

		if(!cnt){
			cout << fixed << setprecision(9) << ans << endl;
			continue;
		}

		for(int i = 2; i <= cnt; i++){
			ans += (pref * x);
			pref *= x;
			tot += ans;
			
		}

		cout << fixed << setprecision(9) << tot << endl;
    }
    return 0 ;

    runtime();

}
