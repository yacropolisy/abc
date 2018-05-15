#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <string>

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

vi x(30),y(30);
ll memo[80][80][80][80];

ll dfs(vi vn, int i, int j, int k, int l){
  if(memo[i][j][k][l] != -1){
    return memo[i][j][k][l];
  }
  ll max = 0;
  int nowx,nowy;
  vi nowvn;
  if(vn.size() == 0){
    return 0;
  }else{
    REP(i,vn.size()){
      if(x[vn[i]] < i || x[vn[i]] > k || y[vn[i] < j || y[vn[i]]] > l){
        vn.erase(vn.begin() + i);
      }
    }
    REP(i,vn.size()){
      nowx = x[vn[i]];
      nowy = y[vn[i]];
      nowvn = vn;
      nowvn.erase(nowvn.begin() + i);
       if ( max < dfs(nowvn, i, j, nowx-1, nowy-1) + dfs(nowvn, nowx + 1, j, k, nowy-1) + dfs(nowvn, i, j, nowx-1, nowy-1) + dfs(nowvn, i, j, nowx-1, nowy-1)){

       }
    }
    return (k - i) + (l - j) + 1 + max;
  }
}

int main(){
  int w,h;
  int n, tx, ty;

  REP(i,n){
    cin >> x[i] >> y[i];
  }




  return 0;
}
