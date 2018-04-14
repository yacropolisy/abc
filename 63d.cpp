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

// #define MAX_N 100000
// ll n, a, b;
// ll h[MAX_N];

int main(){
  int n;
  ll a, b;
  cin >> n >> a >> b;
  ll h[n];
  REP(i,n)cin >> h[i];

  ll lb = 0, ub = 10000000000;
  while(ub - lb > 1){
    ll res = (lb + ub)/ 2;

    ll ct = 0;

    REP(i,n){
      if(h[i] - b * res > 0){
        // ct += ll(ceil((h[i] - b * res) / double(a-b)));
        ct+=(h[i] - b * res + a - b - 1) / (a-b);
      }
    }

    // REP(i,n){
    //     ct += max(0LL,(h[i] - b * res + a - b - 1) / (a-b));
    // }



    if(ct <= res){
      ub = res;
    }else{
      lb = res;
    }

  }

  cout << ub << endl;


  return 0;
}
