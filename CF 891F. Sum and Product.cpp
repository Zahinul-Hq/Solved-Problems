#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
map<long long, int>cnt;
long long my_sqrt(long long a)
{
    long long l = 0, r = 5000000001;
    while(r - l > 1)
    {
        long long mid = (l + r) / 2;
        if(1ll * mid * mid <= a)
        	l = mid;
        else
        	r=mid;
    }
    return l;
}
long long get(int b,long long c)
{
    long long D=1ll*b*b-4ll*c;
    if(D<0)return 0;
    long long x1=(b-my_sqrt(D))/2;
    long long x2=(b+my_sqrt(D))/2;
    if(x1+x2!=b||x1*x2!=c)return 0;
    if(x1==x2)return 1ll*cnt[x1]*(cnt[x1]-1)/2ll;
    else return 1ll*cnt[x1]*cnt[x2];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout();

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, q;
        cin >> n;
        cnt.clear();

        for(int i = 0; i < n; i++){
        	int x; cin >> x;
        	cnt[x]++;
        }
        ll b, c;
        cin >> q;
        while(q--){
        	cin >> b >> c;
        	cout << get(b,c) << " ";
        }
        cout << endl;
    }
    return 0 ;
}
