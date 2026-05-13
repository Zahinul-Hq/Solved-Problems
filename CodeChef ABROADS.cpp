#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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
  vector<ll> par, rnk, sz;
  map<ll,vector<ll>> hist;

  multiset<ll>st;

  ll c, mx = 0;
  DSU(ll n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1) ,c(n) {
    for (ll i = 1; i <= n; ++i)
      par[i] = i;
  }
  ll find(ll i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  ll reset(ll child){
    ll parent = find(child);

    hist[child].pop_back();

    mx = (-*st.begin());

    st.erase(st.find(-sz[parent]));
    sz[parent] += (hist[child].back() - sz[child]);
    sz[child] = hist[child].back();
    st.insert(-sz[parent]);

    return mx ;
  }

  ll merge(ll i, ll j) {
    if ((i = find(i)) == (j = find(j))) return (-*st.begin());

    if (rnk[i] > rnk[j]) 
      swap(i, j);
    par[i] = j;
    mx = (-*st.begin());
    st.erase(st.find(-sz[j]));
    st.erase(st.find(-sz[i]));
    sz[j] += sz[i];

    st.insert(-sz[j]);

    if (rnk[i] == rnk[j]) 
      rnk[j]++;
    return mx;
  }
};
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll n, m, a, b, q;
    cin >> n >> m >> q;

    DSU d(n);

    for(ll i = 1; i <= n; i++){
    	cin >> d.sz[i];
      d.hist[i].push_back(d.sz[i]);
      d.st.insert(-d.sz[i]);
    }

    vector<pair<ll,ll>>vp;
    while(m--){
    	cin >> a >> b;
    	vp.push_back({a, b});
    }

    map<ll,ll>mp;
    vector<pair<char, pair<ll,ll>>>Qry;

    vector<ll>ans(q);
   

    for(ll i = 0; i < q; i++){
      char c; cin >> c;
      if(c == 'P'){
      	cin >> a >> b;
        d.st.erase(d.st.find(-d.sz[a]));
        d.sz[a] = b;
        d.hist[a].push_back(b);
        d.st.insert((-d.sz[a]));

      	Qry.push_back({c, {a, b}});
      }else{
      	cin >> a;
      	mp[a]++;
      	Qry.push_back({c, {a, -1}});
      }
    }

    reverse(Qry.begin(), Qry.end());

    for(ll i = 0; i < vp.size(); i++){
    	if(!mp[i + 1]){
    		ll x = d.merge(vp[i].first, vp[i].second);
    	}
    }
    for(ll i = 0; i < q; i++){
      char c = Qry[i].first;
      if(c == 'P'){
        ans[i] = d.reset(Qry[i].second.first);
	    }else{
        ll indx = Qry[i].second.first;
	    	ans[i] = d.merge(vp[ indx - 1].first, vp[indx - 1].second);
      
	    }
    }


    for(ll i = ans.size() - 1; i >= 0; i--){
      cout << ans[i] << endl;
      
    }

    return 0 ;
    runtime();

    

}
