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
const int MAXN = 2e5 + 7, K = 25;
int n;
vector<int>arr(MAXN), inv_arr(MAXN), lg(MAXN+1);
int st[K + 1][MAXN];

void Sparse_Table(){

	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	    lg[i] = lg[i/2] + 1;

	copy(arr.begin(), arr.end(), st[0]);

	for (int i = 1; i <= K; i++)
	    for (int j = 1; j + (1 << i) <= MAXN; j++)
	        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

}
int query(int L, int R){
	int i = lg[R - L + 1];
	return max(st[i][L], st[i][R - (1 << i) + 1]);
}

ll div_con(int l, int r){

	if(l >= r)
		return 0;

	int max_val = query(l, r);
	int mx_indx =  inv_arr[max_val];
	ll ans = 0;

	if(mx_indx - l > r - mx_indx){
		for(int i = mx_indx + 1; i <= r; i++){
			int pos = inv_arr[max_val - arr[i]];
			if(pos < mx_indx && pos >= l ){
				ans++;
			}
		}
	}else{
		for(int i = l ; i < mx_indx; i++){
			int pos = inv_arr[max_val - arr[i]];
			if(pos > mx_indx && pos <= r ){
				ans++;
			}
		}
	}

	return ans + div_con(l , mx_indx - 1) + div_con(mx_indx + 1, r);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	cin >> n;

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    	inv_arr[arr[i]] = i;
    }

    Sparse_Table();

    cout << div_con(1, n) << endl;

    return 0 ;

    runtime();

}
