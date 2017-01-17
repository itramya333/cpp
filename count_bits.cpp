// C++ program to demonstrate __builtin_popcount()
#include <iostream>
using namespace std;
//O(logn)
void countbits(int n)
{
	int count =0;
	while(n > 0)
	{
		n &= n-1; //101 & 100 = 4; 100 & 011 = 0;
		count++;
	}
	cout << "Count is "<<count<<endl;
}
//Order of theta logn
void countbitsshift(int n)
{
	int countbits =0;
	while(n){
		countbits = countbits + (n&1);
		n >>= 1;		
	}
	cout <<"Count shifting is "<< countbits<<endl;
}
int main()
{
cout << __builtin_popcount (5) << endl;// Lookup table
cout << __builtin_popcount (15)<< endl;
int n =5;
countbits(n);
countbitsshift(n);
return 0;
}
