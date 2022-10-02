const ll N = 2e5 + 5;
ll fac[N], inv[N];
void fill_comb(ll N, ll p) {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i % p;
}
// works for prime p
inv[N-1] = powM(fac[N-1], p - 2, p);
for(int i=N-2;i>=0;i--){
    inv[i]=(i+1)*inv[i+1]%p; 
}

// works for any p
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll inv(ll a) {
	ll x, y;
	ll g = gcd(a, mod, x, y);
	x = (x % mod + mod) % mod;
	return x;
}
  
}
ll choose(ll a, ll b, ll p) {
 if (a < b || b < 0 || a < 0)return 0;
  return (fac[a] * inv[a - b] % p) * (inv[b]) % p;
}
