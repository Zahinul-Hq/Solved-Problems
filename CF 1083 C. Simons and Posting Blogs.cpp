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
	    vector<vector<int>> a(n);
	    set<int> s;
	    for (int i = 0; i < n; i++) {
	      int sz;
	      cin >> sz;
	      a[i].resize(sz);
	      for (auto& x: a[i]) cin >> x;
	      reverse(a[i].begin(), a[i].end());
	      sz = 0;
	      for (int j = 0; j < (int)a[i].size(); j++) {
	        bool dup = 0;
	        for (int k = 0; k < sz; k++) {
	          if (a[i][j] == a[i][k]) {
	            dup = 1;
	            break;
	          }
	        }
	        if (!dup) {
	          a[i][sz++] = a[i][j];
	        }
	      }
	      a[i].resize(sz);
	    }
	 
	    vector<int> ans;
	    while (n) {
	      int min_idx = min_element(a.begin(), a.end()) - a.begin();
	      swap(a[min_idx], a.back());
	      for (auto& x: a.back()) {
	        s.insert(x);
	        ans.emplace_back(x);
	      }
	      a.pop_back();
	      n--;
	      for (int i = 0; i < n; i++) {
	        int sz = 0;
	        for (int j = 0; j < (int)a[i].size(); j++) {
	          if (s.count(a[i][j]) == 0) {
	            a[i][sz++] = a[i][j];
	          }
	        }
	        a[i].resize(sz);
	      }
	    }
	    for (auto& x: ans) cout << x << ' ';
	    cout << '\n';

    }
    return 0 ;

    runtime();

}
