func decodeAtIndex(s string, k int) string {
    len,i := int64(0),0
    
    for len < int64(k) {
        if s[i] >= '0' && s[i] <= '9' {
            len *= int64(s[i] - '0')
        } else {
            len++
        }
        i++
    }

    for j := i - 1; j >= 0; j-- {
        if s[j] >= '0' && s[j] <= '9' {
            len /= int64(s[j] - '0')
            k %= int(len)
        } else {
            if k == 0 || k == int(len) {
                return string(s[j])
            }
            len--
        }
    }

    return ""
}