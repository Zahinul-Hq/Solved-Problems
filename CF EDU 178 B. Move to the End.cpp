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
// const int N = 1e5 + 7;

// int t[4*N];


// void build(int node, int start, int end){

// 	if(start == end){
// 		t[node] = arr[start];
// 		return ;
// 	}

// 	int mid = (start + end) / 2;

// 	build(node * 2, start, mid);
// 	build(node * 2 + 1, mid + 1, end);

// 	t[node] = max(t[node * 2], t[(node * 2) + 1]);
// }

// int query(int node, int start, int end, int i, int j){


// 	if(start > j || end < i)
// 		return -1;

// 	if(i <= start && end <= j){
// 		return t[node];
// 	}

// 	int mid = (start + end) / 2;

// 	return max(query(node * 2, start, mid, i, j),
// 				query(node * 2 + 1, mid + 1, end, i, j));
// }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	vector<ll>arr(n + 1, 0),pref_max(n + 1, 0), suff_min(n + 2, INT_MAX), suff_sum(n + 2, 0);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		pref_max[i] = max(arr[i], pref_max[i - 1]);
    	}

    	debug(pref_max);

    	for(int i = n; i >= 1; i--){
    		suff_min[i] = min(suff_min[i + 1], arr[i]);
    		suff_sum[i] = suff_sum[i + 1] + arr[i];
    	}
    	debug(suff_min);

    	for(int i = n; i >= 1; i--){

    		cout << (suff_sum[i + 1] + pref_max[i]) << " ";

    	}
    	debug(suff_sum);
    	cout << endl;

    	//build()


    }
    return 0 ;

    runtime();

}
