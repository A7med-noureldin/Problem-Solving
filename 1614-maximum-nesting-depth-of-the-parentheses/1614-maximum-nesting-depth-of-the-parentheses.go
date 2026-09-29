func maxDepth(s string) int {
    open, mx := 0, 0
    for _, c := range s{
        if c == '('{
            open++
        }else if c == ')'{
            mx = max(mx, open)
            open--
        }
    }
    return mx
}