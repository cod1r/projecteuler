let words = [['one', 'eleven'], ['two', 'twen'], ['three', 'thir'], ['four', 'for'], ['five', 'fif'], 'six', 'seven', 'eight', 'nine'];
let endings = ['teen', 'ty', 'hundred', 'thousand'];
let string = '';
let get = (n, place) => n >= 5 ? words[n] : (place ? words[n][1]:words[n][0]);
let get_tens = (n) => {
  if (n === 0) {
    return '';
  }
  let tens_place = Math.floor(n / 10);
  let ones_place = (n % 10);
  if (n < 20 && tens_place > 0) {
    if (ones_place === 0) {
      return 'ten';
    } else if (ones_place === 1) {
      return 'eleven';
    } else if (ones_place === 4) {
      return 'fourteen';
    } else if (ones_place === 2) {
      return 'twelve';
    } else if (ones_place === 8) {
      return 'eighteen';
    } else {
      return get(ones_place - 1, 1) + 'teen';
    }
  } else if (tens_place > 0 && n >= 20) {
    return (tens_place !== 8 ? get(tens_place - 1, 1) + 'ty' : get(tens_place - 1, 1) + 'y') + (ones_place > 0 ? get(ones_place - 1, 0) : '');
  } else {
    return get(ones_place - 1, 0);
  }
};
for (let i = 1; i <= 1000; i++) {
  switch (String(i).length) {
    case 1: {
      string += get(i - 1, 0);
      console.log(get(i - 1, 0));
    }
    break;
    case 2: {
      string += get_tens(i);
      console.log(get_tens(i));
    }
    break;
    case 3: {
      let hundreds = Math.floor(i / 100) - 1;
      string += get(hundreds, 0) + 'hundred' + (i % 100 > 0 ? 'and' + get_tens(i % 100) : '');
      console.log(get(hundreds, 0) + 'hundred' + (i % 100 > 0 ? 'and' + get_tens(i % 100) : ''));
    }
    break;
    case 4: {
      string += 'onethousand';
    }
    break;
    default:
      console.error('wtf bro');
      break;
  }
};
console.log(string.length);