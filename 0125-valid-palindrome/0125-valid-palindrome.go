func isPalindrome(s string) bool {
    t := ""
    for _, c := range s{
        if unicode.IsLetter(c) || unicode.IsDigit(c){
            t += string(unicode.ToLower(c))
        }
    }
    // fmt.Println(t)
    i, j := 0, int(len(t))-1
    for i <= j{
        if t[i] == t[j]{
            i++; j--
            continue
        }
        return false
    }
    return true
}