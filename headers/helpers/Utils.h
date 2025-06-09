#pragma once
#include "MyString.h"
#include "../questions/QuestionFactory.h"

void setString(char*& dest, const char* src);
size_t roundToPowerOfTwo(size_t v);
bool stringCmp(const char* str1, const char* str2, size_t size);
size_t dataToAllocByStringLen(size_t size);
int toInt(const MyString& str);
double toDouble(const MyString& str);
QuestionType fromStringToQuestionType(const MyString& type);
MyString toString(int number);
