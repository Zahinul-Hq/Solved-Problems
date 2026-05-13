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
        string s  ,ans="1";

        cin>>s;

        int pos=-s.size()-1;

        for(int i=s.size()-1 ;i>=1 ; i--){

        	if(s[i]>'4'){

        		while(s[i]>='4' && i>=1)
        			i--;
        		
        		s[i]++ ;

        		pos=i ;
        	}
       	}

       	while(pos++<=s.size()-1)
       		s[pos]='0' ;

        if(s[0]>'4'){
        	while(ans.size()!=s.size()+1){
        		ans+='0';
        	}
        	cout<<ans<<endl;
        }else{
        	cout<<s<<endl;
        }

    }
    return 0 ;
}
