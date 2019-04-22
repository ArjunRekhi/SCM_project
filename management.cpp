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

void Lib::librarian()
{
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Change Password\n\n\t\t7.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {

            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:issue();
                     break;
            case 5:system("cls");
                     get();
                     break;
            case 6:password();
                    break;
            case 7:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();

        }

}
~
~
int Lib::branch(int x)
  {
      int i;
      cout<<"\n\t\t>>Please Choose one Branch :-\n";
      cout<<"\n\t\t1.BIT\n\n\t\t2.EE\n\n\t\t3.EC\n\n\t\t4.CIVIL\n\n\t\t5.MECHANICAL\n\n\t\t6.1ST YEAR\n\n\t\t7.Go to menu\n";
      cout<<"\n\t\tEnter youur choice : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  student();
                  else
                    librarian();
          default : cout<<"\n\t\tPlease enter correct option :(";
                    getch();
                    system("cls");
                    branch(x);
        }
  }~
~
void Lib::fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    
    int years,l,i;
    
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    
    n1 = y*365 + d;
    
    for (i=0; i<m - 1; i++)
    
        n1 += monthDays[i]; //fn1353
        
    years = y;
    
    if (m <= 2)
    
    years--;
    
    l= years / 4 - years / 100 + years / 400;
    
    n1 += l;
    
    n2 = yy*365 + dd;
    
    for (i=0; i<mm - 1; i++)
    
        n2 += monthDays[i];
        
    years = yy;
    
    if (m <= 2)
    
    years--;
    
    l= years / 4 - years / 100 + years / 400;
    
    n2 += l;
    
    n1=n2-n1;
    
    n2=n1-15;
    
    if(n2>0)
    cout<<"\n\t\tThe Total Fine is : "<<n2;
    
}

 void Lib::issue()
{
	
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who isuued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    	
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(bookname,100);
    cout<<"\n\t\tEnter Book's ID : ";
    
     cin.getline(sc,20);
    //strcpy(st,sc);
    der(sc,b,1);
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(auname,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(sc1,20);
    cout<<"\n\t\tEnter date : ";
    cin>>q>>B>>p;
    ofstream outf("student.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tIssue Successfully.\n";
}

else if(i==2)
    {
    	
    ifstream intf("student.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->The Details are :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    
    {
    	
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tStudent Name : "<<auname<<"\n\t\t"<<"Student's ID : "<<sc1<<"\n\t\t"<<"Book Name : "<<bookname<<"\n\t\t"<<"Book's ID : "<<sc<<"\n\t\t"<<"Date : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    
     }
    
    intf.close();
    
    }
    
    else if(i==3)
    {
    	
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\n\t\tEnter Student Name : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tEnter Student's ID : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("student.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
        	
              for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++);
              if(sc1[i]=='\0'&&st1[i]=='\0')
              {
              	
                  cont++;
                  if(cont==1)
                  {
                  	
                      cout<<"\n\t\t->The Details are :-\n";
                      cout<<"\n\t\tStudent Name : "<<auname;
                      cout<<"\n\t\tStudent's ID : "<<sc1;
                      
                  }
                  
                  cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
                  cout<<"\n\t\tBook Name : "<<bookname;
                  cout<<"\n\t\tBook's ID : "<<sc;
                  cout<<"\n\t\tDate : "<<q<<"/"<<B<<"/"<<p<<"\n";
                  
              }
                      intf.read((char*)this,sizeof(*this));
                      

        }
        
           
        intf.close();
        if(cont==0)
            cout<<"\n\t\tNo record found.";
            
             }
    
    else if(i==4)
    {
    	
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,50);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    fstream intf("student.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
        	
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                	
                    d=q;
                    m=B;
                    y=p;
                    cout<<"\n\t\tEnter New Date : ";
                    cin>>q>>B>>p;
                    fine(d,m,y,q,B,p); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tReissue successfully."; //fn3
                    break;
                    
                }
                
                   intf.read((char*)this,sizeof(*this));
        }
        
        intf.close();
    }
    
