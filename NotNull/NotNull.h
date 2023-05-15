#pragma once
#include <exception>

template <typename T>
class NotNull
{
	T* m_ptr;
public:
	constexpr NotNull(T* ptr) : m_ptr(ptr)
	{
		if (m_ptr == nullptr)
		{
			throw std::exception("Передан нулевой указатель!");
		}
	}
	constexpr NotNull(const NotNull& otherNotNull) = default;
	constexpr NotNull& operator=(NotNull& otherNotNull) = default;
	constexpr operator T* () const
	{
		return m_ptr;
	}
	constexpr operator const T* () const
	{
		return m_ptr;
	}
	constexpr decltype(auto) operator*() const
	{
		return *m_ptr;
	}
	constexpr decltype(auto) operator->() const
	{
		return m_ptr;
	}

	decltype(auto) operator[](std::size_t) const = delete;
};
