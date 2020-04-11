#include "HugeInt.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int char_to_int(char c)
{
	if (c == '0')
	{
		return 0;
	}
	else if (c == '1')
	{
		return 1;
	}
	else if (c == '2')
	{
		return 2;
	}
	else if (c == '3')
	{
		return 3;
	}
	else if (c == '4')
	{
		return 4;
	}
	else if (c == '5')
	{
		return 5;
	}
	else if (c == '6')
	{
		return 6;
	}
	else if (c == '7')
	{
		return 7;
	}
	else if (c == '8')
	{
		return 8;
	}
	else if (c == '9')
	{
		return 9;
	}
}

char int_to_char(int i)
{
	char c;
	if (i == 0)
	{
		c = '0';
		return c;
	}
	else if (i == 1)
	{
		c = '1';
		return c;
	}
	else if (i == 2)
	{
		c = '2';
		return c;
	}
	else if (i == 3)
	{
		c = '3';
		return c;
	}
	else if (i == 4)
	{
		c = '4';
		return c;
	}
	else if (i == 5)
	{
		c = '5';
		return c;
	}
	else if (i == 6)
	{
		c = '6';
		return c;
	}
	else if (i == 7)
	{
		c = '7';
		return c;
	}
	else if (i == 8)
	{
		c = '8';
		return c;
	}
	else if (i == 9)
	{
		c = '9';
		return c;
	}
}

int* converter(char* ptr_array, int& pr_size, int& pr_digits)
{
	int digits = 0;
	int size, number = 0;
	int* int_array = nullptr;

	for (int i = 0; ptr_array[i] != '\0'; i++)
	{
		digits++;
	}
	pr_digits = digits;


	if (digits % 9 == 0)
	{
		size = digits / 9;
	}
	else
	{
		size = digits / 9 + 1;
	}



	char** ptr_subArrays = new char* [size];
	for (int i = 0; i < size; i++)
	{
		ptr_subArrays[i] = new char[12];
	}

	if (digits == 1)
	{
		ptr_subArrays[0][0] = ptr_array[0];
		ptr_subArrays[0][1] = '\0';
	}
	else
	{
		int x = 0;
		int y = 1;
		for (int i = digits; i >= 1; i--)
		{

			if ((digits - i + 1) % 9 != 0 && i != 1)
			{
				ptr_subArrays[x][y - 1] = ptr_array[i - 1];
				y++;
			}
			else if ((digits - i + 1) % 9 == 0 || i == 1)
			{

				if (i != digits)
				{
					ptr_subArrays[x][y - 1] = ptr_array[i - 1];
					ptr_subArrays[x][y] = '\0';
				}
				else
				{
					ptr_subArrays[x][y - 1] = ptr_array[digits - i - 1];
					ptr_subArrays[x][digits - (x * 9)] = '\0';
				}
				y = 1;
				x++;
			}
		}
	}

	int length = 0;
	char temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; ptr_subArrays[i][j]; j++)
		{
			length++;
		}

		for (int x = 0; x < length / 2; x++)
		{
			temp = ptr_subArrays[i][length - x - 1];
			ptr_subArrays[i][length - x - 1] = ptr_subArrays[i][x];
			ptr_subArrays[i][x] = temp;
		}

		length = 0;
	}

	if (ptr_array[0] == '-' && (digits - 1) % 9 == 0)
	{
		pr_size = size;
		int_array = new int[size];

	}
	else
	{
		pr_size = size + 1;
		int_array = new int[size + 1];
	}

	for (int i = 0; i < size + 1; i++)
	{
		int_array[i] = 0;
	}

	bool negative_flag = false;

	for (int i = 0; i < size; i++)
	{
		negative_flag = false;
		for (int j = 0; ptr_subArrays[i][j] != '\0'; j++)
		{
			if (ptr_subArrays[i][j] == '0')
			{
				number = number + 0;
			}
			else if (ptr_subArrays[i][j] == '1')
			{
				number = number + 1;
			}
			else if (ptr_subArrays[i][j] == '2')
			{
				number = number + 2;
			}
			else if (ptr_subArrays[i][j] == '3')
			{
				number = number + 3;
			}
			else if (ptr_subArrays[i][j] == '4')
			{
				number = number + 4;
			}
			else if (ptr_subArrays[i][j] == '5')
			{
				number = number + 5;
			}
			else if (ptr_subArrays[i][j] == '6')
			{
				number = number + 6;
			}
			else if (ptr_subArrays[i][j] == '7')
			{
				number = number + 7;
			}
			else if (ptr_subArrays[i][j] == '8')
			{
				number = number + 8;
			}
			else if (ptr_subArrays[i][j] == '9')
			{
				number = number + 9;
			}
			if (ptr_subArrays[i][j] == '-')
			{
				negative_flag = true;
			}

			if (ptr_subArrays[i][j + 1] != '\0')
			{
				number = number * 10;
			}

			if (ptr_array[0] == '-' && i == size - 2 && (digits - 1) % 9 == 0)
			{
				negative_flag = true;
			}
		}

		if (negative_flag == true)
		{
			number = -number;
		}

		int_array[i] = number;
		number = 0;
	}
	for (int i = 0; i < size; i++)
	{
		delete[]ptr_subArrays[i];
	}
	delete[]ptr_subArrays;

	return int_array;
}

