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

int memo[301];

ll gcd(ll a, ll b){
  if(b==0){
    return a;
  }else{
    return gcd(b, a%b);
  }

}


int main(){
  int n, m;
  cin >> n >> m;
  int x, y ,ans = 1;
  vi vx, vy;
  int ct = 0;
  int memo[n][n];
  REP(i,n)REP(j,n)memo[i][j] = 0;
  REP(i,n)memo[i][i] = 1;
  REP(i,m){
    cin >> x >> y;
    memo[x-1][y-1] = memo[y-1][x-1] = 1;
    vx.push_back(x); vy.push_back(y);
  }

  vi choice;
  int flag;

  REP(i,1 << n){
    choice.clear();
    flag = 1;
    REP(j, n){
      if(i & 1 << j){
        choice.push_back(j);
      }
    }
    REP(j,choice.size()){
      REP(k,choice.size()){
        if(memo[choice[k]][choice[j]] != 1){
          flag = 0;
          break;
        }
      }
    }
    if(flag == 1){
      ct = choice.size();
      ans = max(ans, ct);
    }
  }

  cout << ans << endl;


  return 0;
}
