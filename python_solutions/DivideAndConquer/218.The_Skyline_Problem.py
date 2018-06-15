# for each rectangle r:
#     for each critical point c:
#         if c.x >= r.left && c.x < r.right:
#             c.y gets the max of r.height and the previous value of c.y

# for each rectangle r:
#     for each critical point c below r (except the one at r.right):
#         c.y gets the max of r.height and the previous value of c.y

# for each critical point c:
#     for each rectangle r:
#         if c.x >= r.left && c.x < r.right:
#             c.y gets the max of r.height and the previous value of c.y

# for each critical point c:
#     for each rectangle r above c (not including the right edge of rectangles):
#         c.y gets the max of r.height and the previous value of c.y

# for each critical point c
#     c.y gets the height of the tallest rectangle over c


class Solution:
    def getSkyline(self, buildings):
        # sort critical points
        events = sorted([(L, -H, R) for L, R, H in buildings] + [(R, 0, None) for _, R, _ in buildings])
        # res: (x, height); hp: (negHeight, y)
        res, hp = [[0, 0]], [(0, float("inf"))]
        
        # for each critical point c
        for x, negH, R in events:
            # c.y gets the height of the tallest rectangle over c
            while x >= hp[0][1]: 
                heapq.heappop(hp)
            if negH: 
                heapq.heappush(hp, (negH, R))
            if (res[-1][1] + hp[0][0]): 
                res += [x, -hp[0][0]],
        return res[1:]
        
                
        