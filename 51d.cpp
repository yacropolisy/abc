#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_V = 100;

ll cost[MAX_V][MAX_V];


struct edge{int to; ll cost; bool used;};
typedef pair<ll, int> P;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P>  > que;
  fill(d, d + V, INFll);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge &e = G[v][i];
      if(d[e.to] >= d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        e.used = true;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}


int main(){
  int n, m;
  cin >> n >> m;
  int a[m], b[m], c[m];
  REP(i,m){
    cin >> a[i] >> b[i] >> c[i];
    G[a[i]].push_back(edge{b[i],ll(c[i]),false});
    G[b[i]].push_back(edge{a[i],ll(c[i]),false});
  }
  V = n;

  REP(i,n){
    dijkstra(i);
  }

  int ans = 0;
  REP(i,n){
    REP(j, G[i].size()){
      if(!G[i][j].used)ans++;
    }
  }

  cout << ans/2 << endl;

  return 0;
}
