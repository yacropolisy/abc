#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <set>

using namespace std;

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

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
// #define mp make_pair
// #define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define show(x) cout << #x << " = " << x << endl;

ll modpow(ll x, ll y){
  ll tmp;
  if(y == 0)return 0;
  else if(y == 1)return x;
  else if(y % 2 == 0){
    tmp = pow(modpow(x,y/2),2);
    return tmp % MOD;
  }else{
    tmp = pow(modpow(x,y/2),2) * x;
    return tmp % MOD;
  }
}

ll gcd(ll a, ll b){
  if(b==0){
    return a;
  }else{
    return gcd(b, a%b);
  }
}



int main(){
  int n;
  cin >> n;
  ll c[n];
  vll memo(n+1);
  REP(i,n){
    cin >> c[i];
  }
  REP(i,n+1){
    memo[i] = INFll;
  }
  memo[1] = c[0];
  memo[0] = -INFll;
  ll mi;
  FOR(i,1,n){
    mi = (lower_bound(ALL(memo),c[i])-memo.begin());
    memo[mi] = min(memo[mi], c[i]);
  }
  ll ma = 0;
  REP(i,n+1){
    if(memo[i] != INFll){
      ma = i;
    }
  }

  cout << n - ma << endl;

  return 0;
}
