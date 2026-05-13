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

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 2e5 + 7;
vector<int>graph[N];
queue<int> q;
vector<bool> used(N);
vector<int>p(N);


void bfs(int s){

	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int u : graph[v]) {
	        if (!used[u]){
	            used[u] = true;
	            q.push(u);
	            p[u] = v;
	        }
	    }
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int n, k, u, v;
    cin >> n >> k;

    for(int i = 0; i < n - 1; i++){
    	cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    vector<int>arr(k + 1);
    map<int,int>vis;
    for(int i = 0; i < k; i++){
    	cin >> arr[i];
    	vis[arr[i]]++;
    }

    bfs(arr[0]);
    int ans = 0;

    for(int i = 1; i < k; i++){
    	if(vis[arr[i]] == -1)
    		continue;
    	for(int v = arr[i]; v != arr[0]; v = p[v]){
    		if(vis[v] != -1)
    			ans++;
    		else
    			break;
    		vis[v] = -1;
    	}
    }

    cout << ans + 1 << endl;
    return 0;
    
    
}
