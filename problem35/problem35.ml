let get_digits n =
  let rec digits n' acc =
    if n' = 0 then acc
    else digits (n' / 10) ((n' mod 10) :: acc)
  in
  digits n []
;;
let get_ten_power_to power =
  let res = ref 1 in
  for _ = 1 to power do
    res := !res * 10
  done;
  !res
let convert_lst_to_num lst =
  let length = List.length lst in
  let num = ref 0 in
  List.iteri (fun idx d -> num := !num + get_ten_power_to (length - 1 - idx) * d) lst;
  !num
;;
let rotate_lst lst =
  if List.length lst = 0 then lst
  else
    match lst with
    | h :: tl -> tl @ [h]
    | _ -> failwith "List empty"
;;
let is_prime n =
  let rec is_prime' num i =
    if num mod i = 0 && num > 2 then false
    else if i >= Int.of_float ((Int.to_float num) ** 0.5) then true
    else is_prime' num (i + 1)
  in
  is_prime' n 2
;;
let ans = ref 0 in
for num = 2 to 1_000_000 do
  let digits = get_digits num in
  let curr_lst = ref digits in
  let len = List.length digits in
  let counter = ref 0 in
  for _ = 1 to len do
    let n = convert_lst_to_num !curr_lst in
    if is_prime n then
      counter := !counter + 1;
    curr_lst := rotate_lst !curr_lst
  done;
  if !counter = len then
    ans := !ans + 1;
done;
Printf.printf "ans: %d" !ans; print_newline ();
