/*
 * solve it using standard dp [i] but try only the first 1000 position to be the right border of the current batch 
 * I think there is a prove to this ( it is not a problem with the tests ) because of the low s & t [i] but I am not sure about it 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
ll n , s ;
ll t [10009] , f [10009] , bs [10009][2] , dp [10009] ;
ll sum ( ll l , ll r , ll t ) {
	return ( l ? bs [r][t] - bs [l-1][t] : bs [r][t] ) ;
}
ll bt ( ll id ) {
	if ( id == n ) return 0ll ;
	ll &ret = dp [id] ;
	if ( ret != -1 ) return ret ;
	ret = inf ;
	ll R = min ( n - 1 , id + 1009ll ) ;
	for ( ll i = id ; i <= R ; i ++ ) {
		ll cost = sum ( id , i , 0 ) + s ;
		ll now = sum ( id , i , 1 ) , nxt = sum ( i+1 , n -1 , 1 ) ;
		ret = min ( ret , bt ( i+1 ) + now * cost + nxt * cost ) ;
	}
	return ret ; 
}
int main () {
	mem ( dp , -1 ) ;
	cin >> n >> s ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> t [i] >> f [i] ;
		bs [i][0] = t [i] ;
		bs [i][1] = f [i] ;
	}
	for ( int i = 1 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < 2 ; j ++ ) {
			bs [i][j] += bs [i-1][j] ;
		}
	}
	cout << bt ( 0 ) << endl ; 
}
