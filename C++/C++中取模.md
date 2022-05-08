##### C++中取模

* 当结果过大，有时采用取模

  ```c++
  typedef long long ll;
  static const ll mod = 1e10 + 7; //只有long long这样写
  //long 会报错
  ll sum = 10000;
  ll ans = sum % mod;
  ```

  