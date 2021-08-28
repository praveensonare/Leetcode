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

def water_pockets(height: List[int]) -> List[int]:
        waterL = 0
        waterR = 0

        left = 0
        right = len(height)-1
        max_left = height[left]
        max_right = height[right]
        t = 0

        result = []
        insertPos = 0
        while left<right:
            if height[left]<height[right]:
                max_left = max(max_left,height[left])
                t=(max_left-height[left])

                if (t > 0) :
                    waterL+=t
                else:
                    if (waterL > 0):
                        result.insert(insertPos, waterL);
                        insertPos = insertPos + 1
                    waterL = 0
                left+=1
            else:
                max_right = max(max_right,height[right])
                t=(max_right-height[right])
                if (t > 0) :
                    waterR+=t
                else:
                    if (waterR > 0):
                        result.insert(insertPos, waterR);
                    waterR = 0
                right-=1

        waterL += waterR
        if (waterL > 0):
            result.insert(insertPos, waterL);
        return result

def main():
    #basic testcases
    landscapes = [[4, 1, 2, 3, 0, 2],
                   [4, 2, 0, 3, 2, 5],
                   [4, 2, 0, 3, 2, 5],
                   [4, 2, 0],
                   [],
                   [5, 3, 8],
                   [516, 113, 171, 46, 318, 390, 949, 590, 231, 220, 456, 460, 958, 667, 884, 305, 270, 700, 659, 812, 424, 503, 859, 107, 745, 621, 770, 426, 819, 15, 331, 216, 122, 43, 72, 458, 375, 349, 735, 871, 179, 60, 101, 315, 555, 313, 581, 972, 911, 472, 88, 973, 880, 418, 971, 211, 196, 423, 14, 465, 873, 612, 180, 607, 567, 810, 154, 511, 117, 794, 214, 603, 932, 685, 544, 734, 885, 346, 959, 788, 457, 130, 740, 791, 489, 29, 831, 824, 674, 172, 944, 383, 676, 506, 250, 766, 710, 288, 624, 361]
                 ]

    for i in range(len(landscapes)):
        if (water_pockets_old(landscapes[1]) == water_pockets(landscapes[1])): print("test_", i, " passed")
        else: print ("test_", i, " failed");



    for i in range(0):
        landscape = random.sample(range(0, 1000), 100)
        if (water_pockets_old(landscape) == water_pockets(landscape)): print("test_", i, " passed")
        else:
            print ("test_", i, " failed tc=[", landscape, "]");
            break


    landscape = random.sample(range(0, 100000), 18000)
    start_time = time.time()
    for i in range(1100):
        water_pockets(landscape)

    end_time = time.time()
    print("running time = ", (end_time - start_time))

main()
