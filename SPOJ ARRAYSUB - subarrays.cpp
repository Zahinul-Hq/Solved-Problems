#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

const int N = 1e6 + 7;

int arr[N];
int t[4 * N];

void build(int node, int start, int end){

	if(start == end){
		t[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = max(t[node * 2] , t[node * 2 + 1]);

}
int query(int node, int start, int end, int l, int r){

	if(start > r || end < l)
		return 0;

	if(start >= l && end <= r){
		return t[node];
	}

	int mid = (start + end) / 2;

	return max(query(node * 2, start, mid, l, r),
					query(node * 2 + 1, mid + 1, end, l, r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;


    	int n , k;

    	cin >> n;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	cin >> k;

    	build(1, 1, n);

    	for(int i = 0; i <= n - k; i++){
    		cout << query(1, 1, n, i + 1, i + k) << " ";
    	}
        
    
    return 0 ;
}
