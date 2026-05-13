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
int cntsum[6][100]={0} ;

int  sum(string s, int l ){

	int sum = 0;

	for(int i=0 ; i<l ; i++){
		sum+=(s[i]-'0');
	}
	for(int i=l ; i<s.size(); i++){
		sum-=(s[i]-'0');
	}

	return sum ;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

        int n;

        cin>>n ;

        vector<string>a ;

        string temp ;

        for(int i=0 ; i<n ; i++){
        	cin>>temp ;
        	a.pb(temp) ;
        	int x = sum(temp ,temp.size()) ;
        	cntsum[temp.size()][x]++ ;

        	
        }

        ll ans=0 ;

        for(int i=0 ; i<n ;i++){
        	for(int j=0; j<a[i].size(); j++){

        		if((a[i].size()+j)%2!=0)
        			continue ;

        		int l = (a[i].size()+j)/2 ;

        		int x = sum(a[i] , l );

        		string str = a[i] ;

        		reverse(str.begin() ,str.end()) ;

        		int y = sum(str, l ) ;

        		if(x>0)
        			ans+=cntsum[j][x] ;

        		if(y>0){
        			ans+=cntsum[j][y] ;
        		}
        	}

        	int z = sum(a[i],a[i].size()) ;

        	ans+=cntsum[a[i].size()][z] ;

        }
        cout<<ans<<endl;


        

    return 0 ;
}
