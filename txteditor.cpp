#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <conio.h>
#include "txteditor.h"
using namespace std;
int flag1;
int flag2;

//a function to check if the file exist or not and open it in case of existing and create it in case of not existing
void open_file(string name1){
    fstream test_file;
   test_file.open(name1+".txt");
    if(!test_file){
        flag1 =0;
        cout<<"file doesn't exist we are now creating the file for you... "<<endl;
        test_file.open(name1+".txt",ios::out);
        cout<<"file created successfully !!"<<endl;
    }
    else{
        flag1 = 1;
        cout<< "file opened successfully"<<endl;
    }
    test_file.close();

}

/////////////////////////////////
// a function to add a text to an existing file at the end of it
void appending(){
    char text;
    file.open(file_name+".txt", ios::out | ios::app);
        cout << "enter some text to append with dot in the end of it.\n";
            while (true){
		cin.get(text);
		file.put(text);
		if (text == '.')

		     break;
	}
	file.put('\n');

        file.close();
}


// a function to show the content of existing file at the console screen
void dsply_cntnt()
{
    string text;
    file.open(file_name+".txt",ios::in);
cout << "the content of the file is: " <<endl ;
    while(!file.eof() && !file.fail()){
        getline(file,text);
         cout << text<<endl ;
    }


    file.close();
}


// function to clear file content
void clear_file(){

file.open(file_name+".txt",ios::out);
file.clear();
file.close();

}

