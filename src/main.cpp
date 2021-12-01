#include "add.h"
#include "output.h"
#include <iostream>
#include <string>

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

    display("Testiram output.cpp with pragma once\n");
    std::cout << "Size of bool:\t\t" << sizeof(bool) << " bytes\n";

    std::cout << "Example of static cast of number 5.5 to integer: " << static_cast<int>(5.5) << '\n';

    //std::cin only reads up uintil whitespace. Use std::getline
    display("Enter your name: \n");
    std::string fullName{};
    //The std::ws input maniuplator thells std::cin to ignore any leading whitespace
    std::getline(std::cin >> std::ws, fullName);
    display("You entered: ");
    std::cout << fullName;

    //Const must be initialized
    const int size = 15;

    //C++11, ensures that const must be a compile-time constant
    constexpr double gravity = 9.8;

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


Header Guards
- Conditional compilation directives.
Namesto Header Guardsov se lahko uporabi #pragma once

Types                  |Category            | Minimum Size |
-----------------------+--------------------+--------------+
float                  |Floating point      |4 bytes       |
dobule                 |                    |8 bytes       |
long double            |                    |8 bytes       |
-----------------------+--------------------+--------------+
bool                   |Integral (Boolean)  |1 byte        |
-----------------------+--------------------+--------------+
char                   |Integral (Character)|1 byte        |
wchar_t                |                    |1 byte        |
char8_t(c++20)         |                    |              |
char16_t(c++11)        |                    |2 bytes       |
char32_t(c++11)        |                    |4 bytes       |
-----------------------+--------------------+--------------+
short                  |Integral (Integer)  |2 bytes       |
int                    |                    |2 bytes       |
long                   |                    |4 bytes       |
long long (c++11)      |                    |8 bytes       |
-----------------------+--------------------+--------------+
std::nullptr_t (c++11) |a null pointer      |/             |
-----------------------+--------------------+--------------+
void                   |no type             |/             |
-----------------------+--------------------+--------------+

To get size of object in bytes there is a "sizeof" operator


Signed integer

To store attribute of number, beeing positive or negative or zero, is called the number's sign.
By default integers are signed, which means the number's siggn is stored as part of the number (sign bit)

Integer ranges:
8 bit signed  = -128 to 127 
16 bit signed = -32,768 to 32,767
32 bit signed = -2,147,483,648 to 2,147,483,647
64 bit signed = -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

For the math inclined, an n-bit signed variable has a range of -(2n-1) to 2n-1-1.

Integer owerflow occurs, when we try to store a value that is outside the range of the type. 
It leads to undefined behaviour

Unsigned integers are integers that can only hold non-negative whole numbers.
Defined with unsigned keyword - unsigned int ui;
1 byte unsigned	0 to 255
2 byte unsigned	0 to 65,535
4 byte unsigned	0 to 4,294,967,295
8 byte unsigned	0 to 18,446,744,073,709,551,615

Because integers are of different site on different architectures, C99 defined a set of fixed-width 
    integers, that are guarnateed to be the same size on any architecture (in stdint.h header).

std::int8_t	1 byte signed	-128 to 127	Treated like a signed char on many systems. See note below.
std::uint8_t	1 byte unsigned	0 to 255	Treated like an unsigned char on many systems. See note below.
std::int16_t	2 byte signed	-32,768 to 32,767	
std::uint16_t	2 byte unsigned	0 to 65,535	
std::int32_t	4 byte signed	-2,147,483,648 to 2,147,483,647	
std::uint32_t	4 byte unsigned	0 to 4,294,967,295	
std::int64_t	8 byte signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807	
std::uint64_t	8 byte unsigned	0 to 18,446,744,073,709,551,615    

c++ adopted these fixed-width integers as part of c++11. _(include <cstdint>)
Fast and least integers

To help address the above downsides, C++ also defines two alternative sets of integers that are guaranteed to be defined.

The fast types (std::int_fast#_t and std::uint_fast#_t) provide the fastest signed/unsigned integer type 
    with a width of at least # bits (where # = 8, 16, 32, or 64). For example, std::int_fast32_t will give
    you the fastest signed integer type that’s at least 32 bits.
The least types (std::int_least#_t and std::uint_least#_t) provide the smallest signed/unsigned integer type
    with a width of at least # bits (where # = 8, 16, 32, or 64). For example, std::uint_least32_t will give
     you the smallest unsigned integer type that’s at least 32 bits.

Best practice
-Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
-Prefer std::int#_t when storing a quantity that needs a guaranteed range.
-Prefer std::uint#_t when doing bit manipulation or where well-defined wrap-around behavior is required.

Avoid the following when possible:
-Unsigned types for holding quantities
-The 8-bit fixed-width integer types
-The fast and least fixed-width types
-Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8, __int16, etc…     

Floating point range
4 bytes	±1.18 x 10-38 to ±3.4 x 1038	6-9 significant digits, typically 7
8 bytes	±2.23 x 10-308 to ±1.80 x 10308	15-18 significant digits, typically 16
80-bits (typically uses 12 or 16 bytes)	±3.36 x 10-4932 to ±1.18 x 104932	18-21 significant digits
16 bytes	±3.36 x 10-4932 to ±1.18 x 104932	33-36 significant digits

Best practice
Favor double over float unless space is at a premium, as the lack of precision in a float will often lead 
to inaccuracies.

Best practice
Put stand-alone chars in single quotes (e.g. ‘t’ or ‘\n’, not “t” or “\n”). 
This helps the compiler optimize more effectively.

To perform an explicit type conversion, we will use the static_cast operator: static_cast<new_type>(expre)

Integer prefixes:
012 - 10 - 0 prefix means octal
0xF - 15 - 0x prefix means hexadeciaml
0b  - assigns 32-bit binary 0000 0000 0000 0001 to the variable (c++14)

printing std::hex, std::oct, std::dec
std::bitset for bits..
*/
