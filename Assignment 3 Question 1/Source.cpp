#include<iostream>
#include"HugeInt.h"

using namespace std;

int main()
{
	HugeInt no_1, no_2;
	cout << "	Enter number 1 : ";
	cin >> no_1;
	cout << endl;

	cout << "	Enter number 2 : ";
	cin >> no_2;
	cout << endl;

	HugeInt no_3;


	int optionn_1 = 0, option_2 = 0, option_3 = 0, number = 0;
	do
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "	----------------------------------------" << endl;
		cout << "	    Select an option from the menu below" << endl;
		cout << "	----------------------------------------" << endl;
		cout << "	1 ->Add two HugeInts" << endl;
		cout << "	------------------------------" << endl;
		cout << "	2 ->Add a HugeInt to a number" << endl;
		cout << "	------------------------------" << endl;
		cout << "	3 ->Add a Number to a HugeInt" << endl;
		cout << "	-------------------------------------" << endl;
		cout << "	4 ->Subtract HugeInt 2 from HugeInt 1" << endl;
		cout << "	-------------------------------------" << endl;
		cout << "	5 ->Subtract HugeInt 1 from HugeInt 2" << endl;
		cout << "	-------------------------------------" << endl;
		cout << "	6 ->Subtract a number from a HugeInt" << endl;
		cout << "	-------------------------------------" << endl;
		cout << "	7 ->Subtract a HugeInt from a number" << endl;
		cout << "	-------------------------" << endl;
		cout << "	8 ->Multiply two HugeInts" << endl;
		cout << "	-------------------------------------" << endl;
		cout << "	9 ->Multiply a HugeInt with a number" << endl;
		cout << "	------------------------------------" << endl;
		cout << "	10->Multiply a number with a HugeInt" << endl;
		cout << "	------------------------" << endl;
		cout << "	11->Compare Two HugeInts" << endl;
		cout << "	-------------------" << endl;
		cout << "	12->print HugeInt 1" << endl;
		cout << "	-------------------" << endl;
		cout << "	13->print HugeInt 2" << endl;
		cout << "	-------------------" << endl;
		cout << "	14->Edit HugeInt 1" << endl;
		cout << "	-------------------" << endl;
		cout << "	15->Edit HugeInt 2" << endl;
		cout << "	-------" << endl;
		cout << "	0->Exit" << endl;
		cout << "	-------" << endl;
		cout << "		";
		cin >> optionn_1;
		if (optionn_1 == 1)
		{
			no_3 = no_1 + no_2;
			cout << endl;
			cout << endl;

			cout << "	--------" << endl;
			cout << "	Answer : " << no_3;
			cout << "	--------" << endl;
			cout << endl;
			cout << endl;
			system("pause");

		}
		else if (optionn_1 == 2)
		{
			cout << "	Enter The Number : ";
			cin >> number;
			do
			{
				system("CLS");
				cout << "	----------------" << endl;
				cout << "	Select a HugeInt" << endl;
				cout << "	----------------" << endl;
				cout << "	1->HugeInt 1" << endl;
				cout << "	----------------" << endl;
				cout << "	2->HugeInt 2" << endl;
				cout << "	----------------" << endl;
				cout << "	0->Exit" << endl;
				cout << "	----------------" << endl;
				cout << "	";
				cin >> option_3;
				if (option_3 == 1)
				{
					no_3.clear();
					no_3 = no_1 + number;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 == 2)
				{
					no_3.clear();
					no_3 = no_2 + number;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 != 0)
				{
					cout << "	****Invalid Option Selected****" << endl;
					system("pause");

				}
			} while (option_3 < 0 || option_3 >0);
		}
		else if (optionn_1 == 3)
		{
			cout << "	Enter The Number : ";
			cin >> number;
			do
			{
				system("CLS");
				cout << "	----------------" << endl;
				cout << "	Select a HugeInt" << endl;
				cout << "	----------------" << endl;
				cout << "	1->HugeInt 1" << endl;
				cout << "	----------------" << endl;
				cout << "	2->HugeInt 2" << endl;
				cout << "	----------------" << endl;
				cout << "	0->Exit" << endl;
				cout << "	----------------" << endl;
				cout << "	";
				cin >> option_3;
				if (option_3 == 1)
				{
					no_3.clear();
					no_3 = number + no_1;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 == 2)
				{
					no_3.clear();
					no_3 = number + no_2;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 != 0)
				{
					cout << "	****Invalid Option Selected****" << endl;
					system("pause");

				}
			} while (option_3 < 0 || option_3 >0);
		}
		else if (optionn_1 == 4)
		{
			no_3.clear();
			no_3 = no_1 - no_2;
			cout << endl;
			cout << endl;

			cout << "	--------" << endl;
			cout << "	Answer : " << no_3;
			cout << "	--------" << endl;
			cout << endl;
			cout << endl;
			system("pause");
		}
		else if (optionn_1 == 5)
		{
			no_3.clear();
			no_3 = no_2 - no_1;
			cout << endl;
			cout << endl;

			cout << "	--------" << endl;
			cout << "	Answer : " << no_3;
			cout << "	--------" << endl;
			cout << endl;
			cout << endl;
			system("pause");
		}
		else if (optionn_1 == 6)
		{
			cout << "	Enter The Number : ";
			cin >> number;
			do
			{
				system("CLS");
				cout << "	----------------" << endl;
				cout << "	Select a HugeInt" << endl;
				cout << "	----------------" << endl;
				cout << "	1->HugeInt 1" << endl;
				cout << "	----------------" << endl;
				cout << "	2->HugeInt 2" << endl;
				cout << "	----------------" << endl;
				cout << "	0->Exit" << endl;
				cout << "	----------------" << endl;
				cout << "	";
				cin >> option_3;
				if (option_3 == 1)
				{
					no_3.clear();
					no_3 = no_1 - number;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 == 2)
				{
					no_3.clear();
					no_3 = no_2 - number;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 != 0)
				{
					cout << "	****Invalid Option Selected****" << endl;
					system("pause");

				}
			} while (option_3 < 0 || option_3 >0);
		}
		else if (optionn_1 == 7)
		{
			cout << "	Enter The Number : ";
			cin >> number;
			do
			{
				system("CLS");
				cout << "	----------------" << endl;
				cout << "	Select a HugeInt" << endl;
				cout << "	----------------" << endl;
				cout << "	1->HugeInt 1" << endl;
				cout << "	----------------" << endl;
				cout << "	2->HugeInt 2" << endl;
				cout << "	----------------" << endl;
				cout << "	0->Exit" << endl;
				cout << "	----------------" << endl;
				cout << "	";
				cin >> option_3;
				if (option_3 == 1)
				{
					no_3.clear();
					no_3 = number - no_1;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 == 2)
				{
					no_3.clear();
					no_3 = number - no_2;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 != 0)
				{
					cout << "	****Invalid Option Selected****" << endl;
					system("pause");

				}
			} while (option_3 < 0 || option_3 >0);
		}
		else if (optionn_1 == 8)
		{
			no_3.clear();
			no_3 = no_1 * no_2;
			cout << endl;
			cout << endl;

			cout << "	--------" << endl;
			cout << "	Answer : " << no_3;
			cout << "	--------" << endl;
			cout << endl;
			cout << endl;
			system("pause");
		}
		else if (optionn_1 == 9)
		{

			cout << "	Enter The Number : ";
			cin >> number;
			do
			{
				system("CLS");
				cout << "	----------------" << endl;
				cout << "	Select a HugeInt" << endl;
				cout << "	----------------" << endl;
				cout << "	1->HugeInt 1" << endl;
				cout << "	----------------" << endl;
				cout << "	2->HugeInt 2" << endl;
				cout << "	----------------" << endl;
				cout << "	0->Exit" << endl;
				cout << "	----------------" << endl;
				cout << "	";
				cin >> option_3;
				if (option_3 == 1)
				{
					no_3.clear();
					no_3 = no_1 * number;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 == 2)
				{
					no_3.clear();
					no_3 = no_2 * number;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 != 0)
				{
					cout << "	****Invalid Option Selected****" << endl;
					system("pause");

				}
			} while (option_3 < 0 || option_3 >0);
		}
		else if (optionn_1 == 10)
		{

			cout << "	Enter The Number : ";
			cin >> number;
			do
			{
				system("CLS");
				cout << "	----------------" << endl;
				cout << "	Select a HugeInt" << endl;
				cout << "	----------------" << endl;
				cout << "	1->HugeInt 1" << endl;
				cout << "	----------------" << endl;
				cout << "	2->HugeInt 2" << endl;
				cout << "	----------------" << endl;
				cout << "	0->Exit" << endl;
				cout << "	----------------" << endl;
				cout << "	";
				cin >> option_3;
				if (option_3 == 1)
				{
					no_3.clear();
					no_3 = number * no_1;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 == 2)
				{
					no_3.clear();
					no_3 = number * no_2;
					cout << endl;
					cout << endl;

					cout << "	--------" << endl;
					cout << "	Answer : " << no_3;
					cout << "	--------" << endl;
					cout << endl;
					cout << endl;
					system("pause");
				}
				else if (option_3 != 0)
				{
					cout << "	****Invalid Option Selected****" << endl;
					system("pause");

				}
			} while (option_3 < 0 || option_3 >0);
		}
		else if (optionn_1 == 11)
		{
			do
			{
				system("CLS");
				cout << "	--------------------------------" << endl;
				cout << "	Select an option from menu below" << endl;
				cout << "	----------------------" << endl;
				cout << "	1->Equal to comparison" << endl;
				cout << "	--------------------------" << endl;
				cout << "	2->Not Equal to comparison" << endl;
				cout << "	--------------------------" << endl;
				cout << "	3->Greater Then Comparison" << endl;
				cout << "	-----------------------" << endl;
				cout << "	4->Less Then comparison" << endl;
				cout << "	";
				cin >> option_2;
				if (option_2 == 1)
				{
					if (no_1 == no_2)
					{
						cout << "	HugeInt 1 and HugeInt 2 are equal" << endl;
					}
					else
					{
						cout << "	HugeInt 1 and HugeInt 2 are not equal" << endl;
					}
					system("pause");

				}
				else if (option_2 == 2)
				{
					if (no_1 != no_2)
					{
						cout << "	HugeInt 1 and HugeInt 2 are not equal" << endl;
					}
					else
					{
						cout << "	HugeInt 1 and HugeInt 2 are equal" << endl;
					}
					system("pause");

				}
				else if (option_2 == 3)
				{
					if (no_1 > no_2)
					{
						cout << "	HugeInt 1 is Greater then HugeInt 2" << endl;
					}
					else if (no_2 > no_1)
					{
						cout << "	HugeInt 2 is Greater then HugeInt 1" << endl;
					}
					else if (option_3 != 0)
					{
						cout << "	Numbers are Equal" << endl;
					}
					system("pause");

				}
				else if (option_2 == 4)
				{
					if (no_1 < no_2)
					{
						cout << "	HugeInt 1 is less then HugeInt 2" << endl;
					}
					else if (no_2 < no_1)
					{
						cout << "	HugeInt 2 is less then HugeInt 1" << endl;
					}
					else if (option_2 != 0)
					{
						cout << "	Numbers are Equal" << endl;
					}
					system("pause");

				}
				else if (option_3 != 0)
				{
					cout << " ***Invalid OPtion Selected" << endl;
					system("pause");
				}
			} while (option_2 < 0 || option_2>0);

		}
		else if (optionn_1==12)
		{
			cout << "	HugeInt 1 : " << no_1;
			system("pause");
		}
		else if (optionn_1 == 13)
		{
			cout << "	HugeInt 2 : " << no_2;
			system("pause");

		}
		else if (optionn_1 == 14)
		{
			cin.ignore();
			cout << "	Enter number 1 : ";
			cin >> no_1;
			cout << endl;

		}
		else if (optionn_1 == 15)
		{
			cin.ignore();
			cout << "	Enter number 2 : ";
			cin >> no_2;
			cout << endl;

		}
		else if (optionn_1 != 0)
		{
			cout << "	****Invalid Option Selected****" << endl;
			system("pause");

		}
		
	} while (optionn_1 < 0 || optionn_1>0);
}