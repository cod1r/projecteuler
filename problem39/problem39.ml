let ht = ref (Hashtbl.create 0) in
for a = 1 to 999 do
  for b = 1 to 999 do
    let c = sqrt ((a * a + b * b) |> Float.of_int) |> Int.of_float in
      if a + b + c <= 1000 then (
        let sorted = List.sort (fun a b -> a - b) [a;b;c] in
        match sorted with
        | small :: medium :: big :: _ -> (
          if small * small + medium * medium = big * big then (
            match Hashtbl.find_opt !ht (a + b + c) with
            | Some (v) -> (
              Hashtbl.replace !ht (a + b + c) (v + 1)
            )
            | None -> (
              Hashtbl.replace !ht (a + b + c) (1)
            )
          )
        )
        | _ -> (
          failwith "impossible case"
        )
      )
    done
  done;
let ans = ref None in
Hashtbl.iter (fun k v ->
  match !ans with
  | Some (k', v') -> if v' < v then ans := Some (k, v)
  | None -> ans := Some (k, v)) !ht
;Printf.printf "ans: %d\n" (Option.get !ans |> fst)
