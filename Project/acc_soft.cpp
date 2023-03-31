#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

unsigned int microsecond= 1000000;

class accounting
{
    public:
    //company info
    string companyName,city,province,country,contact;

    //jornal general
    string date ,accTile ;
    int dr=0,cr=0;

    // companyinfo file handler
    ifstream MyFile;

    void Companyinfo();
    bool isexist(string name);

    void jornalgeneral();
    void simpleEntry();
    void adjustedEntry();

    void generalLedger();

};



void accounting::Companyinfo()
{
  cout<<"********************WELCOME TO KISPY BOOKS*********************"<<endl<<endl<<endl<<flush;
  cout<<"****************TELLS US ABOUT YOUR BUSINESS****************" <<endl<<endl<<endl;
  cout<<"COMPANY NAME :"; cin>>companyName; cout<<endl;
  cout<<"City :";         cin>>city;        cout<<endl;
  cout<<"Province :";     cin>>province;    cout<<endl;
  cout<<"Country :";      cin>>country; cout<<endl;
  cout<<"Contact :";      cin>>contact; cout<<endl;

    // Create and open a text file
  ofstream MyFile("CompanyInfo.txt");

  MyFile << companyName<<endl;
  MyFile << city<<endl;
  MyFile << province<<endl;
  MyFile << country<<endl;
  MyFile << contact<<endl;
  // Close the file
  MyFile.close();
  
  system("clear");

  return;  
}

