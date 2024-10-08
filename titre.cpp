﻿#include "pch.h"

#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "film.h"
#include "serie.h"
#include "console.h"
#include "erreur_ok.h"
#include "Bug.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <stdlib.h>
//#include <math.h>
//#include <sstream>
//#include <ctime>
#include <codecvt>

#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;

//extern const void afficher_X(int, wstring, wstring);
extern class Erreur E;
extern class Bug B;
//extern const struct Person P;

extern const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs);
extern const std::wstring lire_fichierTxt(std::wstring const& t);

std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace);

const std::vector<std::wstring> Audiodescription =
{ // AD : Audiodescription
    /*L"Allemagne - Audiodescription",
    L"Anglais - Audiodescription",
    L"Espagne - Audiodescription",
    L"Français - Audiodescription",
    L"Hébreu - Audiodescription",
    L"Portugais brésilien - Audiodescription"*/
    L"Allemagne",
    L"Anglais",
    L"Espagne",
    L"Français",
    L"Hébreu",
    L"Portugais brésilien"
};

// Exception des éléments
const std::vector<wchar_t> Exception_des_elements
{
    L'\\',
    L'/',
    L':',
    L'*',
    L'?',
    L'"',
    L'<',
    L'>',
    L'|'
};

const std::vector<std::wstring>Genre
{
    L"Action",
    L"Arts Martiaux",
    L"Animation",
    L"Aventure",
    L"Biopic",
    L"Comédie",
    L"Comédie musicale",
    L"Comédie dramatique",
    L"Concert",
    L"Divers",

    L"Docu-séries",
    L"Documentaire",
    L"Drama",
    L"Drame",
    L"Espionnage",
    L"Epouvante-horreur",
    L"Erotique",
    L"Expérimental",
    L"Famille",
    L"Fantastique",

    L"Guerre",
    L"Judiciaire",
    L"Historique",
    L"Manga",
    L"Musical",
    L"Péplum",
    L"Policier",
    L"Opéra",
    L"Romance",
    L"Science fiction",

    L"Science Fiction",

    L"Show",
    L"Survival",
    L"Thriller",
    L"Western"
};

const std::vector<std::wstring> Langue
{ // Nationalité
    L"Afrique du Sud",
    L"Allemand",
    L"Américain",
    L"Argentin",
    L"Australien",
    L"Autrichien",
    L"Belge",
    L"Brésilien",
    L"Britannique",
    L"Canadien",
    L"Chilien",
    L"Chinois",
    L"Corée du Sud", //L"Sud du Coréen"
    L"Danois",
    L"Egypte",
    L"Espagnol",
    L"Français",
    L"Français - CC",
    L"Grec",
    L"Hongrois",
    L"Indien",
    L"Irlandais",
    L"Italien",
    L"Japonais",
    L"Néerlandais",
    L"Norvégien",
    L"Polonais",
    L"Québecois",
    L"Suédois",
    L"Suisse"
};

const std::vector<std::wstring> Nationalite
{
    L"Afrique du Sud",
    L"Allemagne",
    L"Argentine",
    L"Australie",
    L"Barbade",
    L"Belgique",
    L"Brésil",
    L"Canada",
    L"Chili",
    L"Chine",
    L"Corée du Sud",
    L"Danemark",
    L"Danoise",
    L"Egypte",
    L"Espagne",
    L"Finlande",
    L"France",
    L"Grande-Bretagne",
    L"Hong-Kong",
    L"Inde",
    L"Indonésie",
    L"Irlande",
    L"Islande",
    L"Israël",
    L"Italie",
    L"Japon",
    L"Jordanie",
    L"Luxembourg",
    L"Mexique",
    L"Nigéria",
    L"Norvège",
    L"Pays-Bas",    L"Philippines",
    L"Pologne",
    L"République Tchèque",
    L"Russie",
    L"Samoa",
    L"Suède",
    L"Thaïlande",
    L"Turquie",
    L"Ukraine",
    L"U.S.A."
};

const std::vector<std::wstring> Sous_Genre
{
    L"Animation",
    L"Documentaire",
    L"Docu-séries",
    L"Manga",
    L"Mini-série"
};

const std::vector<std::wstring> Soundtrack
{
    L"Compositeur",
    L"Compositeur (chansons du film)",
    L"Montage musical",
    L"Superviseur musical"
};

const std::vector<std::wstring> Sur
{
    L"Apple TV+",
    L"Amazon Prime Video",
    L"Crunchyroll",
    L"Disney+",
    L"DVD",
    L"Max",
    L"Netflix",
    L"SⱯLTO",
    L"VOD"
};


const wchar_t* A[] =
{
    L"_", // Canada
    L"___" // Film ou Séries 
};

const std::vector<std::wstring> AZERTYUIOP =
{
    L"#", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"T\\The ( )",L"U", L"V", L"W", L"X", L"Y", L"Z"
};

// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////

//const Titre titre;

Titre::Titre()
{
    //vector<wstring>Titre{};
}

Titre::~Titre()
{
}

/*void afficher_contenu_formate(std::wstring const& nomFichier, std::wstring prefixe, std::vector<std::wstring> separateurs)
{
    std::vector<std::wstring> liste_a_afficher = lire_fichierTxt(nomFichier, separateurs);

    //....(partie qui affiche les données en utilisant le paramètre "prefixe" pour l'afficher avant la liste récupérée)
}
*/



///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

