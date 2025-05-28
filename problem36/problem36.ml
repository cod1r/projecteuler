let get_digits n =
  let rec digits' n acc =
    if n = 0 then acc
    else
      digits' (n / 10) ((n mod 10) :: acc)
  in
  digits' n []

let binary_digits n =
  let rec digits' n acc =
    if n = 0 then acc
    else digits' (n lsr 1) ((n land 1) :: acc)
  in
  digits' n []

let is_palindrome digits =
  let reverse = List.rev digits in
  reverse = digits
;;
let ans = ref 0 in
for num = 1 to 1_000_000 do
  let digits = get_digits num
  and bdigits = binary_digits num in
  if is_palindrome digits && is_palindrome bdigits then
    ans := !ans + num
done;
Printf.printf "ans %d" !ans; print_newline ()
