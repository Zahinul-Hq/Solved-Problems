#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 ;
vector<int>graph[N];
int vis[N] ;
int parent[N];

void bfs(int src){

	queue<int> q;

	q.push(src);
	vis[src] = true;
	parent[src] = -1;
	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int i= 0 ; i<graph[v].size() ; i++) {
                int u= graph[v][i] ;
	        if (!vis[u]) {
	            vis[u] = true;
	            q.push(u);
	            parent[u] = v;
	        }
	    }
	}
}

int main()
{

    int n , m, u ,v ;

    cin>>n>>m ;
    for(int i=0 ; i<m ;i++){

    	cin>>u>>v ;

    	graph[v].push_back(u) ;
    	graph[u].push_back(v);
    }


    int src , node ;

    cin>>src>>node ;

    bfs(src) ;

    if(!vis[node]){
		cout<<"No Path"<<endl;
	}else{

        vector<int> pth;
        while(node!=-1){
            pth.push_back(node);
            node=parent[node];
        }
        cout << "Path: ";
        for (int i=pth.size()-1; i>=0 ; i--){
            cout << pth[i]<< "->";
        }
	}


    return 0 ;
}
