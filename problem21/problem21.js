let dp = [];
dp[10e3 + 1] = 0;
dp.fill(0);
for (let i = 1; i <= 10e3; i++) {
  let sum = 0;
  for (let j = 1; j <= Math.floor(i/2); j++) {
    if ((i % j) === 0) {
      sum += j;
    }
  }
  dp[i] = sum;
}
let ans = 0;
for (let i = 1; i <= 10e3; i++) {
  if (i === dp[dp[i]] && i !== dp[i]) {
    ans += (i);
  }
}
console.log(ans);