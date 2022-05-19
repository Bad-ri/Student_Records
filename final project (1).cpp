#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void input();
void rec();
void modify();
void search();
void delete_record();
void quit();
void list();
struct information
{
  char ID[15];
  char name[30];
  char section[10];
  char course [35];
};
struct information c;
FILE *studentdb;

int main()
{
int choice1 ;
system("title Student Database Program ");
cout<<"\t\t\t\t\t welcome what would you like to do \n 1.Add a student record \n 2.Search for a record \n 3.Modify a record\n 4.Delete a record\n 5.Quit\n\n";
cin>>choice1;
system("cls");

switch(choice1){
case 1:
    input();
    break;
case 2:
    search();
case 3:
    modify();
case 4:
    delete_record();
case 5:
    quit();
}
return 0;
}
void input(){
    char in;
    FILE *studentdb;
    cout<<"please enter your name"<<endl;
    cin>>c.name;
    cout<<"please enter your ID"<<endl;
    cin>>c.ID;
    cout<<"please enter the course\n";
    cin>>c.course;
    cout<<"please enter the section no.\n";
    cin>>c.section;
studentdb = fopen("studentdb.txt","a");
fwrite(&c,sizeof(c),1,studentdb);
fclose(studentdb);
system("cls");
    cout<<("\n\n");
    cout<<("\t\t\t\t");
    cout<<"Do you want to add more?(Y/N)";
    cin>>in;
    if(in=='Y' || in=='y')
    {
      input();
    }
    else
system("cls");
main();
}

void search()
{
        int ch;
        char sid[30];
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t";

        fflush(stdin);
        cout<<"Enter Name: ";
        cin>>sid;

        studentdb=fopen("studentdb.txt","r");
        while (fread(&c, sizeof(c), 1, studentdb)==1)
        {
          if(strcmp(sid,c.name)==0)
          {
            ch=1;
            break;
          }
        }
        if(ch==1)
        {
          system("cls");
          cout<<"\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";

          cout<<"<<==Search Succesfull==>>\n";
          fflush(stdin);
          list();
          cout<<"\n\n\n";
          cout<<"\t\t\t\t\t";
          cout<<"Press Enter For Main Menu...\n";
          getchar();
          system("cls");
          main();
        }
        else
        {
          system("cls");
          getchar();
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";

          cout<<"<<--Record Not Found-->>\n";
          cout<<"\n\n\n";
          cout<<"\t\t\t\t\t";
          cout<<"Press Enter For Main Menu...\n";
          getchar();
          system("cls");
          main();
        }

        fclose(studentdb);

}
void quit(){

cout<<"thanks for using the program\n"<<endl;
cout<<"made by andria salah , id 20191266\nmohammed mahmoud el badri , id 20194841 \n\n";
system("pause");

}
void delete_record()
{
FILE *studentdb,*temp;
         int ch;
         char sid[30];

         system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
         cout<<"\t\t\t\t\t";
         cout<<"Enter Full Name:";
         fflush(stdin);
         cin>>sid;
         fflush(stdin);
         cout<<"\t\t\t\t\t";
         cout<<"\n";
         cout<<"\t\t\t\t\t";
         cout<<"Record Deleted Successfully.\n";
         cout<<"\n";
         cout<<"\t\t\t\t\t";
         cout<<"Press Enter For Main Menu...";
         getchar();
         system("cls");
         main();
         studentdb=fopen("studentdb.txt","r");
         temp = fopen("temp.txt", "w");
         while (fread(&c, sizeof(c), 1, studentdb)==1)
         {
           if(sid !=c.name)
           {
             {
                 fwrite(&c,sizeof(c),1,temp);
           }
         }
         fclose(studentdb);
         fclose(temp);
         remove("studentdb.txt");
         rename("temp.txt","studentdb.txt");
         }

       }


void list()
{
      cout<<" ";
      cout<<"\n";
      cout<<"\t\t\t\t";

      cout<<"\t\t\t\t";
      cout<<"\n";
      cout<<"\t\t\t\t";
      cout<<"\n";

      cout<<"\t\t\t\t";


      cout<<"\tID       :    "<<c.ID<<endl<<endl;
      cout<<"\t\t\t\t";
      cout<<"Full Name        :     "<<c.name;

      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"course           :     "<<c.course;

      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"section          :     "<<c.section;


}
void modify()
{
  char mid[30];

  int found=0;
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"\t\t\t\t\t";
  cout<<"Enter Full Name: ";
  cin>>mid;
  FILE *studentdb, *temp;
  temp =fopen("temp.txt","w");
  studentdb = fopen("studentdb.txt","r+");
  while(fread(&c, sizeof(c),1,studentdb) == 1)
  {
      if(strcmp(mid, c.name) == 0)
      {

          system("cls");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";
          cout<<"<<<==Old Record==>>>";
          cout<<"\n";
          cout<<"\t\t\t\t\t";
          list();
          cout<<"\n\n";
          cout<<"\t\t\t\t\t";

          cout<<"Press Enter to modify the record...\n\n";
          system("pause");

          system("cls");

          rec();
          fseek(studentdb, ftell(studentdb) - sizeof(c),0);
          fwrite(&c, sizeof(c), 1, studentdb);
          found = 1;
          cout<<"\n\n";
          cout<<"\t\t\t\t\t";
          cout<<"Record Saved !!!";
          getchar();

        }
        fclose(studentdb);
        fclose(temp);
        main();
      }

      if(!found)
      {
        {
          system("cls");



          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";


          cout<<"<<--Record Not Found-->>";
          getchar();
          main();
        }
      }
      fclose(temp);
      fclose(studentdb);
      remove("temp.txt");

}
       void rec()
       {
       cout<<" ";
         cout<<"\n";
         cout<<"\t\t\t\t";
         cout<<"\n";
         cout<<"\t\t\t\t";
         cout<<"\n";
         cout<<"\t\t\t\t";
         cout<<"\n";
         cout<<"\n\n\n\n";
         cout<<"\t\t\t\t";

         cout<<"Enter The Information Below: \n\n";
         cout<<"\t\t\t\t";
         cout<<"\tID      :    "<<c.ID<<endl<<endl;;
         cout<<"\t\t\t\t";
         cout<<"Full Name       :  ";
         cin>>c.name;

         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"course          :  ";
         cin>>c.course;

         cout<<"\n\n";
         cout<<"\t\t\t\t";
         cout<<"section         :  ";
         cin>>c.section;


       }
