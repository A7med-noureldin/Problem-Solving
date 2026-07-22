func checkIfPangram(sentence string) bool {
    freq := make([]int, 26)
    for _, char := range sentence{
        freq[char-'a']++
    }
    for i := 0; i < 26; i++{
        if freq[i] == 0{
            return false
        }
    }
    return true
}