HugeInt::HugeInt()
{
	pr_size=0;
	pr_HugeInt = nullptr;
	pr_char_HugeInt = nullptr;
	pr_digits = 0;
}

void HugeInt::clear()
{
	if (pr_HugeInt != nullptr)
	{
		delete[]pr_HugeInt;
	}
	pr_HugeInt = nullptr;
	pr_char_HugeInt = nullptr;
	pr_digits = 0;
	pr_size = 0;
}

HugeInt::HugeInt(int size)
{
	pr_size = size;
	pr_HugeInt = new int[size];
	pr_digits = 0;
	for (int i = 0; i < pr_size; i++)
	{
		pr_HugeInt[i] = 0;
	}
	pr_char_HugeInt = nullptr;
}

HugeInt::HugeInt(HugeInt& obj_in)
{
	pr_size = obj_in.pr_size;
	pr_HugeInt = new int[obj_in.pr_size];
	pr_char_HugeInt = nullptr;
	pr_digits = obj_in.pr_digits;
	for (int i = 0; i < pr_size; i++)
	{
		pr_HugeInt[i] = obj_in.pr_HugeInt[i];
	}
}


//subscript operator
int& HugeInt::operator[](const int index)
{
	return pr_HugeInt[index];
}



HugeInt& HugeInt::operator=(const HugeInt& obj_in)
{
	if (pr_HugeInt == nullptr)
	{
		pr_size = obj_in.pr_size;
		pr_HugeInt = new int[pr_size];
	}
	
	pr_char_HugeInt = nullptr;
	
	for (int i = 0; i < pr_size; i++)
	{
		pr_HugeInt[i] = obj_in.pr_HugeInt[i];
	}
	return *this;
}


