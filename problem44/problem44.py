import bisect
def pentagonal_num(n):
	return n * (3 * n - 1) / 2

nums = [pentagonal_num(n) for n in range(1, 8001)]

min_ans = float('inf')
for p_j in range(0, len(nums)):
	for p_k in range(p_j, len(nums)):
		added = nums[p_j] + nums[p_k]
		idx = bisect.bisect_left(nums, added)
		sub1 = nums[p_j] - nums[p_k]
		idx_for_sub1 = bisect.bisect_left(nums, sub1)
		sub2 = nums[p_k] - nums[p_j]
		idx_for_sub2 = bisect.bisect_left(nums, sub2)
		if idx < len(nums) and nums[idx] == added and \
			((idx_for_sub1 < len(nums) and nums[idx_for_sub1] == sub1) or \
			(idx_for_sub2 < len(nums) and nums[idx_for_sub2] == sub2)):
			min_ans = min(abs(nums[p_j] - nums[p_k]), min_ans)

print(min_ans)
