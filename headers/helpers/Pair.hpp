#pragma once
#include <iostream>

template <typename T, typename U>
class Pair
{

public:
	Pair();
	Pair(const T& first, const U& second);

	T getFirst() const;
	U getSecond() const;

	template <typename T1, typename U1>
	friend std::ostream& operator<<(std::ostream& os, const Pair<T1, U1>& pair);

	template <typename T1, typename U1>
	friend std::istream& operator>>(std::istream& is, Pair<T1, U1>& pair);


private:
	T first;
	U second;


};

template <typename T, typename U>
bool operator==(const Pair<T, U>& lhs, const Pair<T, U>& rhs)
{
	return (lhs.getFirst() == rhs.getFirst() && lhs.getSecond() == rhs.getSecond());
}

template <typename T, typename U>
bool operator!=(const Pair<T, U>& lhs, const Pair<T, U>& rhs)
{
	return !(lhs == rhs);
}
template <typename T, typename U>
bool operator<(const Pair<T, U>& lhs, const Pair<T, U>& rhs)
{
	return (lhs.getFirst() < rhs.getFirst() || (lhs.getFirst() == rhs.getFirst() && lhs.getSecond() < rhs.getSecond()));
}

template <typename T, typename U>
bool operator>(const Pair<T, U>& lhs, const Pair<T, U>& rhs)
{
	return (lhs.getFirst() > rhs.getFirst() || (lhs.getFirst() == rhs.getFirst() && lhs.getSecond() > rhs.getSecond()));
}

template <typename T, typename U>
Pair<T, U>::Pair() : first(), second() {

}

template <typename T, typename U>
Pair<T, U>::Pair(const T& first, const U& second) : first(first), second(second) {

}

template <typename T, typename U>
T Pair<T, U>::getFirst() const {
	return first;
}
template <typename T, typename U>
U Pair<T, U>::getSecond() const {
	return second;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const Pair<T, U>& pair) {
	os << "(" << pair.first << ", " << pair.second << ")";
	return os;
}

template <typename T, typename U>
std::istream& operator>>(std::istream& is, Pair<T, U>& pair) {
	is >> pair.first >> pair.second;
	return is;
}
