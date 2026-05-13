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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        string s;
        cin >> s;

        int n = s.size();

        int curr_indx = 0, last_sorted_index = 0, first_unsorted_index = -1;

        bool ok = 1;
        for(int i = 0; i < n; i++){
        	if(s[i] == '+')
        		curr_indx++;
        	if(s[i] == '-'){
        		if(last_sorted_index == curr_indx) last_sorted_index--;
        		if(curr_indx == first_unsorted_index)
        			first_unsorted_index = -1;
        		curr_indx--;
        	}
        	if(s[i] == '1'){
        		if(first_unsorted_index != -1)
        			ok = 0;
        		last_sorted_index = curr_indx;

        	}

        	if(s[i] == '0'){
        		if(last_sorted_index == curr_indx || curr_indx < 2)
        			ok = 0;
        		if(first_unsorted_index == -1)
        			first_unsorted_index = curr_indx;
        	}
        }

        if(ok)
        	cout << "Yes" << endl;
        else
        	cout << "No" << endl;
    }
    return 0 ;
}
