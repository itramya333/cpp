#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
struct customer
{
  int acc_no;
  string name;
  string addr;
  long int balance;
  string phone_no;
};
//Sort based on name .If duplicate name sort based on balance.
bool cmd(const customer & c1, const customer & c2)
{
   if (c1.name != c2.name) return c1.name < c2.name;
   return c1.balance < c2.balance;
}

int main()
{
	vector<customer> cust_vect;
	
	cust_vect.push_back({1, "Sam", "Dublin 1", 3000, "111222333"});
	cust_vect.push_back({2, "Cuan", "Dublin 20", 4000, "444555666"});
	
	vector<customer>::iterator it;
	for( it = cust_vect.begin( ); it != cust_vect.end(); ++it )
	{
		cout <<it->acc_no;
	 } 
	sort(cust_vect.begin(), cust_vect.end(), cmd);
	cout <<"After sort"<<endl;
	for( it = cust_vect.begin( ); it != cust_vect.end( ); ++it )
	{
		cout <<"Account no " << it->acc_no <<endl;
		ostringstream phone_format;
		phone_format <<"("<<(it->phone_no).substr(0,3)<<")"<<(it->phone_no).substr(3,3)<<"-"<<(it->phone_no).substr(6,3)<<endl;
		cout << phone_format.str();
	 } 
	return 0;
}

