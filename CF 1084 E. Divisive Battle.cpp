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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 1e6 + 7;
vector<bool>is_prime(N, true);
vector<int> primes, pwrs(N, 0);
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
 
}
void pre_calcualte(){
	seive();

	pwrs[1] = 1;
	for(int i : primes){
		ll val = i;
		while(val < N){
			pwrs[val] = i;
			val *= i; 
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;

    pre_calcualte();
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	vector<int>arr(n);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}

    	if(is_sorted(arr.begin(), arr.end())){
    		cout << "Bob" << endl;
    		continue;
    	}

    	bool f = 0;

    	for(int i = 0; i < n; i++){

    		if(!pwrs[arr[i]]) f = 1;
    		else arr[i] = pwrs[arr[i]];
    		
    	}

    	if(is_sorted(arr.begin(), arr.end()) && !f){
    		cout << "Bob" << endl;
    	}else{
    		cout << "Alice" << endl;
    	}
    }
    return 0 ;

    runtime();

}
