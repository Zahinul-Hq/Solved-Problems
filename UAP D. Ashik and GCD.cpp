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

const int MAXN = 1e5+7 ;
int n, t[4*MAXN];
void build(int a[], int v, int tl, int tr) {

    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = __gcd(t[v*2] , t[v*2+1]);
    }
}

int GCD(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return __gcd(GCD(v*2, tl, tm, l, min(r, tm))
           ,GCD(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
int main() {

    inout() ;
    
    ll t , n;
    

        
        
        
        long double N , ans=0 , x ;
    
    
        cin>>N ;
        
        ans = (N*37.00)/100.00 ;        
        N = N- ans;
        
        ans = ans*2.00; 

        
        N = N/2.00;

        x = N*3.00 ;
        
        ans+= N +x;
        
        cout<<ans<<endl;
            
        
    return 0;
}
