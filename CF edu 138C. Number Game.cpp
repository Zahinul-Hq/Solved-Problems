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

bool check(vector<int>a ,int k){

	multiset<int>s(a.begin() , a.end())  ;

	for(int i=0; i<k ; i++){

		if(s.empty())
			return false ;

		int req = k-i ;

		auto it = s.upper_bound(req) ;

		if(it==s.begin())
			return false;

		it-- ;
		s.erase(it) ;

		if(!s.empty()){
			int q = *s.begin() ;

			q+=(k-i) ;

			s.erase(s.begin());
			s.insert(q) ;

		}
	}

	return true ;
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
        int n ,x;

        cin>>n;

        vector<int>v ;

        for(int i=1 ; i<=n ; i++){
        	cin>>x ;
        	v.pb(x);
        }

        sort(v.begin() , v.end()) ;


        int ans = 0;


        for(int i=1 ; i<=n ; i++){

        	if(check(v, i))
        		ans=i ;
        }
        

        cout<<ans<<endl;
    }
    return 0 ;
}
