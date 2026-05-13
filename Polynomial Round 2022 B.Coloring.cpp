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
        int n , m , k ;

        cin>>n>>m>>k ;

        vector<int>a(m) ;

        for(auto &i : a)
        	cin>>i ;


        int seg = n/k ;

        int md = n%k ;

        int cnt = 0 ;
        bool flag = 0 ;

        for(int i=0 ; i<m ; i++){

        	if(a[i]==(seg+1))
        		cnt++ ;

        	if(a[i]>(seg+1)){
        		flag=1 ;
        		break ;
        	}
        }

        if(cnt>md || flag)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;
    }
    return 0 ;
}
