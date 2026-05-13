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

        cin>>n ;

        string s[2] ;

        cin>>s[0]>>s[1] ;

        int pos= -1 ;

        for(int i=0 ; i<n ; i++){
        	if(s[0][i]!=s[1][i])
        		pos=i ;
        }

        if(pos==-1){
        	cout<<"YES"<<endl;
        	continue ;
        }

        int tg=0 ;

        if(s[1][pos]=='B')
        	tg++ ;

        bool ok = true ;

        for(int i=pos+1; i<n ; i++){

        	if(s[tg][i]=='W')
        		ok = false ;

        	if(s[tg^1][i]=='B')
        		tg=tg^1 ;
        }

        tg=0 ;

        if(s[1][pos]=='B')
        	tg++ ;

        for(int i=pos-1; i>=0 ; i--){

        	if(s[tg][i]=='W')
        		ok = false ;

        	if(s[tg^1][i]=='B')
        		tg=tg^1 ;
        }

        if(ok)
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;

    }
    return 0 ;
}
