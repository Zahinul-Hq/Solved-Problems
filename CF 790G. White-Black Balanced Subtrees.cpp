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

const int N = 4000+7 ;
vector<int>graph[N] ;
bool visited[N];
int f[N], cnt ;
string color ;
void dfs(int v, int p){

	for(int child : graph[v]){

		if(child!=p){

			dfs(child , v) ;

			f[v]+=f[child] ;
		}


	}

	if(color[v]=='W')
		f[v]++ ;
	else
		f[v]-- ;

	cnt+=!f[v];

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        int n ,x;

        cin>>n ;

        for(int i = 1; i <= n-1; i++){
    		cin >> x; 
    		graph[i+1].push_back(x);
    		graph[x].push_back(i+1);
    	}

        cin>>color ;

        color = 'x'+color ;

        dfs(1,0);

        //cout<<black<<" "<<white<<endl;

        cout<<cnt<<endl;

        for(int i=0 ; i<=n ; i++){
        	f[i]=0 ;
        	graph[i].clear() ;

        }
         cnt=0 ;


    }
    return 0 ;
}