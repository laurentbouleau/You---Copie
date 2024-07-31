#include "pch.h"

#include "Utils.h"
#include "Bug.h"
//#include "erreur_ok.h
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "film.h"
#include "serie.h"

#include <windows.h>
#include <cassert>
#include <iostream>
//#include <xstring>
#include <iomanip>
#include <string>
#include <vector>
//#include <sstream>
//#include <conio.h>
//#include <ctype.h>

/*#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;*/

extern int Y;

extern const int Console_Lire_txt(std::wstring, int, int);

Bug B;

Bug::Bug()
{
    //B_T = L"\x1b[38;2;200;200;0m";
    //B_t = L"\x1b[38;2;255;255;255m";
    //B_W = L"\x1b[38;2;155;155;155m";
    //B_w = L"\x1b[38;2;255;255;255m";
}

Bug::~Bug()
{

}

/*const*/ void Bug::Ok_T(std::wstring t)
{
    int i = Console_Lire_txt(B_T + t + B_t, x1, x2);
}

/*const*/ void Bug::Ok_W(std::wstring t)
{
    int i = Console_Lire_txt(B_W + t + B_w, x3, x4);
}

