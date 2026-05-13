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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, m , q;

        cin >> n >> m >> q;
        vector<int>presenter(n, 0), slide(m, 0);

        for(int i = 0; i < n; i++){
        	cin >> presenter[i];
        }
        for(int i = 0; i < m; i++){
        	cin >> slide[i];
        }
        map<int,int>que;

        int j = 0;
        bool ok = 1;

        for(int i = 0; i < m; i++){
        	if(j < n && presenter[j] == slide[i]){
        		que[presenter[j]]++;
        		j++;
        		
        	}else if(que[slide[i]] == 0){
        		ok = 0;
        	}
        }

        if(ok){
        	cout << "YA" << endl;
        }else{
        	cout << "TIDAK" << endl;
        }
    }
    return 0 ;
}
