#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt" ,"r" , stdin);
        freopen("output.txt" , "w" ,stdout);
        cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
    #endif
}


void topoSort(int node, vector < pair < int, int >> adj[],int vis[], stack <pair<int,int> > & st, int i) {
    vis[node] = 1;

    
    for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {

          topoSort(v, adj, vis, st, i+1);
        }
    }
      st.push({node,i});
}
vector < int > shortestPath(int src,int node, vector<pair<int,int>>adj[]) {

    int vis[node] = {0};

    stack < pair<int,int> > st;
    for (int i = 0; i < node; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st , i+1);
        }
    }
      
    vector < int > dist(node);
    for (int i = 0; i < node; i++) {
        dist[i] = 1e9;
    }

    dist[src] = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
    }

    for (int i = 0; i < node; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
    }
    return dist;
}


int main() {

    inout() ;

    int node, edge, src;
    cin >> node >> edge >> src;
    vector<pair<int,int>>adj[edge];
    while(edge--){
        int from, to, cost;
        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
    }
   vector < int > ans = shortestPath(src,node, adj);

    stack < pair<int,int> > st;
    for (int i = 0; i < node; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st , i+1);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        if(ans[i] == -1) {
            cout<<"NO PATH"<<'\n';
        }
        else {
            cout<<"src "<<src<<" to "<<"every node "<<i<<" "<<ans[i]<<'\n';
        }
  }

  return 0;

}

