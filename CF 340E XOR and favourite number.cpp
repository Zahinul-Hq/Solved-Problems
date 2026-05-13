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
const int N = 2e6 + 7;
vector<ll>arr(N, 0), pref(N, 0);
vector<ll>cnt(N, 0);
ll res = 0, k ;
void remove(ll xr){

	cnt[xr]--;
	res -= cnt[xr ^ k];
}  
void add(ll xr){
	res += cnt[xr ^ k];
	cnt[xr]++;
}    
int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<ll> mo_s_algorithm(vector<Query> queries, int n) {
    vector<ll> answers(queries.size() );
    sort(queries.begin(), queries.end());

    int cur_l = 1;
    int cur_r = 0;

    for (Query q : queries) {
        while (cur_l > q.l) {
        	cur_l--;
            add(pref[cur_l]);

        }
        while (cur_r < q.r) {
            cur_r++;
            add(pref[cur_r]); 
        }
        while (cur_l < q.l) {
            remove(pref[cur_l]);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(pref[cur_r]);
            cur_r--;
        }
        answers[q.idx] = res;
        
    }
    return answers;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	int n, q;
	cin >> n >> q >> k;

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] ^ arr[i];
	}
	//cout << arr[38] << " " << arr[39] << endl;
	block_size = sqrt(n) ;

	vector<Query>ranges;

	int j = 0;

	while(q--){
		int l, r;
		cin >> l >> r;
		
		ranges.push_back({l, r, j++});
	}

	vector<ll> ans = mo_s_algorithm(ranges, n);

	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] <<endl;
	}

    return 0 ;

    runtime();

}