//Addition of two hugeint
HugeInt HugeInt::operator+(const HugeInt obj_in)
{
	int carry = 0, x = 0;
	int sign_flag_no1 = 0, sign_flag_no2 = 0;

	if (pr_HugeInt != nullptr && obj_in.pr_HugeInt != nullptr)
	{
		if (pr_size != obj_in.pr_size)
		{
			for (int i = 0; i < pr_size; i++)
			{
				if (pr_HugeInt[i] < 0)
				{
					sign_flag_no1 = -1;
					break;
				}
			}
			if (sign_flag_no1 != -1)
			{
				sign_flag_no1 = 1;
			}

			for (int i = 0; i < obj_in.pr_size; i++)
			{
				if (obj_in.pr_HugeInt[i] < 0)
				{
					sign_flag_no2 = -1;
					break;
				}
			}
			if (sign_flag_no2 != -1)
			{
				sign_flag_no2 = 1;
			}

			int smaller_size = 0, larger_size = 0;
			if (pr_size > obj_in.pr_size)
			{
				smaller_size = obj_in.pr_size - 1;
				larger_size = pr_size - 1;
				HugeInt return_obj(larger_size);

				for (int i = 0; i < larger_size; i++)
				{
					return_obj.pr_HugeInt[i] = 0;
				}
				if (sign_flag_no1 == 1 && sign_flag_no2 == 1)
				{
					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x + 1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + pr_HugeInt[i];
					}
				}
				else if (sign_flag_no1 == -1 && sign_flag_no2 == -1)
				{
					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = -pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x + 1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + pr_HugeInt[i];
					}
				}
				else if (sign_flag_no1 == -1 && sign_flag_no2 == 1)
				{

					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = -pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x + 1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + pr_HugeInt[i];
					}
				}
				else if (sign_flag_no1 == 1 && sign_flag_no2 == -1)
				{
					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x + 1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + pr_HugeInt[i];
					}
				}

				for (int i = return_obj.pr_size - 1; i >= 0; i--)
				{
					if (return_obj.pr_HugeInt[i]<0)
					{
						for (int j = i - 1; j >= 0; j--)
						{
							return_obj.pr_HugeInt[j] = -return_obj.pr_HugeInt[j];
						}
						break;
					}
				}

				return return_obj;
			}
			else if (obj_in.pr_size > pr_size)
			{
				larger_size = obj_in.pr_size - 1;
				smaller_size = pr_size - 1;

				HugeInt return_obj(larger_size);

				for (int i = 0; i < larger_size; i++)
				{
					return_obj.pr_HugeInt[i] = 0;
				}
				if (sign_flag_no1 == 1 && sign_flag_no2 == 1)
				{
					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x+1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + obj_in.pr_HugeInt[i];
					}
				}
				else if (sign_flag_no1 == -1 && sign_flag_no2 == -1)
				{
					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = pr_HugeInt[i] - obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x+1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + obj_in.pr_HugeInt[i];
					}
				}
				else if (sign_flag_no1 == -1 && sign_flag_no2 == 1)
				{
					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x+1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + obj_in.pr_HugeInt[i];
					}




					
				}
				else if (sign_flag_no1 == 1 && sign_flag_no2 == -1)
				{
					for (int i = 0; i < smaller_size; i++)
					{
						x = i;
						return_obj[i] = pr_HugeInt[i] - obj_in.pr_HugeInt[i] + return_obj[i];

						if (return_obj[i] > 999999999)
						{
							carry = return_obj[i] / 1000000000;
							return_obj[i] = return_obj[i] % 1000000000;

							return_obj[i + 1] = carry;

						}
					}

					for (int i = x+1; i < larger_size; i++)
					{
						return_obj[i] = return_obj[i] + obj_in.pr_HugeInt[i];
					}
				}


				for (int i = return_obj.pr_size - 1; i >= 0; i--)
				{
					if (return_obj.pr_HugeInt[i] < 0)
					{
						for (int j = i - 1; j >= 0; j--)
						{
							return_obj.pr_HugeInt[j] = -return_obj.pr_HugeInt[j];
						}
						break;
					}
				}
				return return_obj;
			}
		}
		else if (pr_size == obj_in.pr_size)
		{
			for (int i = 0; i < pr_size; i++)
			{
				if (pr_HugeInt[i] < 0)
				{
					sign_flag_no1 = -1;
					pr_HugeInt[i] = -pr_HugeInt[i];
					break;
				}
			}
			if (sign_flag_no1 != -1)
			{
				sign_flag_no1 = 1;
			}

			for (int i = 0; i < obj_in.pr_size; i++)
			{
				if (obj_in.pr_HugeInt[i] < 0)
				{
					sign_flag_no2 = -1;
					obj_in.pr_HugeInt[i] = -obj_in.pr_HugeInt[i];
					break;
				}
			}
			if (sign_flag_no2 != -1)
			{
				sign_flag_no2 = 1;
			}

			int size = obj_in.pr_size;
			HugeInt  return_obj(size);


			for (int i = 0; i < size; i++)
			{
				return_obj.pr_HugeInt[i] = 0;
			}

			if (sign_flag_no1 == sign_flag_no2)
			{
				for (int i = 0; i < size; i++)
				{
					return_obj[i] = pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];

					if (return_obj[i] > 999999999)
					{
						carry = return_obj[i] / 1000000000;
						return_obj[i] = return_obj[i] % 1000000000;

						return_obj[i + 1] = carry;
					}
				}

				if (sign_flag_no1 == -1 && sign_flag_no2 == -1)
				{

					for (int i = return_obj.pr_size - 1; i >= 0; i--)
					{
						if (return_obj.pr_HugeInt[i] != 0)
						{
							return_obj.pr_HugeInt[i] = -return_obj.pr_HugeInt[i];
							break;
						}
					}
				}
			}
			else if (sign_flag_no1 == 1 && sign_flag_no2 == -1)
			{
				for (int i = 0; i < size; i++)
				{
					if (i != size - 1)
					{
						return_obj[i] = pr_HugeInt[i] - obj_in.pr_HugeInt[i] + return_obj[i];
					}
					else
					{
						return_obj[i] = pr_HugeInt[i] + obj_in.pr_HugeInt[i] + return_obj[i];
					}
					if (return_obj[i] > 999999999)
					{
						carry = return_obj[i] / 1000000000;
						return_obj[i] = return_obj[i] % 1000000000;

						return_obj[i + 1] = carry;
					}
				}

				for (int i = return_obj.pr_size - 1; i >= 0; i--)
				{
					if (return_obj.pr_HugeInt[i] < 0)
					{
						for (int j = i - 1; j >= 0; j--)
						{
							return_obj.pr_HugeInt[j] = -return_obj.pr_HugeInt[j];
						}
						break;
					}
				}
			}
			else if (sign_flag_no1 == -1 && sign_flag_no2 == 1)
			{
				for (int i = 0; i < size; i++)
				{
					return_obj[i] = obj_in.pr_HugeInt[i] - pr_HugeInt[i] + return_obj[i];

					if (return_obj[i] > 999999999)
					{
						carry = return_obj[i] / 1000000000;
						return_obj[i] = return_obj[i] % 1000000000;

						return_obj[i + 1] = carry;
					}
				}

				for (int i = return_obj.pr_size-1; i >=0 ; i--)
				{
					if (return_obj.pr_HugeInt[i] < 0)
					{
						for (int j = i -1; j >= 0; j--)
						{
							return_obj.pr_HugeInt[j] = -return_obj.pr_HugeInt[j];
						}
						break;
					}
				}

			}

			if (sign_flag_no1 == -1)
			{
				for (int i = pr_size - 1; i >= 0; i--)
				{
					if (pr_HugeInt[i] != 0)
					{
						pr_HugeInt[i] = -pr_HugeInt[i];
						break;
					}
				}
			}
			return return_obj;
		}
	}
	else
	{
		HugeInt return_obj;
		return return_obj;
	}
}

