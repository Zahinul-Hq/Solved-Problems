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
const int N = 3e5 + 9, mod = 1e9;

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


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin.ignore();
    	int n, m; cin >> n;
	  	vector<array<int, 3>> ed;
	  	for(int i = 1; 1; i++){
	    	int u, v, w; cin >> u >> v >> w;
	    	if(u == 0 && v == 0 && w == 0)
	    		break;
	    	ed.push_back({w, u , v});
	  	}
	  	sort(ed.begin(), ed.end());
	  	long long ans = 0;
	  	dsu d(n);
	  	for (auto e: ed){
		    int u = e[1], v = e[2], w = e[0];
		    if (d.same(u, v)) continue;
		    ans += w;
		    d.merge(u, v);
	  	}

	  	sort(ed.rbegin(), ed.rend());
	  	long long ans1 = 0;
	  	dsu d1(n);
	  	for (auto e: ed){
		    int u = e[1], v = e[2], w = e[0];
		    if (d1.same(u, v)) continue;
		    ans1 += w;
		    d1.merge(u, v);
	  	}

	  	cout << "Case " << cs++ << ": ";

	  	if((ans1 + ans) % 2 == 0){
	  		cout << (ans + ans1) / 2 << endl;
	  	}else{
	  		cout << (ans + ans1) << "/" << 2 << endl;
	  	}

    }
    return 0 ;

    runtime();

}

