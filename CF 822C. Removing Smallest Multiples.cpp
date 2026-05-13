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
        int n ;

        string s ;

        cin>>n>>s ;

        vector<int>cost(n+1,0) ;



        ll sum= 0 ;


        for(int i=n; i>=1 ; i--){
        	
        		for(int j=i ; j<=n ; j+=i){
        			if(s[j-1]=='0'){
        				cost[j]=i ;
        			}else
        				break;
        		

        	}
        }

        for(int i=1 ; i<=n ; i++){
        	if(s[i-1]=='0')
        		sum+=cost[i];
        }


        cout<<sum<<endl;
    }


    return 0 ;
}
