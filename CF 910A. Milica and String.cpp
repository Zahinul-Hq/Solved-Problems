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

        string s ;

        cin>>s ;

        map<char,int>mp ;

        for(int i=0 ; i<n ; i++){
        	mp[s[i]]++ ;
        }

        if(mp['B']==k){
        	cout<<0<<endl;
        	continue ;
        }

        int cnt=0 ;

        if(mp['B']>k){

        	int x = mp['B']-k ;

        	int in=-1;

        	for(int i=0 ; i<n ; i++){
        		
        		if(s[i]=='B'){
        			cnt++ ;

        		}
        		in= i;

        		if(cnt==x){
        			break;
        		}


        	}

        	cout<<1<<endl;
        	cout<<in+1<<" A"<<endl;

        }
        if(mp['B']<k){

        	int x = k-mp['B'] ;

        	int in=-1;

        	for(int i=0 ; i<n ; i++){
        		
        		if(s[i]=='A'){
        			cnt++ ;

        		}
        		in= i;

        		if(cnt==x){
        			break;
        		}


        	}
        	cout<<1<<endl;
        	cout<<in+1<<" B"<<endl;
        }
    }
    return 0 ;
}
