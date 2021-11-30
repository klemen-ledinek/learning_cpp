#include "add.h"
#include <iostream>

//Macro 
#define MY_NAME "Klemen"

#define PRINT_DA


int main()
{
    //int i = 1;    
    //std::cin >> i;
    std::cout << "Wilde " << add(3, 4) << '\n';
    std::cout << "My name macro is " << MY_NAME << '\n';

#ifdef PRINT_DA
    std::cout << "Print DA, ce je ta definiran \n";
#endif

#ifdef PRINT_NE
    std::cout << "Print DA, ce je ta definiran";
#endif

#if 0 //Don't compile anything starting here
    std::cout << "TEST if 0" << '\n';
#endif // Until this point

    return 0;
}

/*
To resolve naming collisions (different types with same names) whe can use NAMESPACES
Namespace is a region, that allows you to declare names inside of it for the purpose of disambiguation.
The namespace procides a scope (namespace scope) to the names declared inside of it -- which simply
means, that any name decalred inside the namespace won't be mistaken for identical names in other scopes


When you use an identifier that is defined inside a namespace (such as the std namespace), 
you have to tell the compiler that the identifier lives inside the namespace.

Before compiling, code goes throug phase known as TRANSLATION.

One of translation paheses involves the PREPROCESSOR.
The preprocessor is best thought of as a separate program that manipulates the text in each code file.
It scans thoruh the code file looking for preprocessor directives.
These are instructionst that start with a # symbol and end with a newline.

Common preprocessor directives:
- Includes (#include <>)        : Preprocessor replaces the #include with content of the included file
- Macro defines (#define macro) : macro is a rule that defgines how input text is converted into replacment 
    output text. Two basic types of macros: object-like macros and function-like macros
- Conditional compilation       : Specify under what conditions one part of code will compile (#ifdef
    , #ifndef and #endif)  

*/
