#include "Header.h"

// 1184. Distance Between Bus Stops
// Level - Easy
// 
// A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.
// 
// The bus goes along both directions i.e. clockwise and counterclockwise.
// Return the shortest distance between the given start and destination stops.
// 
// Example 1:
// Input: distance = [1,2,3,4], start = 0, destination = 1
// Output: 1
// Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
// 
// Example 2:
// Input: distance = [1,2,3,4], start = 0, destination = 2
// Output: 3
// Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
// 
// Example 3:
// Input: distance = [1,2,3,4], start = 0, destination = 3
// Output: 4
// Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
// 
// Constraints:
// 1 <= n <= 10^4
// distance.length == n
// 0 <= start, destination < n
// 0 <= distance[i] <= 10^4

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int len = distance.size();
    int total = 0;
    for (int i = 0; i < len; ++i)
    {
        total = distance[i] ^ total;
        distance[i] = distance[i] ^ total;
        total = distance[i] ^ total;
        total += distance[i];
    }
    distance.push_back(total);

    if (destination < start)
    {
        start       = destination ^ start;
        destination = destination ^ start;
        start       = destination ^ start;
    }

    return min(distance[destination] - distance[start], distance[distance.size()-1]-distance[destination] + distance[start]);
}

void test_distanceBetweenBusStops()
{
    vector<PAIR_VII> tc = { PAIR_VII(VI({1,2,3,4}), PAIR_II(0,1)),
        PAIR_VII(VI({1,2,3,4}), PAIR_II(0,2)),
        PAIR_VII(VI({1,2,3,4}), PAIR_II(0,3))};
    VI answers = {1,3,4};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (answers[i] != distanceBetweenBusStops(tc[i].first, tc[i].second.first, tc[i].second.second)) ERROR_LOG;
    }
}
