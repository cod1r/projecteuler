let fs = require('fs');
let contents = fs.readFileSync('p022_names.txt').toString().split(',').map(s => s.substring(1, s.length-1));
contents.sort();
let sum = 0;
for (let word = 0; word < contents.length; word++) {
  let total = 0;
  for (let letter of contents[word]) {
    if (typeof letter === 'string') {
      total += letter.toLowerCase().charCodeAt(0) - 96;
    }
  }
  sum += (total * (word + 1));
}
console.log(sum);