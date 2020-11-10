#pragma once

#include "Header.h"

bool CompareList(ListNode* l1, ListNode* l2);
ListNode* GetListFromVectorString(const vector<string>& v);
vector<string> GetTokenizeStringByComma(string s);
TreeNode* GetTreeFromStringVec(vector<string>& s);
TreeNode* DeSerializeTree(string s);
ListNode* DeSerializeList(string s);
