# Codex
A simple encryption sequence generator.  Creates keys using mt19937 and uses cycles and saved key files to generate exponential ecryption.

- Key Syntax
  cc - (number of charactors per input) - (number of repersentable charactors default to 150) .txt

- File Names
  codex.txt : the input file for longer text inputs 
  directions.txt : preformat directions for encryption (i.e. preset cycles and keys for complex output ) *** in progress
  codex-directory.txt : stores the names of all key files
  ency_output.txt : the basic output file
  
- Functions
    //menu elements

      void menu_header();
      void menu_input(string &text, string cust_array[]);
      void menu_modifiers(string text, string codex[], string cust_array[]);

    //codex

      void code_gen(); // uses mt to create a codex
      void code_usr(string cust_array[150]); //allows custom codex from file

    //libraries

      void alphabet_a(char alph_array[27]); //a-z
      void alphabet_A(char elph_array[27]);
      void symbols(char symbol_array[43]); // , . : ; " ' / { } [ ] ( ) * & ...

    //modifier functions

      string ency(string code_array[], string text); 
      string dncy(string code_array[], string text);
      string scramble(string tmp);
      void create_code(string codex[]); // connects codex to function

    //output

      void write_file(string tmp, int o); //writes file/cout based on call
    //directions

    void directions();
