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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        ll n , m , k ,x ;

        cin >> n >> m >> k;

        ll free_space = n * m - 2;

        int top_card = k;

        priority_queue<ll> pq;

        bool flag = 1;

        for(int i = 0; i < k; i++){
        	cin >> x;
        	pq.push(x);
        	free_space--;

        	if(!free_space) flag = 0;

        	while(!pq.empty() && pq.top() == top_card){
        		top_card--;
        		free_space++;
        		pq.pop();
        	} 
        }

        if(flag)
        	cout << "YA" << endl;
        else
        	cout << "TIDAK" << endl;
    }
    return 0 ;
}
