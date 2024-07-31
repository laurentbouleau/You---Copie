#pragma once

#define vector_afficher_fichier_lire_     1
#define afficher_fichier_lire_            1

#define afficher_Path_Exists_             0

#define afficher_Netflix_SJ_              0

//#define afficher_Path_Exists_             0

#define Console_Lire_txt_                 1
#define Console_Lire_txt_OK_              0
#define PrintStringW_                     1

//#include "Source.h"
#include "titre.h"
//#include "you_txt.h"
#include "film.h"
#include "serie.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <sstream>
//#include <conio.h>
#include <ctype.h>
#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <locale>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation


const void afficher_Audiodescription(std::wstring& a, std::wstring const& nomFichier, std::wstring& audiodescription);
const int afficher_Avec(std::wstring&, std::wstring&, std::vector<std::wstring>&, std::vector<std::wstring>&);
const void afficher_Disney_SJ(std::wstring&, const std::wstring&, std::wstring&);
const void afficher_Genre(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);
const void afficher_Image(const std::wstring& nomFichier, std::vector<std::wstring>& images);
const void afficher_Nationalite(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);
const bool afficher_Min(std::wstring&);
//const int afficher_Nationalite(std::wstring&, std::wstring const&, std::vector<std::wstring>&, std::vector<std::wstring> const&);
const void afficher_Netflix_SJ(std::wstring&, const std::wstring&, std::wstring&);
const void afficher_SJ(std::wstring&, const std::wstring&, std::wstring&);
//const wstring afficher_SJ(std::wstring);
const int afficher_Sous_Genre(std::wstring&);
const void afficher_Sur(std::wstring&);
const int afficher_T123(std::wstring, std::wstring&, std::wstring&, std::wstring&);
const bool afficher_Temps(std::wstring);
const int afficher_Temps(std::wstring, std::tm&);
const void afficher_Temps(std::tm&);
const void afficher_Temps_OK(std::wstring&, bool);
const int afficher_Titre(std::wstring t, std::vector<std::wstring>& titre, bool& titre_);
const void afficher_Titre(std::wstring, std::vector<std::wstring>& titre);
const void afficher_Titre_Original(std::wstring&, std::wstring const&, std::vector<std::wstring>&);

extern const std::vector<std::wstring> Audiodescription;


//void PrintStringW(HANDLE hOut, const std::wstring& str);
static inline void rtrim(std::wstring& s);
std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace);
const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs);
const std::vector<std::pair<std::wstring, std::wstring>>lire_paireCleValeur_depuisFichierTxt(std::wstring const& nomFichier, std::wstring separeteur); 
const std::wstring lire_fichierTxt(std::wstring const& nomFichier);

//void PrintNationalites(const std::vector<std::wstring>& nationalites, bool nationalite_, std::wstring& titre_T, std::wstring& titre_t);

//bool checkyear(int y);
//bool checkmonth(int m);
//bool checkday(int m, int d, int y);
class exception_date_year
{
	std::wstring message;
public:
	exception_date_year() : message(L"L'année illégale doit être l'année numérique - entre 1900 et 3001") {}
	std::wstring get_message() const { return message; }
};

class exception_date_month
{
	std::wstring message;
public:
	exception_date_month() : message(L"Le mois illégal doit être un mois numérique - entre 1 et 12") {}
	std::wstring get_message() const { return message; }
};

class exception_date_day
{
	std::wstring message;
public:
	exception_date_day() : message(L"Le jour illégal doit être un jour numérique - entre 1 et 31") {}
	std::wstring get_message() const { return message; }
};

class exception_date_tiret
{
	std::wstring message;
public:
	exception_date_tiret() : message(L"aaaaaaaaaa") {}
	std::wstring get_message() const { return message; }
};

class exception_date_tiret_sp_etc
{
	std::wstring message;
public:
	exception_date_tiret_sp_etc() : message(L"bbbbbbbbbbb") {}
	std::wstring get_message() const { return message; }
};

class exception_test_sp_et_npos_ou_pas_isblank
{
	std::wstring message;
public:
	exception_test_sp_et_npos_ou_pas_isblank() : message(L"Espace invalide !!!") {}
	std::wstring get_message() const { return message; }
};

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # struct DateRecord                                                                                                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

struct DateRecord
{
	std::tm date{ 0 };
	bool someFlag{ false };
};

