func isPalindrome(s string) bool {
    i, j := 0, int(len(s))-1
    n := int(len(s))
    for i <= j{
        for i < n && !unicode.IsLetter(rune(s[i])) && !unicode.IsDigit(rune(s[i])){
            i++
        }
        for j >= 0 && !unicode.IsLetter(rune(s[j])) && !unicode.IsDigit(rune(s[j])){
            j--
        } 
        if i <= j && unicode.ToLower(rune(s[j])) != unicode.ToLower(rune(s[i])){
            return false
        }
        i++; j--
    }
    return true
}