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
const int N = 5e6 + 7;
vector<int>phi(N);
vector<unsigned long long> pref(N);
void phi_function(){
	for(int i = 1; i < N; i++){
		phi[i] = i;
	}
	for(int i = 2; i < N; i++){
		if(phi[i] == i){
			for(int j = i; j < N; j += i){
				phi[j] -= (phi[j] / i);
			}
		}
	}
	for(int i = 1; i < N; i++){
		pref[i] = pref[i - 1] + (1LL * phi[i] * phi[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    phi_function();
    while (test_cases--)
    {
        int a, b;
        cin >> a >> b;

        unsigned long long score = pref[b] - pref[a - 1];

        cout << "Case " << cs++ << ": " << score << endl;
    }
    return 0 ;
}
