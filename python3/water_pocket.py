from typing import List
import time
import random

def water_pockets_old(landscape: List[int]) -> List[int]:
    result = []
    length = len(landscape)
    if length < 2:
        return result

    maxL = [landscape[0]] * length
    maxR = [landscape[length - 1]] * length
    last = length - 1
    for i in range(1, length):
        maxL[i] = max(maxL[i-1], landscape[i]);
        maxR[last - i] = max(maxR[last - i + 1], landscape[last - i]);

    sum = 0
    trap = 0

    for i in range(1, length):
        trap = min(maxL[i], maxR[i]) - landscape[i];
        if (trap > 0) :
            sum += trap;
        else :
            if (sum > 0):
                result.append(sum);
            sum = 0;

    return result

def water_pockets(landscape: List[int]) -> List[int]:
    waterL = 0
    waterR = 0
    
    left = 0
    right = len(landscape) - 1
    
    max_left = landscape[left]
    max_right = landscape[right]
    insertPosL = 0
    insertPosR = len(landscape)
    
    trap = 0
    result = [0]*len(landscape)
    while left < right:

        if landscape[left] < landscape[right]:
            max_left = max(max_left, landscape[left])
            trap = (max_left - landscape[left])
    
            if (trap > 0) :
                waterL += trap
            else:
                if (waterL > 0):
                    result[insertPosL] = waterL
                    insertPosL = insertPosL + 1
                waterL = 0
            left += 1
        else:
            max_right = max(max_right, landscape[right])
            trap = (max_right - landscape[right])
            if (trap > 0) :
                waterR += trap
            else:
                if (waterR > 0):
                    insertPosR = insertPosR - 1
                    result[insertPosR] = waterR
                waterR = 0
            right -= 1

    
    if (waterL > 0):
        result[insertPosL] = waterL
        insertPosL = insertPosL + 1
    if (waterR > 0):
        insertPosR = insertPosR - 1
        result[insertPosR] = waterR

    return result[:insertPosL] + result[insertPosR:]

def main():
    #basic testcases
    landscapes0 = [[4, 1, 2, 3, 0, 2]]
    landscapes1 = [[7, 16, 17, 5, 5, 8, 18, 6, 12]]
    landscapes = [[4, 1, 2, 3, 0, 2],
                   [4, 2, 0, 3, 2, 5],
                   [4, 2, 0, 3, 2, 5],
                   [4, 2, 0],
                   [5, 3, 8],
                   [516, 113, 171, 46, 318, 390, 949, 590, 231, 220, 456, 460, 958, 667, 884, 305, 270, 700, 659, 812, 424, 503, 859, 107, 745, 621, 770, 426, 819, 15, 331, 216, 122, 43, 72, 458, 375, 349, 735, 871, 179, 60, 101, 315, 555, 313, 581, 972, 911, 472, 88, 973, 880, 418, 971, 211, 196, 423, 14, 465, 873, 612, 180, 607, 567, 810, 154, 511, 117, 794, 214, 603, 932, 685, 544, 734, 885, 346, 959, 788, 457, 130, 740, 791, 489, 29, 831, 824, 674, 172, 944, 383, 676, 506, 250, 766, 710, 288, 624, 361],
                   [7, 16, 17, 5, 5, 8, 18, 6, 12]
                 ]

    passed = 0
    for i in range(len(landscapes)):
        list_old = water_pockets_old(landscapes[i])
        list_new = water_pockets(landscapes[i])
        if (list_old == list_new): passed = passed + 1
        else:
            print ("test_", i, " failed")
            print ("answer\t:", list_new)
            print ("expect\t:", list_old)

    print("Basic  Test Total:", len(landscapes), "\tPass:", passed, "\tFail:", len(landscapes) - passed)

    totalTest = 1000;
    passed = 0
    for i in range(totalTest):
        landscape = random.sample(range(0, 100), 80)
        if (water_pockets_old(landscape) == water_pockets(landscape)): passed = passed + 1

    print("Random Test Total:", totalTest, "\tPass:", passed, "\tFail:", totalTest - passed)

    landscape = random.sample(range(0, 100000), 18000)
    start_time = time.time()
    for i in range(1000):
        water_pockets(landscape)

    end_time = time.time()
    print("running time = ", (end_time - start_time))

main()
