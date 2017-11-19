/*
 * cp.h
 *
 *  Created on: Nov 18, 2017
 *      Author: Sourav
 */

#ifndef CP_H_
#define CP_H_

#include <list>
#include <map>
#include <string>

namespace cp
{
using namespace std;
class cyp;
void CrypSolver();
}

class cp::cyp
{
private:
	//Array of available numbers
	bool arr[10];
	map<char,int> lt_mp;
	string str1, str2, res_str;
	bool Solve();
	void SolveHelper(int &num1, int &num2, int &res_sum );
	bool isDigitAvailable(int);
	void insertUniqueLetters(string);
	bool isUnassignedLetterExists();
	bool ArithSolver(int);
	void PrintResults();
	char GetCharFromMap(int);
public:
	cyp(string,string,string);
	friend void CrypSolver();

};



#endif /* CP_H_ */
