func firstUniqChar(s string) int {
    mp := make(map[rune]int)
    for _, char := range s{
        mp[char] += 1
    }
    for idx, char := range s{
        if mp[char] == 1{
            return idx
        } 
    }
    return -1
}