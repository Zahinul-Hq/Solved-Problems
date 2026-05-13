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
const int N = 30005;
int arr[N];
int t[4 * N];
vector<pair<int,int>> Q[N];

void build(int node, int start, int end){

	if(start == end){
		t[node] = arr[start];
		return ;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = t[node * 2] + t[node * 2 + 1];
}

void update(int node, int start, int end, int pos, int val){

	if(start > pos || end < pos)
		return ;

	if(start == pos && end == pos){
		t[node] += val;
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, pos, val);
	update(node * 2 + 1, mid + 1, end, pos, val);

	t[node] = t[node * 2] + t[node * 2 + 1];

}

int query(int node, int start, int end, int l, int r){

	if(start > r || end < l)
		return 0;

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

    int n, q;

    cin >> n;

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    }

    cin >> q;

    for(int i = 1; i <= q; i++){
    	int l , r;

    	cin >> l >> r;

    	Q[r].push_back({l,i});
    }

    map<int,int> last_occ;


    int ans[q + 1];


    for(int r = 1; r <= n; r++){

    	if(last_occ.find(arr[r]) != last_occ.end()){
    		update(1, 1, n, last_occ[arr[r]], -1);

    	}
    	last_occ[arr[r]] = r;

    	update(1, 1, n, r, 1);

    	for(auto [l, i] : Q[r]){
    		ans[i] = query(1, 1, n, l, r);
    	}

    }


    for(int i = 1; i <= q; i++){

    	cout << ans[i] << endl;
    }

    return 0 ;
}
