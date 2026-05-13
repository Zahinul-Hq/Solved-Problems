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
const int N = 1e7 + 3, L = 1 << 31;
vector<bool>is_prime(N + 1, true);
vector<ll>primes;
void sieve(){
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= N; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= N; j += i)
	            is_prime[j] = false;
	    }
	}
	primes.push_back(2);
	for(int i = 3; i < N; i++){
		if(is_prime[i])
			primes.push_back(i);

	}

	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases , cs= 1;
    cin >> test_cases ;

    sieve();
    
    while (test_cases--)
    {
        ll n, ans = 0;
        cin >> n;

        for(int i = 0; i < primes.size(); i++){
        	if(primes[i] > n) break;

        	if(is_prime[n - primes[i]]){
        		ans++;
        	}
        }

        bool p = is_prime[n / 2];

        cout << "Case " << cs++ << ": " << ans / 2  + p << endl;

    }
    return 0 ;
}
