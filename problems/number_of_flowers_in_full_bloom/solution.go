func fullBloomFlowers(F [][]int, ind []int) []int {
	result := make([]int, len(ind))
	begin, end := make([]int, 0, len(F)), make([]int, 0, len(F))
	for _, f := range F {
		begin = append(begin, f[0])
		end = append(end, f[1]+1)
	}
	sort.Ints(begin)
	sort.Ints(end)
	for i, day := range ind {
		beginSize := find(day, begin)
		endSize := find(day, end)
		result[i] = beginSize - endSize
	}
	return result
}

func find(val int, Q []int) int {
	l, r := 0, len(Q)-1
	for l <= r {
		u := (l + r) >> 1
		if Q[u] <= val {
			l = u + 1
		} else {
			r = u - 1
		}
	}
	return l
}