let get_power_of_ten ~power =
  let res = ref 1 in
  for _ = 0 to power - 1 do
    res := !res * 10
  done;
  !res
let len_of_num n =
  let rec len' n acc =
    if n = 0 then acc
    else len' (n / 10) (acc + 1)
  in
  len' n 0
let truncate_from_left n =
  let length = len_of_num n in
  let power_ten = get_power_of_ten ~power:length in
  let rec truncate divisor acc =
    if divisor = 1 then acc
    else truncate (divisor / 10) ((n mod divisor) :: acc)
  in
  truncate power_ten []
let truncate_from_right n =
  let length = len_of_num n in
  let rec truncate divisor acc =
    if divisor = get_power_of_ten ~power:length then acc
    else truncate (divisor * 10) ((n / divisor) :: acc)
  in
  truncate 1 []
let is_prime n =
  let is_prime = ref true in
  for d = 2 to n / 2 do
    if n mod d = 0 then
      is_prime := false
  done;
  !is_prime && n > 1
;;
let eleven = ref [] in
let number = ref 9 in
while List.length !eleven < 11 do
  let left = truncate_from_left !number
  and right = truncate_from_right !number in
  let valid = List.for_all (fun n -> is_prime n) (left @ right) in
  if valid then (eleven := !number :: !eleven);
  number := !number + 1
done;
Printf.printf "ans: %d\n" (List.fold_left (fun acc n -> acc + n) 0 !eleven)
