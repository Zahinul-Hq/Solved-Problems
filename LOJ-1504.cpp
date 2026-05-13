#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
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

    ll n, m, d, q, y, qq = 1;
    cin >> n;
    vector<ll>calenders[n + 1], months(n + 1, 0), total_days(n + 1, 0);

    for(int i = 1; i <= n; i++){
    	cin >> m;
    	for(int j = 0; j < m; j++){
    		cin >> d;
    		calenders[i].push_back(d);
    		total_days[i] += d;
    	}
    }
    cin >> q;

    while(q--){
    	int from, to;
    	cin >> from >> to >> d >> m >> y;

    	ll total_d = ((y - 1) * total_days[from]) + d - 1 ;
    	for(int i = 0; i < m - 1; i++){
    		total_d += calenders[from][i];
    	}
    	ll dy = total_d / total_days[to], dm = 0, dd = 0;

    	total_d %= total_days[to];

    	for(int i = 0; i < calenders[to].size(); i++){
    		if(total_d - calenders[to][i] >= 0){
    			dm++;
    			total_d -= calenders[to][i];
    		}else{
    			break;
    		}
    	}
    	
    	dd = total_d;

    	cout << "Query " << qq++ << ": " << dd + 1 <<" " << dm + 1 << " " << dy + 1 << endl; 
    }
    return 0 ;
}
