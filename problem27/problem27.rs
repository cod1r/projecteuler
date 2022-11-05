fn main() {
    let mut b_primes: Vec<isize> = Vec::new();
    for b in -1000 as isize .. 1001 {
        let mut add = true;
        for c in 2 .. isize::abs(b) {
            if (b % c) == 0 {
                add = false;
                break;
            }
        }
        if add {
            b_primes.push(b);
        }
    }
    let mut max_n = 0;
    let mut a_ans: isize = 0;
    let mut b_ans: isize = 0;
    for a in -999 as isize .. 1000 {
        for b in &b_primes {
            for n in 0 .. 1000 as isize {
                let res = (n * n) + (a * n) + b;
                let mut check = true;
                for c in 2 .. isize::abs(res) {
                    if (res % c) == 0 {
                        check = false;
                        break;
                    }
                }
                if !check {
                    if max_n < n {
                        max_n = n;
                        a_ans = a;
                        b_ans = *b;
                    }
                    break;
                }
            }
        }
    }
    println!("{} {}", max_n, a_ans * b_ans);
}
