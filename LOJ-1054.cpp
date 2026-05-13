#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;

const int MOD = 1e9 + 7;



ll binary_expo(ll base, ll pwr, ll mod){
	ll result = 1; 
	base %= mod;
	while(pwr){
		if(pwr & 1){
			result = (result * 1LL * base) % mod;
		}
		base = (base * 1LL * base) % mod;
		pwr >>= 1;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll n, m;

    	cin >> n >> m;

    	ll sod = 1;

        map<ll,ll>cnt;

    	for(ll i = 2;  i * i <= n ; i++){

    		if(n % i != 0)continue;
    		while(n % i == 0){
    			cnt[i]++;
    			n /= i;
    		}
    	}

    	if(n > 1){
            cnt[n]++;
    	}

        for(auto i : cnt){

            i.second *= m;
            ll tval = binary_expo(i.first,(i.second + 1 ), MOD);
            ll d = binary_expo(i.first - 1, MOD - 2, MOD);

            tval -= 1;
            if(tval < 0)
                tval += MOD;

            tval %= MOD;

            tval *= d;
            sod = ((sod % MOD) *(tval % MOD)) % MOD;

        }

    	cout<< "Case " << cs++ << ": "<< sod << endl;

    }
    return 0 ;


}