func numberOfEmployeesWhoMetTarget(hours []int, target int) int {
    slices.Sort(hours)
    lowerBound := sort.Search(len(hours), func(i int) bool {
		return hours[i] >= target
	})
    return len(hours)-lowerBound
}