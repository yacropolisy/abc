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

vector< vector <unsigned int > > matmulmat(vector< vector <unsigned int > > mat1, vector< vector <unsigned int > > mat2){
  int n = mat1.size();
  vector< vector <unsigned int > > ret(n, vector<unsigned int> (n,0));
  REP(i,n){
    REP(j,n){
      REP(k,n){
        ret[i][j] ^= mat1[i][k] & mat2[k][j];
      }
    }
  }
  return ret;
}

vector<unsigned int> matmulvec(vector< vector <unsigned int > > mat, vector<unsigned int> va){
  int n = va.size();
  vector<unsigned int> ret(n,0);
  REP(i,n){
    REP(j,n){
      ret[i] ^= mat[i][j] & va[j];
    }
  }
  return ret;
}



int main(){
  int k,m;
  cin >> k >> m;
  unsigned int a[k],c[k];
  vector< vector <unsigned int > > mat(k , vector < unsigned int >(k,0));
  vector<unsigned int>va(k,0);

  REP(i,k)cin >> a[i];
  REP(i,k)cin >> c[i];
  REP(i,k){
    mat[0][i] = c[i];
    va[i] = a[k-i-1];
  }
  REP(i,k-1){
    mat[i + 1][i] = unsigned(-1) ;
  }

  if(m <= k){
    cout << a[m-1] << endl;
    return 0;
  }

  //あとはmat　とpow　使ってm にあわせて計算する

  vector< vector <unsigned int > > mats[32];
  mats[0] = mat;

  REP(i,k)REP(j,k){
    if(i == j)mat[i][j] = unsigned(-1);
    else mat[i][j] = 0;
  }




  REP(i,31){
    mats[i+1] = matmulmat(mats[i],mats[i]);

  }
  REP(i,32){
    if((1 << i ) & (m-k)){
      mat = matmulmat(mat,mats[i]);
    }
  }
  // REP(r,4){
  // REP(i,k){
  //   REP(j,k){
  //     cout << mats[r][i][j] << ",";
  //   }
  //   cout << endl;
  // }
  // }

  vector<unsigned int>vans(k,2);

  vans = matmulvec(mat,va);

  cout << vans[0] << endl;




  return 0;
}
