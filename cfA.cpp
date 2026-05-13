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
	#endif
}
int main() {

	//inout() ;
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t ;

    cin>>t ;

    while(t--){


        int p ;

        cin>>p ;

        string x;
        cin >> x;
        string s = "FBFFBFFBFBFFBFFBFB";
        int n = int(s.size());

        int flag =0 ;


        if(s.find(x)!=string::npos)
            cout<<"Yes"<<endl ;
        else
            cout<<"No"<<endl ;




    }


    return 0 ;
}

