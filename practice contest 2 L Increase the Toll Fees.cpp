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
struct dsu {
	vector<int> par, rnk, size; int c;
  	dsu(int n) : par(n+1), rnk(n+1,0), size(n+1,1), c(n) {
    	for (int i = 0; i <= n; ++i)
    		par[i] = i;
  	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }
	int merge(int i, int j) {
	    if ((i = find(i)) == (j = find(j))) return -1; else --c;
	    if (rnk[i] > rnk[j]) swap(i, j);
	    par[i] = j; size[j] += size[i];
	    if (rnk[i] == rnk[j]) rnk[j]++;
	    return j;
  	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int n, m; cin >> n >> m;
	  	vector<array<int, 3>> ed;
	  	for(int i = 1; i <= m; i++){
	    	int u, v, w; cin >> u >> v >> w;
	    	
	    	ed.push_back({w, u , v});
	  	}
	  	sort(ed.begin(), ed.end());
	  	long long ans = 0;
	  	dsu d(n);
	  	for (auto e: ed){
		    int u = e[1], v = e[2], w = e[0];
		    if (d.same(u, v)) continue;
		    ans += w;

		    cout << u << " " << v << " " << w << endl;
		    d.merge(u, v);
	  	}
    return 0 ;

    runtime();

}
