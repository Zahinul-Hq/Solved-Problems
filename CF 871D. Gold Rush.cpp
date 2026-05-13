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

bool f(int n , int m  ){

	if(n==m)
		return 1 ;
	if(n<m || n%3!=0)
		return 0 ;

	return f(n/3, m)||f(2*n/3, m) ;
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

    	int n , m ;
      	

      	cin>>n>>m ;

      	if(f(n,m))
      		cout<<"yes"<<endl;
      	else
      		cout<<"No"<<endl;

      	

    }
    return 0 ;
}
