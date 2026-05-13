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
const int N = 1e4 + 7;
vector<pair<int,int>> graph[N];


int dijkstra(int src, int des){

	vector<bool> vis(N, false);
	vector<int> dis(N, INT_MAX);

	dis[src] = 0;

	set<pair<int,int>>st;
	st.insert({0, src});

	while(st.size() > 0){
		auto node = *st.begin();
		int d = node.first;
		int parent = node.second;

		st.erase(st.begin());

		if(vis[parent]) continue;
		vis[parent] = true;

		for(auto child : graph[parent]){

			int child_node = child.first;
			int child_dis = child.second;

			if(dis[parent] + child_dis < dis[child_node]){
				dis[child_node] = dis[parent] + child_dis;
				st.insert({dis[child_node], child_node});
			}
		}
	}

	return dis[des];
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
        int n , m, q; 

        string s,  src, des;

        unordered_map<string,int> ump;

        cin >> n;

        for(int i = 1; i <= n; i++){

        	cin >> s >> m;
        	ump[s] = i;

        	while(m--){

        		int  v, dis;
        		cin >> v >> dis;

        		graph[i].push_back({v, dis});
        	}
        }

        cin >> q;

        while(q--){

        	cin >> src >> des;
        	cout << dijkstra(ump[src], ump[des]) << endl;
        }

        for(int i = 1; i <= n; i++){
        	graph[i].clear();
        }
    }
    return 0 ;
}
