fn main() {
    for n in 0..81 {
        let mut check = true;
        let res = n * n - 79 * n + 1601;
        for c in 2 .. n {
            if (res % c) == 0 {
                check = false;
                break;
            }
        }
        if !check {
            println!("{}", n);
            break;
        }
    }
}
