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
const int N = 1e5 + 7;
struct node_val{
	int a;
};

int t[4*N];
int arr[N];


int combine(int l_node, int r_node){

	return max(l_node, r_node);
}

void build(int node, int start, int end){

	if(start == end){
		t[node] = arr[start];
		return ;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
int query(int node, int start, int end, int i, int j){


	if(start > j || end < i)
		return 0;

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	return combine(query(node * 2, start, mid, i, j),
				query(node * 2 + 1, mid + 1, end, i, j));
}
//modify combine, node_val, lazy
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

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}

    	build(1, 0, n - 1);

    	int mn = INT_MAX, mn_indx = n - 1;
    	vector<int>ans(n);


    	for(int i = n - 1; i >= 0; i--){
    		if(mn > arr[i]){
    			mn = arr[i];
    			mn_indx = i;
    		}
    		ans[i] = query(1, 0, n - 1, 0, mn_indx );

    		debug(ans[i], mn, mn_indx);

    		
    	}

    	for(int i = 0; i < n; i++){
    		cout << ans[i] << " ";
    	}
    	cout << endl;
    }
    return 0 ;
}
