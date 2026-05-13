#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128_t ll;
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
const int N = 1e4 + 7;
vector<bool>is_prime(N, true), primes;
void seive(){
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i < N; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j < N; j += i)
	            is_prime[j] = false;
	    }
	}
	for(int i = 1; i < N; i++){
		if(is_prime[i])
			primes.push_back(i);
	}
	// Change N 
}
string string_multiplication(string a, ll b){
	string result = "";
	ll carry = 0;
	reverse(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++){

		carry = (a[i] - '0') * b + carry;
		result += ((carry % 10) + '0') ;
		carry = carry / 10;
	}
	while(carry != 0){
		result += (carry % 10) + '0';
		carry /= 10;
	}
	return result;


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
      	int n;
        cin >> n;
        vector<ll>arr(n);
        for(int i = 0; i < n; i++){
       		cin >> arr[i];
       	}

       	ll ans = lcm(arr[0], arr[1]);

       	for(int i = 2; i < n; i++){
       		ans = lcm(ans, arr[i]);
       	}
       	cout <<"Case " << cs++ << ": " << ans << endl;
    }
    return 0 ;
}
