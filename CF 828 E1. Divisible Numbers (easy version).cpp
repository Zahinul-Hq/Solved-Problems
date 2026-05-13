#include<bits/stdc++.h>
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
ll a, b, c, d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;

    while (t--)
    {
        cin >> a >> b >> c >> d;
 

        bool done = 0;

        vector<pair<ll,ll>>afact, bfact;


        for(ll i = 1; i * i <= a; i++){
        	if(a % i == 0){
        		afact.push_back({i, a/i});
        		afact.push_back({a/i, i});
        	}

        }
        for(ll i = 1; i * i <= b; i++){
        	if(b % i == 0){
        		bfact.push_back({i, b/i});
        		bfact.push_back({b/i, i});
        	}
        }

        for(auto i : afact){
        	for(auto j : bfact){

        		ll a1 = i.first, a2 = i.second;
        		ll b1 = j.first, b2 = j.second;

        		ll a1b1 = a1 * b1, a2b2 = a2 * b2;

        		ll k1 = (a / a1b1) + 1, k2 = (b / a2b2) + 1;

        		if(k1 * a1b1 <= c && k2 * a2b2 <= d){
        			cout << a1b1 * k1 << " " << a2b2 * k2<< endl;
        			done = 1;
        			break;
        		}
        	}
        	if(done)
        		break;
        }

        if(!done)
        	cout << -1 << " " << -1 << endl;

        
    }
    return 0 ;
}
