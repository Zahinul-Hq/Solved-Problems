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
    	int n, m;
    	cin >> n >> m;
    	vector<int>a(n), b(m), pref(m, n), suff(m, -1);

    	for(int i = 0; i < n; i++){
    		cin >> a[i];
    	}
    	for(int i = 0; i < m; i++){
    		cin >> b[i];
    	}
    	int pos = 0;
    	for(int i = 0; i < n; i++){
            if(pos < m){
        		if(a[i] >= b[pos]){
        			pref[pos++] = i;
        		}
            }
    	}
    	if(pos == m){
    		cout << 0 << endl;
    		continue;
    	}
        pos = m - 1;
        for(int i = n - 1; i >= 0; i--){
            if(pos >= 0){
                if(a[i] >= b[pos]){
                    suff[pos--] = i;
                }
            }     
        }
        int ans = INT_MAX;

        for(int i = 0; i < m; i++){
            int match_previous = i == 0 ? -1 : pref[i - 1];
            int match_next = i + 1 == m ? n : suff[i + 1];
            if(match_next > match_previous){
                ans = min(ans, b[i]);
            }
        }
        debug(pref, suff);

        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0 ;

    runtime();

}
