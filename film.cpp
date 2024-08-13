#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
//#define _CRT_NONSTDC_NO_WARNINGS
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
//#pragma warning(disable : 4996)
//#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"

#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "serie.h"
#include "film.h"
#include "console.h"
#include "erreur_ok.h"
//#include "Bug.h"

#include <windows.h>
#include <cassert>
//#include <climits>
#include <algorithm>
#include <string>
#include <iostream>
//#include <sstream>
//#include <ctime>
#include <codecvt>
#include <vector>
/*#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;*/

extern int X;

extern class Erreur E;
//extern class Bug B;

//extern const int afficher_Avec(std::wstring&, std::wstring const&, std::vector<std::wstring>&, std::vector<std::wstring>&);
extern const void afficher_Avec(std::wstring& a_filename, const std::wstring& nomFichier, std::vector<std::pair<std::wstring, std::wstring>>& avec);

extern const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs);
extern const std::vector<std::pair<std::wstring, std::wstring>>lire_paireCleValeur_depuisFichierTxt(std::wstring const& nomFichier, std::wstring separeteur);
extern const std::wstring lire_fichierTxt(std::wstring const& nomFichier);

extern const void Console_Lire_txt(std::wstring);
extern const void Console_Lire(std::wstring wstr, int x1, int x2);
extern const int Console_Lire_txt(std::wstring, int, int);

//extern std::tm ParseDate(std::wstring& str);

extern void PrintAudiodescription(const std::wstring& ad, bool ad_, std::wstring& titre_T, std::wstring& titre_t, int x);
extern void PrintGenres(const std::vector<std::wstring>& genres, bool genre_, const std::wstring& sous_genre, bool sous_genre_, std::wstring& titre_T, std::wstring& titre_t);
extern void PrintImages(const std::vector<std::wstring>& images, bool image_, std::wstring& titre_T, std::wstring& titre_t, int x1, int y1, int x2, int y2);
extern void PrintNationalites(const std::vector<std::wstring>& nationalites, bool nationalite_, std::wstring& titre_T, std::wstring& titre_t);
extern void PrintNetflixokounon(bool netflix_ok_ou_non, bool affichage_sur_actif, std::wstring& keyColor, std::wstring& valuesColor);
extern void PrintTitreOriginal(const std::vector<std::wstring>& titre_original, bool affichage_titre_original_actif, std::wstring& keyColor, std::wstring& valuesColor, std::wstring& keyColor2, std::wstring& valuesColor2);

extern bool checkyear(int y);
extern bool checkmonth(int m);
extern bool checkday(int m, int d, int y);

extern void test_date_year(int&);
extern void test_date_month(int&);
extern void test_date_day(int&);
extern void test_date_tire(wchar_t d);
extern void test_date_tiret_sp_etc(wchar_t d);
extern void test_sp_et_npos_ou_pas_isblank(wchar_t sp, bool t);



Film::Film()
{
	//std::vector<std::wstring>Titre{};
}

