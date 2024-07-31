#pragma once
#include "pch.h"
// you_txt
#define You_txt_                          1
#define You_txt_fs_                       0
#define You_txt_is_directory_             0
#define You_txt_OK_                       1

#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "film.h"
#include "serie.h"
#include "erreur_ok.h"

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale>

struct P_FS
{
    std::wstring fs = L"";
    std::wstring note[6] = { L"", L"", L"", L"", L"", L"" };
    int fs_{ 0 };
};

const int You_txt(int&);
const int You_txt_OK();