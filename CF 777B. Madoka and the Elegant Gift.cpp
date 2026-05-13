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
        int n , m , flag=0;

        cin>>n>>m ;

        string s[n] ;

        for(int i=0 ; i<n; i++){
        	cin>>s[i] ;
        }

        for(int i=0 ; i<n-1 ; i++){
        	for(int j= 0 ; j<m-1 ; j++){
        		int sum= 0 ;
        		for(int x=0 ; x<2 ; x++){
        			for(int y=0 ; y<2 ; y++){

        				sum+=(s[i+x][j+y]=='1') ;

        			}
        		}

        		if(sum==3){
        			flag=1;
        			break ;
        		}
        	}

        	if(flag){
        		cout<<"No"<<endl;
        		break ;
        	}
        }

        if(!flag)
        	cout<<"Yes"<<endl;
    }
    return 0 ;
}
