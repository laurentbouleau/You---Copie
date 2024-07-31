#pragma once

#define Titre_afficher_AD_                1
// 
#define afficher_AD_                      1
#define afficher_Avec_                    1
#define afficher_Genre_                   1
#define afficher_Image_                   1
#define afficher_Min_                     0
//#define afficher_Netflix_SJ_              1
#define afficher_Nationalite_             1
#define afficher_SJ_                      1
#define afficher_Sous_Genre_              1
#define afficher_Sur_                     1
#define afficher_T123_                    1
#define afficher_Temps_                   0
#define afficher_Temps_1_                 1
//#define afficher_Temps_Ok_                0
#define afficher_Titre_                   1
#define afficher_Titre_1_                 1
#define afficher_Titre_Original_          1

#include "Utils.h"
//#include "Header.h"
#include "You.h"
//#include "you_txt.h"
#include "film.h"
#include "serie.h"
#include "console.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
//#include <stdio.h>
//#include <locale>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

/*struct Avec2
{
	wstring Avec = L"";
	wstring Avec_role = L"";
} avec;*/
//vector<Avec2> avec;


class Console;
class Titre
{
public:
	Titre(void);
	~Titre();
	//const void afficher_Audiodescription(std::wstring& a_filename, std::wstring const& nomFichier, std::wstring& audiodescription);
protected:
	std::wstring audiodescription = L"";
	bool audiodescription_ = true;
private:
};

