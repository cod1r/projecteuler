// jan 1 1900 was a monday 
// jan 1 1901 was a tuesday because of the offset with the previous year
// 365/7 is roughly 52 with a remainder of 1 so if the previous year started on sunday, 1901 would have started
// on a monday.
// offset is initially 1, but leapyears add to it.
function getMonths(n) {
  let months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  let offset = 0;
  if ((n % 4 === 0 && n % 100 !== 0) || n % 400 === 0) {
    months[1] = 29;
    offset = 1;
  }
  return [months, offset];
}
// our objective is to find how many sundays were on the first day of any month for years 1901 - 2000 inclusive
let sundays = 0;
// initial offset starting at 1901
let offset = 2;
for (let i = 1901; i <= 2000; i++) {
  let [months, addToOffset] = getMonths(i);
  // adding to offset because leapyears cause offsets in future years
  // also adding one because every year causes an offset of 1.
  offset += addToOffset + 1;
  for (let j = 0; j < months.length; j++) {
    // adding offset to every remainder because offset applies to the entire year
    let remainder = (months[j] % 7) + offset;
    // if our remainder plus offset can be divided by 7, this means that the last week of our current month is a full 7
    if (remainder % 7 === 0) {
      sundays ++;
    }
  }
}
console.log(sundays, offset);