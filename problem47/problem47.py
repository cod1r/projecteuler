from math import sqrt
def sieve(n):
	primes = list(range(1, n + 1))
	for i in range(2, n + 1):
		multiplier = 2
		while multiplier * i <= n:
			primes[multiplier * i - 1] = -1
			multiplier += 1
	return primes

primes = sieve(200_000)

consecutive_length = 4
for n in range(1, 500_000):
  def get_unique_factors(dividend):
    original = dividend
    factor = 2
    factors = []
    while factor <= int(sqrt(original)) + 1:
      if dividend % factor == 0:
        if factor not in factors and primes[factor -1] != -1:
          factors.append(factor)
        dividend //= factor
      else:
        factor += 1
    if original % dividend == 0 and primes[dividend - 1] != -1 and dividend > 1:
      factors.append(dividend)
    return factors
  consecutive = [get_unique_factors(n) for n in range(n, n + consecutive_length)]
  all_right_length = True
  for factors in consecutive:
    all_right_length = all_right_length and len(factors) == consecutive_length
  if all_right_length:
    print(n, consecutive)
    break
