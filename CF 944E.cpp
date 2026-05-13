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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        ll n, k , q, x;

        cin >> n >> k >> q;

        vector<ll>dis, tm;

        dis.push_back(0);
        tm.push_back(0);

        for(int i = 0; i < k; i++){
        	cin >> x;
        	dis.push_back(x);

        }
        for(int i = 0; i < k; i++){
        	cin >> x;
        	tm.push_back(x);
        }

        while(q--){

        	ll d;

        	cin >> d;

        	

        	int dpos = lower_bound(dis.begin(), dis.end(), d) - dis.begin();

        	if(dis[dpos] == d){
        		cout << tm[dpos] << " ";
        		continue;
        	}



        	int sm = (dis[dpos] - dis[dpos - 1]) ;

        	int tt = (tm[dpos] - tm[dpos - 1]) ;

        	int rt;

        	//cout << "n" << endl;

        	//cout << sm << " " << tt << " " << rt << endl;

        	//cout << rt << " rt " << endl;


        	d -=  dis[dpos - 1];

        	//cout << sm << endl;

        	ll ans =  0;

        	ans = ((tt * d) / sm) + tm[dpos - 1];

        	cout << ans << " ";
        }

        cout << endl;
    }
    return 0 ;
}
