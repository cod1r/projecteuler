let n = 1n;
for (let i = 100; i >= 1; i--) {
  n *= BigInt(i);
  while (n % 10n === 0) {
    n /= 10n;
  }
}
console.log([...String(BigInt(n))].map(c => Number(c)).reduce((prev, curr) => prev + curr));