HugeInt HugeInt::operator+(const int num)
{
	int carry = 0;
	if (pr_HugeInt != nullptr)
	{
		HugeInt return_obj(pr_size);
		return_obj = *this;

		return_obj.pr_HugeInt[0] = pr_HugeInt[0] + num;
		if (return_obj.pr_HugeInt[0] > 999999999)
		{
			carry = return_obj.pr_HugeInt[0] / 1000000000;
			return_obj.pr_HugeInt[0] = return_obj.pr_HugeInt[0] % 1000000000;
			return_obj[1] = return_obj[1] + carry;
		}
		return return_obj;
	}
	else
	{
		HugeInt return_obj;
		return return_obj;
	}
}


HugeInt operator+(const int num, const HugeInt& obj_in)
{
	int carry = 0;
	if (obj_in.pr_HugeInt != nullptr)
	{
		HugeInt return_obj(obj_in.pr_size);
		return_obj = obj_in;

		return_obj.pr_HugeInt[0] = obj_in.pr_HugeInt[0] + num;
		if (return_obj.pr_HugeInt[0] > 999999999)
		{
			carry = return_obj.pr_HugeInt[0] / 1000000000;
			return_obj.pr_HugeInt[0] = return_obj.pr_HugeInt[0] % 1000000000;
			return_obj[1] = return_obj[1] + carry;
		}
		return return_obj;
	}
	else
	{
		HugeInt return_obj;
		return return_obj;
	}
}

HugeInt HugeInt::operator-( HugeInt obj_in)
{
	int sign_flag = 0;

	obj_in.pr_HugeInt[obj_in.pr_size - 2] = -obj_in.pr_HugeInt[obj_in.pr_size - 2];

	HugeInt  return_obj;

	return_obj = (*this + obj_in);

	for (int i = 0; i < return_obj.pr_size; i++)
	{
		if (return_obj.pr_HugeInt[i] < 0)
		{
			sign_flag = -1;
			return_obj.pr_HugeInt[i] = -return_obj.pr_HugeInt[i];
		}
	}

	if (sign_flag == -1)
	{
		for (int i = return_obj.pr_size - 1; i >= 0; i--)
		{
			if (return_obj.pr_HugeInt[i] != 0)
			{
				return_obj.pr_HugeInt[i] = -return_obj.pr_HugeInt[i];
				break;
			}
		}
	}

	return return_obj;
}

HugeInt HugeInt::operator-(const int num)
{
	int carry = 0;
	if (pr_HugeInt != nullptr)
	{
		HugeInt return_obj(pr_size);
		return_obj = *this;

		return_obj.pr_HugeInt[0] = pr_HugeInt[0] - num;
		
		return return_obj;
	}
	else
	{
		HugeInt return_obj;
		return return_obj;
	}
}


