let digits n =
  let rec digits' n acc =
    if n = 0 then acc
    else digits' (n / 10) ((n mod 10) :: acc)
  in
  digits' n []

let rec perm' set acc curr =
  if List.length set = 0 then
    curr :: acc
  else
    let add_to_val = curr * 10 in
    List.fold_left (fun acc' d ->
      let new_val = add_to_val + d in
      let new_set = List.filter (fun v -> v != d) set in
      perm' new_set acc' new_val) acc set

let permutation n =
  let digits = digits n
  in perm' digits [] 0

let get_ten_power_to power =
  let res = ref 1 in
  for _ = 1 to power do
    res := !res * 10
  done;
  !res

let p = permutation 123_456_789
let () =
  let ans = ref [] in
  List.iter (fun v ->
    for one = 1 to 9 do
      for two = 1 to 9 do
        for three = 1 to 9 do
          if one + two + three = 9 then (
            let ten_power_of_three = get_ten_power_to three
            and ten_power_of_two = get_ten_power_to two
            and ten_power_of_one = get_ten_power_to one in
            let third, new_val = v mod ten_power_of_three, v / ten_power_of_three in
            let second, new_val = new_val mod ten_power_of_two, new_val / ten_power_of_two in
            let first, new_val = new_val mod ten_power_of_one, new_val / ten_power_of_one in
            if first * second = third then
              (Printf.printf "%d %d %d" first second third; print_newline (); ans := third :: !ans)
          )
        done
      done
    done) p;
    let uniq = List.fold_left (fun acc v ->
      v :: List.filter (fun v' -> v' != v) acc) [] !ans
    in
    let sum = List.fold_left (fun acc v -> acc + v) 0 uniq in
    print_int sum; print_newline ()
