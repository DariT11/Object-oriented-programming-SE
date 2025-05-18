#pragma once
#include <iostream>

template <typename U, typename V>
class MyPear
{
	U first;
	V second;
};

template <typename U, typename V>
bool operator==(const MyPear<U, V>& lhs, const MyPear<U, V>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename U, typename V>
bool operator!=(const MyPear<U, V>& lhs, const MyPear<U, V>& rhs)
{
	return (lhs.first != rhs.first || lhs.second != rhs.second);
}

template <typename U, typename V>
bool operator<(const MyPear<U, V>& lhs, const MyPear<U, V>& rhs)
{
	return (lhs.first < rhs.first && lhs.second < rhs.first);
}