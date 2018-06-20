	# The insight is that each new ugly number is generated from the previous ugly number by multiplying one of the prime. Thus we can maintain a pointer for each prime which indicates the current position of the generated ugly number list. Then there is a new ugly number from each prime, then we find the minimum one from them. Naturally the minimum one can be found by min-heap.

class Solution:
    def nthSuperUglyNumber(self, n, primes):
    	"""
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
	    heap, uglies = [], [1]
	    k = len(primes)
	    for i in range(k):
	        heapq.heappush(heap, (primes[i], 0, primes[i]))
	    while len(uglies) < n:
	        x, idx, p = heap[0]
	        uglies += [x]
	        while heap and heap[0][0] == x:
	            x, idx, p = heapq.heappop(heap)
	            heapq.heappush(heap, (p * uglies[idx+1], idx+1, p))
    
    	return uglies[-1]

    def nthSuperUglyNumber(self, n, primes):
        import heapq
        q, uglyNums, uglySet = [], [1],  set([1])
        k = len(primes)
        for i in range(k): 
            heapq.heappush(q, (primes[i], 0, primes[i]))
            uglySet.add(primes[i])
        for _ in range(1, n):
            x, i, p = heapq.heappop(q)
            uglyNums += [x]
            j = i+1
            while (p * uglyNums[j]) in uglySet: j += 1
            heapq.heappush(q, (p * uglyNums[j], j, p))
            uglySet.add(p * uglyNums[j])
        return uglyNums[-1]

	# Maintain a pointer from prime to ugly numbers and extract minimum next each time.
    def nthSuperUglyNumber(self, n, primes):
        indexs, uglies = [0] * len(primes), [1]
        while len(uglies) < n:
            uglies.append(min([p * uglies[indexs[i]] for i, p in enumerate(primes)]))
            # print([p * uglies[indexs[i]] for i, p in enumerate(primes)])
            for i, p in enumerate(primes):
                if p * uglies[indexs[i]] == uglies[-1]:
                    indexs[i] += 1
        return uglies[-1]

