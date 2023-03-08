/* Citation and Sources...
Final Project Milestone 52
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Name   :Pawan Deep
		ID     :111144218
		Email  :pdeep1@myseneca.ca
		Date   :04/05/2022
Revision History
-----------------------------------------------------------
Date      Reason
04/05/2022  Preliminary release
04/05/2022  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <fstream>
#include "AidMan.h"
#include "Date.h"
#include "Utils.h"
#include "iProduct.h"
#include "Item.h"
#include "Perishable.h"
using namespace std;
namespace sdds {
	unsigned int AidMan::menu(){
		int num = 0;
		cout << "Aid Management System" << endl;
		cout << "Date: " << Date() << endl;
		if (file==nullptr)
		{
			cout << "Data file: "  <<"No file" << endl;
		}
		else
		{
			cout << "Data file: " << file << endl;
		}

		cout << "---------------------------------" << endl;
		num=mainmenu.run();
		return num;
	}
	AidMan::AidMan() :mainmenu{ "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n",7 } {
		file = nullptr;
	}
	AidMan::~AidMan() {
	
		delete[] file;
		file = nullptr;
		deallocate();
	}
	void AidMan::run() {
		int num;
		do
		{
			num = menu();
			if (num!=0 && file==nullptr)
			{
				num = 7;
			}
			switch (num)
			{
			case 1:
				cout << endl << "****List Items****" << endl;
				list();
				break;
			case 2:
				cout << endl << "****Add Item****"  << endl;
				if (counter== sdds_max_num_items)
				{
					cout << "Database full!" << endl;
				}
				else
				{
					int number = 0;
					cout << "1- Perishable" << endl << "2- Non-Perishable" << endl << "-----------------" << endl << "0- Exit" << endl << "> ";
					cin >> number;
					if (number==0)
					{
						cout << "Aborted\n";
					}
					else
					{
						int c = 0;
						if (number==1)
						{
							arr[counter] = new Perishable;
							c = search(arr[counter]->readSku(cin));
							if (c != -1)
							{
								delete arr[counter];
								arr[counter] = nullptr;
							}
							else
							{
								arr[counter]->read(cin);
								if (arr[counter]->operator bool())
								{
									counter++;
								}
								else
								{
									arr[counter]->display(cout);
									delete arr[counter];
									arr[counter] = nullptr;
								}
							}
						}
						else if(number==2)
						{
							arr[counter] = new Item;
							c = search(arr[counter]->readSku(cin));
							if (c != -1)
							{
								delete arr[counter];
								arr[counter] = nullptr;
							}
							else
							{
								arr[counter]->read(cin);
								if (arr[counter]->operator bool())
								{
									counter++;
								}
								else
								{
									arr[counter]->display(cout);
									delete arr[counter];
									arr[counter] = nullptr;
								}
							}
						}
						
					}
				}
				cout << endl;
				break;
			case 3:
				cout << endl << "****Remove Item****" << endl << endl;
				break;
			case 4:
				cout << endl << "****Update Quantity****" << endl << endl;
				break;
			case 5:
				cout << endl << "****Sort****" << endl << endl;
				break;
			case 6:
				cout << endl << "****Ship Items****" << endl << endl;
				break;
			case 7:
				cout << endl << "****New/Open Aid Database****"<< endl;
				load();
				break;
			default:
				cout << "Exiting Program!" << endl;
				save();
				break;
			}
			
		} while (num!=0);
	}
	void AidMan::save() {
		if (file!=nullptr)
		{
			ofstream out(file);
			for (int i = 0; i < counter; i++)
			{
				arr[i]->save(out);
				out << endl;
			}
		}
	}
	void AidMan::deallocate() {
		for (int i = 0; i < counter; i++)
		{
			delete arr[i];
			arr[i] = nullptr;
		}
		counter = 0;
	}
	bool AidMan::load() {
		save();
		deallocate();
		char fop[50];
		cout << "Enter file name: ";
		cin >> fop;
		ut.alocpy(file, fop);
		ifstream f(file);
		bool ans=false;
		if (!f.is_open())
		{
			int num = -1;
			cout << "Failed to open "<< file <<" for reading!"<< endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl << "0 - Exit" << endl << ">";
			cin >> num;
			if (num==1)
			{
				ofstream newfile(file);
			}
			else
			{
				delete[] file;
				file = nullptr;
			}
		}
		else
		{
			while (f)
			{
				char ch = f.peek();
				if (ch >= '1' && ch <= '3')
				{
					arr[counter] = new Perishable;
					arr[counter]->load(f);
					if (arr[counter]->operator bool())
					{
						counter++;
					}
					else
					{
						deallocate();
					}
					ans = true;
				}
				else if (ch >= '4' && ch <= '9')
				{
					arr[counter] = new Item;
					arr[counter]->load(f);
					if (arr[counter]->operator bool())
					{
						counter++;
					}
					else
					{
						deallocate();
					}
					ans = true;
				}
				else
				{
					f.setstate(ios::failbit);
				}
				
			}
			cout << counter << " records loaded!" << endl<< endl;
		}
		return ans;
	}
	int AidMan::list(const char* sub_desc) {
		int ans = 0;
		char num =0;
		int i = 0;
		if (counter == 0)
		{
			cout << "The list is emtpy!" << endl;
		}
		else if (sub_desc == nullptr)
		{
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			for (i = 0; i < counter; i++) {
				cout << "   " << fixed << right  << i+1 << " | ";
				arr[i]->linear(true);
				arr[i]->display(cout);
				cout << endl;
				ans = i;
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		}
		else {
			for (i = 0; i < counter; i++) {
				if (*arr[i] == sub_desc)
				{
					arr[i]->linear(false);
					arr[i]->display(cout);
					cout << endl;
					ans++;
				}
			}
		}
		if (counter > 0)
		{
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			char ch = 0;

			while (1)
			{
				num = getchar();
				if (num == '\n' && ch == num)
				{
					cout << endl;
					break;
				}
				else if (num>='1'&&num<'9')
				{
					break;
				}

				ch = num;
			}
			do
			{
				if (int(num)-48 <= counter)
				{
					for (i = 0; i < counter; i++) {
						if (int(num)-49 == i)
						{
							arr[i]->linear(false);
							arr[i]->display(cout);
							cout << endl << endl;
							ans++;
						}
					}
				}
				else if (int(num)-48 > counter &&num!='\n')
				{
					cout << "invalid number, try again :";
					cin >> num;
				}
			} while (int(num)-48 > counter&& num!='\n');
		}
		return ans;
	}
	int AidMan::search(int sku) const
	{
		for (int i = 0; i < counter; i++)
		{
			
			if (arr[i]->operator==(sku))
			{
				cout << "Sku: " << sku << " is already in the system, try updating quantity instead." << endl;
				return i;
			}
		}
		return -1;
	}
	
}