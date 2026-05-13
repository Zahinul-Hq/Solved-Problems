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
const int N = 2e5+9 ;
int n , k ;
vector<int>vec(N,0) ;
bool f(int x ){

	int cnt=0 ,i;

	for(i=x ; i<=n ; i+=x){

		if(vec[i-x]!=vec[i])
			cnt++ ;

		if(cnt>1)
			return false ;
	}

	return (i==n+) ;
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
    	cin>>n>>k ;

    	for(int i=1 ; i<=n ; i++){
    		cin>>vec[i] ;
    	} 

    	int hi = n-1 , lo = 0  ;

    	for(int j=n-1 ; j>=1 ; j--){

    		if(f(j))
    			lo=j ;
    		
    	}

    	cout<<lo<<endl;
    }
    return 0 ;
}
