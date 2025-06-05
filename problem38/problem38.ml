let digits n =
  let rec digits' n acc =
    if n = 0 then acc else digits' (n / 10) ((n mod 10) :: acc)
  in
  digits' n []

let is_pandigital n =
  let s = string_of_int n in
  let has_zero = ref false in
  let arr =
    String.fold_left
      (fun acc c ->
        (match c with
        | '1' -> acc.(0) <- acc.(0) + 1
        | '2' -> acc.(1) <- acc.(1) + 1
        | '3' -> acc.(2) <- acc.(2) + 1
        | '4' -> acc.(3) <- acc.(3) + 1
        | '5' -> acc.(4) <- acc.(4) + 1
        | '6' -> acc.(5) <- acc.(5) + 1
        | '7' -> acc.(6) <- acc.(6) + 1
        | '8' -> acc.(7) <- acc.(7) + 1
        | '9' -> acc.(8) <- acc.(8) + 1
        | '0' -> has_zero := true
        | _ -> failwith ("char " ^ Char.escaped c));
        acc)
      [| 0; 0; 0; 0; 0; 0; 0; 0; 0 |]
      s
  in
  !has_zero = false && Array.fold_left (fun acc v -> acc && v = 1) true arr

let perm set =
  let rec perm' set acc curr =
    if List.length set = 0 then curr :: acc
    else
      List.fold_left
        (fun acc' v ->
          let filt = List.filter (fun v' -> v' != v) set in
          perm' filt acc' (v :: curr))
        acc set
  in
  perm' set [] []

let len_of_nums lst =
  List.fold_left (fun acc v -> List.length (digits v) + acc) 0 lst

let concatenate lst =
  let strs = List.map (fun n -> string_of_int n) lst in
  List.fold_left (fun acc ns -> acc ^ ns) "" strs

let fold attempt =
  let res = ref None in
  let _ =
    List.fold_left
      (fun acc v ->
        let mult = v * attempt in
        let new_acc = acc @ [ mult ] in
        (if len_of_nums new_acc = 9 then
           let concatenated = concatenate new_acc in
           let num = int_of_string concatenated in
           if is_pandigital num && num != mult then res := Some num);
        new_acc)
      []
      [ 1; 2; 3; 4; 5; 6; 7; 8; 9 ]
  in
  !res

let list =
  perm [ 1; 2; 3; 4; 5; 6; 7; 8; 9 ]
  |> List.filter (function h :: _ -> h = 9 | _ -> failwith "not possible")

let print_list l =
  List.iter
    (fun v ->
      print_int v;
      print_string " ")
    l;
  print_newline ()

let solve lst =
  List.fold_left
    (fun acc l ->
      let _, curr =
        List.fold_left
          (fun (prev_attempt, n) v ->
            let attempt = (prev_attempt * 10) + v in
            let pandigital = fold attempt in
            match pandigital with
            | Some num ->
                ( attempt,
                  Some (match n with Some pd -> max pd num | None -> num) )
            | None -> (attempt, n))
          (0, None) l
      in
      match curr with Some pd -> max pd acc | None -> acc)
    0 list

let ans = solve list
let () = Printf.printf "ans: %d\n" ans
