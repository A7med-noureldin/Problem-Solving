func countKeyChanges(s string) int {
    s = strings.ToLower(s)
    cnt := 0
    for i := 0; i+1 < len(s); i++{
        if s[i] != s[i+1]{
            cnt++
        }
    }
    return cnt
}