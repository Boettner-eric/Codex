***This software is provided as is by its owner. Any modification, distribution, malicious use or use for illegal means is prohibited.  This work is that of the developer and is compliant with copyright and intellectual property laws***

Hello based developer: this file explains the basic use and structure of encr



Key terms: v - var, o - option, f - function, a - array

	a- codex - a/z symbols and numbers: this (char array) is set at 68 characters and is every possible input

	a- cust_array - this is set at 150 max and generates all the possible characters 

	v- text - the name of the main input - file/text/continuous

	o- Continuos - carries over current (string text) and skips menu_input()

	f- code_usr() - contains the codex directory and allows usr to pick file [skipped if usr continues with codex] 
	
	f- code_gen() - creates codex file based on name input, number of characters per symbol and number of symbols - uses mt() rand function to generate random results
	
	



Complex functions

Scramble Function: 
this is included in usr_gen() aka generate codex: it generates an identical codex with a fully scrambled code set.  This allows the alternation of codes creating more advanced security.  It also allows the generation of scrambled files that require multiple codex to break down: i.e. multi key software

(in initial codex, out multiple copies of random permutations)

Directions ip:
will take a series of inputs and apply them to variables that run the whole process automatically using files

basically a second main that generates based on inputted code

