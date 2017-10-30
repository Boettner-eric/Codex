//  hour of code - today.cpp
//  Created by Eric Boettner on 9/13/16.

#include <iomanip>
#include <string>
#include <fstream> //ofstream, ifstream (output filestream, input filestream)
#include <cstdlib> //exit
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <random>

using namespace std; //just copy and paste this header every time you write source code



//menu elements---------------------------------------------------------------------------------------------------------------------

void menu_header();

void menu_input(string &text, string cust_array[]);

void menu_modifiers(string text, string codex[], string cust_array[]);


//codex------------------------------------------------------------------------------------------------------------------------

void code_gen(); // selection C: asks for every char to have a two point graph, then asks for a function to graph

void code_usr(string cust_array[150]); //allows custom codex from file


//libraries-------------------------------------------------------------------------------------------------------------------------------

void alphabet_a(char alph_array[27]); //a-z

void alphabet_A(char elph_array[27]);

void symbols(char symbol_array[43]); // , . : ; " ' / { } [ ] ( ) * & ...


//modifier functions-------------------------------------------------------------------------------------------------------------------------------------------

string ency(string code_array[], string text); //main function

string dncy(string code_array[], string text);

string scramble(string tmp);

void create_code(string codex[]);

//output-------------------------------------------------------------------------------------------------------------------------------------------------------

void write_file(string tmp, int o); //writes file/cout based on result of "string decode()"


//directions---------------------------------------------------------------------------------------------------------------------------------------------------

void directions();


