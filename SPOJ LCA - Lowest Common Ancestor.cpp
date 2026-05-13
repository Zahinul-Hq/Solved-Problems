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

const int N = 1002;
const int LOG = 14;
vector<int>graph[N];
vector<int>depth(N, 0);
int up[N][LOG];
void dfs(int parent){

	for(auto child : graph[parent]){
		depth[child] = depth[parent] + 1;
		up[child][0] = parent;
		for(int j = 1; j < LOG; j++){
			up[child][j] = up[up[child][j - 1]][j - 1];
		}
		dfs(child);
	}
}
int get_lca(int a, int b){

	if(depth[a] < depth[b])
		swap(a,b);

	int k = depth[a] - depth[b];

	for(int j = LOG - 1; j >= 0; j--){
		if(k & (1 << j)){
			a = up[a][j];
		}
	}
	if(a == b)
		return a;

	for(int j = LOG - 1; j >= 0; j--){
		if(up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];

		}
	}

	return up[a][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t, cs = 1;

    cin >> t;
    while(t--){
    	int n, m, q , ch;

    	memset(up, 0 , sizeof up);

	    cin >> n;

	    for(int i = 1; i <= n; i++){
	    	cin >> m;
	    	while(m--){
	    		cin >> ch;
	    		graph[i].push_back(ch);
	    	}
	    }

	    dfs(1);

	    cin >> q;

	    cout << "Case " << cs++ << ":" << endl;

	    while(q--){
	    	int a , b;

	    	cin >> a >> b;

	    	cout << get_lca(a, b) << endl;
	    }


	    for(int i = 1; i <= n; i++){
	    	graph[i].clear();
	    	depth[i] =0;
	    }


    }
    return 0 ;
}
