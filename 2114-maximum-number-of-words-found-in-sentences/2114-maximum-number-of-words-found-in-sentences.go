func mostWordsFound(sentences []string) int {
    mx := 0
    for _, s := range sentences{
        cur := 0
        for _, t := range s{
            if t == ' '{
                cur++
            }
        } 
        mx = max(mx, cur+1)
    }
    return mx
}