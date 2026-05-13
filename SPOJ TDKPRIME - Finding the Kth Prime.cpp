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

const int N =  86028119;
vector<bool>is_prime(N, true);
vector<int>primes;
void seive(){

    for(ll i = 3; i*i <= N; i += 2){
        if(is_prime[i])
            for(int j = i + i; j <= N; j += i)
                is_prime[j] = false;
    }
    primes.push_back(2);

    for(int i = 3; i <= N; i += 2){
        if(is_prime[i])
            primes.push_back(i);
    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//inout() ;

	seive();

	int t;
	cin >> t;



	while(t--){
        int pos;

        cin >> pos;

        cout << primes[pos - 1]<< endl;
	}
    return 0 ;
}
