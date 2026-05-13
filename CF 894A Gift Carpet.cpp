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
        int n , m ;

        cin>>n>>m ;

        char inp[n][m] ;

        for(int i=0;i<n;i++){
        	for(int j=0; j<m ; j++){

        		cin>>inp[i][j] ;
        	}
        }

        bool v=0 , ii=0 , k=0 ,a=0 ;

        for(int i=0;i<n;i++){
        	for(int j=0; j<m ; j++){

        		if(inp[j][i]=='v'){
        			v=1;
        			break ;
        		}

        		if(inp[j][i]=='i'){
        			ii=1;
        			break ;
        		}
        		if(inp[j][i]=='k'){
        			k=1;
        			break ;
        		}
        		if(inp[j][i]=='a'){
        			a=1;
        			break ;
        		}
        		
        	}
        }

        if((v==1 && ii==1)&&(k==1 && a==1))
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;


    }
    return 0 ;
}
