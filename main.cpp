// Purpose : program for displaying and manipulating text files, displays a menu with the list of options
#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <conio.h>
#include "functions-header.h"
//fstream file;
//string file_name, file_tmp = "";
using namespace std;
int main(){
string text;
int option;
cout << "welcome to our program to for editing text !!"<< endl;
cout << "please enter the text file name."<< endl;
getline(cin,file_name);
open_file(file_name);
file.open(file_name+".txt", ios::in);
while(!file.eof() && !file.fail())
    {
        getline(file,text);
          for (int j=0; j < text.length() ;j++)
            {
                file_tmp += text[j];

            }
            file_tmp += '\n';
    }
    file.close();
/////////////////////////////////
 while(true)
     {
 {
     cout<<"choose an edit to apply or 0 to exit : "<<endl;
     cout<<"1- Add new text to the end of the file"<<endl;
     cout<<"2- Display the content of the file"<<endl;
     cout<<"3- Empty the file" <<endl;
     cout<<"4- Encrypt the file content " <<endl;
     cout<<"5- Decrypt the file content"  <<endl;
     cout<<"6- Merge another file"<<endl;
     cout<<"7- Count the number of words in the file."<<endl;
     cout<<"8- Count the number of characters in the file"<<endl;
     cout<<"9- Count the number of lines in the file"<<endl;
     cout<<"10-Search for a word in the file"<<endl;
     cout<<"11-Count the number of times a word exists in the file" <<endl;
     cout<<"12-Turn the file content to upper case."  <<endl;
     cout<<"13-Turn the file content to lower case."<<endl;
     cout<<"14-Turn file content to 1st caps (1st char of each word is capital)"<<endl;
     cout<<"15-Save"<<endl;
     cout<<"0- Exit" <<endl;

     cin >> option;
     }


     if (option == 1)
    {
        appending();
    }
     else if (option == 2)
    {
        dsply_cntnt();
    }
      else if (option == 3)
    {
         clear_file();
    }
      else if (option == 4)
    {
        encrypt_file();
    }
      else if (option == 5)
    {
          decrypt_file();
    }
      else if (option == 6)
    {
          merging();
    }
      else if (option == 7)
    {
          countwords();
    }
       else if (option == 8)
    {
        countchar();
    }
      else if (option == 9)
    {
          countlines();
    }
      else if (option == 10)
    {
         search_for_word();
    }
      else if (option == 11)
    {
        search_num_of_word();
    }
      else if (option == 12)
    {
        turn_to_upper();
    }
        else if (option == 13)
    {
         turn_to_lower();
    }
     else if (option == 14)
    {
        cap_each_1st_alpha();
    }
     else if (option == 15)
    {
     save();
    }
     else if (option == 0)
    {   exit(file_name);
        cout<<"thanks for using our program "<<endl;

        break;

    }
    }
}
