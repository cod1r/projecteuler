let product = ref (1, 1) in
for i = 10 to 99 do
  for j = 10 to 99 do
    if i mod 10 = j / 10 && j mod 10 < j / 10 && i mod 10 > i / 10 && j mod 10 > i / 10
    && Float.of_int i /. Float.of_int j = Float.of_int (i / 10) /. Float.of_int (j mod 10) then
      (product := (i * fst !product, j * snd !product))
  done
done;
let big = max (fst !product) (snd !product) in
for d = 2 to big do
  let numerator = ref (fst !product)
  and denominator = ref (snd !product) in
  while !numerator mod d = 0 && !denominator mod d = 0 do
    numerator := !numerator / d;
    denominator := !denominator / d
  done;
  product := (!numerator, !denominator)
done;
Printf.printf "ans: %d" (snd !product); print_newline ()
