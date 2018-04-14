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

const int MAX_E = 1000000;
const int MAX_V = 1000;

struct edge{int from, to; ll cost;};
edge es[MAX_E];

ll d[MAX_V];
int V, E;

bool bellman_ford(int s){
  REP(i,V)d[i] = INFll;
  d[s] = 0;
  REP(i,V-1){
    REP(j,E){
      edge e = es[j];
      if(d[e.from] != INFll && d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
      }
    }
  }

  ll ans = d[V-1];

  REP(i,V){
    REP(j,E){
      edge e = es[j];
      if(d[e.from] != INFll && d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
      }
    }
  }

  if(d[V-1]!= ans){
    return false;
  }else{
    return true;
  }

}


int main(){
  int n, m;
  cin >> n >> m;
  E = m;
  V = n;
  int a[m], b[m];
  ll c[m];
  REP(i,m){
    cin >> a[i] >> b[i] >> c[i];
    es[i] = (edge){a[i]-1, b[i]-1, -c[i]};
  }

  bool flag =  bellman_ford(0);
  if(!flag){cout << "inf" << endl;}
  else{cout << -d[n-1] << endl;}


  return 0;
}
