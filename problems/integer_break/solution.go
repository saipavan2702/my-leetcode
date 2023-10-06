func integerBreak(n int) int {
    if n == 2 { return 1 }
    if n == 3 { return 2 }
    
    got := n / 3
    have := n % 3

    if have == 0 {
        return int(math.Pow(3, float64(got)))
    } else if have == 1 {
        return int(math.Pow(3, float64(got - 1))) * 4
    } else {
        return int(math.Pow(3, float64(got))) * 2
    }
}