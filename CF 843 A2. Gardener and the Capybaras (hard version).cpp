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
        string s ;

        cin>>s ;

        int pos=0 ;

        for(int i=1 ; i<s.size()-1 ; i++){

        	if(s[i]=='a'){
        		pos=i ;
        		break;
        	}
        }


        if(pos)
        	cout<<s.substr(0 , pos)<<" a "<<s.substr(pos+1)<<endl;
        else
        	cout<<s[0]<<" "<<s.substr(1, s.size()-2)<<" "<<s[s.size()-1]<<endl;

        
    }
    return 0 ;
}
