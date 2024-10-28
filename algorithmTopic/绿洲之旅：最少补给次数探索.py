import heapq

def solution(d, w, position, supply):
    position.append(d)
    supply.append(0)

    current_pos = 0
    current_water = w
    refills = 0
    max_heap = []

    for i in range(len(position)):
        distance = position[i] - current_pos
        
        current_water -= distance
        
        while current_water < 0:
            if not max_heap:
                return -1
            current_water += -heapq.heappop(max_heap)
            refills += 1
        
        heapq.heappush(max_heap, -supply[i])
        current_pos = position[i]
    
    return refills

if __name__ == "__main__":
    #  You can add more test cases here
    testPosition = [170, 192, 196, 234, 261, 269, 291, 404, 1055, 1121, 1150, 1234, 1268, 1402, 1725, 1726, 1727, 1762, 1901, 1970]
    testSupply = [443, 185, 363, 392, 409, 358, 297, 70, 189, 106, 380, 130, 126, 411, 63, 186, 36, 347, 339, 50]

    print(solution(10, 4, [1,4,7], [6,3,5]) == 1 )
    print(solution(2000, 200, testPosition, testSupply) == 5 )