HugeInt operator-(const int num, const HugeInt& obj_in)
{
	if (obj_in.pr_size == 2 && obj_in.pr_HugeInt[obj_in.pr_size - 1] == 0)
	{
		HugeInt return_obj(obj_in.pr_size);
		return_obj = obj_in;
		return_obj[0] = num - obj_in.pr_HugeInt[0];
		return return_obj;
	}
	else
	{
		HugeInt return_obj(obj_in.pr_size);
		return_obj = obj_in;
		return_obj[0] = obj_in.pr_HugeInt[0] - num;
		if (return_obj[0] < 0)
		{
			return_obj[0] = -return_obj[0];
		}
		for (int i = return_obj.pr_size - 1; i >= 0; i--)
		{
			if (return_obj[i] != 0)
			{
				return_obj[i] = -return_obj[i];
				break;
			}
		}
		return return_obj;
	}
}



HugeInt HugeInt::operator*( HugeInt& obj_in)
{
	char temp_char;
	int singel_digit_1 = 0;
	int single_digit_2 = 0;
	int digits_number = 0;
	int digits_product = 0;
	int carry_1 = 0;
	int carry = 0;
	int sign_flag_1 = 0;
	int sign_flag_2 = 0;

	for (int i = pr_size - 1; i >= 0; i--)
	{
		if (pr_HugeInt[i] < 0)
		{
			sign_flag_1 = -1;
			break;
		}
	}
	if (sign_flag_1 == 0)
	{
		sign_flag_1 = 1;
	}

	for (int i = obj_in.pr_size - 1; i >= 0; i--)
	{
		if (obj_in.pr_HugeInt[i] < 0)
		{
			sign_flag_2 = -1;
			break;
		}
	}
	if (sign_flag_2 == 0)
	{
		sign_flag_2 = 1;
	}
	
	if (sign_flag_1 == -1)
	{
		pr_digits--;
	}

	if (sign_flag_2 == -1)
	{
		obj_in.pr_digits--;
	}


	char** sub_Arrays = new char* [obj_in.pr_digits];
	for (int i = 0; i < obj_in.pr_digits; i++)
	{
		sub_Arrays[i] = new char[50];
	}

	for (int i = 0; i < obj_in.pr_digits; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			sub_Arrays[i][j] = '0';
		}
	}

	int j = 0;

	for (int x = 0; x < obj_in.pr_digits; x++)
	{

		singel_digit_1 = char_to_int(obj_in.pr_char_HugeInt[x]);

		for (int i = 0; i < pr_digits; i++)
		{

			temp_char = pr_char_HugeInt[i];
			single_digit_2 = char_to_int(pr_char_HugeInt[i]);




			digits_product = singel_digit_1 * single_digit_2;

			digits_product = digits_product + carry_1;
			carry_1 = 0;

			if (digits_product >= 10)
			{
				carry_1 = digits_product / 10;
				digits_product = digits_product % 10;
			}

			sub_Arrays[x][i + x] = int_to_char(digits_product);


			if (i == pr_digits - 1 && carry_1 != 0)
			{
				i++;
				while (carry_1 != 0)
				{
					carry = carry_1 % 10;

					sub_Arrays[x][i + x] = int_to_char(carry);


					carry_1 = carry_1 / 10;
				}
			}

			j = i;
		}

		sub_Arrays[x][j + 1 + x] = '\0';
	}


	char* Array = new char[50];
	int sum = 0;
	carry = 0;
	carry_1 = 0;
	int start = 0;

	for (int i = 0; sub_Arrays[obj_in.pr_digits - 1][i] != '\0'; i++)
	{
		for (int x = start; x < obj_in.pr_digits; x++)
		{
			if (temp_char = sub_Arrays[x][i] == '\0')
			{
				start++;
			}
			else
			{
				temp_char = sub_Arrays[x][i];
				single_digit_2 = char_to_int(sub_Arrays[x][i]);

				sum = sum + single_digit_2 + carry;
				carry = 0;
			}
		}
		if (sum >= 10)
		{
			carry = sum / 10;
			sum = sum % 10;
		}

		Array[i] = int_to_char(sum);


		j = i;
		sum = 0;
	}

	start = 0;

	Array[j + 1] = '\0';
	for (int i = 0; Array[i] != '\0'; i++)
	{
		start++;
	}

	for (int i = 0; i < start / 2; i++)
	{
		temp_char = Array[start - i - 1];
		Array[start - i - 1] = Array[i];
		Array[i] = temp_char;
	}

	


	HugeInt obj_return;
	obj_return.pr_HugeInt = converter(Array, obj_return.pr_size, obj_return.pr_digits);
	if (sign_flag_1 == -1 && sign_flag_2 == 1|| sign_flag_1 == 1 && sign_flag_2 == -1)
	{
		for (int i = obj_return.pr_size - 1; i >= 0; i--)
		{
			if (obj_return.pr_HugeInt[i] != 0)
			{
				obj_return.pr_HugeInt[i] = -obj_return.pr_HugeInt[i];
				break;
			}
		}
	}

	if (sign_flag_1 == -1)
	{
		pr_digits++;
	}

	

	for (int i = 0; i < obj_in.pr_digits; i++)
	{
		delete[]sub_Arrays[i];
	}
	delete[]sub_Arrays;
	delete[] Array;

	if (sign_flag_2 == -1)
	{
		obj_in.pr_digits++;
	}

	return obj_return;
}

