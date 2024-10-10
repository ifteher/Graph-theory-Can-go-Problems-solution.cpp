কন্টেস্ট লিংক: https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-04/challenges
Problem Statement:
You will be given  numbers of nodes,  numbers of edges in a graph. For each edge you will be given ,  and  which means there is a connection from  to  only and for which you need to give  cost. The value of nodes could be from  to .
You will be given a source node . Then you will be given a test case , for each test case you will be given a destination node  and a cost . You need to tell if you can go to the destination from source using atmost  cost.

Input Format:
First line will contain  and .
Next  lines will contain ,  and .
Next line will contain source node .
Next line will contain , the number of test cases.
For each test case, you will get  and .
Constraints

Output Format:
Ouput "YES" or "NO" for each test case if it is possible to go from  to  using atmost  cost.
Sample Input 0

5 7
1 2 10
1 3 2
3 2 1
2 4 7
3 4 2
4 5 5
2 5 2
1
5
1 0
2 5
3 1
4 4
5 6
Sample Output 0

YES
YES
NO
YES
YES
Solution:///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
const int inf = 1e9;
const int N = 1e5 + 5;

vector<vector<pii>> adj;  // Adjacency list for graph: adj[u] = {v, cost}
vi dist;  // Distance array to store shortest path costs

void dijkstra(int src, int n) {
    dist.assign(n + 1, inf); // Initialize distances with infinity
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap to pick the minimum cost node
    
    dist[src] = 0;
    pq.push({0, src});  // Start from source node
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        if (current_dist > dist[u]) continue;  // Skip if this path is not optimal
        
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    // Reading edges
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].PB({v, cost});
    }

    int source;
    cin >> source;
    
    // Compute shortest path from the source node
    dijkstra(source, n);

    int t;
    cin >> t;

    // Process each test case
    for (int i = 0; i < t; i++) {
        int dest, max_cost;
        cin >> dest >> max_cost;

        if (dist[dest] <= max_cost) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
