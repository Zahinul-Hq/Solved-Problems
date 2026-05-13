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
const int N = 2e5 ;
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
        int n , c,q ;

        cin>>n>>c>>q;
        string s  ;
        vector<string>v ;
        cin>>s ;
        v.pb(s) ;
        int sz = v[0].size() ;

        while(c--){

        	int l ,r ;

        	string temp ;
        	cin>>l>>r ;
        	for(int i=l ; i<=r ; i++){
        		temp+=s[i] ;
        	}
        	s+=temp ;
        }

        while(q--){
        	int x; 
        	cin>>x ;
        	cout<<s[x]<<endl;
        }

        s.clear() ;


    }
    return 0 ;
}
