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

        cin>>n ;

        string s; 

        cin>>s ;

        vector<pair<char,int>>ch ;
        vector<pair<int,char>>a ;

        ch.pb({s[n-1], n-1});
        a.pb({n-1,s[n-1]});

        for(int i=n-2; i>=0 ; i--){

        	if(s[i]>=(ch.back().F)){
                ch.pb({s[i],i});
                a.pb({i,s[i]});
            }
        }

        sort(a.begin() ,a.end()) ;
        /*for(int i=0 ; i<ch.size() ; i++){
            cout<<ch[i].F<<" "<<ch[i].S<<endl;
        }*/
        int pos= 0 ;
        int ans = 0 ;
        for(int i=n-1 ; i>=0 ; i--){
        	if(ch[pos].S==i && pos<ch.size()){
        		s[i]=a[pos].S;
        		pos++;
                ans++;
        	}
        }
        int j=0 ;

        while(a[0].S==a[j].S  && j<a.size()){
            j++ ;
        }

        if(is_sorted(s.begin() , s.end())){
        	cout<<ans-j<<endl;
        }else{
        	cout<<-1<<endl;
        }
    }
    return 0 ;
}
