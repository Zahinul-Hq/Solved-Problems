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
        int n,x ,flag=0;

        cin>>n ;

        vector<int>p(n+1 ,0) , q(n+1,0);

        vector<pair<int,int>>a ;

        map<int,int>cnt , mp , mq ;

        for(int i=1 ; i<=n ; i++){

        	cin>>x;
        	cnt[x]++ ;

        	a.pb({x,i}) ;

        	mp[x]=1; 
        	mq[x]=1 ;

        	if(cnt[x]>2 || cnt[1]>1)
        		flag=1 ; 
        }

        if(flag){
        	cout<<"No"<<endl;
        	continue ;
        }

        sort(a.rbegin() , a.rend()) ;

        for(int i=0 ; i<n ;i++){

        	int k = a[i].S ;

        	if(mp[a[k].F]>0){

        		p[k]=a[k].F ;

        		mp[a[k].F]--;
        	}else{

        		q[k]=a[k].F;
        		mq[a[k].F]--;
        	}
        }


    int r1 = n, r2 = n;
	for (int i = 0; i < n; i++)
	{
		int k = a[i].second;
		if (p[k] == 0)
		{
			while (mp[r1] == 0) r1--;
			mp[r1]--;
			if (r1 > q[k])
			{
			    flag=1 ;
			}
			p[k] = r1--;
		}
		else
		{
			while (mq[r2] == 0) r2--;
			mq[r2]--;
			if (r2 > p[k])
			{
			    flag=1;
			}
			q[k] = r2--;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (mp[i] != 0 || mq[i] != 0)
		{
			flag=1 ;
		}
	}
	if(flag)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;












    }
    return 0 ;
}