HugeInt HugeInt::operator*( int number)
{
	int temp = number;
	char temp_char;
	int singel_digit_1 = 0;
	int single_digit_2 = 0;
	int digits_number = 0;
	int digits_product = 0;
	int carry_1 = 0;
	int carry = 0;
	int sign_flag_1 = 0;
	int sign_flag_2 = 0;

	for (int i = pr_size - 1; i >= 0; i--)
	{
		if (pr_HugeInt[i] < 0)
		{
			sign_flag_1 = -1;
			break;
		}
	}
	if (sign_flag_1 == 0)
	{
		sign_flag_1 = 1;
	}

	if (number >= 0)
	{
		sign_flag_2 = 1;
	}
	else
	{
		sign_flag_2 = -1;
	}

	if (sign_flag_1 == -1)
	{
		pr_digits--;
	}

	if (sign_flag_2 == -1)
	{
		number = -number;
	}


	while (temp != 0)
	{
		digits_number++;
		temp = temp / 10;
	}

	temp = number;

	char** sub_Arrays = new char*[digits_number];
	for (int i = 0; i < digits_number; i++)
	{
		sub_Arrays[i] = new char[50];
	}

	for (int i = 0; i < digits_number; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			sub_Arrays[i][j] = '0';
		}
	}

	int j = 0;

	for (int x = 0; x < digits_number; x++)
	{
		
		singel_digit_1 = temp % 10;

		for (int i = 0; i < pr_digits; i++)
		{
			
			temp_char = pr_char_HugeInt[i];
			single_digit_2 = char_to_int(pr_char_HugeInt[i]);

			


			digits_product = singel_digit_1 * single_digit_2;

			digits_product = digits_product + carry_1;
			carry_1 = 0;

			if (digits_product >= 10)
			{
				carry_1 = digits_product / 10;
				digits_product = digits_product % 10;
			}

			sub_Arrays[x][i + x] = int_to_char(digits_product);

			
			if (i == pr_digits - 1 && carry_1 != 0)
			{
				i++;
				while(carry_1!=0)
				{
					carry = carry_1 % 10;
					
					sub_Arrays[x][i + x] = int_to_char(carry);
					

					carry_1 = carry_1 / 10;
				}
			}

			j = i;
		}

		sub_Arrays[x][j + 1 + x] = '\0';
		temp = temp / 10;
	}

	
	char* Array = new char[50];
	int sum = 0;
	carry = 0;
	carry_1 = 0;
	int start = 0;
	
	for (int i = 0; sub_Arrays[digits_number-1][i] != '\0'; i++)
	{
		for (int x = start; x < digits_number; x++)
		{
			if (temp_char = sub_Arrays[x][i] == '\0')
			{
				start++;
			}
			else
			{
				temp_char = sub_Arrays[x][i];
				single_digit_2 = char_to_int(sub_Arrays[x][i]);

				

				sum = sum + single_digit_2+carry;
				carry = 0;
			}
		}
		if (sum >= 10)
		{
			carry = sum / 10;
			sum = sum % 10;
		}

		Array[i] = int_to_char(sum);
		

		j = i;
		sum = 0;
	}

	start = 0;

	Array[j+1] = '\0';
	for (int i = 0; Array[i] != '\0'; i++)
	{
		start++;
	}

	for (int i = 0; i < start / 2; i++)
	{
		temp_char = Array[start - i - 1];
		Array[start - i - 1] = Array[i];
		Array[i] = temp_char;
	}


	HugeInt obj_return;
	obj_return.pr_HugeInt = converter(Array, obj_return.pr_size, obj_return.pr_digits);
	if (sign_flag_1 == -1 && sign_flag_2 == 1 || sign_flag_1 == 1 && sign_flag_2 == -1)
	{
		for (int i = obj_return.pr_size - 1; i >= 0; i--)
		{
			if (obj_return.pr_HugeInt[i] != 0)
			{
				obj_return.pr_HugeInt[i] = -obj_return.pr_HugeInt[i];
				break;
			}
		}
	}
	
	
	for (int i = 0; i < digits_number; i++)
	{
		delete[]sub_Arrays[i];
	}
	delete[]sub_Arrays;
	delete []Array;

	if (sign_flag_1 == -1)
	{
		pr_digits++;
	}

	return obj_return;
}

