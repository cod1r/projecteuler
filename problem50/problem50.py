import bisect
def sieve(n):
  primes = [n for n in range(1, n + 1)]
  for i in range(2, n + 1):
    multiplier = 2
    while multiplier * i <= n:
      primes[multiplier * i - 1] = -1
      multiplier += 1
  return primes

primes = list(filter(lambda x : x != -1, sieve(1_000_000)))
length = 0
ans = 0
for i in range(len(primes)):
  s = 0
  for j in range(i, len(primes)):
    s += primes[j]
    if s >= 1_000_000: break
    idx = bisect.bisect_left(primes, s)
    if idx < len(primes) and primes[idx] == s and j - i - 1 > length:
      ans = s
      length = j - i - 1
print(ans)
