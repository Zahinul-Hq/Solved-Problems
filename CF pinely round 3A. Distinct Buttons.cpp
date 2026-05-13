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
        cin>>n;

        vector<bool>mark(4,0) ;

        while(n--){
        	int x , y ;

        	cin>>x>>y ;

        	if(x>0 )
        		mark[1]=1;
        	if(x<0 )
        		mark[2]=1;
        	if(y>0)
        		mark[3]=1;
        	if(y<0)
        		mark[4]=1;

        }

        int cnt = 0 ;

        for(int i=1 ; i<=4 ; i++){
        	if(mark[i])
        		cnt++ ;
        }

        if(cnt>=3){
        	cout<<"No"<<endl;
        	continue ;
        }
        if(cnt<=1){
        	cout<<"Yes"<<endl;
        	continue ;
        }

        
        if(mark[1] && mark[3]){

        	cout<<"No"<<endl;
        }else if(mark[2] && mark[4]){
        	cout<<"No"<<endl;
        }else{
        	cout<<"Yes"<<endl;
        }

    }
    return 0 ;
}