bool accounting::isexist(string name)
{
    MyFile.open(name);
    if(MyFile)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void accounting::jornalgeneral()
{
    char op; //option for entry
    
    cout<<endl;
    cout<<"******************************************************************************"<<endl;
    cout<<"                           JORNAL GENERAL                                     "<<endl;
    cout<<"******************************************************************************"<<endl<<endl<<endl;
    
   
    cout<<"a)Simple Entry"<<endl;
    cout<<"b)Adjusting Entry"<<endl<<endl;
    
    cout<<"Enter a or b"<<endl;
    cin>>op;

    switch (op)
    {
    case 'a':
            simpleEntry();
            return;
        break;

    case 'b':
            adjustedEntry();
            return;
        break;    
    
    default:
        break;
    }
  

}

void accounting::simpleEntry()
{   
    cout<<"DATE :";  cin>>date;
    cout<<"Account Tile :"; cin>>accTile;
    cout<<"Debit :"; cin>>dr; 
    cout<<"Credit :"; cin>>cr;

    cout<<endl;

    system("clear");
                               
    cout<<"| DATE(dd-mm-yyyy)|";cout<<"|    Account Tile    |";cout<<"| Debit |" ; cout<<"| Credit |   ";cout<<endl;
    cout<<" ";cout<<date;cout<<"             "; cout<<accTile;cout<<"               ";cout<<dr;cout<<"       " ;cout<<cr; cout<<endl;
        
        ofstream MyFile("SimpleEntry.txt", ios::app);

            MyFile <<accTile<<endl;
            MyFile <<date<<endl;
            MyFile <<dr<<endl;
            MyFile << cr<<endl;
            // Close the file
            MyFile.close();


    if(dr==0)
    {
        cout<<endl;

        cout<<"                    ";   cin>>accTile; 
        cout<<"                                          ";cout<<cr;cout<<"            " ;cout<<"0"; cout<<endl;   
        
        cout<<"\nYou have successfully entered the entry"<<endl<<endl;

       
       usleep(3 * microsecond);//sleeps for 3 second

        dr=cr;
        cr=0;


        ofstream MyFile("SimpleEntry.txt", ios::app);

            MyFile <<accTile<<endl;
            MyFile <<date<<endl;
            MyFile <<dr<<endl;
            MyFile <<cr<<endl;
            // Close the file
            MyFile.close();

            return;
            
    }

    else
    {
        cout<<"                          ";   cin>>accTile; 
        cout<<"                                            ";cout<<"0";cout<<"          " ;cout<<dr; cout<<endl;  

       cout<<"\nYou have successfully entered the entry"<<endl<<endl;
       unsigned int microsecond = 1000000;
       usleep(3 * microsecond);//sleeps for 3 second

        cr=dr;
        dr=0;
        
        ofstream MyFile("SimpleEntry.txt", ios::app);

            MyFile <<accTile<<endl;
            MyFile <<date<<endl;
            MyFile <<dr<<endl;
            MyFile <<cr<<endl;
            // Close the file
            MyFile.close();

            return;
    }      
}


void accounting::adjustedEntry()
{
    cout<<"DATE :";  cin>>date;
    cout<<"Account Tile :"; cin>>accTile;
    cout<<"Debit :"; cin>>dr; 
    cout<<"Credit :"; cin>>cr;

    cout<<endl;

    system("clear");

    cout<<"| DATE(dd-mm-yyyy)|";cout<<"|    Account Tile    |";cout<<"| Debit |" ; cout<<"| Credit |   ";cout<<endl;
    cout<<" ";cout<<date;cout<<"             "; cout<<accTile;cout<<"               ";cout<<dr;cout<<"       " ;cout<<cr; cout<<endl;
        
        ofstream MyFile("adjustedEntry.txt", ios::app);

            MyFile <<accTile<<endl;
            MyFile <<date<<endl;
            MyFile <<dr<<endl;
            MyFile << cr<<endl;
            // Close the file
            MyFile.close();

    if(dr==0)
    {
        cout<<endl;

        cout<<"                    ";   cin>>accTile; 
        cout<<"                                          ";cout<<cr;cout<<"            " ;cout<<"0"; cout<<endl;   
        
        cout<<"\nYou have successfully entered the entry"<<endl<<endl;

       unsigned int microsecond = 1000000;
       usleep(2 * microsecond);//sleeps for 3 second

        dr=cr;
        cr=0;

        ofstream MyFile("adjustedEntry.txt", ios::app);

            MyFile <<accTile<<endl;
            MyFile <<date<<endl;
            MyFile <<dr<<endl;
            MyFile <<cr<<endl;
            // Close the file
            MyFile.close();

        return ;    
    }

    else
    {
       cout<<"                          ";   cin>>accTile; 
        cout<<"                                            ";cout<<"0";cout<<"          " ;cout<<dr; cout<<endl;  

       cout<<"\nYou have successfully entered the entry"<<endl<<endl;
       
       unsigned int microsecond = 1000000;
       usleep(2 * microsecond);//sleeps for 3 second

        cr=dr;
        dr=0;
        
        ofstream MyFile("adjustedEntry.txt", ios::app);

            MyFile <<accTile<<endl;
            MyFile <<date<<endl;
            MyFile <<dr<<endl;
            MyFile <<cr<<endl;
            // Close the file
            MyFile.close();

        return;    
    }      
}

void accounting::generalLedger()
{
    int n=0;
    string check="\0";

    cout<<"******************************************************************************"<<endl;
    cout<<"                           GENERAL LEDGER                                    "<<endl;
    cout<<"******************************************************************************"<<endl<<endl<<endl;

    cout<<"| DATE(dd-mm-yyyy)|";cout<<"|    Type    |";cout<<"| Debit |" ; cout<<"| Credit |"; cout<<"| Balance |";cout<<endl;
}


int main()
{
    //making obj for accounting class
    accounting obj;
    char option;

    if(obj.isexist("CompanyInfo.txt")==false)
    {
        obj.Companyinfo();
    }
           
    // obj.homepage();

    do
    {
        cout<<"********************WELCOME TO KISPY BOOKS*********************"<<endl<<endl<<endl;

        cout<<"*************************HOME PAGE*****************************"<<endl<<endl;
        cout<<"                      a)JORNAL GENERAL                         "<<endl<<endl;
        cout<<"                      b)LEDGER ACCOUNT                         "<<endl<<endl;
        cout<<"                      c)TRIAL BALANCE                          "<<endl<<endl;
        cout<<"                      d)ADJUSTED TRIAL BALANCE                 "<<endl<<endl;
        cout<<"                      e)INCOME STATEMENT                       "<<endl<<endl;
        cout<<"                      f)BALANCE SHEET                          "<<endl<<endl;
        cout<<"                      g)Exit                          "<<endl<<endl<<endl;

        cout<<"ENTER THE OPTION (e.g. if you want to open jornal general press a): ";
        cin>> option;

        switch (option)
        {
        case 'a':
            obj.jornalgeneral();
            break;
        case 'b':
            
            break;
        case 'c':
            
            break;
        case 'd':
            
            break;
        case 'e':
            
            break;
        case 'f':
            
            break;
        default:
            break;
        }

    } while (option != 'g');
    
}
