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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;
    	string s;

    	cin >> s;


    	s = "#" + s;

    	vector<int>suff(n + 2, 0), pref(n + 2, 0);

    	for(int i = n; i >= 1; i--){
    		suff[i] = suff[i + 1] + (s[i] == '1');
    	}
    	for(int i = 1; i <= n; i++){
    		pref[i] = pref[i - 1] + (s[i] == '0');
    	}

    	int ab = INT_MAX, ans = n;


    	for(int i = n - 1 ; i >= 0; i--){
    		if(pref[i] >= ((i + 1) / 2) && suff[i + 1 ] >= ((n - i + 1) / 2)){

    			if(ab >= 2*abs((n) - (2*i))){
    				ans = i ;
    				ab = 2*abs((n) - (2*i));

    			}

    		}
    		debug(i, pref[i], suff[i + 1], ab,ans );
    	}


    	cout << ans << endl;
    }
    return 0 ;

    runtime();

}
