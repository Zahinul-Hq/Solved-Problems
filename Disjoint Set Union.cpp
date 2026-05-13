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
const int N = 1e5 + 7 ;
int parent[N] ;
int size[N] ;
void make_set(int v) {
    parent[v] = v;
    size[v]=1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

   	int n , k ;
   	cin>>n>>k ;

   	for(int i= 1; i<=n ; i++){
   		make_set(i);
   	}

   	while(k--){
   		int u, v ;

   		cin>>u>>v ;
   		union_sets(u,v);
   	}
    return 0 ;
}
