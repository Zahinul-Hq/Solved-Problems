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

ll breaking_process(ll val){

	ll res = 0;

	while(val ){

		res += (val % 10) * (val % 10);

		val = val / 10;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    ll n;
    bool flag = 0; 

    cin >> n;

    map<ll,ll>mp;

    mp[n]++;




    int cnt = 0;

    while(n > 1){

    	n = breaking_process(n);

    	if(mp.find(n) == mp.end()){
    		mp[n]++;
    		cnt++;
    	}else{

    		flag = 1;
    		break;
    	}

    }

    if(flag){
    	cout << -1 << endl;
    }else{
    	cout << cnt << endl;
    }


    return 0 ;
}
