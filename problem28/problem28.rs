fn main() {
    let mut sum: usize = 0;
    for b in (1 .. 1002).step_by(2) {
        if b > 1 {
            for sub_m in 0 .. 4 {
                sum += b * b - sub_m * (b - 1);
            }
        }
    }
    println!("{}", sum);
}
