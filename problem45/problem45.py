import bisect
def triangle_num(n):
	return n * (n + 1) / 2
def pentagonal_num(n):
	return n * (3 * n - 1) / 2
def hexagonal_num(n):
	return n * (2 * n - 1)

triangle_numbers = [triangle_num(n) for n in range(1, 100_000)]
pentagonal_numbers = [pentagonal_num(n) for n in range(1, 100_000)]
hexagonal_numbers = [hexagonal_num(n) for n in range(1, 100_000)]

for i in range(len(triangle_numbers)):
	pentagonal_idx = bisect.bisect_left(pentagonal_numbers, triangle_numbers[i])
	hexagonal_idx = bisect.bisect_left(hexagonal_numbers, triangle_numbers[i])
	if pentagonal_idx < len(pentagonal_numbers) and pentagonal_numbers[pentagonal_idx] == triangle_numbers[i]\
		and hexagonal_idx < len(hexagonal_numbers) and hexagonal_numbers[hexagonal_idx] == triangle_numbers[i]:
		print(triangle_numbers[i])
