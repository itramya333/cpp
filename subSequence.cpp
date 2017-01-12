#include<iostream>
#include<cstring>
using namespace std;
#include<vector>

bool isSubSequence( char str1[],char str2[], int m,int n )
{
	cout <<str1 <<m<<endl;
	int j =0;
	for(int i=0; i<n && j<m; i++)
	{
		if(str1[j] == str2[i])
		j++;
	}
	return j==m;
}

int main()
{
	
	vector<string> arrVec ;
	arrVec.push_back("ks");
	arrVec.push_back("gt");
	string str1;
	int m;
	for(vector<string>::iterator it = arrVec.begin(); it!= arrVec.end(); it++)
	{
		str1 = *it;
		m = str1.size();
		//Convert string to char array
		//	const char* char1 = str1.c_str() ;

		char char1[m+1];
		strcpy(char1, str1.c_str() );
		
		char str2[]= "geeks";
		int n = strlen(str2);
		if(isSubSequence(char1,str2, m, n ))
			cout <<"YES"<<endl;
		else
		cout<< "NO"<<endl;
	}
	

	return 0;
	
}
