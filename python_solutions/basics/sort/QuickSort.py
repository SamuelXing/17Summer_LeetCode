# O(nlog(n)) average, O(n^2) worst case, Memory O(log(n))
# Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

# Always pick first element as pivot.
# Always pick last element as pivot (implemented below)
# Pick a random element as pivot.
# Pick median as pivot.

def QuickSort(array, low, high):
	if low < high:
		pi = partition(array, low, high)

		QuickSort(array, low, pi-1)
		QuickSort(array, pi+1, high)

def partition(array, low, high):
	i = low - 1
	pivot = array[high]

	for j in range(low, high):

		if array[j] <= pivot:
			i += 1
			array[i], array[j] = array[j], array[i]

	array[i+1], array[high] = array[high], array[i+1]
	return (i+1)

array = [5, 4, 3, 2, 1]
QuickSort(array, 0, len(array)-1)
print(array)
	
