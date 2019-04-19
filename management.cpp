//various header files required
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h> //various header files required
#include<conio.h>
using namespace std;
class Lib
{
   public:
       char bookname[100],auname[50],sc[20],sc1[50];
       //variables when data is to be input from the user
	   int q,B,p;
       Lib()
       {
           bookname=null;
           auname=null;
           sc=null;
           sc1=null;
           q=0;
           B=0;
           p=0;
       }
        //functionalites of the management system
          void get();
          
          void student();
          
          void pass();
          
          void librarian();
          
          void password();
          
          void getdata();
          
          void show(int);
          
          void booklist(int);
          
          void modify();
          
          void see(int);
          
          int branch(int);
          
          void issue();
          
          void der(char[],int,int);
          
          void fine(int,int,int,int,int,int);
          
};
