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

    	int a , b;

    	cin>>a>>b ;

    	int n = a-b;

    	cout<<2*n<<endl; 

    	int i= b ;

    	while(i!=a)
    		cout<<++i<<" " ;

    	i=a ;

    	while(i!=b)
    		cout<<--i<<" " ;

    	cout<<endl;


        
    }
    return 0 ;
}
