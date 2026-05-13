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

        int n = s.size() ;

        map<int ,int>mp ;

        for(int i=0; i<n ; i++){
        	mp[s[i]]++ ;
        }

        int ans=0 ;

        vector<int>mn ;

        for(auto p : mp ){

        	char ch =p.first ;

        	//cout<<ch<<" ";

        	int block= 0 ;

        	for(int j=0 ; j<n ; j++){

        		if(s[j]!=ch ){
        			block++;
        			continue;
        		}	        		
        		ans=max(ans ,block) ;
	        	block=0 ;
        	}

        	ans=max(ans,block) ;
        	mn.pb(ans) ;
        	ans=0 ;
        }

        sort(mn.begin() , mn.end()) ;

        if(mn[0]>0){
        	ans = (int)log2(mn[0]);
        	cout<<ans+1<<endl;
        }else
        	cout<<0<<endl;

        

     
    }
    return 0 ;
}
