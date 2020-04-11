#pragma once
#include<iostream>

using namespace std;

class HugeInt
{
	private:
		int* pr_HugeInt;
		int pr_size;
		int pr_digits;
		char* pr_char_HugeInt;

	public:

		//constructors
		HugeInt();
		HugeInt(int);
		HugeInt(HugeInt&);

		//operators
		int& operator[](const int);
		HugeInt& operator =(const HugeInt&);
		HugeInt operator +(const HugeInt);
		HugeInt operator +(const int);
		friend HugeInt operator +(const int, const HugeInt&);
		HugeInt operator -( HugeInt);
		HugeInt operator -(const int);
		friend HugeInt operator -(const int, const HugeInt&);
		HugeInt operator *( HugeInt&);
		HugeInt operator *( int);
		friend HugeInt operator *( int,  HugeInt&);
		bool operator >(const HugeInt&);
		bool operator <(const HugeInt&);
		bool operator ==(const HugeInt&);
		bool operator !=( HugeInt&);
		friend void operator >>(istream&, HugeInt&);
		friend void operator<<(ostream&, HugeInt&);


		//functions
		void print();
		void setSize(int);
		void clear();

		~HugeInt();


};

