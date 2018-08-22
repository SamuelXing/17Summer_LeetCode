# Bubble Sort: O(n^2) average and worst case. Memory O(1)
def BubbleSort(array):
	'''
	input: list
	output: list
	'''
	index = len(array) - 1
	while index >= 0:
		for j in range(index):
			if array[j+1] < array[j]:
				array[j+1], array[j] = array[j], array[j+1]
		index -= 1
	return array


array = BubbleSort([5,4,3,2,1])
print(array)

# if array is partially sorted
def BubbleSortOptimized(array):
	index = len(array) - 1
	while index >= 0:
		swapped = False

		for j in range(index):
			if array[j+1] < array[j]:
				array[j+1], array[j] = array[j], array[j+1]
				swapped = True

		if swapped == False:
			break
		index -= 1
	return array

array = BubbleSortOptimized([1,2,3,5,4])
print(array)