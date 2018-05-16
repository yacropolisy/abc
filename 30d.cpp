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

const int MAX_N = 100000;

ll looplen[MAX_N];
bool used[MAX_N];

int b[MAX_N];

int dfs(int v, int ct){
    used[v] = ct;
    if(used[b[v] > 0) return ct - used[b[v]];
    else return looplen[v] = dfs(b[v], ct++);
}

int main(){
  int n, a;
  string k;
  cin >> n >> a;
  cin >> k;

  REP(i,n) cin >> b[i];

  if(k.size() <= 6){
    REP(i,int(k)){
      a = b[a];
    }
    cout << a << endl;
  }else{
    REP(i,n){
      
      if(looplen[i] == 0){
        dfs(i,0);
      }
    }
  }

  return 0;
}