HugeInt operator*(int number, HugeInt& obj_in)
{

	int temp = number;
	char temp_char;
	int singel_digit_1 = 0;
	int single_digit_2 = 0;
	int digits_number = 0;
	int digits_product = 0;
	int carry_1 = 0;
	int carry = 0;

	int sign_flag_1 = 0;
	int sign_flag_2 = 0;

	if (number >= 0)
	{
		sign_flag_1 = 1;
	}
	else
	{
		sign_flag_1 = -1;
	}

	for (int i = obj_in.pr_size - 1; i >= 0; i--)
	{
		if (obj_in.pr_HugeInt[i] < 0)
		{
			sign_flag_2 = -1;
			break;
		}
	}
	if (sign_flag_2 == 0)
	{
		sign_flag_2 = 1;
	}

	

	if (sign_flag_2 == -1)
	{
		obj_in.pr_digits--;
	}

	if (sign_flag_1 == -1)
	{
		number = -number;
	}

	while (temp != 0)
	{
		digits_number++;
		temp = temp / 10;
	}

	temp = number;

	char** sub_Arrays = new char* [digits_number];
	for (int i = 0; i < digits_number; i++)
	{
		sub_Arrays[i] = new char[50];
	}

	for (int i = 0; i < digits_number; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			sub_Arrays[i][j] = '0';
		}
	}

	int j = 0;

	for (int x = 0; x < digits_number; x++)
	{

		singel_digit_1 = temp % 10;

		for (int i = 0; i < obj_in.pr_digits; i++)
		{

			temp_char = obj_in.pr_char_HugeInt[i];
			single_digit_2 = char_to_int(obj_in.pr_char_HugeInt[i]);




			digits_product = singel_digit_1 * single_digit_2;

			digits_product = digits_product + carry_1;
			carry_1 = 0;

			if (digits_product >= 10)
			{
				carry_1 = digits_product / 10;
				digits_product = digits_product % 10;
			}

			sub_Arrays[x][i + x] = int_to_char(digits_product);


			if (i == obj_in.pr_digits - 1 && carry_1 != 0)
			{
				i++;
				while (carry_1 != 0 )
				{
					carry = carry_1 % 10;

					sub_Arrays[x][i + x] = int_to_char(carry);


					carry_1 = carry_1 / 10;
				}
			}

			j = i;
		}

		sub_Arrays[x][j + 1 + x] = '\0';
		temp = temp / 10;
	}

	char* Array = new char[50];
	int sum = 0;
	carry = 0;
	carry_1 = 0;
	int start = 0;

	for (int i = 0; sub_Arrays[digits_number - 1][i] != '\0'; i++)
	{
		for (int x = start; x < digits_number; x++)
		{
			if (temp_char = sub_Arrays[x][i] == '\0')
			{
				start++;
			}
			else
			{
				temp_char = sub_Arrays[x][i];
				single_digit_2 = char_to_int(sub_Arrays[x][i]);



				sum = sum + single_digit_2 + carry;
				carry = 0;
			}
		}
		if (sum >= 10)
		{
			carry = sum / 10;
			sum = sum % 10;
		}

		Array[i] = int_to_char(sum);
		j = i;
		sum = 0;
	}

	start = 0;

	Array[j + 1] = '\0';
	for (int i = 0; Array[i] != '\0'; i++)
	{
		start++;
	}

	for (int i = 0; i < start / 2; i++)
	{
		temp_char = Array[start - i - 1];
		Array[start - i - 1] = Array[i];
		Array[i] = temp_char;
	}


	HugeInt obj_return;
	obj_return.pr_HugeInt = converter(Array, obj_return.pr_size, obj_return.pr_digits);
	if (sign_flag_1 == -1 && sign_flag_2 == 1 || sign_flag_1 == 1 && sign_flag_2 == -1)
	{
		for (int i = obj_return.pr_size - 1; i >= 0; i--)
		{
			if (obj_return.pr_HugeInt[i] != 0)
			{
				obj_return.pr_HugeInt[i] = -obj_return.pr_HugeInt[i];
				break;
			}
		}
	}

	

	for (int i = 0; i < digits_number; i++)
	{
		delete[]sub_Arrays[i];
	}
	delete[]sub_Arrays;
	delete []Array;

	if (sign_flag_2 == -1)
	{
		obj_in.pr_digits++;
	}

	return obj_return;
}

