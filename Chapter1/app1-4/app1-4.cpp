// USE B.CPP INSTEAD

#include<iostream>
using namespace std;

void main()
{
    int i=0,j=0,count=0;
	for (i=2;i<=1000;i++)
	{	
		for (j=2;j<=i-1;j++)
			if(i%j==0) 
				break;
		if(j>i-1)
		{
				cout<<j<<'\t';
				count++:
				if(cout%5==0) cout<<endl;		
		}
	return ;
}