#pragma once
#include <cstring>
#include <iostream>

class String
{
public:
	String(const char *cstr = 0);
	String(const String&);
	String& operator=(const String&);
	~String();
	char* get_c_str() const { return m_data;}
private:
	char *m_data;
};


inline
String::String(const char *cstr) {
	if (cstr) {
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	} else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline 
String::~String() {
	delete[] m_data;
}

inline
String::String(const String& other) {
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}

inline String&
String::operator = (const String& other) {
	if (this == &other) {
		return *this;
	}

	delete[] m_data;
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	return *this;
}

inline std::ostream&
operator<<(std::ostream& os, const String& str) {
	return os << str.get_c_str();
}
