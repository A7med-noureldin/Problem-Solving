func numberOfEmployeesWhoMetTarget(hours []int, target int) int {
    cnt := 0
    for _, hr := range hours{
        if hr >= target{
            cnt++
        }
    }
    return cnt
}