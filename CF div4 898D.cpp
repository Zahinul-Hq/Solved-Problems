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

        int n , k  ,cnt=0;

        cin>>n>>k ;

        cin>>s ;

        for(int i=0 ; i<s.size() ; i++){

        	if(s[i]=='B'){

        		int range=i , j=0;

        		for( j=0 ; j<k && (i+j)<n ; j++){

        			if(s[i+j]=='B')
        				s[i+j]='W' ;
        		}

        		cnt++ ;

        	}

        }

        cout<<cnt<<endl;
    }
    return 0 ;
}
