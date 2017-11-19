//============================================================================
// Name        : crypta.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "cp.h"
using namespace std;
using namespace cp;

void cyp::SolveHelper(int &num1, int &num2, int &res_sum )
{
	int st_count;
	string tmp_str;
	int num_count = 0;
	int tmp_num = 0;

	/* Debug code */
	/*
	tmp_num = this->lt_mp['S'];
	tmp_num = this->lt_mp['E'];
	tmp_num = this->lt_mp['N'];
	tmp_num = this->lt_mp['D'];
	tmp_num = this->lt_mp['M'];
	tmp_num = this->lt_mp['O'];
	tmp_num = this->lt_mp['R'];
	tmp_num = this->lt_mp['Y'];
	tmp_num  = 0;

	if( ( this->lt_mp['S'] == 9 ) &&
			( this->lt_mp['E'] == 5 ) &&
			( this->lt_mp['N'] == 6 ) &&
			( this->lt_mp['D'] == 7 ) &&
			( this->lt_mp['M'] == 1 ) &&
			( this->lt_mp['O'] == 0 ) &&
			( this->lt_mp['R'] == 8 ) &&
			( this->lt_mp['Y'] == 2 ) )
	{
		tmp_num  = 0;
	}
	*/


	/* First string equivalent number */
	st_count = str1.length();
	tmp_str = str1;
	while(num_count < 3)
	{
		while(st_count > 0)
		{
			tmp_num+= (this->lt_mp[tmp_str[st_count-1]])*pow(10,tmp_str.length() - st_count);
			st_count--;
		}

		if( num_count == 0 )
		{
			num1 = tmp_num;
			st_count = str2.length();
			tmp_str = str2;
		}
		else if(num_count == 1)
		{
			num2 = tmp_num;
			st_count = res_str.length();
			tmp_str = res_str;
		}
		else res_sum = tmp_num;

		num_count++;
		tmp_num = 0;
	}


}

void cyp::PrintResults()
{
	int num1;
	int num2;
	int res_sum;

	this->SolveHelper(num1, num2, res_sum );

	cout<<num1<<" "<<num2<<" "<<res_sum;
}

bool cyp::Solve()
{
	int num1;
	int num2;
	int res_sum;

	this->SolveHelper(num1, num2, res_sum );

	if( num1 + num2 == res_sum )
		return true;
	else
	{
		cout<<"Nope";
		return false;
	}
}

bool cyp::isUnassignedLetterExists()
{
	map<char,int>::iterator it = this->lt_mp.begin();
	while(it != this->lt_mp.end())
	{
		if( it->second == -1 )
			return true;
		it++;
	}
	return false;
}


bool cyp::isDigitAvailable(int i)
{
	if( i < 0 || i > 9 ) return false;
	else return this->arr[i];
}

cyp::cyp(string st1, string st2, string rs_str)
{
	for(int i=0; i<10; i++)
	{
		arr[i] = true;
	}

	this->str1 = st1;
	this->str2 = st2;
	this->res_str = rs_str;
	this->insertUniqueLetters(this->str1);
	this->insertUniqueLetters(this->str2);
	this->insertUniqueLetters(this->res_str);
}

void cyp::insertUniqueLetters(string str)
{
	map<char,int>::iterator it;
	it = this->lt_mp.begin();
	int str_count = str.length();
	while(str_count > 0 )
	{
		it = this->lt_mp.begin();
		while(it != this->lt_mp.end())
		{
			/* Char of string is found so break out of map iteration */
			if( it->first == str[str_count-1] )
				break;
			it++;
		}

		/* End of map was reached and char wasn't found,
		 * so insert it into the list
		 */
		if( it == this->lt_mp.end() )
		{
			this->lt_mp[str[str_count-1]] = -1;
		}
		str_count--;
	}


}

char cyp::GetCharFromMap(int idx)
{
	list<char> c_l;
	map<char,int>::iterator it;
	it = this->lt_mp.begin();
	char ch;
	while(it != this->lt_mp.end())
	{
		ch = (it->first);
		c_l.push_back(ch);
		it++;
	}

	/* Debug code */
	list<char>:: iterator cit = c_l.begin();
	while( cit != c_l.end() )
	{
		ch = (*cit);
		cit++;
	}

	int count = 0;
	cit = c_l.begin();
	while( cit != c_l.end() )
	{
		if( count == idx )
		{
			return (*cit);
		}

		count++;
		cit++;
	}
}


bool cyp::ArithSolver(int idx)
{
	if( this->isUnassignedLetterExists() == false )
	{
		return this->Solve();
	}

	char ch = this->GetCharFromMap(idx);

	/*
	if( this->lt_mp['D'] == 7 )
	{
		if( this->lt_mp['E'] == 5 )
		{
			if( this->lt_mp['M'] == 1 )
			{
				if( this->lt_mp['N'] == 6 )
				{
					if( this->lt_mp['O'] == 0 )
					{
						if( this->lt_mp['R'] == 8 )
						{
							if( this->lt_mp['S'] == 9 )
							{
								if( this->lt_mp['Y'] == 2 )
								{
									ch = this->GetCharFromMap(idx);
								}
							}
						}
					}
				}
			}
		}
	}
	*/

	/*
	if( idx == 0 )
	{
		idx = 0;
	}
	else if(idx == 1 )
	{
		idx = 1;
	}
	else if( idx == 2 )
	{
		idx = 2;
	}
	else if(idx == 3 )
	{
		idx = 3;
	}
	else if(idx == 4)
	{
		idx = 4;
	}
	else if(idx == 5)
	{
		idx = 5;
	}
	else if(idx == 6)
	{
		idx = 6;
	}
	else if(idx == 7 )
	{
		idx = 7;
	}
	*/
	for(int i =0; i<10;i++)
	{
		if( this->isDigitAvailable(i) == true )
		{
			this->lt_mp[ch] = i;
			this->arr[i] = false;
			if( ArithSolver(idx+1) == true ) return true;
			else
			{
				this->lt_mp[ch] = -1;
				this->arr[i] = true;
			}
		}
	}
	return false;
}

void cp::CrypSolver()
{
	cyp* c_ptr = new cyp("SEND","MORE","MONEY");
	if( c_ptr->ArithSolver(0) == true )
	{
		c_ptr->PrintResults();
	}
}

int main() {
	CrypSolver();
}
