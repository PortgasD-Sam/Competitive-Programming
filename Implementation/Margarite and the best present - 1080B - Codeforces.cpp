#include <bits/stdc++.h>

using namespace std;

int q;

int main() {
  scanf("%d", &q);
  long long l, r, e;
  for(int i = 0; i < q; ++i) {
    scanf("%lld %lld", &l, &r);
    e = r / 2;
    long long sum = 1ll * e * (e + 1);
    e = (l - 1) / 2;
    sum -= 1ll * e * (e + 1);
    e = r / 2;
    sum -= (1ll * r * (r + 1) / 2) - (1ll * e * (e + 1));
    --l;
    e = l / 2;
    sum += (1ll * l * (l + 1) / 2) - (1ll * e * (e + 1));
    printf("%lld\n", sum);
  }

  return 0;
}