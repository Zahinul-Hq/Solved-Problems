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

        int a[n][m] , temp[n][m];

        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<m; j++){
        		cin>>a[i][j];
        		temp[i][j]=a[i][j];
        	}
        }
        for(int i=0 ; i<n ; i++){
        	sort(temp[i] , temp[i]+m);
        }

        int l=-1 ,r=-1;
        bool f=false ;
        for(int i=0 ; i<n ; i++){
        	l=-1 ,r=-1 ;
        	for(int j=0 ; j<m; j++){

        		if(a[i][j]!=temp[i][j] && l<0){
        			l=j ;
        		}else if(a[i][j]!=temp[i][j] && r<0){
        			r=j ;
        		}else if(a[i][j]!=temp[i][j]){
        			f=true ;
        		}
        	}

        	if(l>-1 &&r>-1)
        		break;
        }

        if(f){
        	cout<<-1<<endl;
        	continue;
        }
        if(!f && l==-1 && r==-1){
        	cout<<1<<" "<<1<<endl;
        	continue;
        }

        for(int i=0 ; i<n ; i++){
        	swap(a[i][l],a[i][r]);
        }

        bool ff = true ;

        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<m; j++){

        		if(temp[i][j]!=a[i][j]){
        			ff=false;
        		}
        	}

        	if(!ff)
        		break;
        }

        if(ff)
        	cout<<l+1<<" "<<r+1<<endl;
        else{
        	cout<<-1<<endl;
        }
    }


    return 0 ;
}
