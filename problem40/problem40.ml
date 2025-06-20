let ans = ref 1

let digit_num = ref 1

let num_digits n =
  let rec digits n acc =
  if n = 0 then acc
  else digits (n / 10) (acc + 1)
  in
  digits n 0

let get_digits n =
  let rec digits n acc =
  if n = 0 then acc
  else digits (n / 10) ((n mod 10) :: acc)
  in
  digits n []

let digits_to_look_for = [1; 10; 100; 1000; 10000; 100000; 1000000]

let () =
  for num = 1 to 1_000_000 do
    let digit_cnt = num_digits num in
    let digit_target = List.find_opt (fun v -> v >= !digit_num && v < !digit_num + digit_cnt) digits_to_look_for in
    (match digit_target with
    | Some (d) -> (
      let digits = get_digits num in
      let diff = d - !digit_num in
      let d_to_mult = List.nth digits diff in
      ans := !ans * d_to_mult
    )
    | None -> ());
    digit_num := !digit_num + digit_cnt
  done

let () =
  Printf.printf "ans: %d\n" !ans
