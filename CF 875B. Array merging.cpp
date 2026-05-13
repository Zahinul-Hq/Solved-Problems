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

        vector<int>frst(n,0) ;
        vector<int>sec(n,0); 

        for(int i=0 ; i<n ; i++){
        	cin>>frst[i] ;
        }
        for(int i=0 ; i<n ; i++){
        	cin>>sec[i] ;
        }


        int i ,j=0 ;
        map<int ,int>mp ;
        for( i=0 ; i<n ;){

        	j=i+1 ;
        	int cnt=1;
        	while(frst[i]==frst[j] && j<n){
        		j++;
        		cnt++ ;
        		
        	}
        	mp[frst[i]]=max(mp[frst[i]] , (cnt));
        	i=j ;
        }

        map<int,int>mp2 ;

        for( i=0 ; i<n ;){

        	j=i+1 ;
        	int cnt=1 ;
        	while(sec[i]==sec[j] && j<n){
        		j++;
        		cnt++ ;
        	}
        	mp2[sec[i]]=max(mp2[sec[i]] , (cnt));
        	i=j ;
        }
        int ans=-1 ;
        for(int k=1 ; k<=(2*n) ;k++){
        	ans= max(ans , (mp[k]+mp2[k])) ;
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