// a function to encrypt content of the file
void encrypt_file(){
    string encrypt , decrypt;
    char lst[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    file.open(file_name+".txt",ios::in);

while(!file.eof() && !file.fail()){
            getline(file,encrypt);
               for(int i =0;i<encrypt.length();i++){
                for(int j =0;j<26;j++){
                    if(tolower(encrypt[i]) == lst[j]){
                        if(j<=12){
                            decrypt += lst[(13-j)+12];
                        }
                        else if(j>12){
                            decrypt  += lst[12-(j-13)];
                        }

                    }
                    else if(encrypt[i] == ' ')
                        {
                            decrypt += ' ';
                            break;
                        }
                }
            }
            decrypt += '\n';
            }
            file.close();
            file.open(file_name+".txt",ios::out);

            for(int i = 0; i < decrypt.length();i++){
                    file.put(decrypt[i]);


	}
	cout<<"file encrypted successfully !!"<<endl;
	file.close();

}


// a function to decrypt a content of a file
void decrypt_file(){

    string encrypt , decrypt;
    char lst[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    file.open(file_name+".txt",ios::in);
while(!file.eof() && !file.fail()){
            getline(file,decrypt);
            for(int i =0;i<decrypt.length();i++){
                for(int j =0;j<26;j++){
                    if(tolower(decrypt[i]) == lst[j]){
                        if(j<=12){
                            encrypt += lst[(13-j)+12];
                        }
                        else if(j>12){
                            encrypt  += lst[12-(j-13)];
                        }
                    }
                            else if(decrypt[i] == ' ')
                        {
                            encrypt += ' ';
                            break;
                        }
                }
            }
            encrypt += '\n';
}
                file.close();
            file.open(file_name+".txt",ios::out);

            for(int i = 0; i < encrypt.length();i++){
                    file.put(encrypt[i]);


	}
	cout<<"file decrypted successfully !!"<<endl;
	file.close();

     }


// a functions to add the content of existing file to the main file we are using
void merging(){
    fstream file2;
        string name2;
        string text="";
        cout << "Enter the second file name you want to merge in.\n";
        cin.clear();
        cin.sync();
        getline(cin,name2);
        cin.clear();
        cin.sync();
        open_file(name2);
        file.open(file_name+".txt", ios::app);
        file2.open(name2+".txt", ios::in);
        while(!file2.eof() && !file2.fail())
    {
        getline(file2,text);
        for (int j=0; j < text.length() ;j++)
            {
                file.put(text[j]);
            }
           file.put('\n');
    }


        file.close();
        file2.close();
}

// a function to count how many lines we have at the file
void count_lines(){
    int counter = 0;
    char character;
    file.open(file_name+".txt", ios::in);

    while(file){
        file.get(character);
        if (character =='\n'){
            counter++;
        if (character == ' '){
            continue;
        }
        }
    }

    cout << "number of lines in the file =  " << counter;
    file.close();
}

// a function to count how many words we have at the file
void count_words(){

   int counter = 0;
    string word;

    file.open(file_name+".txt", ios::in);

    while(file >> word ){
        counter++;
    }

    cout << "number of words in the file =  " << counter << endl;
    file.close();
}


// a function to count how many characters we have at the file
void count_char(){
    int counter = 0;
    char character;
    file.open(file_name+".txt", ios::in);

    while(file.get(character)){
            if (character == ' ' || character == '\n')
            continue;
            else
                counter++;
            }

    cout << "number of characters in the file =  " << counter;
    file.close();
}


// a  function to turn all letters in the file to the upper case
void turn_to_upper(){
    char ch ;
    string str ;
    file.open(file_name+".txt", ios:: in);
    while (!file.eof()&& !file.fail())
    {
        file.get(ch);
        str += toupper(ch);
   }
    file.close();
    file.open(file_name+".txt",ios::out);
    for (int i = 0 ; i < str.length()-1 ; i++)
    {
        file.put(str[i]);
    }
    file.close();
}

// a  function to turn all letters in the file to the lower case
void turn_to_lower(){
    char ch ;
    string str ;
    file.open(file_name+".txt", ios:: in);
    while (!file.eof()&& !file.fail())
    {
        file.get(ch);
        str += tolower(ch);
   }
    file.close();
    file.open(file_name+".txt",ios::out);
    for (int i = 0 ; i < str.length()-1 ; i++)
    {
        file.put(str[i]);
    }
    file.close();
}


// turning every start of any word in the file to upper case
void cap_each_1st_alpha(){
    char ch ;
    int check =0 ;
    string str ;
    file.open(file_name+".txt", ios:: in);
    while (!file.eof()&& !file.fail())
    {
        file.get(ch);
        str += tolower(ch);
   }
   cin.clear();
   for (int i = 0; i < str.length(); i++) {
        if (check == 0) {
            str[i] = toupper(str[i]);
            check = 1;
        } else if (str[i] == ' ')
            check = 0;
    }

    file.close();
    file.open(file_name+".txt",ios::out);

    for (int i = 0 ; i < str.length()-1 ; i++)
    {
        file.put(str[i]);
    }
    file.close();
}


// a function to check of the word exist or not
void search_for_word(){

   int counter = 0;
   bool flag = false;
    string word = "" , str = "" ;
    file.open(file_name+".txt", ios::in);

    cout << "Enter the word u want to search about : ";
    cin >> str;

       while (file >> word)
       {
           for (int i = 0 ,j = 0 ; i < word.length() , j < str.length(); i++ , j++)
       {
           word[i] = tolower(word[i]);
           str[j] = tolower(str[j]);
       }
           if (word == str)
           {
               cout << "The word exists "<< endl;
               flag = true;
               break;
       }
}
if (!flag)
    {
        cout<< "this word doesn't exist"<<endl;
    }
file.close();
}

// a function to count how many times does a word exist in the file
void search_num_of_word(){

   int counter = 0;
    string word , str ;
    char ch;
    file.open(file_name+".txt", ios::in);

    cout << "Enter the word u want to search about : ";
    cin >> str;

    while(file >> word ){
       for (int i = 0 ,j = 0 ; i < word.length() , j < str.length(); i++ , j++)
       {
           word[i] = tolower(word[i]);
           str[j] = tolower(str[j]);
       }
       if (str == word)
        {counter += 1;}

    }
    file.close();
    cout <<"the word exists " <<counter <<" times"<< endl;
}

// a function to save the file at the current name or new file with a different name
void save(){
string text = "";
char letter;
file_tmp = "";
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
    cout << "press enter for saving in current file or enter other file name to save"<<endl;
    letter = _getch();
    if(letter != 13){
        cout << letter;
        file_name = "";
        file_name += letter;
        while(true){
            cin >> letter;
            file_name += letter;
            cout << letter;
            if(letter == 13){
                break;
            }
        }
    }

}

// function to terminate and end the program
void exit(string name)
{
    file.open(name+".txt", ios::out);
    for (int j=0; j < file_tmp.length() ;j++)
            {
                file.put(file_tmp[j]);
            }
    file.close();
}
