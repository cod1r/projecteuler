def sieve(n):
	primes = list(range(1, n + 1))
	for i in range(2, n + 1):
		multiplier = 2
		while multiplier * i <= n:
			primes[multiplier * i - 1] = -1
			multiplier += 1
	return primes

primes = sieve(9999)

def is_perm(n1, n2):
  return sorted([c for c in str(n1)]) == sorted([c for c in str(n2)])

for p1 in range(len(primes)):
  for p2 in range(p1 + 1, len(primes)):
    if primes[p1] != -1 and primes[p2] != -1 and p2 + (p2 - p1) < len(primes) and is_perm(primes[p1], primes[p2]) and \
      is_perm(primes[p2], primes[p2 + (p2 - p1)]):
      print(primes[p1], primes[p2], primes[p2 + (p2 - p1)])
