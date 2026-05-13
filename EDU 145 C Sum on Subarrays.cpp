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
    	int n , k ;
        cin>>n>>k ;

        int p=0 ;

        while(p*(p+1)/2 <= k)
        	p++ ;

        int ex = p*(p+1)/2 - k ;

        bool f = 1 ;

        for(int i=1 ; i<=n ;i++ ){

        	if(i<p){
        		cout<<2 ;
        	}
        	else if(ex>0 && i==p){
        		cout<<(1-(ex*2));
        	}
        	else
        		cout<<-1000;

        	if(i==n)
        		cout<<endl;
        	else
        		cout<<" " ;

        }
    }
    return 0 ;
}
