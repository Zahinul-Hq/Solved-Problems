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
const int N = 5e5 + 7;
vector<int>arr(N), vis(N);
int rec(int i){
	if(arr[i] == i){
		return i;
	}
	if(vis[i]){
		return vis[i];
	}

	vis[i] = rec(arr[i]);

	return vis[i];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			int ans = rec(i);
			vis[i] = ans;
		}
	}

	for(int i = 1; i <= n; i++){
		cout << vis[i] << " ";
	}
	cout << endl;
    return 0 ;

    runtime();

}
