# Selection Sort: O(n^2) average and worst; Memory O(1)
def SelectionSort(array):
	for i in range(len(array)):
		minIdx = i
		for j in range(i+1, len(array)):
			if array[minIdx] > array[j]:
				minIdx = j
		array[i], array[minIdx] = array[minIdx], array[i]
	return array

array = SelectionSort([5, 4, 3, 2, 1])
print(array)