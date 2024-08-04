#pragma once

#define avec_txt_ 1

// serie
#define Serie_afficher_dossier_          0
#define Serie_afficher_fichier_          0
#define Serie_afficher_fichier_2_        0
#define Serie_afficher_AD_               0
//#define Serie_afficher_Avec_             0
#define Serie_afficher_Avec_2_           1
#define Serie_afficher_Chaine_           1
#define Serie_afficher_Chaine_1_         1
#define Serie_afficher_Creee_par_        0       
#define Serie_afficher_Date_             1
#define Serie_afficher_Diffusee_         0
#define Serie_afficher_En_relation_avec_ 0
#define Serie_afficher_Image_            0
#define Serie_afficher_Image_1_          0
#define Serie_afficher_Note_             0
#define Serie_afficher_t123_temps_       0
#define Serie_afficher_Titre_            0
#define Serie_afficher_Titre_1_          0       
#define Serie_afficher_Titre_2_          0
#define Serie_afficher_Titre_3_          0
#define Serie_afficher_Titre_min_        0
#define Serie_afficher_Titre_Original_   0

#define Serie_afficher_X_x_              1

#define Serie_afficher_pas_de_OK_        1
#define Serie_afficher_OK_               1
#define Serie_afficher_OK_Note_          0
#define Serie_afficher_OK_Temps_         0
//#define Serie_afficher_Temps_OK_

#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "film.h"
#include "console.h"
#//include "series.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
//#include <xstring>
#include <string>
//#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
//#include <sstream>
//#include <ctime>
//#include <corecrt_wstring.h>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

//extern Avec2 avec;

extern class Erreur E;
extern class Bug B;

extern const std::vector<std::wstring> Genre;
extern const std::vector<std::wstring> Sur;
extern const std::vector<std::wstring> Sous_Genre;
extern const std::vector<std::wstring> Nationalite;

class Titre;
//class Console;
class Serie
{
	friend class Titre;
public:
	Serie(void);
	~Serie();

	const int afficher_dossier(std::wstring const& t);
	const int afficher_fichier(std::wstring const& t, int const& _T_);
	const int afficher_fichier(int I, std::wstring const& t, int const& _T_);
	void afficher_Chaine(std::wstring&, std::wstring const&, std::wstring&) const;
	void afficher_Creee_par(std::wstring&, std::wstring const&, std::vector<std::wstring>&) const;
	const int afficher_Date(std::wstring d);
	const int afficher_Diffusee(int& I, std::wstring const& d);
	void afficher_En_relation_avec(std::wstring& e, std::wstring const& nomFichier, std::vector<std::wstring>&e_r_a) const;
	const void afficher_Note(std::wstring&, std::wstring const&, int);
	const int afficher_t123_temps(std::vector<std::wstring>&, std::wstring&, std::wstring&, std::wstring&);
	const int afficher_Titre(std::wstring& t, std::wstring const& nomFichier);

	const int afficher_pas_de_OK() const;
	const int afficher(void);
	//const int Ok_S(bool S_Espace, std::wstring S_MIN, std::wstring S_T, std::wstring S_t, std::wstring S_W, std::wstring S_w);
	const int Ok_S(bool S_Espace, std::wstring S_MIN, std::vector<std::wstring> S_keyColor, std::wstring S_valuesColor);

protected:
	//std::wstring ad;// = L"";
	//bool ad_ = true;

private:
	const int afficher_Titre_2(int I, std::wstring t, std::wstring nomFichier);
	const int afficher_Titre_3(int I, std::wstring t, std::wstring nomFichier);
	const int afficher_X_x(int I, int J, std::wstring const& nomFichier, std::wstring& t);

	const std::wstring afficher_OK_Note();
	const bool afficher_Titre_chiffre_et_point_ou_pas(std::wstring&);
    const int afficher_OK_T(std::vector <std::wstring>&, std::wstring&, std::wstring&, bool, int y0, int y1, int y2);
	const std::wstring afficher_OK_Temps(std::wstring& v, std::wstring& S, std::wstring& s);
	const std::wstring afficher_OK_Temps(std::tm& t, std::wstring &S, std::wstring &s);

