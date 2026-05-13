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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


    while(1)
    {
    	int n ;
    	cin>>n ;

    	if(n==0)
    		break ;

    	vector<int>a[n] ;

	    for(int i=0 ; i<n ; i++)
	    {
	    	for(int l=0 ; l<5 ;l++)
	    	{
	    	    int x ;
	    		cin>>x ;

	    		a[i].push_back(x) ;
	    	}

	    	sort(a[i].begin() , a[i].end()) ;

	    }

	    for(int i=0 ; i<n ; i++)
	    {
	    	for(int l=0 ; l<5 ;l++)
	    	{
                cout<<a[i][l]<<" ";
	    	}

        cout<<endl;


	    }


	    vector<int> ct ;

	    for(int j=0 ;j<5 ;j++)
	    {

	        set<int>st ;
	    	for(int i=0 ;i<n ;i++)
	    	{
	    		st.insert(a[i][j]) ;
	    	}

	    	cout<<st.size()<<endl ;

	    	ct.push_back(st.size()) ;
	    }


	    	int mx = *max_element(ct.begin() , ct.end()) ;


	    	cout<<mx<<endl ;


    }

    return 0 ;
}


