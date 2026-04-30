def sieve(n):
	primes = list(range(1, n + 1))
	for i in range(2, n + 1):
		multiplier = 2
		while multiplier * i <= n:
			primes[multiplier * i - 1] = -1
			multiplier += 1
	return primes

primes = sieve(100_000)

odd_numbers = [x if x % 2 != 0 and primes[x - 1] == -1 else -1 for x in range(1, 100_000 + 1)]
for prime in primes:
	square = 1
	while (val := prime + 2 * square ** 2) <= 100_000:
		odd_numbers[val - 1] = -1
		square += 1

ans = float('inf')
for n in odd_numbers:
	if n != -1:
		ans = min(n, ans)
print(ans)
