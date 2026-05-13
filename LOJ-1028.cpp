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
const int N = 1e6 + 10;
vector<ll>primes, mark(N, 0);
void pre(){
	for(int i = 2; i * i <= N; i++){
		if(!mark[i]){
			for(int j = i * i; j <= N; j += i){
				mark[j] = i;
			}
		}
	}
	for(int i = 2; i <= N; i++){
		if(!mark[i])
			primes.push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;
	pre();

    int test_cases, cs = 1;
    cin >> test_cases ;



    while (test_cases--)
    {
        ll n;
        cin >> n;

        ll ans = 1, val = n;

        for(ll i = 0; i < primes.size() && primes[i] * primes[i] <= val; i++){
        	ll cnt = 1;
        	while(val % primes[i] == 0 && val > 1){
        		val /= primes[i];
        		cnt++;
        	}

        	//cout << val << " " << primes[i] << " " << cnt << endl;
        	ans *= (cnt);
        }
        if(val != 1)
        	ans *= 2;


        cout <<"Case " << cs++ << ": " <<  ans - 1 << endl;
    }
    return 0 ;
}
