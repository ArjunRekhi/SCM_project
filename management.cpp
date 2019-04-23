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

void Lib::show(int i)
{
	
    cout<<"\n\t\tBook Name : "<<bookname<<endl;
    cout<<"\n\t\tBook's Author Name : "<<auname<<endl;
    cout<<"\n\t\tBook's ID : "<<sc<<endl;
    cout<<"\n\t\tBook's Publication : "<<sc1<<endl;
    if(i==2)
    {
    	
        cout<<"\n\t\tBook's Price : "<<p<<endl;
        cout<<"\n\t\tBook's Quantity : "<<q<<endl;
        
    }

    
}

	void Lib::getdata()
{
	
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(bookname,100);
                    for(i=0;bookname[i]!='\0';i++)
                    {
                    if(bookname[i]>='a'&&bookname[i]<='z')
                       bookname[i]-=32;
                    }
                    cout<<"\n\t\tEnter Author's Name : ";
                    cin.getline(auname,50);
                    cout<<"\n\t\tEnter Publication name : ";
                    cin.getline(sc1,50);
                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(sc,20);
                    cout<<"\n\t\tEnter Book's Price : ";
                    cin>>p;
                    cout<<"\n\t\tEnter Book's Quantity : ";
                    cin>>q;
                    
}
 void Lib::get()
{
	
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
        	
            system("cls");
            student();
        }
        
        else if(i==2)
        
            pass();

        else if(i==3)
        
            exit(0);
        else
        {
        	
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("CLS");
           get();
           
        
		}
		
}


void Lib::booklist(int i)
  {
  	
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                	
                    cout<<"\n\t    ************ Book List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                	
                    if(b==B)
                    {
                    	
                        if(q==0 && i==1)
                        {
                        	

                        }
                        else
                            {
                            	
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                                
                           
						    }
						    
                    }
                    intf.read((char*)this,sizeof(*this));
                    
                }
                
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
    }
    
    void Lib::student()
{
	
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
            
                booklist(1);
            else if(i==2)
            
                see(1);
                
            else if(i==3)
            {
            	
                system("cls");
                get();
                
            }
            else if(i==4)
            
                exit(0);
            else
            {
            	
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                student();
                
            }
}
  

void Lib::see(int x)
  {
  	
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
        	
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            librarian();
            
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      
      if(i==1)
      
      {
      	
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
          	
            for(i=0;b==B&&q!=0&&bookname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bookname[i]||ch[i]==bookname[i]+32);i++);
            if(bookname[i]=='\0'&&ch[i]=='\0')
                {
                	
                	
                        cout<<"\n\t\tBook Found :-\n";
                        show(x);
                        cont++;
                        break;
                        
                }
             intf.read((char*)this,sizeof(*this));
             
          }
          
      }
          else if(i==2)
          {
          	
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
          	
              for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                	
                            cout<<"\n\t\tBook Found :-\n";
                            show(x);
                            cont++;
                            break;
                            
                }
                
               intf.read((char*)this,sizeof(*this));
               
          }
          

          }
          else
          {
          	
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             see(x);
             
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();


  }
 
