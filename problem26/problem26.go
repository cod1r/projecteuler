package main

func main() {
	var max_repeat = make(map[int]int)
	for i := 1; i < 1001; i++ {
		var m = make(map[int]bool)
		var start_value = make(map[int]int)
		var start int = 1
		for start < i {
			start *= 10
		}
		var counter int = 1
		for true {
			var times = 1
			for times*i <= start {
				times++
			}
			start -= (times - 1) * i
			if start == 0 {
				max_repeat[i] = 1
				break
			}
			for start < i {
				start *= 10;
			}
			if m[start] == false {
				start_value[start] = counter
				m[start] = true
			} else {
				max_repeat[i] = counter - start_value[start]
				break
			}
			counter++
		}
	}
	var m int = 0
	for i := 1; i < 1001; i++ {
		if max_repeat[m] < max_repeat[i] {
			m = i
		}
	}
	println(m)
}
