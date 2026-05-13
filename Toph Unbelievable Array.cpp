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
const int N = 1e5;
struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : ( par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c; //connected components
  }
  void merge(int i, int j) {

  	if(i != j)
   		par[i] = j;
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
    	DSU dsu(N), dsu2(N);
    	int n, q;
    	cin >> n >> q;
    	vector<int>arr(n + 1, 0);
    	map<int,int>mp;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		mp[arr[i]] = 1;
      }
    	int x, y, t;

    	cout << "Case " << cs++ << ": "<< endl ;

    	while(q--){
    		cin >> t;
    		if(t == 1){
    			cin >> x >> y;
    			if(mp[x] == 1){
            if(y == dsu.find(y)){
              dsu.merge(x, y);
            }else{
              dsu2.merge(x, y); 
            }
            mp[x] = 0;
            mp[y] = 1;
    				
    			}
    		}else{
    			cin >> x;
          if(par[x] == -1 ){
            cout << dsu.find(arr[x]) << endl;
          }else{
            cout << dsu.find(par[x]) << endl;
          }
    			
    		}
    	}
    }
    return 0 ;

    runtime();

}
