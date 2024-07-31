#include "pch.h"

#include "console.h"
#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "film.h"
#include "serie.h"
#include "erreur_ok.h"
#include "Bug.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <string>
//#include <algorithm>
#include <vector>
#include <iostream>
//#include <sstream>
//#include <ctime>
#include <codecvt>

#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;

//extern Titre;
//extern const Cinema C;
//extern const Serie S;
extern class Erreur E;
extern class Bug B;

Console::Console()
{
    //vector<wstring>Titre{};
}

Console::~Console()
{
}

void Console::affiche_CleValeur(std::wstring cle, std::wstring valeur)
{
    //PrintStringW(getInstance(), Text_Color + cle + Default_Color + L" : " + Text_Color + valeur + Default_Color + End_Ln);
    return;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintStringW                                                                                                                                       #
// # const void Console::PrintStringW(HANDLE hOut, const std::wstring& str)                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Console::PrintStringW(HANDLE hOut, const std::wstring& str)
{
    DWORD dwMode = 0;

    BOOL res = WriteFile(
        hOut,
        &str[0],
        (DWORD)(str.size() * sizeof(wchar_t)),
        &dwMode,
        NULL);
    assert(res == TRUE);
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintStringW                                                                                                                                       #
// # const void Console::PrintCreee_par(const std::vector<std::wstring>& creee_par, std::wstring titre_T, std::wstring titre_t, bool creee_par_)        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Console::PrintCreee_par(const std::vector<std::wstring>& creee_par, std::wstring titre_T, std::wstring titre_t, bool creee_par_)
{
    if (creee_par_ == true && creee_par.size() > 0)
    {
        std::wstring creee_par_str = titre_T + L"aaaaCréée" + ((creee_par.size() > 1) ? L"s" : L"") + L" par : " + titre_t;
        bool first = true;
        for (auto&& c : creee_par)
        {
            if (!first)
            {
                creee_par_str += titre_T + L", " + titre_t;
            }
            creee_par_str += c;
            first = false;
        }
        creee_par_str += L"\r\n";

        // ???
        //PrintStringW(hOut, creee_par_str);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintNationalites                                                                                                                                  #
// # const void Console::PrintNationalites(const std::vector<std::wstring>& nationalites, bool nationalite_                                             #
// #                                       const std::wstring& sous_genre, bool sous_genre_                                                             #
// #                                       std::wstring& titre_T, std::wstring& titre_t)                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Console::PrintNationalites(const std::vector<std::wstring>& nationalites, bool nationalite_, const std::wstring& sous_genre, bool sous_genre_, std::wstring& titre_T, std::wstring& titre_t)
{
    if (nationalite_ == true && nationalites.size() > 0)
    {
        std::wstring nationalite_str = titre_T + L"Nationalite" + ((nationalites.size() > 1) ? L"s" : L"") + L" : " + titre_t;

        bool first = true;
        for (auto&& nationalite : nationalites)
        {
            if (!first)
            {
                nationalite_str += titre_T + L", " + titre_t;
            }
            nationalite_str += nationalite;
            first = false;
        }
        if (sous_genre_ == true && sous_genre.size() != 0)
            nationalite_str += L' ' + titre_T + L'(' + titre_t + sous_genre + titre_T + L')' + titre_t;
        nationalite_str += L"\r\n";

        //PrintStringW(m_hOut, nationalite_str);
    }
}


// m_ c'est un préfixe pour indiquer que c'est un membre de l'objet, ici un champ plus précisément
// m_hOut : handle de la console

/*void Console::PrintSoundtracks(const std::vector<std::pair<std::wstring, std::wstring>> >& soundtraks)
{
    // à l'arrache, faudrait dégager ces C_x à la con et utiliser des noms de constante CORRECTES
    if (soundtraks.size() > 0)
    {
        PrintStringW(m_hOut, C_T + L"Soundtrack :" + C_t + L"\r\n");
        for (auto&& [role, nom] : soundtraks)
        {
            PrintStringW(m_hOut, C_G + role + L" : " + C_g, 4); //Utilisation d'une version de PrintStringW où l'on ne spécifie que le décalage en x et les C_G/C_g pour "green" (t=>turquoise ? , w=>White?)
            PrintStringW(m_hOut, C_W + nom + C_w + L"\r\n");
        }
    }
}*/