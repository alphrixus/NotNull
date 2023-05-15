#include <iostream>
#include "NotNull.h"

template<typename T>
void Foo(NotNull<T> notNull)
{

}
template<typename T>
void Foo2(const T *temp)
{

}
void Foo3(const char *temp)
{

}

int main()
{
	int x = 10, y = 20;
	int *ptr = &x;
	int *ptr2 = &y;
	
	NotNull m_notNull(ptr); // прямая инициализация - ok
	NotNull m_notNull2 = ptr; // копирующая инициализация - ok
	m_notNull = m_notNull2; //  присваивание - ok
	NotNull m_notNull3(m_notNull); //  копирование - ok

	Foo<int>(m_notNull); //  передача в функцию с параметром типа NotNull - ok
	Foo2<int>(m_notNull); //  передача в функцию с параметром шаблонного указателя - ok
	y = *m_notNull; //  разыменование - ok

	char v = 5;
	char* c = &v;
	NotNull m_notNullCh(c); 
	Foo3(m_notNullCh); // передача NotNull в функцию, принимающую указатель на константу - ok

	ptr = nullptr;
	//NotNull m_notNull4(ptr); 
	// инициализация nullptr значением - бросает исключение - ok

	//m_notNull = 0; 
	// присвоить 0 нельзя - ok
	//m_notNull = nullptr;
	// присвоить nullptr нельзя - ok
	//m_notNull[1];
	// оператор [] вызвать нельзя - ok
}