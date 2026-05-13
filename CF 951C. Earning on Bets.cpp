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

ll lcm(ll a, ll b){

	return (a * b) / __gcd(a, b);
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
        int n;
        cin >> n ;

        vector<int>arr(n);
        ll mul = 1, sum = 0;
        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	mul = lcm(mul, arr[i]);
        }
        for(int i = 0; i < n; i++){
        	sum += (mul / arr[i]);
        }

        if(sum >= mul){
        	cout << -1 << endl;
        	continue;
        }

        for(int i = 0; i < n; i++){
        	cout << mul / arr[i] << " ";
        }
        cout << endl;

    }
    return 0 ;
}
