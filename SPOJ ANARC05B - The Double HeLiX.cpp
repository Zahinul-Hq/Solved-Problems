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

    int n, m ;
    
    
    while (1)
    {
    	cin >> n;

    	if(!n)
    		break;

    	int seq1[n];
        for(int i = 0; i < n; i++){
        	cin >> seq1[i];
        }
        cin >> m;

    	int seq2[m];
        for(int i = 0; i < m; i++){
        	cin >> seq2[i];
        }

        int seq1_sum = 0, seq2_sum = 0, sum = 0, i = 0, j = 0;
        bool flag = 0;

        for(;j < m && i < n;){

        	if( i < n &&( seq1[i] < seq2[j])){
        		seq1_sum += seq1[i];
        		i++;
        	}
        	else if(j < m && ( seq1[i] > seq2[j] )){
        		seq2_sum += seq2[j];
        		j++;
        	}
        	else if(seq1[i] == seq2[j]){

        		seq1_sum += seq1[i] , seq2_sum += seq2[j];

        		//cout << seq1_sum <<  " " << seq2_sum << endl;
        		sum += max(seq1_sum, seq2_sum);


        		seq1_sum = 0, seq2_sum = 0,  i++, j++ ;

        	}
        }


        while( i < n ){
        		seq1_sum += seq1[i];
        		i++;
        }
        while(j < m ){
        		seq2_sum += seq2[j];
        		j++;
        }

        //cout << seq1_sum << " " << seq2_sum << endl;

        sum += max(seq1_sum, seq2_sum);
        

        cout << sum << endl;


    }
    return 0 ;
}
