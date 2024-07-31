#pragma once

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS
//#define NDEBUG
//#define _MAX_PATH 32 768

//#define B_T                               L"\x1b[38;2;200;200;0m"
//#define B_t                               L"\x1b[38;2;255;255;255m"
//#define B_W                               L"\x1b[38;2;155;155;155m"
//#define B_w                               L"\x1b[38;2;255;255;255m"

#define wmain_                            1
#define wmain_C_S_CV_CD_                  1
#define you_substr_                       0
#define You_txt_ok_                       0
#define You_txt_C_S_CV_CD_                1
#define You_you_                          1
#define You_                              1
#define You_t_                            1
#define You_Genre_                        1
#define You_Rechercher_                   1
#define compare_path_                     1





#define Allocine_AD                       6


//#define CINEMA                            2048

#define Cinema_afficher_Nationalite       21

#define _X_                               10
#define _X2_                              25
#define _x_                               5
//#define _x_ 7

#define TXT_                             0
#define JGP_                             1
#define PNG_                             2
#define WEBP_                            3

//#define CP_ACP 1
//#define MB_ERR_INVALID_CHARS 1

// *****************************************************************************************************
#include "Utils.h"
#include "titre.h"
//#include "you_txt.h"
#include "film.h"
#include "serie.h"
#include "erreur_ok.h"
#include "console.h"

#include <windows.h>
#include <cassert>
//#include <cstddef>
#include <sstream>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <locale>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

//namespace std::byte; // ???

//Person P;
//Erreur E;
//const struct Person;

extern class Erreur E;
extern class Bug B;

extern const std::vector<std::wstring> AZERTYUIOP;

extern const bool afficher_Path_Exists(std::wstring& t);
extern const int Compare_Path(int rc, path p1, path p2);

struct Person
{
    // _ h __ min
    // X
    bool F_Espace1 = false; // true ou false
    wchar_t F_H = L'h'; // = L'h' : h ou H
    bool F_Espace2 = false; // true ou false
    // XX
    bool F_Espace3 = false; // true ou false
    std::wstring F_MIN = L"min"; // = L"min" : MIN ou Min ou min
    //std::wstring F_T = L"\x1b[94;1m";
    //std::wstring F_t = L"\x1b[38;2;255;255;255m";
    //std::wstring F_W = L"\x1b[38;2;0;255;0m";
    //std::wstring F_w = L"\x1b[38;2;255;255;255m";
    std::vector<std::wstring> F_keyColor{ L"\x1b[94;1m", L"\x1b[38;2;0;255;0m" };
    std::wstring F_valuesColor = L"\x1b[38;2;255;255;255m";

    // min
    bool S_Espace = false; // true ou false
    std::wstring S_MIN = L"min"; // = L"min";
    //std::wstring S_T = L"\x1b[38;2;0;0;255m";
    //std::wstring S_t = L"\x1b[38;2;255;255;255m";
    //std::wstring S_W = L"\x1b[38;2;0;255;0m";
    //std::wstring S_W = L"\x1b[92m";
    //std::wstring S_w = L"\x1b[38;2;255;255;255m";
    //std::wstring S_w = L"\x1b[97m";
    std::vector<std::wstring> S_keyColor{ L"\x1b[94;1m", L"\x1b[38;2;0;255;0m" };
    std::wstring S_valuesColor = L"\x1b[38;2;255;255;255m";

    // Bug
    //wstring B_T = L"\x1b[38;2;200;200;0m";
    //wstring B_t = L"\x1b[38;2;255;255;255m";
    //wstring B_W = L"\x1b[38;2;155;155;155m";
    //wstring B_w = L"\x1b[38;2;255;255;255m";

    // Erreur
    std::wstring E_T = L"\x1b[38;2;255;0;0m";
    std::wstring E_t = L"\x1b[38;2;255;255;255m";

    // Rechercher
    std::wstring R_T = L"\x1b[38;2;255;255;0m";
    std::wstring R_t = L"\x1b[38;2;255;255;255m";

    //
    std::wstring& P_T = F_keyColor[0];
    std::wstring& P_t = F_valuesColor;
};


//const int ScrollByAbsoluteCoord(int);
const int You_you(int c, wchar_t** v);
const int You_Genre(std::wstring);
//const void afficher_X(int, wstring, wstring);
const int compare_path(path& t, std::wstring& t2);
const int You_t(std::wstring);
//const int You_t(int& c, wchar_t ** v);
const int You_t(std::vector<std::wstring>&);
//const int You_Rechercher(wstring);
const int You_Rechercher(int c, wchar_t** v);
//const int console_OK(void);
//int qqqqq();
//int qsdfg();



const int You_txt_ok(void);
