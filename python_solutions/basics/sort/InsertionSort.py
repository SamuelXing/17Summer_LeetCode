# Insertion Sort: O(n^2) average and worst case. Memory O(1)

def InsertionSort(array):
	'''
	Input: list
	Output: list
	'''

	for i in range(1, len(array)):
		key = array[i]

		j = i-1
		while j >= 0 and key < array[j]:
			array[j+1] = array[j]
			j -= 1

		array[j+1] = key
	return array


array = InsertionSort([5, 4, 3, 2, 1])
print(array)
