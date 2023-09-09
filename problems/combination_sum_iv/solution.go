import "sort"

func recur(A []int, n int, dp map[int]int) int {
    if val, found := dp[n]; found {
        return val
    }
    if n == 0 {
        return 1
    }
    if n < A[0] {
        return 0
    }
    
    count := 0
    for _, i := range A {
        if n - i < 0 {
            break
        }
        count += recur(A, n - i, dp)
    }
    
    dp[n] = count
    return count
}

func combinationSum4(A []int, T int) int {
    sort.Ints(A)
    dp := make(map[int]int)
    return recur(A, T, dp)
}