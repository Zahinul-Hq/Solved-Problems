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
	inout();
	

    int n , m ; 

    cin>>n>>m ;

    vector<string>dic , in ;
    string s ;

    for(int i=0 ; i<n ; i++){
    	cin>>s ;
    	dic.pb(s) ;
    }
    for(int i=0 ; i<m ; i++){
    	cin>>s ;
    	in.pb(s) ;
    }


   	for(int i=0 ; i<m ; i++){
   		int f=0;
   		for(int j=0 ; j<n ; j++){

   			int find = dic[j].find(in[i][0]+32) ;
   			if(find!=string::npos)
   			{
   				find = dic[j].find(in[i][1]+32, find+1);
   				if(find!=string::npos)
   				{
   					find = dic[j].find(in[i][2]+32, find+1);

   					if(find!=string::npos){
   						cout<<dic[j]<<endl;
   						f=1;
   						break;
   					}
   				}
   			}
   		}
   		if(!f)
   			cout<<"No valid word"<<endl;
   	}


    return 0 ;
}
