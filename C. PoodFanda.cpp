/**
 *   author: fahim_7272      
**/
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

//#define ar array
#define ll long long
#define ld long double
#define ull unsigned long long int

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rep(i,a,n) for(ll i = a; i < (ll)(n); i++)
#define rrep(i,n) for(ll i = (ll)(n) - 1; i >= 0; i--)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define mp make_pair

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = INT_MAX;
const ld EPS = INT_MAX * (-1);

vector<ll>visited(MAX_N+1, 0);
ll fun(vector<ll>&ind, ll n, vector<ll>res[21])
{
	ll mn = INF;
	ll mn_ind = -1;

	vector<pair<ll,ll>>vp;
    for(ll i=0; i<n; i++)
    {
    	ll calc = 0;
	    for(ll j=0; j<4; j++)
	    	calc += res[i][ind[j]];
	    
	    vp.push_back({calc, i});
    }

    sort(vp.begin(),vp.end());

   	ll mn_time = INT_MAX;

   	mn = vp[0].first;

    for(int i = 0; i < vp.size(); i++){
    	if(vp[0].first == vp[i].first){

    		if(mn_time >= res[vp[i].second][0]){
    			mn_ind = vp[i].second;
    			mn_time = res[vp[i].second][0];
    		}
    	}

    }

	visited[mn_ind] = 1;
	return mn;
}

void solve() {

    ll n,k,m,cnt = 0,ans = 0, mx = 0, mn = INF;
    cin >> n;
    for(ll i=0; i<n; i++)
        visited[i] = 0;
    vector<ll>ind[5];
    vector<ll>res[21];
    ll y;
    for(ll i=0; i<4; i++) {cin >> y; ind[0].pb(y);};
    for(ll i=0; i<4; i++) {cin >> y; ind[1].pb(y);};
    for(ll i=0; i<4; i++) {cin >> y; ind[2].pb(y);};
    for(ll i=0; i<4; i++) {cin >> y; ind[3].pb(y);};
    for(ll i=0; i<4; i++) {cin >> y; ind[4].pb(y);};

    for(ll i=0; i<n; i++)
    {
        ll u; cin >> u;
		res[i].pb(u);
		for(ll j=1; j<21; j++)
        {
            ll o; cin >> o;
			res[i].pb(o);
        }
    }

    ans += fun(ind[0], n, res);
    ans += fun(ind[1], n, res);
    ans += fun(ind[2], n, res);
    ans += fun(ind[3], n, res);
    ans += fun(ind[4], n, res);

    for(ll i=0; i<n; i++)
    {
        if(visited[i])
            mx = max(mx, res[i][0]);
    }
    cout << ans + mx << endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}