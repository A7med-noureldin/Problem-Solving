func firstPalindrome(words []string) string {
    isPal := func(s string) bool{
        l, r := 0, len(s)-1
        for l <= r{
            if s[l] != s[r]{
                return false
            }
            l++; r--
        }
        return true
    }

    for _, s := range words{
        if isPal(s){
            return s
        }
    }
    return ""
}