bool HugeInt::operator>(const HugeInt& obj_in)
{
	if (pr_size == obj_in.pr_size)
	{
		for (int i = 0; i < pr_size - 1; i++)
		{
			if (pr_HugeInt[i] <= obj_in.pr_HugeInt[i])
			{
				return false;
			}
		}

		return true;
	}
	else if (pr_size > obj_in.pr_size)
	{
		return true;
	}
	else if (pr_size < obj_in.pr_size)
	{
		return false;
	}
}

bool HugeInt::operator<(const HugeInt& obj_in)
{
	if (pr_size == obj_in.pr_size)
	{
		for (int i = 0; i < pr_size-1; i++)
		{
			if (pr_HugeInt[i] >= obj_in.pr_HugeInt[i])
			{
				return false;
			}
		}

		return true;
	}
	else if (pr_size < obj_in.pr_size)
	{
		return true;
	}
	else if (pr_size > obj_in.pr_size)
	{
		return false;
	}
}

bool HugeInt::operator==(const HugeInt& obj_in)
{
	if (pr_size == obj_in.pr_size)
	{
		for (int i = 0; i < pr_size; i++)
		{
			if (pr_HugeInt[i] != obj_in.pr_HugeInt[i])
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}

bool HugeInt::operator!=(HugeInt& obj_in)
{
	if (obj_in == *this)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//function to print 
void HugeInt::print()
{
	for (int i = 0; i < pr_size; i++)
	{
		cout << pr_HugeInt[i];
	}
	cout << endl;
}


//Function to set size
void HugeInt::setSize(int size)
{
	pr_size = size;
	if (pr_HugeInt == nullptr)
	{
		pr_HugeInt = new int[pr_size];
	}
	else
	{
		delete[]pr_HugeInt;
		pr_HugeInt = new int[pr_size];
	}
}





//Input operator
void operator>>(istream& in, HugeInt& obj_in) 
{
	int digits = 0;
	int size, number = 0;
	char* ptr_array = new char[50];

	in.getline(ptr_array, 50);
	
	
	for (int i = 0; ptr_array[i] != '\0'; i++)
	{
		digits++;
	}
	obj_in.pr_digits = digits;
	obj_in.pr_char_HugeInt = new char[digits+1];
	for (int x = digits - 1; x >= 0; x--)
	{
		obj_in.pr_char_HugeInt[digits - (x + 1)] = ptr_array[x];
	}

	obj_in.pr_char_HugeInt[digits] = '\0';

	obj_in.pr_HugeInt = converter(ptr_array, obj_in.pr_size, obj_in.pr_digits);

	delete[]ptr_array;
	
	
}


//Output operator
void operator<<(ostream& out, HugeInt& obj_in)
{
	int size=0,temp=0;

	
	for (int i = obj_in.pr_size - 1; i >= 0; i--)
	{
		if (obj_in.pr_HugeInt[i] != 0 && obj_in.pr_HugeInt[i] < 100000000 && (i != obj_in.pr_size - 2 || obj_in.pr_size == 2) && (i + 1) != obj_in.pr_size - 1)
		{
			temp = obj_in.pr_HugeInt[i];
			while (temp != 0)
			{
				size++;
				temp = temp / 10;
			}

			for (int i = 0; i < 9 - size; i++)
			{
				cout << "0";
			}

			cout << obj_in[i];
			temp = 0;
			size = 0;
		}
		else if (obj_in.pr_HugeInt[i] != 0)
		{
			out << obj_in[i];
		}
		else if (obj_in.pr_HugeInt[i] == 0 && i != obj_in.pr_size - 1 )
		{
			out << "000000000";
		}
	}
	cout<<endl;
}

HugeInt::~HugeInt()
{
	if (pr_HugeInt != nullptr)
	{
		delete[]pr_HugeInt;
	}

	if (pr_char_HugeInt != nullptr)
	{
		delete[]pr_char_HugeInt;
	}
}