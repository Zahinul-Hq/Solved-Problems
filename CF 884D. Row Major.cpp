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
        int n , sz=2;

        cin>>n ;

        if(n==1){
        	cout<<'a'<<endl;
        	continue ;
        }

        for(int i=2 ; i<=n ; i++){
        	if(n%i!=0){
        		sz=i;
        		break ;
        	}
        }

        string s="" , l=""  ,ans="";

        for(char ch = 'a' ; ch-'a'<sz ;ch++){
        	s+=ch ;
        	if(ch-'a'<(n%sz))
        		l+=ch;
        }

        for(int i=1; i<=(n/sz) ; i++){
        	ans+=s ;
        }

        cout<<ans+l<<endl;
    }
    return 0 ;
}
