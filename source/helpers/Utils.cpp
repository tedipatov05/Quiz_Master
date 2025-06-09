#include "../../headers/helpers/Utils.h"
#include "../../headers/helpers/Constants.h"
#include <iostream>
#pragma warning(disable:4996)


void setString(char*& dest, const char* src) {
	size_t len = strlen(src);
	dest = new char[len + 1];
	strcpy(dest, src);
}

size_t roundToPowerOfTwo(size_t v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	v++;
	return v;
}


size_t dataToAllocByStringLen(size_t size)
{
	return std::max(roundToPowerOfTwo(size + 1), INITIAL_SIZE);
}

bool stringCmp(const char* str1, const char* str2, size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}



int toInt(const MyString& str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + (str[i] - '0');
	}
	return result;
}

double toDouble(const MyString& str) {
	double result = 0.0;
	double factor = 1.0;
	bool isFractionalPart = false;

	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			isFractionalPart = true;
			continue;
		}

		if (isFractionalPart) {
			factor /= 10.0;
			result += (str[i] - '0') * factor;
		}
		else {
			result = result * 10.0 + (str[i] - '0');
		}
	}

	return result;
}





QuestionType fromStringToQuestionType(const MyString& type) {
	if (type.toLower() == "t/f") {
		return QuestionType::TrueOrFalse;
	}
	else if (type.toLower() == "sc") {
		return QuestionType::SingleChoice;
	}
	else if (type.toLower() == "mc") {
		return QuestionType::MultipleChoice;
	}
	else if (type.toLower() == "sha") {
		return QuestionType::ShortAnswer;
	}
	else if (type.toLower() == "mp") {
		return QuestionType::MatchingPairs;
	}
	else {
		return QuestionType::Unknown;
	}


}

MyString toString(int number) {
	if (number == 0) {
		return MyString("0");
	}

	bool isNegative = number < 0;
	if (isNegative) {
		number = -number;
	}

	char buffer[12];
	int index = 0;

	while (number > 0) {
		buffer[index++] = (number % 10) + '0';
		number /= 10;
	}

	if (isNegative) {
		buffer[index++] = '-';
	}

	buffer[index] = '\0';


	for (int i = 0; i < index / 2; ++i) {
		std::swap(buffer[i], buffer[index - i - 1]);
	}

	return MyString(buffer);
}




