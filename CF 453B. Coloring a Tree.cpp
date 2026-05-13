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
const int N = 1e4+7;
vector<int>graph[N] ;
vector<int>color(N,0) ;
vector<bool>visited(N,0);

int cnt=1 ;

void bfs(int src){

	queue<int>q;

	q.push(src);
	visited[src]=true;

	while(!q.empty()){

		int par =q.front() ;
		q.pop();

		for(int child : graph[par]){

			if(visited[child]){
				continue ;
			}

			q.push(child) ;

			visited[child]=true ;

			if(color[child]!=color[par])
				cnt++ ;

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;



        int n ,x;

        cin>>n ;

        for(int i=1 ; i<=n-1 ; i++){
        	cin>>x;

        	graph[i+1].push_back(x);
        	graph[x].push_back(i+1);

        }

        for(int i=1 ;i<=n;i++){
        	cin>>color[i] ;
        	
        }

        bfs(1) ;


        cout<<cnt<<endl;
    
	

	return 0 ;

}