	//const void PrintGenres(const std::vector<std::wstring>& genres);
	const void PrintAvec(const std::vector<std::pair<std::wstring, std::wstring>> avec);
	const void PrintChaine(const std::wstring& chaine);
	const void PrintCreee_par(const std::vector<std::wstring>&creee_par);
	const void PrintEn_relation_avec(const std::vector<std::wstring>&en_relation_avec);
	const void PrintNote(int, int);
	const void PrintTitre();

	const void PrintHeader();

	std::wstring Ok = L"";
	std::wstring Titre__;// = L"";

	bool S_Espace; // = false ou true;
	std::wstring S_MIN; // = L"min";
	std::vector<std::wstring> keyColor; // keyColor[0] (bleu) et keyColor[1] (vert)
	std::wstring valuesColor; // Blanc

	std::vector<std::wstring> titre{};
	std::vector<std::wstring> titre_original;
	std::wstring chaine{};
	std::tm Temps{ 0 };
	std::vector<std::wstring> genre;
	std::vector<std::wstring> creee_par;
	std::vector<std::wstring> Avec;
	std::vector<std::wstring> Avec_role;
	//int Avec_i = 0;
	std::vector<std::wstring> nationalite;
	std::wstring sur = L"";
	std::wstring sous_genre{};
	std::wstring disney_sj;
	std::wstring netflix_sj;
	std::wstring sj = L"";
	
	std::wstring audiodescription = L"";
	
	std::vector<std::wstring> en_relation_avec;
	double note = 0.0;
	std::vector<std::wstring> image;

	bool chaine_ = true;
	bool Date_ = false, Temps_ = false;
	
	bool affichage_avec_actif = true;
	bool affichage_audiodescription_actif = true;
	bool affichage_creee_par_actif = true;// false;
	bool affichage_disney_sj_actif = true;
	bool affichage_image_actif = true;
	bool affichage_genres_actif = true;
	bool affichage_nationalite_actif = true;
	bool affichage_netflix_sj_actif = true;
	bool affichage_note_actif = true;
	bool affichage_sj_actif = true;
	bool affichage_sous_genre_actif = true;
	bool affichage_sur_actif = true;
	bool affichage_temps_actif = true;
	bool affichage_titre_actif = false;
	bool affichage_titre_original_actif = true;

	bool d_affichage_image_actif = true;

	bool Avec_ = true;//false;//

	bool netflix_ok_ou_non = false;
	bool disney_ok_ou_non = false;

	bool en_relation_avec_ = true;//false;
	//bool Note_ = true;// false;
	bool X_ = false;

	std::wstring Titre_1 = L"";
	bool Titre_1_ = false;

	std::tm Date_X[_X2_][_X_ * 4][_x_] = { 0 };
	std::tm Date_Diffusee_a_partir_de[_X2_] = { 0 };
	bool Date_Diffusee_a_partir_de_[_X2_] = { true };

	std::wstring D[_X2_] = { L"" };
	std::wstring D_Titre[_X2_] = { L"" };
	std::vector<std::wstring> D_titre[_X2_];// = { L"" };
	std::vector<std::wstring> D_t[_X2_][_X_ * 4];// = { L"" };
	//wstring D_s[_X2_][_X_ * 4] = { L"" };
	//std::vector<std::wstring> D_Avec[_X2_];
	//std::vector<std::wstring> D_Avec_role[_X2_];// = { L"" };
	std::wstring d_audiodescription[_X2_] = { L"" };
	std::vector<std::pair<std::wstring, std::wstring>> avec[_X2_];
	std::wstring d_chaine[_X2_] = { L"" };
	std::vector<std::wstring> d_image[_X2_];
	std::vector<std::pair<int, double>> m_note;
	
	int D_I = { 0 };
	int D_J[_X2_] = { 0 };
bool D_J_[_X2_] = { false }; // D_J == D_J_[_X2_]
	int D_K[_X2_][_X_ * 4] = { -1 };
	//wchar_t D_K_[_X2_][_X_ * 4] = { L' ' };
	bool D_K_[_X2_][_X_ * 4] = { false };
	int D_K_d[_X2_][_X_ * 4] = { 0 };

	//bool D_Netflix[_X2_] = { false };
	bool D_DVD[_X2_] = { false };
	bool d_chaine_[_X2_] = { true };
	bool D_Note_[_X2_] = { true };
	bool D_Titre_[_X2_] = { false };

	bool affichage_annees_actif = true;

};


