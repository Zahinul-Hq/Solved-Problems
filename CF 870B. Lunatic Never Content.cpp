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
const int N= 1e5+7;
vector<int>vec(N , 0) ;
int n ; 
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
        cin>>n ;

        for(int i=0 ; i<n ; i++){
        	cin>>vec[i] ;
        }

        if(n==1){
        	cout<<0<<endl; 
        	continue ;
        }

        vector<int>ans(n/2 ,0) ;

        for(int i=0 ; i<(n/2) ; i++){
        	ans[i]=(abs(vec[n-i-1]-vec[i])) ;
		}
		int ss=ans[0];

		
		for(int i=1 ; i<ans.size() ; i++){
			ss = __gcd(ss,ans[i]) ;
		}
		
	

		cout<<ss<<endl; 

        

        
    }
    return 0 ;
}
