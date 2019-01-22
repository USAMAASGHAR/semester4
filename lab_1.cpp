#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int linear_search(int array[],int key,int i,int a)
{
	for(int j=0;j<=i-1;j++)
	 {
		 if(key==array[j])
		 {
	  return a;
	   }
		 a++;
	 }
	 return -2;
}
int binary_search(int array[],int first,int size,int key,int a)
{
	if(size>=first)
	 {

			int mid=first+(size-first)/2;
			if(array[mid]==key)
			    {a++;
					return a;}
			if(array[mid]>key)
					{ a++;
						return binary_search(array,first,mid-1,key,a);
          }
       if(array[mid]<key)
			    {
						return binary_search(array,mid+1,size,key,a);
            a++;
					}
	 }
	return -2;
}

int main()
{
int a,b;
ifstream fin;
string line;
	int i = 0;
vector < string > v;
fin.open("data");
	if(fin.is_open())
	{
		while(getline(fin,line))
		{
				v.push_back(line);
		}
		while(true)
		{
			if(i==v.size())
			{
				break;
			}
			cout<<v[i]<<"\n";
			i++;
		}
	}
                                    //convertion string to int
int array[1000];
int array1;
		 for(int j=0;j<=i;j++)
		 {
			 stringstream geek(v[j]);
		 	 geek >>array1;
			 array[j]=array1;
		 }
		    	                          //Searching of Number
			int number,choice;
      int c=0;
			cout<<"Enter your number :  > ";
 			cin>>number;
			cout<<endl<<"Press 1 for Linear Search And 2 for Binary Search :   ";
			cin>>choice;
			cout<<"Number is founded in  :    ";
			if(choice==1)
        {   cout<<linear_search(array,number,1000,c);  }    //Linear Search
      else if(choice==2)
			  {   cout<<binary_search(array,0,1000,number,c);  }     //Binary Search
				cout<<"  tries";
return 0;
}
