#pragma once

#include "Header.h"

bool CompareList(ListNode* l1, ListNode* l2);
ListNode* GetListFromVectorString(const vector<string>& v);
vector<string> GetTokenizeStringByComma(string s);
TreeNode* GetTreeFromStringVec(vector<string>& s);
TreeNode* DeSerializeTree(string s);
ListNode* DeSerializeList(string s);

// Circular Double link List
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
