let count = ref 0;;

for one = 0 to 200 do
  for two = 0 to 100 do
    for five = 0 to 40 do
      for ten = 0 to 20 do
        for twenty = 0 to 10 do
          for fifty = 0 to 4 do
            for one_pound = 0 to 2 do
              for two_pound = 0 to 1 do
                if
                  (one * 1) + (two * 2) + (five * 5) + (ten * 10) + (twenty * 20) + (fifty * 50)
                  + (one_pound * 100) + (two_pound * 200)
                  = 200
                then count := !count + 1
              done
            done
          done
        done
      done
    done
  done
done
;;

print_string (string_of_int !count ^ "\n")
