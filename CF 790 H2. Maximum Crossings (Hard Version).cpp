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
const int N = 2e5 + 7 ;
ll t[4 * N];

void build(int node, int start, int end){

	if(start == end){
		t[node] = 0;
		return ;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = t[node * 2] + t[node * 2 + 1];
}

void update(int node, int start, int end, int l, int r){
	if(end < l || start > r){
		return;
	}

	if(start >= l && end <= r){
		 t[node]++;
		 return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, l, r);
	update(node * 2 + 1, mid + 1, end, l, r);

	t[node] = t[node * 2] + t[node * 2 + 1];
}

ll query(int node, int start, int end, int l, int r){
	if(end < l || start > r){
		return 0;
	}

	if(start >= l && end <= r){
		 return t[node];
	}

	int mid = (start + end) / 2;

	return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {

    	int n; cin >> n;

    	int arr[n];

    	o_set<pair<int,int>> st;

    	ll ans = 0;

    	build(1, 1, n);

    	for(int i = 0; i < n; i++){

    		cin >> arr[i];
    		
    		ans += query(1, 1, n, arr[i], n);

    		update(1, 1, n, arr[i], arr[i]);
    	}
    	

    	cout << ans << endl;
        
    }
    return 0 ;
}
