#include "Header.h"

// 146. LRU Cache
// Level - Medium
// 
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// 
// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// Follow up:
// Could you do get and put in O(1) time complexity?
// 
// Example 1:
// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]
// 
// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:
// 1 <= capacity <= 3000
// 0 <= key <= 3000
// 0 <= value <= 104
// At most 3 * 104 calls will be made to get and put.

template<class Key, class Value>
class DLL
{
public:
    pair<Key, Value> data; // key-value
    DLL* prev;
    DLL* next;

    DLL(pair<Key, Value> _data): data(_data), prev(nullptr), next(nullptr) {}
    DLL(pair<Key, Value> _data, DLL* n): data(_data){
        if (n)
        {
            prev = n->prev;
            next = n;
            prev->next = this;
            next->prev = this;
        }
        else
        {
            next = prev = this;
        }
    }
};

class LRUCache {
    int cap;
    int size;
    DLL<int, int>* head = nullptr;
    map<int, DLL<int,int>*> H;
    void updateHead(DLL<int,int>* n)
    {
        // it accessed node is head, no need to update
        if (head == n) return;

        // remove n from DLL
        n->prev->next = n->next;
        n->next->prev = n->prev;

        // add n in begining
        n->prev = head->prev;
        head->prev = n;
        n->prev->next = n;
        n->next = head;
        head = n;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = nullptr;
        H.clear();
    }

    int get(int key) {

        if (H.find(key) != H.end())
        {
            updateHead(H[key]);
            return head->data.second;
        }
        else
            return -1;
    }

    void put(int key, int value) {

        if (H.find(key) == H.end())
        {
            if (size == cap)
            {
                head = head->prev;
                H.erase(H.find(head->data.first));
                head->data.first = key;
                head->data.second = value;
                H[key] = head;
            }
            else
            {
                head = new DLL<int, int>(pair<int,int>(key, value), head);
                H[key] = head;
                ++size;
            }
        }
        else
        {
            H[key]->data.second = value;
            updateHead(H[key]);
        }
    }
};

#define PAIR pair<string, vector<int>>
void test_LRUCache()
{
#if 0
    // ["LRUCache", "put",  "put",  "get", "put",  "get", "put",  "get", "get", "get"]
    // [ [2],       [1, 1], [2, 2], [1],   [3, 3], [2],   [4, 4], [1],   [3],   [4]]
    // Output
    // [null, null, null, 1, null, -1, null, -1, 3, 4]

    vector<PAIR> tc = {PAIR("LRUCache",{2}), PAIR("put", {1,1}), PAIR("put", {2,2}), PAIR("get", {1}), PAIR("put", {3,3}), PAIR("get", {2}), PAIR("put", {4,4}), PAIR("get", {1}), PAIR("get", {3}), PAIR("get", {4}) };
    vector<int> answers = {INT_MIN, INT_MIN, INT_MIN, 1, INT_MIN, -1, INT_MIN, -1, 3, 4};
#else
    vector<string> cmds = {"LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
    vector<vector<int>> vals = {{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    //vector<vector<int>> vals = {{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6}};
    vector<int> answers = {0,0,0,0,0,0,-1,0,19,17,0,-1,0,0,0,-1,0,-1,5,-1,12,0,0,3,5,5,0,0,1,0,-1,0,30,5,30,0,0,0,-1,0,-1,24,0,0,18,0,0,0,0,-1,0,0,18,0,0,-1,0,0,0,0,0,18,0,0,-1,0,4,29,30,0,12,-1,0,0,0,0,29,0,0,0,0,17,22,18,0,0,0,-1,0,0,0,20,0,0,0,-1,18,18,0,0,0,0,20,0,0,0,0,0,0,0};
#endif
    LRUCache LRU(vals[0][0]);
    for (int i = 1; i < vals.size(); ++i)
    {
        if (cmds[i] == "get")
        {
            int t = LRU.get(vals[i][0]);
            if (t != answers[i])
                cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
        }
        else if (cmds[i] == "put")
        {
            LRU.put(vals[i][0], vals[i][1]);
        }
    }
}
