def exp_by_squaring(x, n):
  if n < 0:
    return exp_by_squaring(1 / x, -n)
  elif n == 0:
    return 1
  elif n % 2 == 0:
    return exp_by_squaring(x * x, n / 2)
  return x * exp_by_squaring(x * x, (n - 1) / 2)

s = 0
for n in range(1, 1000):
  s += exp_by_squaring(n, n)
print(s % 10000000000)
