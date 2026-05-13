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
        string a ,b ;

        cin>>a>>b ;

        int n = a.size()-1 , m=b.size() -1;


        if(a[0]==b[0]){
        	cout<<"YES"<<endl;
        	cout<<a[0]<<"*"<<endl;
        	continue;
        }
        if(a[n]==b[m]){
        	cout<<"YES"<<endl;
        	cout<<"*"<<a[n]<<endl;
        	continue ;
        }

        bool flag=0;


        for(int i=0 ; i<=n-2; i++){
        	for(int j=n+1 ; j>=i+1 ; j--){
        		if(b.find(a.substr(i,j))>=0 && b.find(a.substr(i,j))<=n){
        			cout<<"YES"<<endl;
        			cout<<"*"<<a.substr(i,j)<<"*"<<endl;
        			flag=1 ;
        			break ;
        		}

        	}

        	if(flag)
        		break;
        }

        if(!flag)
        	cout<<"NO"<<endl;



    }
    return 0 ;
}
