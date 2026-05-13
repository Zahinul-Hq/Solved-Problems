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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N = 1e5 + 7;
vector<ll>primes;
map<ll,int>mp;
void pre_calculate(){

	vector<bool>mark(N, 0);

	for(ll i = 2; i * i < N; i++){
		for(ll j = i * i; j < N; j += i){
			mark[j] = 1;
		}
	}
	for(int i = 2; i <= N; i++){
		if(!mark[i])
			primes.push_back(i);
	}

}
void check(int val){

	for(int i = 0; primes[i] * primes[i] <= val && i < primes.size(); i++){
		if(val % primes[i] == 0){
			while(val % primes[i] == 0)
				val = val / primes[i];
			mp[primes[i]]++;
		}
	}
	if(val > 1)
		mp[val]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    pre_calculate();
    
    while (test_cases--)
    {
        int n , x;
        
        bool ok = 0;

        mp.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
        	cin >> x;
        	check(x);
        }
        for(auto i : mp){
        	if(i.S >= 2)
        		ok = 1;
        }
        if(ok)
        	cout << "YES" << endl;
        else
        	cout << "NO" << endl;
    }
    return 0 ;
}
