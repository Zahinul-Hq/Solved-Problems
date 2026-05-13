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

        vector<int>a(n,0) ;
        vector<char>s(n, '0') ;


        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        }

        map<char,int>mp ;

        for(char ch = 'a'  ; ch<='z'; ch++){

        	for(int i=0 ; i<n ; i++){
        		if(mp[ch]==a[i] && s[i]==('0')){
        			s[i]= ch ;
        			mp[ch]++ ;
        		}
        	}	
        }

        for(int i=0 ; i<n ; i++){
        	cout<<s[i] ;
        }

        cout<<endl;
    }
    return 0 ;
}