//main---------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    string codex[97], cust_array[150], text, var, dashes = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";  //all possible charactors in one array, need each library here
    
    char y_n;             // yes no opperands with Y/y or N/n as possible inputs
    ofstream outfile;  // writes an output file
    menu_header();            // opening text: void function with no var

    do
    {
        menu_modifiers(text, codex, cust_array);
        do
        {
            cout << "\nrestart? (y/n) ";
            cin >> y_n;
        }
        while(y_n != 'y' && y_n != 'Y' && y_n != 'n' && y_n != 'N');
    
        cout << "\n" << dashes << "\n";
    }
    while(y_n == 'y' || y_n == 'Y');
    
    system("clear"); // dont use in programs

    cout << "processes terminated \n";
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu_header()
{
    string dashes ="___________________________________________________________________________________________________";
    system("clear");
    cout << "\n" << dashes << "\n\n                                     welcome to cyrpto heaven                            \n\n                                        developed by t$rnp\n\n" << dashes << "\n\nThis software is provided as is by its owner. Any modification, distribution, malicious\nuse or use for illegal means is prohibited.  This work is that of the developer and is\ncompliant with copyright and intellectual property laws.\n\n" << dashes << "\n\n                                        hit enter to begin\n";
    cin.get();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu_modifiers(string text, string codex[], string cust_array[])
{
    char buff[100], yn = 'n', ak = 'n'; //yn is always my yes/no char
    string tmp, tmp_1, file_name, dashes ="___________________________________________________________________________________________________";
    ifstream name_file;
    ofstream d_file, operations;
    int o = 0, x = 0, help, selection;

    time_t now = time (0);

    strftime (buff, 100, "%m-%d-%Y %H:%M:%S", localtime (&now));

    system("clear");

    
    do{
        printf ("%s\n", buff);

        cout << "\n" << dashes << "\n\nselect mode: \n\n(1) custom codex\n\n(2) direction file\n\n(3) [x] analyse codex\n\n(4) help\n\n(5) exit\n\n";
        cin >> selection;
        
    if (selection == 1)
    {
        cout << "\n" << dashes << "\n                               Codex Directory and Filesystem. \n" << dashes << "\nSelect mode: Encode/Decode/Generate  (e/d/g)\n";
        x = 0;
        cin >> yn;
        if (yn == 'E' || yn == 'e')
        {
            yn = 'y';
            menu_input(text, cust_array); //creates encrypted text from input
            do {
            tmp = ency(cust_array, text);
            write_file(tmp, o);
            cout << "\noutput size " <<  tmp.size() << "\n";
            cout << "\nreturn? (y/n) ";
            cin >> yn;
            text = tmp;
            if (yn == 'y' || yn == 'Y')
            {
                cout << "same codex? (y/n) ";
                cin >> ak;
                if (ak == 'n' || ak == 'N')
                {
                    code_usr(cust_array);
                }
                else
                {
                    cout << "\n" << dashes << "\n";

                }
            }
            //cout << "\n\n" << tmp << " ; " << text << "\n\n";
            }
            while (yn == 'y' || yn == 'Y');

        }
        
        else if (yn == 'D' || yn == 'd')
        {
            yn = 'y';
            menu_input(text, cust_array); //creates encrypted text from input

            while (yn == 'y' || yn == 'Y')
            {
            tmp = dncy(cust_array, text);
            text = tmp;
            write_file(tmp, o);
            cout << "\nretry? (y/n) ";
            cin >> yn;
        }
        }
        else if (yn == 'G' || yn == 'g')
        {
            code_gen();
        }
    }
    else if (selection == 2)
    {
        directions();
    }
    else if (selection == 3)
    {
            cout << "\n" << dashes << "\n\nanalyse codex\n" << dashes << "\n\n(a) check for charactor repetition\n\n(s) check for multi-digit repetition\n\n(d) \n\n(f) \n\n(e) exit \n";
            cin >> yn;
            if (yn == 'a' || yn == 'A')
            {
                cout << "\ncharactor repetition\n";
            }
            else if (yn == 's' || yn == 'S')
            {
                cout << "\nmulti-digit repetition\n";
            }
            else if (yn == 'd' || yn == 'D')
            {
                cout << "\nD\n";
            }
            else if (yn == 'f' || yn == 'F')
            {
                cout << "\nF\n";
            }
            else
            {
                cout << "\nExit\n";
            }
            
    }
    
    else if (selection == 4)
    {
        do {
            cout << "\n" << dashes << "\n\nhelp menu \n1 - main menu shortcut key \n2 - how to add modifier strands \n3 - errors and error codes \n4 - how to format codex files\n5 - exit\n";
            cin >> help;
            cout << "\n" << dashes << "\n";
            if (help == '1')
            {
                cout << "m - modify text input (encode/decode)\na - add library of modifiers\nh - help menu (duh)\ne - exit or restart program\n\n" << dashes<< "\n";
            }else if (help == '2')
            {
                cout << " empty \n\n" << dashes << "\n";
            } else if (help == '3')
            {
                cout << "error 55: encryption output incorrect\nerorr 777: insufficient charactor input: text doesnt have correct number of charactors for it to be decoded\nerror 277/377 : text input not correctly read \nerror 111 : input is the wrong type \nerror 112 : module not called correctly \nerror 110: incorrect input from program type (m,a,h,e)\n-------------------------------------------------------------------------------\n";
            }
            else if (help == '4')
            {
                cout << "codex files should only include strings separated by spaces, anyother charactor will be read incorrectly.  Every string must be of equal size and there cannot be any repition" << dashes << "\n";
            }

        } while (help != 5);
    }
    } while (selection != 5);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu_input(string &text, string cust_array[])
{
    char yn;
    string dashes ="___________________________________________________________________________________________________";
    
    cout << " \n" << dashes << "\ntext, file or continuation input (t/f/c)" << endl;
    
    do {    //validation
        cin >> yn;
    } while(yn != 't' && yn != 'T' && yn != 'f' && yn != 'F' && yn != 'C' && yn != 'c');
    
    cout << " \n" << dashes << "\n";
    
    if (yn =='t' || yn == 'T')
    {
        cout << "enter the base text";
        cout << "\n - ";
        cin.ignore();
        getline(cin,text);
        code_usr(cust_array);

    }
    else if (yn == 'f' || yn == 'F')
    {
        ifstream codex("codex.txt");
        stringstream buffer;
        buffer << codex.rdbuf();//read the file
        text = buffer.str();//str holds the content of the file
        cout << " \n" << dashes << "\n" << text << endl;
        codex.close();
        cout << "\n" << text << endl;
        code_usr(cust_array);

    }
    else
    {
    cout << "\ncontinuation : " << text;
        
    }
    cout << "\n" << dashes << "\n";
    
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void alphabet_A(char elph_array[27])
{
    elph_array[1] = 'A';
    elph_array[2] = 'B';
    elph_array[3] = 'C';
    elph_array[4] = 'D';
    elph_array[5] = 'E';
    elph_array[6] = 'F';
    elph_array[7] = 'G';
    elph_array[8] = 'H';
    elph_array[9] = 'I';
    elph_array[10] = 'J';
    elph_array[11] = 'K';
    elph_array[12] = 'L';
    elph_array[13] = 'M';
    elph_array[14] = 'N';
    elph_array[15] = 'O';
    elph_array[16] = 'P';
    elph_array[17] = 'Q';
    elph_array[18] = 'R';
    elph_array[19] = 'S';
    elph_array[20] = 'T';
    elph_array[21] = 'U';
    elph_array[22] = 'V';
    elph_array[23] = 'W';
    elph_array[24] = 'X';
    elph_array[25] = 'Y';
    elph_array[26] = 'Z';

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void alphabet_a(char alph_array[27]) //library of the alphabet 26
{
    alph_array[0] = ' ';  //0.13703 * 1
    alph_array[1] = 'a';  //0.08167 **** 4
    alph_array[2] = 'b';  //0.01492  21
    alph_array[3] = 'c';  //0.02782  13
    alph_array[4] = 'd';  //0.04253  11
    alph_array[5] = 'e';  //0.12702 ** 2
    alph_array[6] = 'f';  //0.02228  17
    alph_array[7] = 'g';  //0.02015  18
    alph_array[8] = 'h';  //0.06094  9
    alph_array[9] = 'i';  //0.06966 ****** 6
    alph_array[10] = 'j'; //0.00153  24
    alph_array[11] = 'k'; //0.00772  23
    alph_array[12] = 'l'; //0.04025  12
    alph_array[13] = 'm'; //0.02406  15
    alph_array[14] = 'n'; //0.06749  7
    alph_array[15] = 'o'; //0.07507 ***** 5
    alph_array[16] = 'p'; //0.01929  20
    alph_array[17] = 'q'; //0.00095  26
    alph_array[18] = 'r'; //0.05987  10
    alph_array[19] = 's'; //0.06327  8
    alph_array[20] = 't'; //0.09056 *** 3
    alph_array[21] = 'u'; //0.02758  14
    alph_array[22] = 'v'; //0.00978  22
    alph_array[23] = 'w'; //0.02360  16
    alph_array[24] = 'x'; //0.00150  25
    alph_array[25] = 'y'; //0.01974  19
    alph_array[26] = 'z'; //0.00074  27
    
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void symbols(char symbol_array[43]) // : ; " ' / { } [ ] ( ) * & ...  39
{
    symbol_array[0] =  '0';
    symbol_array[1] =  '1';
    symbol_array[2] =  '2';
    symbol_array[3] =  '3';
    symbol_array[4] =  '4';
    symbol_array[5] =  '5';
    symbol_array[6] =  '6';
    symbol_array[7] =  '7';
    symbol_array[8] =  '8';
    symbol_array[9] =  '9';
    symbol_array[10] = '`';
    symbol_array[11] = '-';
    symbol_array[12] = '=';
    symbol_array[13] = '+';
    symbol_array[14] = ',';
    symbol_array[15] = '.';
    symbol_array[16] = '/';
    symbol_array[17] = '<';
    symbol_array[18] = '>';
    symbol_array[19] = '?';
    symbol_array[20] = '"';
    symbol_array[21] = '|';
    symbol_array[22] = ':';
    symbol_array[23] = ';';
    symbol_array[24] = '~';
    symbol_array[25] = '{';
    symbol_array[26] = '}';
    symbol_array[27] = '[';
    symbol_array[28] = ']';
    symbol_array[29] = '(';
    symbol_array[30] = ')';
    symbol_array[31] = '!';
    symbol_array[32] = '@';
    symbol_array[33] = '#';
    symbol_array[34] = '$';
    symbol_array[35] = '%';
    symbol_array[36] = '^';
    symbol_array[37] = '&';
    symbol_array[38] = '*';
    symbol_array[39] = '_';
    
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

string ency(string code_array[], string text)
{
    bool result = false;
    
    string tmp, end_f, dashes ="___________________________________________________________________________________________________";
    char alph_array[27], elph_array[27], symbol_array[43];
    int n=0,f,x=0;
    char * tmp_array;
    string * final_array;
    
    final_array = new string [text.size()*5];
    tmp_array = new char [text.size()+1];
   
    
    if (text != "error")
    {
        strcpy(tmp_array, text.c_str());
        //cout << "\n debug - tmp_array " << tmp_array << "\n tmp array size : " << text.size();
    }
    else if (text == "error")
    {
        cout << "force quit \n";
        exit(EXIT_FAILURE);
    }
    alphabet_a(alph_array);
    alphabet_A(elph_array);
    symbols(symbol_array);
    
    n=0;
    
    x=0;
    do {                                    //sets the charactors for each input charactor
        do
        {
            if (tmp_array[n] == alph_array[x])
            {
                cout << code_array[x];
                final_array[n] = code_array[x];
                result = true;
            }
            x++;
        }
        while ((result == false) && (x != 27));
        
        x=1;
        
        while ((result == false) && (x != 27))//now check for symbols
        {
           if (tmp_array[n] == elph_array[x])
           {
               cout <<  code_array[25+x];
               final_array[n] = code_array[26+x];
               result = true;
           }
            x++;
        }
        
        x=0;
        
        while ((result == false) && (x != 40))//now check for symbols
        {
            if (tmp_array[n] == symbol_array[x])
            {
                cout << code_array[52+x];
                final_array[n] = code_array[52+x];
                result = true;
            }
            x++;
        }
        
        x=0;
        
        if (result == false)
        {
            cout << "\n\n ERROR \n\n";
            exit(EXIT_FAILURE);
        }
        
        result = false;
    n++;

    }
    while (n < text.size());
   
    for (f=0;f<n;f++)
    {
        end_f += final_array[f];
    }
    if (end_f.size() % code_array[2].size() !=0)
    {
        cout << "\n\n**             error 55                **\n";
        exit(EXIT_FAILURE);
    }
    delete [] tmp_array;
    delete [] final_array;
    
    return end_f;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

string dncy(string code_array[], string text)
{
    string tmp, fial;
    int x=0;
    long b, c, n;
    bool result = false;
    double a;
    char alph_array[27], elph_array[27], tmp_array[text.size()+1], symbol_array[43];
    alphabet_a(alph_array);
    alphabet_A(elph_array);
    symbols(symbol_array);
    cout << "\ntext size " << text.size() << "\n";
    
    strcpy(tmp_array, text.c_str()); //learn to convert to strncpy
    
    b = code_array[1].size();

    if (text.size()%b != 0)
    {
        cout << "\ncode has insufficient charactors\n";
        exit(EXIT_FAILURE);
    }
    a = text.size()/b;
   for (n=0;n<a;n++)
   {
       for (c=n*b;c<b*n+b;c++) // 0-0/6, 1-6/12
       {
           tmp += tmp_array[c];
       }
    do
    {
        if (tmp == code_array[x])
        {
            cout << alph_array[x];
            fial += alph_array[x];
            result = true;
        }
        x++;
    }
    while ((result == false) && (x != 27));
    
    x=1;

    while ((result == false) && (x != 27))
    {
        if (tmp == code_array[x+25])
        {
            cout << elph_array[x];
            fial += elph_array[x];
            result = true;
        }
        x++;
    }
    
    x=0;
        
    while ((result == false) && (x != 40))
    {
        if (tmp == code_array[x+52])
        {
            cout << symbol_array[x];
            fial += symbol_array[x];
            result = true;
        }
    x++;
    }
       
    x=0;
    
    result = false;
    tmp = "";
    
   }
    return fial;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void write_file(string tmp, int o)
{
    ofstream outfile;
    outfile.open("ency_output.txt", ios::out);
    if (o==0)
    {
        outfile << "\noutput: " << tmp;
    }
    else
    {
        outfile << "\n output scramble: " << tmp;
    }
    outfile.close();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void code_usr(string cust_array[])
{
    int f=0, i=0, num;
    string name, nme[20], dashes ="___________________________________________________________________________________________________";
    
    ifstream codex, dir_file;
    
    dir_file.open("codex-directory.txt");
    while(!dir_file.eof())
    {
        getline(dir_file, nme[i]);
        i++;
    }
    dir_file.close();
    system("clear");
    cout << dashes << "\nCodex Directory\n";
    
    for (int z = 0; z<i; z++)
    {
        cout << z+1 << " " << nme[z] << "\n";
    }
    
    cout << "\nenter file number ";
    cin >> num;
    name = nme[num-1];
    cout << dashes << "\n" <<"   " << name << "\n";
    
    codex.open(name.data());
    while (!codex.eof())
    {
        codex >> cust_array[f];
        f++;
    }
    cout << "\n";
    for (i=0; i<f-1;i++)
    {
        cout << cust_array[i] << " ";
    }
    cout << "\nSymbols = " << i << "\n" << dashes << "\n";
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void code_gen()
{
    string compare, codex[150], file_name, real_file, name[20], dashes ="_________________________________________________________________________________________________";
    int n=0, c=0, i=0;
    bool search, usr_file;
    char yn = 'n';
    ofstream filecodex, name_file;
    long num, fam;
    ifstream dir_file;
    
    cout << "                                   onetime key generator\n" << dashes << "\n\nsave codex to file? (y/n) ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        usr_file = true;
        dir_file.open("codex-directory.txt");
        while(!dir_file.eof())
        {
            getline(dir_file, name[i]);
            i++;
        }
        dir_file.close();
        
        for (int z = 0; z<i; z++)
        {
            cout << name[z] << "\n";
        }
        
        cout << "\nname your file: (no spaces) ";
        cin >> file_name;
        file_name += ".txt";
    }
    else
    {
        usr_file = false;
    }
    
    cout << "\nhow many charactors per symbol? (1-10,000) ";
    cin >> num;
    cout << "\nhow many symbols need repersentation? (150 max) ";
    cin >> fam;
    cout << "\ngenerating codex with " << fam << " symbols and " << num << " charactors per symbol\n\n" << dashes << "\n";
    
    string vvr;
    int x;
    
    filecodex.open(file_name.data());
    do
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        vvr = "";
        for (int i=0; i<num; ++i) {
            std::uniform_int_distribution<int> dist(0, 9);
            x = dist(mt);
            cout << x << " ";
            ostringstream convert;
            convert <<  x;
            vvr += convert.str();
            std::mt19937 mt(x);
        }
        compare = vvr;
        search = true;

    for(i = 0; i <= fam; i++)
    {
            if(compare == codex[i])
            {
                search = false;
                break;
            }
    }
    if (search == true && compare.size() == num)
    {
        if (usr_file == true){
            filecodex << compare << " ";
        }
        cout << "\"" << compare << "\", ";
        codex[n] = "\"" + compare + "\", ";
        n++;
    }
    c++;
    }
    while(n != fam);
    filecodex.close();
    
    name_file.open("codex-directory.txt", ios::app);
    name_file << "\n" << file_name;
    name_file.close();
    
    cout << " \n" << dashes << "\n\n";
    cout << "filename:   Macintosh_HD/users/boettner/codex/" << file_name  <<"\nnumber of symbols  " << n;
    cout << " \n\n" << dashes << "\n";
}

void directions()
{
    
    int f=0, i=0, num=0, cycles=0, type=0;
    string name, text, nme[20], tmp, dashes = "_________________________________________________________________________________________________";
    ifstream dir_file;
    ifstream directions;
    string * ust_array;

    system("clear");
    
    dir_file.open("codex-directory.txt");
    while(!dir_file.eof())
    {
        getline(dir_file, nme[i]);
        i++;
    }
    
    dir_file.close();
    
    cout << dashes << "Quickmode";
    cout << "\ntype (0/1) : ";
    cin >> type;
    cout << "num (1-20) : ";
    cin >> num;
    cout << "cycles (1-5) : ";
    cin >> cycles;
    
    ifstream codex("codex.txt");
    stringstream buffer;
    buffer << codex.rdbuf();//read the file
    text = buffer.str();//str holds the content of the file
    cout << " \n" << dashes << "\n" << text << endl;
    codex.close();
    ust_array = new string[20];
    
    name = nme[num-1];
    
    codex.open(name.data());
    while (!codex.eof())
    {
        codex >> ust_array[f];
        f++;
    }
    cout << "\n";
    for (i=0; i<f-1;i++)
    {
        cout << ust_array[i] << " ";
    }
    cout << "\n" << dashes << "\n";
    
    do{
    if (type == 0)
    {
        tmp = ency(ust_array,text);
        text = tmp;
        cout << tmp << "\n";
    }
    else if (type == 1)
    {
        tmp = dncy(ust_array, text);
        text = tmp;
        cout << tmp << "\n";
    }
        cout << "\ncycles left " << cycles;
    cycles --;
    }
    while (cycles != 0);
    
    cout << "\n" << dashes << "\n";
    delete [] ust_array;

}

