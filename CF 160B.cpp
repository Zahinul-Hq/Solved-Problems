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
        map<char,int>mp ;

        for(int i=0 ; i<s.size() ; i++){
        	mp[s[i]]++ ;
        }

        int i=0  , n=s.size()-1;

        for(i=0 ; i<=n ; i++){

        	if(s[i]=='0'){
        		if(mp['1']==0)
        			break;
        		mp['1']-- ;
        	}else{

        		if(mp['0']==0)
        			break;
        		mp['0']--;
        	}

        }

        cout<<n-i+1<<endl;
    }
    return 0 ;
}
