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

#define MAX_N 100000
#define MAX_Q 100000
int n, q, k;


#define MAX_E 1000000
#define MAX_V 1000000

struct edge{int to; ll cost;};
edge es[MAX_E];
int V, E;
vector<edge> G[MAX_V];
ll dist[MAX_V];
int used[MAX_V];

void dijkstra(ll s){
  REP(i,V){
    dist[i] = INFll;
  }
  dist[s] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  pque.push(pll(0,s));
  while(!pque.empty()){
    ll v, d;
    d = pque.top().first;
    v = pque.top().second;
    pque.pop();
    if(dist[v] < d)continue;
    REP(i,G[v].size()){
      edge e = G[v][i];
      if(dist[e.to] > d + e.cost){
        dist[e.to] = d + e.cost;
        pque.push(pll(d+e.cost,e.to));
      }
    }
  }
}

int main(){
  cin >> n;
  int a[n-1], b[n-1];
  ll c[n-1];
  REP(i,n-1)cin >> a[i] >> b[i] >> c[i];
  cin >> q >> k;
  int x[q], y[q];
  REP(i,q)cin >> x[i] >> y[i];

  REP(i,n-1){
    edge e1, e2;
    e1.to = b[i]-1;
    e1.cost = c[i];
    G[a[i]-1].push_back(e1);
    e2.to = a[i]-1;
    e2.cost = c[i];
    G[b[i]-1].push_back(e2);
  }
  V = n;
  E = n-1;

  dijkstra(k-1);

  REP(i,q){
    cout << dist[x[i]-1] + dist[y[i]-1] << endl;
  }

  return 0;
}
