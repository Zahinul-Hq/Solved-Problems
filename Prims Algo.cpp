#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;

vector <PII> adj[MAX];
void inout()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt" ,"r" , stdin);
        freopen("output.txt" , "w" ,stdout);
        cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
    #endif
}

long long prim(int x)
{

    priority_queue<PII, vector<PII>, greater<PII> > Q;
    vector<bool>marked(MAX , 0) ;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {

            // Pushing connected vertices into Q
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);


        }
    }
    return minimumCost;
}

int main()
{
    inout() ;
    int nodes, edges, x, y;

    long long weight, minimumCost ,sum=0;

    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }


    for(int i=1 ; i<=nodes ; i++){
        //minimumCost = prim(1);

        sum+=prim(i);
    }

    
    cout << sum << endl;
    return 0;
}