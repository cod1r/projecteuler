let get_digits n =
  let rec digits' n acc =
    if n = 0 then
      acc
    else
      digits' (n / 10) ((n mod 10) :: acc)
  in
  digits' n []
;;
let fact n =
  let rec fact' n' acc =
    if n' <= 1 then acc
    else fact' (n' - 1) (acc * n')
  in
  fact' n 1
;;
let ans = ref 0 in
let biggest = fact 9 in
for n = 3 to biggest do
  let digits = get_digits n in
  let sum = List.fold_left (fun acc d -> acc + fact d) 0 digits
  in
  if sum = n then
    ans := !ans + n
done;
Printf.printf "ans: %d" !ans; print_newline ()
