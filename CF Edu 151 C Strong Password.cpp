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
        string s , l ,r ;

        cin>>s ;

        int m ,p=-1 ,flag=0;

        cin>>m>>l>>r ;



        for(int i=0 ;i<m ;i++){
        	int mx = -1 ;
        	for(char d=l[i];d<=r[i];d++ ){
        		int nxt=p+1;
        		while(nxt<s.size() && s[nxt]!=d){
        			nxt++ ;
        		}

        		mx=max(mx,nxt);
        	}
        	if(mx==-1)
        		break;
        	p=mx;
        	if(mx>=s.size()){
        		flag=1;
        		break;
        	}
        }

        if(flag)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;
    }
    return 0 ;
}
