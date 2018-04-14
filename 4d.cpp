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
  int r,g,b;
  int gr, gl, rr, rl, br, bl;
  ll sumr, sumg, sumb;
  cin >> r >> g >> b;
  if(g % 2 == 0){
    if(r < b){
      gl = g / 2;
      gr = g / 2 - 1;
    }else{
      gl = g / 2 - 1;
      gr = g / 2;
    }
  }else{
    gl = gr = g / 2;
  }

  if(r / 2 < 100 - gl){

  }

  if(gl < 100){
    rr = 100 - gl - 1;
    sumr = rr * (rr + 1) / 2 + (r - rr - 1) * (r - rr) / 2;
  }else {
    rr = gl - 100 + 1;
    sumr = (rr + rr + r - 1) * r / 2;
  }

  if(gr < 100){
    bl = 100 - gr - 1;
    sumb = bl * (bl + 1) / 2 + (b - bl - 1) * (b - bl) / 2;
  }else {
    bl = gr - 100 + 1;
    sumb = (bl + bl + b - 1) * b / 2;
  }

  sumg = gr * (gr + 1) / 2 + gl * (gl + 1 ) / 2;
  cout << sumg + sumr + sumb << endl;

  return 0;
}
