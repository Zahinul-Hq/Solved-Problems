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
        int n, m ;

        cin>>n>>m ;

        string s[n] ;

        for(int i=0 ; i<n ; i++){
        	cin>>s[i] ;
        }

        bool flag=0 ;
        bool last= 0 ;

        for(int i=0 ; i<n ; i++){
        	int cnt =0 ;
        	for(int j=0 ; j<m ; j++){
        		if(s[i][j]!='.'){
        			cnt++ ;

        			if(s[i][j]=='U'){

        				if(last){

        					s[i][j]='B';
        					s[i+1][j]='W' ;

        				}else{
        					s[i][j]='W';
        					s[i+1][j]='B' ;
        				}
        				last^=1 ;
        			}
        		}
        	}

        	if(cnt%2!=0)
        		flag=1;
        }

        last=1 ;

        for(int i=0; i<m ; i++){
        	int cnt =0 ;
        	for(int j=0 ; j<n ; j++){
        		if(s[j][i]!='.'){
        			cnt++ ;

        			if(s[j][i]=='L'){

        				if(last){
        					s[j][i]='B';
        					s[j][i+1]='W' ;
        				}
        				else{
        					s[j][i]='W' ;
        					s[j][i+1]='B' ;
        				}

        				last^=1 ;
        			}
        		}

        	}

        	if(cnt%2!=0)
        		flag=1;
        }

        if(flag){
        	cout<<-1<<endl;
        	continue ;
        }

        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<m ; j++){
        		cout<<s[i][j] ;
        	}
        	cout<<endl;
        }






    }
    return 0 ;
}
