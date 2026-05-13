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

const int N = 1e9 + 7;
map<ll,int>mp ;
ll val = 1;

void pre_calculate(){
	int i = 1;
	while(val < N){
		mp[val]++;
		val = val + 6LL * i++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    pre_calculate();

    while (1)
    {
        ll n ;
        cin >> n;

        if(n == -1)
        	break;

        if(mp.find(n) != mp.end()){
        	cout << "Y" << endl;
        }else{
        	cout << "N" << endl;
        }
    }
    return 0 ;
}
