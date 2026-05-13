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

#define MAXN 1000001
 
// stores smallest prime factor for every number
vector<int> spf(MAXN,1);
 
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

map<int,int>mp ;
 
void getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        mp[spf[x]]++ ;
        x = x / spf[x];
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;

    sieve() ;
    
    while (t--)
    {
        int sz ;

        cin>>sz ;

        vector<int>a(sz,0) ;

        for(int i=0 ; i<sz; i++){

        	cin>>a[i];
        }

        for(int i=0 ; i<sz ; i++){

        	getFactorization(a[i]);
        }

        bool flag = 0 ;

        for(auto i : mp){

        	if(i.S %sz!=0)
        		flag=1 ;
        }

        if(flag)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;

        mp.clear() ;
    }
    return 0 ;
}
