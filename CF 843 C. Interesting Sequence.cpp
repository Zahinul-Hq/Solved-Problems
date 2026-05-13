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
bool is_set(ll val, int i){
	return val & (1LL << i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n, x;

        cin >> n >> x;
         bool p = 0, nt = 0 ;
        ll mx = 0, indx = 0, nt_set = -1;

        if(x == 0){
        	for(int i = 0 ; i <= 60; i++){
        		if(is_set(n, i)){
        			mx = max(mx, 1LL << (i + 1));
        		}
        	}
        	cout << mx << endl;
        	continue;
        }

       

        for(ll i = 0; i <= 60; i++){
        	if(p && !is_set(x, i) && is_set(n, i))
        		nt = 1;
        	if(is_set(x, i) && !is_set(n, i))
        		nt = 1;
        	if(is_set(x, i) && is_set(n, i) && !p){
        		p = 1;
        		indx = i;
        	}
        }
        indx--;
        bool all_set = is_set(n, indx);
        for(int i = indx; i >= 0; i--){
        	if(is_set(n, i)){
        		nt_set = i;
        		break; 
        	}
        }

        
        if(nt || (all_set))
        	cout << -1 << endl;
        else{
        	if(nt_set > -1)
        		mx = 1LL << (nt_set + 1);
        	cout << mx + x  << endl;
        }
    }
    return 0 ;
}
