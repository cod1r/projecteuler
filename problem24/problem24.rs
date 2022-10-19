use std::collections::HashSet;
fn permutation(idx: u8, options: HashSet<u8>, vec: Vec<u8>, all: &mut Vec<Vec<u8>>) {
    if idx >= 10 {
        all.push(vec.clone());
        return;
    }
    for n in &options {
        let mut copy = vec.clone();
        copy.push(*n);
        let mut copy_opt = options.clone();
        copy_opt.remove(n);
        permutation(idx + 1, copy_opt, copy, all);
    }
}
fn main() {
    let vec = vec![];
    let mut all = vec![];
    let mut opt = HashSet::new();
    for i in 0..10 {
        opt.insert(i);
    }
    permutation(0, opt, vec, &mut all);
    all.sort_by(|a, b| {
        let mut s1 = String::new();
        let mut s2 = String::new();
        for n in a {
            s1.push(*n as char);
        }
        for n in b {
            s2.push(*n as char);
        }
        s1.cmp(&s2)
    });
    for n in &all[1000000 - 1] {
        print!("{}", n);
    }
}
