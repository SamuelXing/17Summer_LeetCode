# Merge Sort: O(NlogN) average and worst case, Memory depends

def MergeSort(array, l, r):
	if l < r:
		m = (l+(r-1))//2

		MergeSort(array, l, m)
		MergeSort(array, m+1, r)
		merge(array, l, m, r)

def merge(array, l, m, r):

	n1 = m - l + 1
	n2 = r - m

	arr1 = [array[l+i] for i in range(n1)]
	arr2 = [array[m+1+j] for j in range(n2)]

	i, j, k = 0, 0, l
	while i < n1 and j < n2:
		if arr1[i] < arr2[j]:
			array[k] = arr1[i]
			i += 1
		else:
			array[k] = arr2[j]
			j += 1
		k += 1

	while i < n1:
		array[k] = arr1[i]
		i += 1
		k += 1

	while j < n2:
		array[k] = arr2[j]
		j += 1
		k += 1

array = [5, 4, 3, 2, 1]
MergeSort(array, 0, len(array)-1)
print(array)

