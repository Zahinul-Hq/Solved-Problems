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
const int N = 32768+7 ;
vector<int>d(N, 0) ;
vector<int>graph[N] ;
void bfs(int src){

	 d[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : graph[v]) {
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n,x ;

    for(int i=0 ; i<32768 ;i++){

    	graph[(i * 2) % 32768].push_back(i);
        graph[(i + 1) % 32768].push_back(i);
    }

    cin>>n ;


    bfs(0);

    for(int i=1;i<=n ; i++){
    	cin>>x ;
    	cout<<d[x]<<" ";
    }
    return 0 ;
}