Film::~Film()
{
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_dossier                                                                                                                                   #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Film::afficher_dossier(std::wstring const& t)
{
#if Film_afficher_dossier_ == true
	B.Ok_T(L"const int Cinema::afficher_dossier(" + t + L") :");
#endif
	int i = 0;
	std::wstring t2;
	std::size_t idx, idx2 = 0;
	idx = t.find(L".(", 0);
	t2 = t.substr(0, idx);
	i = ::afficher_Titre(t2, titre, Titre_);
	idx = t.find_last_of(L"(");
	idx2 = t.find_last_of(L")");
	if (idx2 - idx - 1 == 0)
		return EXIT_FAILURE;
	idx2--;
	if (!(t.at(idx2) == L' ' || t.at(idx2) == L'-' ||
		t.at(idx2) == L'0' || t.at(idx2) == L'1' || t.at(idx2) == L'2' || t.at(idx2) == L'3' || t.at(idx2) == L'4' ||
		t.at(idx2) == L'5' || t.at(idx2) == L'6' || t.at(idx2) == L'7' || t.at(idx2) == L'8' || t.at(idx2) == L'9'))
	{ // Sur
		std::size_t idx3;
		idx3 = t.find_first_of(L" ", idx);
		idx3++;
		t2 = t.substr(idx3, idx2 - idx3 + 1);
	    afficher_Sur(t2);
		if (sur == t2)
		{
			E.afficher_X(-1, L"Sur !", L"Érreur (" + t2 + L") !!!");
			return EXIT_FAILURE;
		}
		else
		{
			sur = t2;
			//sur_ = true;
		}
		if (sur == L"Netflix")
			netflix_ok_ou_non = true;
		std::wcout << L"Sur={" << sur << L"}" << std::endl;
		idx2 = idx3 - 2;
	}
	idx++;
	if (t.at(idx2) == L' ' || t.at(idx2) == L'-' ||
		t.at(idx2) == L'0' || t.at(idx2) == L'1' || t.at(idx2) == L'2' || t.at(idx2) == L'3' || t.at(idx2) == L'4' ||
		t.at(idx2) == L'5' || t.at(idx2) == L'6' || t.at(idx2) == L'7' || t.at(idx2) == L'8' || t.at(idx2) == L'9')
	{ // Date
		t2 = t.substr(idx, idx2 - idx + 1);
		//i = afficher_Date(t2, t);
		afficher_Date(t2);
	}
	else
		return i;
	idx = t.find(L").");
	if (idx != std::wstring::npos)
	{ // Sous_Genre
		idx = idx + 2;
		sous_genre = t.substr(idx);
		//wstring sous_genre = L"";
		i = afficher_Sous_Genre(sous_genre);
		affichage_sous_genre_actif = true;
	}
	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_fichier                                                                                                                                   #
// # const int Film::afficher_fichier(wstring const& _T, int const& _T_ = _TXT_)                                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Film::afficher_fichier(std::wstring const& nomFichier, int const& nomImage = TXT_)
{
	int i = 0;
	std::size_t pos;
	pos = nomFichier.find_last_of(L"\\");
//	if (Ok == L"")
//		Ok = nomFichier.substr(0, pos);
	pos++;
	std::wstring t = nomFichier.substr(pos);
	if (nomImage == TXT_)
	{
		if (t[0] == L'1' || t[0] == L'2' || t[0] == L'3')
		{
			/*          0 1 2 3 4 5 6 7 8 9                   */
			// Date_ou_dates
			afficher_Date_ou_Dates(t);
			return EXIT_SUCCESS;
		}
		/*          A B C D E F G H I J K L M N O P Q R S T U V W Y Z            */
		else
		{
			// AD : Audiodescription
			if (t == L"AD.txt")
			{
				afficher_Audiodescription(t, nomFichier, audiodescription);
				return EXIT_SUCCESS;
			}
			// Avec
			if (L"Avec.txt" == t)
			{
				afficher_Avec(t, nomFichier, avec);
				return EXIT_SUCCESS;
			}
			// Date de reprisé
			if (t == L"Date de reprise.txt")
			{
				afficher_Date_de_reprise_ou_de_sortie(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// Date de sortie
			if (t == L"Date de sortie.txt")
			{
				afficher_Date_de_reprise_ou_de_sortie(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// De
			if (t == L"De.txt")
			{
				afficher_De(t, nomFichier, de);
				return EXIT_SUCCESS;
			}
			// Disney+
			if (t == L"Disney+.txt")
			{
				afficher_Disney_SJ(t, nomFichier, disney_sj);
				return EXIT_SUCCESS;
			}
			// Distributeur
			if (t == L"Distributeur.txt")
			{
				afficher_Distributeur(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// Genre
			if (t == L"Genre.txt")
			{
				afficher_Genre(t, nomFichier, genre, ::Genre);
				return EXIT_SUCCESS;
			}
			// Nationalité
			if (t == L"Nationalité.txt")
			{
				afficher_Nationalite(t, nomFichier, nationalite, ::Nationalite);
				return EXIT_SUCCESS;
			}
			// Netflix
			if (t == L"Netflix.txt")
			{
				afficher_Netflix_SJ(t, nomFichier, netflix_sj);
				return EXIT_SUCCESS;
			}
			// Note
			if (t == L"Note.txt")
			{
				afficher_Note(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// Par
			if (t == L"Par.txt")
			{
				afficher_Par(t, nomFichier, par);
				return EXIT_SUCCESS;
			}
			// SJ
			if (t == L"SJ.txt")
			{
				afficher_SJ(t, nomFichier, sj);
				return EXIT_SUCCESS;
			}
			// Soundtrack
			if (t == L"Soundtrack.txt")
			{
				afficher_Soundtrack(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// Titre
			if (t == L"Titre.txt")
			{
				afficher_Titre(t, nomFichier);
				//	if (Ok == L"")
				//Ok = nomFichier.substr(0, pos);
				return EXIT_SUCCESS;
			}
			// Titre original
			if (t == L"Titre original.txt")
			{
				afficher_Titre_Original(t, nomFichier, titre_original);
				return EXIT_SUCCESS;
			}
			// www.nautiljon.com
			if (t == L"www.nautiljon.com.txt")
			{
				return EXIT_SUCCESS;
			}
		}
	}
	else if (nomImage == JGP_ || nomImage == PNG_ || nomImage == WEBP_)
	{
		afficher_Image(nomFichier, image);
		B.Ok_T(L"const int Cinema::afficher_fichier() : Ok !");
		return EXIT_SUCCESS;
	}
	else
	{
		E.afficher_X(-1, t, t + L" erreur (" + t + L") !!!");
		return EXIT_FAILURE;
	}
	E.afficher_X(-1, t, t + L" erreur (" + t + L") !!!");
	return EXIT_FAILURE;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Date                                                                                                                                               #
// # const void Film::afficher_Date(std::wstring& d)                                                                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::afficher_Date(std::wstring& d)
{ // Date
	std::size_t pos = 0;
	// year
	int year = 0;
	year = std::stoi(d, &pos);
	try
	{
		test_date_year(year);
	}
	catch (exception_date_year e)
	{
		std::wcout << L"Exception a été capturée : " << e.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(4);
	// date
	try
	{
		test_date_tire(d[0]);
	}
	catch (exception_date_tiret e2)
	{
		std::wcout << L"Exception a été capturée : " << e2.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(1);
	// mon
	int mon = 0;
	pos = 0;
	mon = std::stoi(d, &pos);
	try
	{
		test_date_month(mon);
	}
	catch (exception_date_month e3)
	{
		std::wcout << L"Exception a été capturée : " << e3.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(2);
	// date
	try
	{
		test_date_tire(d[0]);
	}
	catch (exception_date_tiret e2)
	{
		std::wcout << L"Exception a été capturée : " << e2.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(1);
	// mday
	int mday = 0;
	mday = std::stoi(d, &pos);
	try
	{
		test_date_day(mday);
	}
	catch (exception_date_day e4)
	{
		std::wcout << L"Exception a été capturée : " << e4.get_message() << std::endl;
		exit(1);
	}
	//
	date.tm_year = year - 1900;
	date.tm_mon = mon - 1;
	date.tm_mday = mday;
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Date_de_reprise_ou_de_sortie                                                                                                              #
// # const void Film::afficher_Date_de_reprise_ou_de_sortie(std::wstring& d_filename, const std::wstring& nomFichier)                                 #
// #                                                                                                                                                    #
// ######################################################################################################################################################


const void Film::afficher_Date_de_reprise_ou_de_sortie(std::wstring& d_filename, const std::wstring& nomFichier)
{ // Date de reprise
	assert((d_filename == createdBy_filename) && L"Erreur !!! Date de reprise... !");
	std::wstring d = lire_fichierTxt(nomFichier);
	std::size_t pos = 0;
	// year
	int year = 0;
	year = std::stoi(d, &pos);
	try
	{
		test_date_year(year);
	}
	catch (exception_date_year e)
	{
		std::wcout << L"Exception a été capturée : " << e.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(4);
	// date_tire_sp_etc
	try
	{
		test_date_tiret_sp_etc(d[0]);
	}
	catch (exception_date_tiret_sp_etc e2)
	{
		std::wcout << L"Exception a été capturée : " << e2.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(1);
	// mon
	int mon = 0;
	pos = 0;
	mon = std::stoi(d, &pos);
	try
	{
		test_date_month(mon);
	}
	catch (exception_date_month e3)
	{
		std::wcout << L"Exception a été capturée : " << e3.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(2);
	// date_tire_sp_etc
	try
	{
		test_date_tiret_sp_etc(d[0]);
	}
	catch (exception_date_tiret_sp_etc e2)
	{
		std::wcout << L"Exception a été capturée : " << e2.get_message() << std::endl;
		exit(1);
	}
	d = d.substr(1);
	// mday
	int mday = 0;
	mday = std::stoi(d, &pos);
	try
	{
		test_date_day(mday);
	}
	catch (exception_date_day e4)
	{
		std::wcout << L"Exception a été capturée : " << e4.get_message() << std::endl;
		exit(1);
	}
	//
	std::tm date;
	date.tm_year = year - 1900;
	date.tm_mon = mon - 1;
	date.tm_mday = mday;
	if (d_filename == L"Date de reprise.txt")
		date_de_reprise = date;
	else
		date_de_sortie = date;
	}

/*void Cinema::afficherDateRepriseOuSortie(std::wstring& d, const std::wstring& nomFichier)
{
	//afficherDate(m_dateReprise != nullptr ? m_dateReprise : m_dateSortie);
	assert((d_filename == createdBy_filename) && L"Erreur !!! date... !");
	afficherDate(date_de_reprise != nullptr ? date_de_reprise : date_de_sortie);
}*/

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Date_ou_Dates                                                                                                                             #
// # void Film::afficher_Date_ou_Dates(std::wstring const& wstr)                                                                                        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Film::afficher_Date_ou_Dates(std::wstring const& wstr)
{
	assert(nomFichier.length() > 0 && L"Nom de fichier vide");

	std::size_t pos;
	pos = wstr.length();
	std::wstring strRestant = wstr.substr(0, pos - 4);
	assert(strRestant.length() > 9 && L"Nom de fichier trop court pour avoir au moins une date");

	std::vector<DateRecord> dr;
	std::wstring streaming = L"";

	wchar_t sp = L' ', tiret = L'-', tiret_bas = L'_';
	int y, m, d;
	int firstYear = 0, firstMon = 0, firstDay = 0;
	int i = 0;
	do
	{
		if (strRestant[0] == sp)
		{
			if (strRestant[1] == std::wstring::npos || strRestant[1] == sp)
			{
				// try cath !!!
				// Explique-moi ??? 
				// ou : 
				exit(1);
			}
			strRestant = strRestant.substr(1);
			// try cath !!!
			// Explique-moi ??? 
			// ou : 
			try // Erreur !!!
			{
				test_sp_et_npos_ou_pas_isblank(strRestant[0], isblank(strRestant[1]));
			}
			catch (exception_test_sp_et_npos_ou_pas_isblank e)
			{
				exit(1);
			}
			if (strRestant.length() > 0)
			{
				streaming = strRestant;
			}
			strRestant = L"";
			break;
		}
		if (!isdigit(strRestant[0]))
		{
			// try cath !!!
			// Explique-moi ??? 
			// ou : 
			exit(1);
		}
		// year + mon + mday
		if ((y = stoi(strRestant.substr(0, 4))) && checkyear(y)
			&&
			strRestant[4] == tiret
			&&
			(m = std::stoi(strRestant.substr(5, 2))) && checkmonth(m)
			&&
			strRestant[7] == tiret
			&&
			(d = std::stoi(strRestant.substr(8, 2))) && checkday(m, d, y)
			&&
			firstYear < y)
		{
			assert(firstYear < y && L"L'année aaaaa");
			firstYear = y;
			assert(firstMon < m && L"Le mois aaaaa");
			firstMon = m;
			assert(firstDay <= d && L"Le jours aaaaa");
			firstDay = d;
			dr.push_back(DateRecord{ 0 });
			dr[i].date.tm_year = y - 1900;
			dr[i].date.tm_mon = m - 1;
			dr[i].date.tm_mday = d;
			strRestant = strRestant.substr(10);
			if (strRestant[0] == tiret_bas)
			{
				dr[i].someFlag = true;
				strRestant = strRestant.substr(1);
			}
			i++;
			continue;
		}
		// mon + mday
		if ((m = std::stoi(strRestant.substr(0, 2))) && checkmonth(m)
			&&
			strRestant[2] == tiret
			&&
			(d = std::stoi(strRestant.substr(3, 2))) && checkday(m, d, firstYear)
			&&
			firstMon < m)
		{
			assert(firstMon < m && L"Le mois aaaaa");
			firstMon = m;
			dr.push_back(DateRecord{ 0 });
			dr[i].date.tm_year = firstYear - 1900;
			dr[i].date.tm_mon = m - 1;
			dr[i].date.tm_mday = d;
			assert(firstDay <= d && L"Le jours aaaaa");
			firstDay = d;
			strRestant = strRestant.substr(5);
			if (strRestant[0] == tiret_bas)
			{
				dr[i].someFlag = true;
				strRestant = strRestant.substr(1);
			}
			i++;
			continue;
		}
		// mday
		if ((d = std::stoi(strRestant.substr(0, 2))) && checkday(firstMon, d, firstYear)
			&&
			firstDay <= d)
		{
			firstDay = d;
			assert(firstDay <= d && L"Le jours aaaaa");
			dr.push_back(DateRecord{ 0 });
			dr[i].date.tm_year = firstYear - 1900;
			dr[i].date.tm_mon = firstMon - 1;
			dr[i].date.tm_mday = d;
			strRestant = strRestant.substr(2);
			if (strRestant[0] == tiret_bas)
			{
				dr[i].someFlag = true;
				strRestant = strRestant.substr(1);
			}
			i++;
			continue;
		}
		// try cath !!!
		// Explique-moi ???
		// ou : 
		exit(1);
	} while (strRestant.length() > 0);
	date_ou_dates.push_back(make_pair(dr, streaming));
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_De                                                                                                                                        #
// # void Film::afficher_De(std::wstring& d_filename, std::wstring const& nomFichier, std::vector<std::wstring>&de) const                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Film::afficher_De(std::wstring& d_filename, std::wstring const& nomFichier, std::vector<std::wstring>&de) const
{
	assert((d_filename == createdBy_filename) && L"Erreur !!! De... !");
	de = lire_fichierTxt(nomFichier, { L"\n", L", " });
	assert((de.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Distributeur                                                                                                                              #
// # const int Film::afficher_Distributeur(std::wstring& d_filename, std::wstring const& nomFichier)                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::afficher_Distributeur(std::wstring& d_filename, std::wstring const& nomFichier)
{ // Distributeur
	assert((d_filename == createdBy_filename) && L"Erreur !!! Distributeur... !");
	distributeur = lire_fichierTxt(nomFichier);
	assert((distributeur.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Par                                                                                                                                       #
// # void Film::afficher_Par(std::wstring& p_filename, std::wstring const& nomFichier, std::vector<std::wstring>& par) const                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Film::afficher_Par(std::wstring& p_filename, std::wstring const& nomFichier, std::vector<std::wstring>& par) const
{
	assert((p_filename == createdBy_filename) && L"Erreur !!! Par... !");
	par = lire_fichierTxt(nomFichier, { L"\n", L", " });
	assert((par.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Note                                                                                                                                      #
// # const void Film::afficher_Note(std::wstring& n_filename, std::wstring const& nomFichier)                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::afficher_Note(std::wstring& n_filename, std::wstring const& nomFichier)
{ // 0...5 ou -1
    std::wstring n = lire_fichierTxt(nomFichier);
	std::size_t pos = n.length();
	if (n == L"")
	{
		note = -1.0;
		return;
	}
	if (pos != 1 && pos != 3)
	{
		E.afficher_X(-1, n, L"Pas de [a-z] et/ou [0-9] et/ou etc…");
		return;
	}
	if (!iswdigit(n[0]))
	{
		E.afficher_X(-1, n, L"Pas de [a-z] et/ou etc…");
		return;
	}
	if (!(n[0] == L'0' || n[0] == L'1' || n[0] == L'2' || n[0] == L'3' || n[0] == L'4' || n[0] == L'5'))
	{
		E.afficher_X(-1, n, L"Pas de [0-5]");
		return;
	}
	if (pos == 1)
		note = std::stod(n);
	else
	{
		if ((n[1] == L',' || n[1] == L'.') && iswdigit(n[2]) && pos == 3)
		{
			//
			n[1] = L',';
			//
			// Ok !!!
			note = std::stod(n);
			//
		}
		else
		{
			E.afficher_X(-1, n, L"Pas de…");
			return;
		}
	}
	return;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Soundtrack                                                                                                                                         #
// # const int afficher_Soundtrack(std::wstring& s_filename, const std::wstring& nomFichier)                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::afficher_Soundtrack(std::wstring& s_filename, const std::wstring& nomFichier)
{
	// utiliser les fonctions plus générique ("de plus bas niveau") pour avoir un code simple pour les fonction de plus "haut" niveau
	// Il y a peut-être un peu de customisation pour gérer les "rôles" mais rien d'insurmontable
	//std::vector<std::pair<std::wstring, std::wstring>> clevaleurs = lire_paireCleValeur_depuisFichierTxt(L"Soundtrack.txt", L" : ");

	//Console::PrintStringW(Console::Ponctuation_Color + L"Soundtrack :" +  console.End_Ln + L"\r\n");
	//Console::PrintStringW(L"Soundtrack :" + L"\r\n");

	//for (const auto& [cle, valeur] : clevaleurs) {
	//	Console::affiche_CleValeur(L"\t" + cle, valeur);
	assert((s_filename == createdBy_filename) && L"Erreur !!! Soundtrack... !");
	//par = lire_fichierTxt(nomFichier, { L"\n", L", " });
	
	m_soundtrack = lire_paireCleValeur_depuisFichierTxt(nomFichier, L" : ");
	assert((soundtrack.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Titre                                                                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::afficher_Titre(std::wstring& t_filename, std::wstring const& nomFichier)
{ // Titre_1
	assert((t_filename == createdBy_filename) && L"Erreur !!! Titre... !");
	std::vector<std::wstring>t = lire_fichierTxt(nomFichier, { L"\n"});
	std::size_t pos = 0;

	assert(t.size() < 3 L"" && L"Erreur !!! Titre[0]... !");
	::afficher_Titre(t[0], titre);
	titre_ok = t[0];
	//
	bool titre_, h_min_;
	titre_ = h_min_ = false;

	h_min_ = ::afficher_Temps(t[1]);
	if (!h_min_)
	{
		E.afficher_X(-1, t[1], t[1] + L" érreur (" + t[1] + L") !!!");
		return;// EXIT_FAILURE;
	}
	titre.push_back(t[1]);
	temps.tm_hour = std::stoi(t[1]);
	temps.tm_min = std::stoi(t[1].substr(2));
	//if (!Temps_)
	//	Temps_ = true;
	t.erase(t.begin());
	t.erase(t.begin());

	std::wstring wstr;
	for (auto&& ti : t)
		wstr += ti + L'\n';
	titre.push_back(wstr);
	return;// EXIT_SUCCESS;
}

/////////////////
// //////////////

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # pas de OK                                                                                                                                          #
// # const int Film::afficher_pas_de_OK()                                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Film::afficher_pas_de_OK() const
{
#if Film_afficher_pas_de_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_pas_de_OK() :");
#endif
	if (!affichage_genres_actif)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Genre !!!");
#if Film_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Genre !!!");
#endif
	}
	if (!affichage_nationalite_actif)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Nationalité !!!");
#if Film_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Nationalité !!!");
#endif
	}
	// Note
	if (!affichage_note_actif)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Note !!!");
#if Film_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Note !!!");
#endif
	}
	// Titre
	if (!Titre_)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Titre !!!");
#if Film_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Titre !!!");
#endif
	}
#if Film_afficher_pas_de_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_pas_de_OK() : Ok !");
#endif
	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher                                                                                                                                           #
// # const int Film::afficher()                                                                                                                       #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Film::afficher()
{ // OK !
#if Film_afficher_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_OK() :");
#endif
	int i = 0;
	std::vector <wstring>::iterator iter;
	std::size_t pos = 0;
	std::wstring wstr;
	std::wstring Textes;
	//
#if Film_afficher_OK_ == 1
	Console_Lire_txt(L"~~~~~~~~~~ ");
	if (Ok != L"Titre.txt")
		std::wcout << L"    " << C_T << L'{' << C_t << Ok << C_T << L'}' << C_t << std::endl;
	else
	{
		std::wcout << L"    " << C_T << L'{' << C_t << Titre[0];
		if (Titre[1] != L"")
		{
			std::wcout << C_T << Titre[1] << C_t;
			std::wcout << Titre[2];
		}
		std::wcout << C_T << L'}' << C_t << std::endl;
	}
#endif
	Console_Lire_txt(L"~~~~~~~~~~ ");
	if (titre_ok == L"")
	{
		if (E.Ok())
			Console_Lire_txt(L"---------- ");
		return -1;
	}
	// Titre
	//PrintTitre();
	// Header
	PrintHeader();
	// Date de reprise
	PrintDatedeReprise();
	// Date de sortie
	PrintDatedeSortie();
	// Titre original
	PrintTitreOriginal(titre_original, affichage_titre_original_actif, keyColor[0], valuesColor, keyColor[1], valuesColor);
	// Distributeur
	PrintDistributeur();
	// Audiodescription
	PrintAudiodescription(audiodescription, affichage_audiodescription_actif, keyColor[0], valuesColor, 0);
	// Genre
	PrintGenres(genre, affichage_genres_actif, sous_genre, affichage_sous_genre_actif, keyColor[0], valuesColor);
	// De
	PrintDe(de);
	// Par
	PrintPar(par);
	// Avec
	PrintAvec(avec);
	// Nationalité(s)
	PrintNationalites(nationalite, affichage_nationalite_actif, keyColor[0], valuesColor);
	// Image
	PrintImages(image, affichage_image_actif, keyColor[0], valuesColor, 0, 0, 0, 0);
	// Netflix ?
	PrintNetflixokounon(netflix_ok_ou_non, affichage_sur_actif, keyColor[0], valuesColor);
	//
	Console_Lire_txt(L"~~~~~~~~~~ ");
	PrintTitre_sur_4();
    // Date_ou_dates
	if(PrintDate_ou_Dates())
        Console_Lire_txt(L"~~~~~~~~~~ ");
	// Avec
	PrintAvec();
	// Soundtrack
	PrintSoundtracks();
	if(affichage_avec_actif || affichage_soundtraks_actif)
	    Console_Lire_txt(L"~~~~~~~~~~ ");
    // ???
	//Console_Lire_txt(L"---------- ");
	i = E.Ok();
#if Cinema_afficher_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_OK() : Ok !");
#endif
	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Temps_OK                                                                                                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const wstring Film::afficher_Temps_OK()
{ // h:mm
#if Film_afficher_Temps_OK_ == 1
#endif
	wchar_t date_string[22];
	wcsftime(date_string, 20, L"%H:%M", &temps);
	std::wstring t = date_string;
	std::size_t pos = t.find(L':');
	std::wstring h = t.substr(1, pos - 1);
	std::wstring m = t.substr(pos + 1);
	std::wstring wstr = h;
	if (F_Espace1)
		wstr += L' ';
	wstr += keyColor[0] + F_H + valuesColor;
	if (F_Espace2)
		wstr += L' ';
	wstr += m;
	if (F_Espace3)
		wstr += L' ';
	if (F_MIN != L"")
		wstr += keyColor[0] + F_MIN + valuesColor;
#if Film_afficher_Temps_OK_ == 1
#endif
	return wstr;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// #                                                                                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Film::Ok_F(bool P_F_Espace1, wchar_t P_F_H, bool P_F_Espace2, bool P_F_Espace3, std::wstring P_F_MIN, std::vector<std::wstring> F_keyColor, std::wstring F_valuesColor)
{
	F_Espace1 = P_F_Espace1;
	F_H = P_F_H;
	F_Espace2 = P_F_Espace2;
	F_Espace3 = P_F_Espace3;
	F_MIN = P_F_MIN;
	//keyColor.push_back(P_C_T);
	//keyColor.push_back(P_C_W);
	keyColor = F_keyColor;
	valuesColor = F_valuesColor;

	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintAvec                                                                                                                                          #
// # const void Film::PrintAvec(std::vector<std::pair<std::wstring, std::wstring>>& avec)                                                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintAvec(std::vector<std::pair<std::wstring, std::wstring>>& avec)
{
	if (affichage_avec_actif && avec.size())
	{
		// j ???
		int j;
		std::wstring avec_str = keyColor[0] + L"Avec : " + valuesColor;
		std::vector<pair<std::wstring, std::wstring>>::iterator iter2;
		for (iter2 = avec.begin(), j = 0; iter2 != avec.end(); iter2++)
		{
			if (
				(j < (avec.size() - 1)
					&&
					(*iter2).first != L"")
				)
			{
				avec_str += (*iter2).first;
				j++;
			}
			if (j > 2)
				break;
			avec_str += keyColor[0] + L", " + valuesColor;
		}
		//Console_Lire(avec_str, 4, 0);
		int i = Console_Lire_txt(avec_str, 0, 0);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintAvec                                                                                                                                          #
// # const void Film::PrintAvec()                                                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintAvec()
{
	if (affichage_avec_actif && avec.size())
	{
		int i = Console_Lire_txt(keyColor[0] + L"Avec :" + valuesColor + L"\r\n", 0, 0);

		std::wstring avec_str;
		bool found = false;
		for (auto&& [nom, role] : avec)
		{
			if (nom == L"…" || nom == L"..." || nom == L".")
				{
				found = true;
				break;
				}
			if (nom != L"" && role != L"")
			{
				avec_str += nom + L' ' + keyColor[1] + L"(" + valuesColor + role + keyColor[1] + L")" + valuesColor;
			}
			else if (nom == L"" && role != L"")
			{
				avec_str += keyColor[1] + L"(" + valuesColor + role + keyColor[1] + L")" + valuesColor;
			}
			else
			{
				avec_str += nom;
			}
			if (avec.back().first != nom)
				avec_str += keyColor[1] + L", " + valuesColor;
			else
				avec_str += keyColor[1] + L'.' + valuesColor;
		}
		if(found)
		    avec_str += L"...";
		//Console_Lire(avec_str + L"\r\n", 4, 0);
		i = Console_Lire_txt(avec_str + L"\r\n", 4, 0);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintDatedeReprise()                                                                                                                               #
// # const void Film::PrintDatedeReprise()                                                                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintDatedeReprise()
{
	if (affichage_date_de_reprise_actif && date_de_reprise.tm_year != 0)
	{
		wchar_t date_string[22];
		std::wstring wstr;
		wcsftime(date_string, 18, L"%d/%m/%Y", &date_de_reprise);
		wstr = date_string;
		//Console_Lire(keyColor[0] + L"Date de reprise : " + valuesColor + wstr.substr(0, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(6, 4), 0, 19);
		int i = Console_Lire_txt(keyColor[0] + L"Date de reprise : " + valuesColor + wstr.substr(0, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(6, 4), 0, 19);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintDatedeReprise()                                                                                                                               #
// # const void Film::PrintDatedeReprise()                                                                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintDatedeSortie()
{
	if (affichage_date_de_sortie_actif && date_de_sortie.tm_year != 0)
	{
		wchar_t date_string[22];
		std::wstring wstr;
		wcsftime(date_string, 14, L"%d/%m/%Y", &date_de_sortie);
		wstr = date_string;
		//Console_Lire(keyColor[0] + L"Date de sortie : " + valuesColor + wstr.substr(0, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(6, 4), 0, 18);
		int i = Console_Lire_txt(keyColor[0] + L"Date de sortie : " + valuesColor + wstr.substr(0, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(6, 4), 0, 18);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintDate_ou_Dates                                                                                                                                 #
// # const void Film::PrintDate_ou_Dates()                                                                                                              #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const bool Film::PrintDate_ou_Dates()
{
	if (affichage_date_ou_dates_actif && date_ou_dates.size() > 0)
	{
		//std::vector<std::wstring>keyColor{ L"\x1b[94;1m", L"\x1b[38;2;0;255;0m" }; // keyColor[0] (bleu) et keyColor[1] (vert)
		//std::wstring valuesColor = L"\x1b[38;2;255;255;255m"; // Blanc
		std::size_t taille, taille2;
		wchar_t date_string[15];
		taille = std::size(date_ou_dates);
		std::wstring wstr;
		for (int i = 0; i < taille; i++)
		{
			taille2 = std::size(date_ou_dates[i].first);
			if (taille2 == 1)
			{
				wcsftime(date_string, 15, L"%d/%m/%Y", &date_ou_dates[i].first[0].date);
				wstr = date_string;
				wstr = wstr.substr(0, 2) + keyColor[1] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[1] + L'/' + valuesColor + wstr.substr(6, 4);
				if (date_ou_dates[i].second != L"")
					wstr += keyColor[1] + L" : " + valuesColor + date_ou_dates[i].second;
				if (date_ou_dates[i].first[0].someFlag)
					wstr += keyColor[1] + L" (" + valuesColor + L"stop ou pas !" + keyColor[1] + L')' + valuesColor;
				//Console_Lire(wstr + L"\r\n", 4, 4);
				int qqq = Console_Lire_txt(wstr + L"\r\n", 4, 4);
			}
			else
			{
				int j;
				wstr = L"";
				std::wstring wstr2;
				std::size_t pos = 0;
				std::vector<wstring>k(taille2);
				std::tm temp{ 0 };
				int temp2 = 1;
				for (j = 0; j < taille2; j++)
				{
					if (date_ou_dates[i].first[j].date.tm_year == temp.tm_year && date_ou_dates[i].first[j].date.tm_mon == temp.tm_mon && date_ou_dates[i].first[j].date.tm_mday == temp.tm_mday)
						// dates[i].first[j].date == temp : Marche pas !!!
					{
						k[j] = keyColor[1] + L'(' + valuesColor + std::to_wstring(temp2 + 1) + keyColor[1] + L')' + valuesColor;
						if (temp2 == 1)
							k[j - 1] += L' ' + keyColor[1] + L'(' + valuesColor + std::to_wstring(temp2) + keyColor[1] + L')' + valuesColor;
						temp2++;
					}
					else
					{
						wcsftime(date_string, 15, L"%d/%m/%Y", &date_ou_dates[i].first[j].date);
						wstr2 = date_string;
						k[j] = wstr2.substr(0, 2) + keyColor[1] + L'/' + valuesColor + wstr2.substr(3, 2) + keyColor[1] + L'/' + valuesColor + wstr2.substr(6, 4);
						temp.tm_year = date_ou_dates[i].first[j].date.tm_year;
						temp.tm_mon = date_ou_dates[i].first[j].date.tm_mon;
						temp.tm_mday = date_ou_dates[i].first[j].date.tm_mday;
						temp2 = 1;
					}

				}
				wstr2 = L"";
				for (j = 1; j < taille2 - 1; j++)
				{
					pos = k[j].find(L"/");
					if (pos != string::npos)
						k[j] = keyColor[1] + L", " + valuesColor + k[j];
				}
				k.back() = keyColor[1] + L" et " + valuesColor + k.back();
				for (j = 0; j < taille2; j++)
					wstr2 += k[j];
				wstr += wstr2;
				wstr += L' ' + keyColor[1] + L'[' + valuesColor + L"pas-à-pas" + keyColor[1] + L']' + valuesColor;
				if (date_ou_dates[i].first.back().someFlag == true)
					wstr += keyColor[1] + L" (" + valuesColor + L"à suivre" + keyColor[1] + L')' + valuesColor;
				//Console_Lire(wstr + L"\r\n", 4, 4);
				int qqq = Console_Lire_txt(wstr + L"\r\n", 4, 4);
			}
		}
		return true;
	}
	return false;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintDe                                                                                                                                            #
// # const void Film::PrintDe(const std::vector<std::wstring>&de)                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintDe(const std::vector<std::wstring>&de)
{
	if (affichage_de_actif && de.size() > 0)
	{
		std::wstring de_str = keyColor[0] + L"De" + ((de.size() > 1) ? L"s" : L"") + L" : " + valuesColor;
		bool first = true;
		for (auto&& d : de)
		{
			if (!first)
			{
				de_str += keyColor[0] + L", " + valuesColor;
			}
			de_str += d;
			first = false;
		}
		de_str += L"\r\n";

		//PrintStringW(m_hOut, creee_par_str, 0);
		//PrintStringW(HANDLE hOut, creee_par_str);
		//Console_Lire(de_str, 0, 0);
		int i = Console_Lire_txt(de_str, 0, 0);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintDistributeur                                                                                                                                  #
// # const void Film::PrintDistributeur()                                                                                                               #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintDistributeur()
{
	if (affichage_distributeur_actif && distributeur.size() > 0)
	{
		std::wstring distributeur_str = keyColor[0] + L"Distributeur : " + valuesColor + distributeur + L"\r\n";
		//PrintStringW(m_hOut, creee_par_str, 0);
		//PrintStringW(HANDLE hOut, creee_par_str);
		//Console_Lire(distributeur_str, 0, 0);
		int i = Console_Lire_txt(distributeur_str, 0, 0);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const void Film::Print_Header()                                                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintHeader()
{
	if (affichage_titre_actif)
	{
		/*std::wstring titre_str;
		std::wstring wstr;
		bool titre_ = false;
		titre_str = keyColor[0] + L"Titre : " + valuesColor + titre[0];
		if (titre[2] != L"")
			titre_str += keyColor[1] + titre[1] + valuesColor + titre[2];
		if (affichage_date_actif && date.tm_year != 0)
		{
			wchar_t date_string[22];
			wcsftime(date_string, 15, L"%d/%m/%Y", &date);
			wstr = date_string;
			titre_str += keyColor[0] + L" (" + valuesColor + wstr.substr(0, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(6, 4) + keyColor[0] + L')' + valuesColor;
		}
		// Sur
		if (affichage_genres_actif && sur != L"")
			titre_str += keyColor[0] + L" (" + valuesColor + sur + keyColor[0] + L')' + valuesColor;
		// En salle
		else
			titre_str += keyColor[0] + L" (" + valuesColor + L"en salle" + keyColor[0] + L')' + valuesColor;
		// La signalétique jeunesse
		if (affichage_sj_actif && sj.length() != 0)
			titre_str += keyColor[0] + L" (" + valuesColor + sj + keyColor[0] + L')' + valuesColor;
		// Disney+ SJ
		if (affichage_disney_sj_actif && disney_sj.length() != 0)
			titre_str += (keyColor[0] + L" [" + valuesColor + disney_sj + keyColor[0] + L']' + valuesColor);
		// Netflix SJ
		if (affichage_netflix_sj_actif && netflix_sj.length() != 0)
			titre_str += keyColor[0] + L" [" + valuesColor + netflix_sj + keyColor[0] + L']' + valuesColor;
		// Temps
		if (affichage_temps_actif)
		{
			titre_str += L' ';
			if (temps.tm_hour != 0)
			{
				wstr = afficher_Temps_OK();
				titre_str += wstr;
			}
		}
		// Note
		wstr = PrintNote();
		// Prroblème !!!
		//Console_Lire(titre_str + wstr + L"\r\n", 0, 0);
		//
		int i = Console_Lire_txt(titre_str + wstr + L"\r\n", 0, 0);
		*/
		std::wstring titres_str;
		std::wstring date_str;
		std::wstring sur_str;
		std::wstring sj_str;
		std::wstring temps_str;
		std::wstring note_str;

		titres_str = keyColor[0] + L"Titre : " + valuesColor + titre[0];
		if (titre.size() > 1)
			titres_str += keyColor[1] + titre[1] + valuesColor + titre[2];
		// Date
		if (affichage_date_actif)
		{
			//annees_str = format_Annees();
			wchar_t date_string[22];
			wcsftime(date_string, 15, L"%d/%m/%Y", &date);
			std::wstring wstr = date_string;
			date_str = keyColor[0] + L" (" + valuesColor + wstr.substr(0, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(6, 4) + keyColor[0] + L')' + valuesColor;
		}
		// sur
		if (affichage_sur_actif && sur == L"")
			sur_str += keyColor[0] + L" (" + valuesColor + L"en salle" + keyColor[0] + L')' + valuesColor;

		if (affichage_sur_actif && sur != L"" && sur != L"Disney+" && sur != L"Netflix")
		{
			sur_str += keyColor[0] + L" (" + keyColor[1] + L"sur " + valuesColor + sur + keyColor[0] + L')' + valuesColor;
		}
		if (affichage_sur_actif && (sur == L"Disney+" || sur == L"Netflix"))
		{
			sur_str += keyColor[0] + L" (" + keyColor[1] + L"sur " + valuesColor + sur + keyColor[1] + L" : " + valuesColor;
			// Disney+ SJ
			if (affichage_disney_sj_actif && disney_sj.length() != 0)
				sur_str += disney_sj;
			// Netflix SJ
			if (affichage_netflix_sj_actif && netflix_sj.length() != 0)
				sur_str += netflix_sj;
			sur_str += keyColor[0] + L')' + valuesColor;
		}
		else
		{
			// Disney+ SJ
			if (affichage_disney_sj_actif && disney_sj.length() != 0)
				sur_str += keyColor[0] + L" (" + valuesColor + L"Disney+" + keyColor[1] + L" : " + valuesColor + disney_sj + keyColor[0] + L')' + valuesColor;
			// Netflix SJ
			if (affichage_netflix_sj_actif && netflix_sj.length() != 0)
				sur_str += keyColor[0] + L" (" + valuesColor + L"Netflix" + keyColor[1] + L" : " + valuesColor + netflix_sj + keyColor[0] + L')' + valuesColor;
		}
		// La signalétique jeunesse
		if (affichage_sj_actif && sj.length() != 0)
			sj_str += keyColor[0] + L" (" + valuesColor + L"SJ" + keyColor[1] + L" : " + valuesColor + sj + keyColor[0] + L')' + valuesColor;
		if (affichage_temps_actif)
		{
			temps_str += L' ';
			if (temps.tm_hour != 0)
			{
				temps_str += afficher_Temps_OK();
				//titre_str += wstr;
			}
		}
		// Note
		if (affichage_note_actif)
			//note_str += calcul_Note_Affichage();
			note_str += PrintNote();
		//std::wcout << titres_str << date_str << sur_str << sj_str << temps_str << note_str << std::endl;
		int i = Console_Lire_txt(titres_str + date_str + sur_str + sj_str + temps_str + note_str + L"\r\n", 0, 0);
	}

}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintPar                                                                                                                                           #
// # const void Film::PrintPar(const std::vector<std::wstring>&par)                                                                                   #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintPar(const std::vector<std::wstring>&par)
{
	if (affichage_par_actif && par.size() > 0)
	{
		std::wstring par_str = keyColor[0] + L"Par : " + valuesColor;
		bool first = true;
		for (auto&& p : par)
		{
			if (!first)
			{
				par_str += keyColor[0] + L", " + valuesColor;
			}
			par_str += p;
			first = false;
		}
		par_str += L"\r\n";

		//PrintStringW(m_hOut, creee_par_str, 0);
		//PrintStringW(HANDLE hOut, creee_par_str);
		//Console_Lire(par_str, 0, 0);
		int i = Console_Lire_txt(par_str, 0, 0);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintNote                                                                                                                                          #
// # const std::wstring Film::PrintNote()                                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring Film::PrintNote()
{
	if (affichage_note_actif)
	{
		std::wstring note_str;
		if (note != 0.0)
		{
			if (note == -1.0)
				note_str += L' ' + keyColor[0] + L'(' + valuesColor + L"pas de note !" + keyColor[0] + L')' + valuesColor;
			else
			{
				if (note == 0 || note == 1 || note == 2 || note == 3 || note == 4 || note == 5)
					//note_str += L' ' + std::to_wstring(note);
					note_str = L' ' + std::to_wstring(static_cast<int>(std::floor(note)));
				else
				{
					std::wstring wstr = std::to_wstring(note);
					wstr = wstr[0] + keyColor[0] + wstr[1] + valuesColor + wstr[2];
					note_str += L' ' + wstr;
				}
				note_str += keyColor[0] + L"/5" + valuesColor;
			}
		}
		else
		{
			note_str = L' ' + keyColor[0] + L'(' + valuesColor + L"pas de note !" + keyColor[0] + L')' + valuesColor;
		}
		return note_str;
	}
	return L"";
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintSoundtracks                                                                                                                                   #
// # const void Film::PrintSoundtracks()                                                                                                              #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintSoundtracks()
{
	if (affichage_soundtraks_actif && m_soundtrack.size() > 0)
	{
		std::size_t maxKeyLength = 0;
		for (int i = 0; i < m_soundtrack.size(); i++)
		{
			maxKeyLength = max(maxKeyLength, m_soundtrack[i].first.length());
			//maxKeyLength = std::max(maxKeyLength, m_soundtrack[i].first.length()); // Erreur !!!
		}

		//PrintTmp(keyColor + L"Soundtrack :" + valuesColor + L"\r\n");
		Console_Lire(keyColor[0] + L"Soundtrack :" + valuesColor + L"\r\n", 0, 0);

		for (auto&& [role, nom] : m_soundtrack)
		{
			//PrintTmp(keyColor2 + role + std::wstring(maxKeyLength - role.size(), L' ') + L" : " + valuesColor2 + nom + L"\r\n");
		    //Console_Lire(role + keyColor[1] + std::wstring(maxKeyLength - role.size(), L' ') + L" : " + valuesColor + nom + L"\r\n", 4, 0);
			int i = Console_Lire_txt(role + keyColor[1] + std::wstring(maxKeyLength - role.size(), L' ') + L" : " + valuesColor + nom + L"\r\n", 4, 0);
		}
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintTitre                                                                                                                                         #
// # const void Film::PrintTitre()                                                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintTitre()
{
	if (affichage_titre_actif)
	{
		std::wstring titre_str;
		std::wstring wstr;
		bool titre_ = false;
		titre_str = keyColor[0] + L"Titre : " + valuesColor + titre[0];
		if (titre[2] != L"")
			titre_str += keyColor[1] + titre[1] + valuesColor + titre[2];
		if (affichage_date_actif && date.tm_year != 0)
		{
			wchar_t date_string[22];
			wcsftime(date_string, 15, L"%d/%m/%Y", &date);
			wstr = date_string;
			titre_str += keyColor[0] + L" (" + valuesColor + wstr.substr(0, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[0] + L'/' + valuesColor + wstr.substr(6, 4) + keyColor[0] + L')' + valuesColor;
		}
		// Sur
		if (affichage_genres_actif && sur != L"")
			titre_str += keyColor[0] + L" (" + valuesColor + sur + keyColor[0] + L')' + valuesColor;
		// En salle
		else
			titre_str += keyColor[0] + L" (" + valuesColor + L"en salle" + keyColor[0] + L')' + valuesColor;
		// La signalétique jeunesse
		if (affichage_sj_actif && sj.length() != 0)
			titre_str += keyColor[0] + L" (" + valuesColor + sj + keyColor[0] + L')' + valuesColor;
		// Disney+ SJ
		if (affichage_disney_sj_actif && disney_sj.length() != 0)
			titre_str += (keyColor[0] + L" [" + valuesColor + disney_sj + keyColor[0] + L']' + valuesColor);
		// Netflix SJ
		if (affichage_netflix_sj_actif && netflix_sj.length() != 0)
			titre_str += keyColor[0] + L" [" + valuesColor + netflix_sj + keyColor[0] + L']' + valuesColor;
		// Temps
		if (affichage_temps_actif)
		{
			titre_str += L' ';
			if (temps.tm_hour != 0)
			{
				wstr = afficher_Temps_OK();
				titre_str += wstr;
			}
		}
		// Note
		wstr = PrintNote();
		// Prroblème !!!
		//Console_Lire(titre_str + wstr + L"\r\n", 0, 0);
		//
		int i = Console_Lire_txt(titre_str + wstr + L"\r\n", 0, 0);
	}
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintTitre4                                                                                                                                        #
// # const void Film::PrintTitre4()                                                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Film::PrintTitre_sur_4()
{
	if (affichage_titre_actif)
	{
		if (titre.size() == 5)
		{ // Titre[4]
			//Console_Lire(titre[4], 4, 0);
			int i = Console_Lire_txt(titre[4], 4, 0);
			Console_Lire_txt(L"---------- ");
		}
	}
}


