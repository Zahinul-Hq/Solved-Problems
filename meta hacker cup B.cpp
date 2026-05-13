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
const int N = 1e7 + 3;
vector<bool> is_prime(N+1, true);
vector<int>primes;
set<int>diffs;
void sieve(){
	is_prime[0] = is_prime[1] = false;
	for (ll i = 3; i * i <= N; i += 2) {
	    if (is_prime[i]) {
	        for (ll j = i * i; j <= N; j += i)
	            is_prime[j] = false;
	    }
	}
	primes.push_back(2);
	for(int i = 3, j = 2; i <= N; i += 2, j += 2){
		if(is_prime[i]){
			primes.push_back(i);
		}
		if(j != 2){
			is_prime[j] = false;
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    sieve();

    set<int>st;
    st.insert(2);
    vector<pair<int,int>>val;
    val.push_back({2, 0});
    int cnt = 1;

    for(int i = 1; i < primes.size(); i++){
    	int d = primes[i] - primes[0];
    	if(is_prime[d]){
    		st.insert(d);
    	}
    	val.push_back({primes[i], st.size()});
    }
    int test, cs = 1;
    cin >> test;


    while(test--){
    	int n;
    	cin >> n;

    	if(n < 5){
    		cout << "Case #" << cs++ << ": " << 0 << endl;
    		continue;
    	}


    	int it = lower_bound(primes.begin(), primes.end(), n) - primes.begin();



    	if(is_prime[n]){
    		cout << "Case #" << cs++ << ": " << val[it].second << endl;
    	}else{
    		cout << "Case #" << cs++ << ": " << val[it - 1].second << endl;
    	}

    }


    
    return 0 ;
}
