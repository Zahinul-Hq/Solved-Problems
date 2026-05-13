

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define long long int;
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

struct DSU {
  vector<int> par, rnk, sz, ex;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 0), c(n), ex(n + 1 , 0) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : ( find(par[i])));
  }
  int get_size(int i) {
      return(i == par[i]) ? sz[i] : sz[i] - ex[i] + get_size(par[i]);
  }
  void add(int i, int val){
    sz[find(i)] += val;
  }
  int count() {
    return c;    //connected components
  }
  void merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    ex[i] += sz[j];
    //sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;

  }
};
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    
    int n, q, i, val, j;
    cin >> n >> q;

    DSU dsu(n);
    string s;

    while(q--){

    	cin >> s;
    	if(s == "add"){
    		cin >> i >> val;
    		dsu.add(i , val);
    	}else if(s == "join"){
    		cin >> i >> j;
    		dsu.merge(i, j);
    	}else{
    		cin >> i;
    		cout << dsu.get_size(i) << endl;
    	}

    }

    return 0 ;

    runtime();

}
