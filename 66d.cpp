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

#define MAX_V 100000

vector<int> G[MAX_V];

int main(){
  ll n;
  cin >> n;
  int a[n-1], b[n-1];
  REP(i,n-1){
    cin >> a[i] >> b[i];
    G[a[i]-1].push_back(b[i]-1);
    G[b[i]-1].push_back(a[i]-1);
  }
  int d1[n], dn[n];

  bool used[n];
  REP(i,n)used[i] = false;

  queue<pi> q;
  q.push(pi(0,0));
  while(!q.empty()){
    pi p = q.front(); q.pop();
    int v = p.first;
    int d = p.second;
    used[v] = true;
    d1[v] = d;
    REP(i,G[v].size()){
      if(!used[G[v][i]])q.push(pi(G[v][i], d+1));
    }
  }

  REP(i,n)used[i] = false;
  q.push(pi(n-1,0));
  while(!q.empty()){
    pi p = q.front(); q.pop();
    int v = p.first;
    int d = p.second;
    used[v] = true;
    dn[v] = d;
    REP(i,G[v].size()){
      if(!used[G[v][i]])q.push(pi(G[v][i], d+1));
    }
  }


  int num1=0, numn=0;
  REP(i,n){
    if(d1[i] > dn[i]){
      numn++;
    }else{
      num1++;
    }
  }

  if(num1 <= numn){
    cout << "Snuke" << endl;
  }else{
    cout << "Fennec" <<  endl;
  }




  return 0;
}
