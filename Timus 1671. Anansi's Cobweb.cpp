
#include<bits/stdc++.h>
using namespace std;


const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
struct DSU {
  vector<int> par, rnk, sz;
  int c, mx = 0;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return mx;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    mx = max(mx, sz[j]);
    if (rnk[i] == rnk[j]) rnk[j]++;
    return mx;
  }
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, a, b, k;
    cin >> n >> m;

    DSU d(n);

    string s;

    vector<pair<int,int>>vp;
    while(m--){
    	cin >> a >> b;
    	vp.push_back({a, b});
    }
    cin >> k;
    map<int,int>mp;
    vector<int>arr(k), ans(k);
    for(int i = 0; i < k; i++){
      cin >> arr[i];
      mp[--arr[i]]++;
    }
    for(int i = 0; i < vp.size(); i++){
      if(!mp[i])
        int mx = d.merge(vp[i].first, vp[i].second);
    }
    reverse(arr.begin(), arr.end());

    for(int i = 0; i < k; i++){
      ans[i] = d.count();

      d.merge(vp[arr[i]].first, vp[arr[i]].second);

    }

    for(int i = ans.size() - 1; i >= 0; i--){
      cout << ans[i];
      if(i != 0)
        cout << " ";
    }
    cout << endl;

    return 0 ;

    runtime();

}
