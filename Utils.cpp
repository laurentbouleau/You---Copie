#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include "pch.h"

#include "Utils.h"
#include "titre.h"
#include "You.h"
#include "you_txt.h"
#include "film.h"
#include "serie.h"
#include "erreur_ok.h"
#include "Bug.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <regex>
#include <iostream>
//#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;

extern const std::vector<std::wstring> AZERTYUIOP;

extern class Erreur E;
extern class Bug B;

//extern const std::vector<std::wstring> Audiodescription;

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # wstr_to_u8                                                                                                                                         #
// # std::string wstr_to_u8(std::wstring uneWString)                                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

std::string wstr_to_u8(std::wstring uneWString)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(uneWString);
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # lire_fichierTxt                                                                                                                                    #
// # const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs)                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs)
{
    std::string contenuFichier{ u8"" };
    std::string ligneCourante{ u8"" };
    std::vector<std::wstring> retVal{};

    ifstream fichier{ nomFichier };
    if (!fichier)
    {
        throw std::runtime_error("Fichier impossible à ouvrir.");
    }

    while (getline(fichier, ligneCourante, u8'\n'))
    {
        contenuFichier += ligneCourante + u8'\n';
    }

    if (contenuFichier == u8"")
    {
        throw std::runtime_error("Le fichier '" + wstr_to_u8(nomFichier) + "' est vide.");
    }
    //wstring_convert<codecvt_utf8_utf16<wchar_t>, wchar_t> convertiseur;
    
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> convertiseur;
    std::wstring converti = convertiseur.from_bytes(contenuFichier);
    rtrim(converti);

    bool found = false;

    do
    {
        found = false;
        size_t pos_found = std::string::npos;
        std::wstring sep_found = L"";

        for (auto&& sep : separeteurs)
        {
            std::size_t pos = converti.find(sep);
            if (pos != std::wstring::npos && (!found || pos_found > pos))
            {
                pos_found = pos;
                found = true;
                sep_found = sep;
            }
        }

        if (found)
        {
            retVal.push_back(converti.substr(0, pos_found));
            converti = converti.substr(pos_found + sep_found.length());
        }
    } while (found);

    if (converti.length() > 0)
    {
        retVal.push_back(converti);
    }

    //std::vector<std::wstring>::iterator iter;
    //for (iter = retVal.begin(); iter != retVal.end(); iter++)
    //    std::wcout << L"iter={" << *iter << L'}' << std::endl;
    return retVal;
}

//
//
//
/*const std::vector<std::pair<std::wstring, std::wstring>>lire_paireCleValeur_depuisFichierTxt(std::wstring const& nomFichier, std::wstring separeteur)
{
    std::string contenuFichier{ u8"" };
    std::string ligneCourante{ u8"" };
    std::vector<std::pair<std::wstring, std::wstring>> clevaleurs{};
    std::vector<std::wstring> items{};

    ifstream fichier{ nomFichier };
    if (!fichier)
    {
        throw std::runtime_error("Fichier impossible à ouvrir.");
    }

    while (getline(fichier, ligneCourante, u8'\n'))
    {
        contenuFichier += ligneCourante + u8'\n';
    }

    if (contenuFichier == u8"")
    {
        throw std::runtime_error("Le fichier '" + wstr_to_u8(nomFichier) + "' est vide.");
    }

    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> convertiseur;
    std::wstring converti = convertiseur.from_bytes(contenuFichier);
    rtrim(converti);

    bool found = false;

    do
    {
        found = false;
        size_t pos_found = std::string::npos;
        std::wstring sep_found = L"";

        for (auto&& sep : separeteur)
        {
            std::size_t pos = converti.find(sep);
            if (pos != std::wstring::npos && (!found || pos_found > pos))
            {
                pos_found = pos;
                found = true;
                sep_found = sep;
            }
        }

        if (found)
        {
            items.push_back(converti.substr(0, pos_found));
            converti = converti.substr(pos_found + sep_found.length());
        }
    } while (found);

    if (converti.length() > 0)
    {
        items.push_back(converti);
    }

    if (items.size() % 2 != 0)
    {
        throw std::runtime_error("Le fichier '" + wstr_to_u8(nomFichier) + "' contient un nombre impair d'élément.");
    }

    for (int i = 0; i < items.size(); i += 2)
    {
        clevaleurs.push_back(std::make_pair(items[i], items[i + 1]));
    }

    return clevaleurs;
}*/
const std::vector<std::pair<std::wstring, std::wstring>>lire_paireCleValeur_depuisFichierTxt(std::wstring const& nomFichier, std::wstring separeteur)
{
    std::string contenuFichier{ u8"" };
    std::string ligneCourante{ u8"" };
    std::vector<std::pair<std::wstring, std::wstring>> clevaleurs;

    ifstream fichier{ nomFichier };
    if (!fichier)
    {
        throw std::runtime_error("Fichier impossible à ouvrir.");
    }

    while (getline(fichier, ligneCourante, u8'\n'))
    {
        contenuFichier += ligneCourante + u8'\n';
    }

    if (contenuFichier == u8"")
    {
        throw std::runtime_error("Le fichier '" + wstr_to_u8(nomFichier) + "' est vide.");
    }
    //wstring_convert<codecvt_utf8_utf16<wchar_t>, wchar_t> convertiseur;

    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> convertiseur;
    std::wstring converti = convertiseur.from_bytes(contenuFichier);
    rtrim(converti);
    converti += L"\n";

    //std::wcout << L"lire_paireCleValeur_depuisFichierTxt" << std::endl;
    //std::wcout << L"converti{" << converti << L"}" << L"\n" << std::endl;
    std::size_t pos = converti.length();

    if (pos == std::wstring::npos)
        return clevaleurs;

    std::size_t pos2 = 0;
    while (pos = converti.find(L"\n"))
    {
        if (converti[0] != converti.length())
        {
            pos2 = converti.find(L"...");
            if (pos2 != std::wstring::npos && converti[0] == L'.' && converti[1] == L'.' && converti[2] == L'.')
            {
                //std::wcout << L"aaa" << std::endl;
                clevaleurs.push_back(std::make_pair(L"…", L""));
                return clevaleurs;
            }
            pos2 = converti.find(L"…");
            if (pos2 != std::wstring::npos && converti[0] == L'…')
            {
                //std::wcout << L"bbb" << std::endl;
                clevaleurs.push_back(std::make_pair(L"…", L""));
                return clevaleurs;
            }
            pos2 = converti.find(L".");
            if (pos2 != std::wstring::npos && converti[0] == L'…')
            {
                //std::wcout << L"ccc" << std::endl;
                clevaleurs.push_back(std::make_pair(L"…", L""));
                return clevaleurs;
            }
            pos2 = converti.find(separeteur);
            if (pos2 == std::wstring::npos && pos != std::wstring::npos)
            {
                //std::wcout << L"ddd" << std::endl;
                clevaleurs.push_back(std::make_pair(converti.substr(0, pos - 1), L""));
            }
            else if (pos2 == 0)
            {
                //std::wcout << L"eee" << std::endl;
                clevaleurs.push_back(std::make_pair(L"", converti.substr(3, (pos - 1) - 2)));
            }
            else if (pos > pos2)
            {
                //std::wcout << L"eee" << std::endl;
                //std::wcout << converti.substr(0, pos2) << separeteur << converti.substr(pos2 + 3, pos - (pos2 + 3)) << std::endl;
                clevaleurs.push_back(std::make_pair(converti.substr(0, pos2), converti.substr(pos2 + 3, pos - (pos2 + 3))));
            }
            else
            {
                //std::wcout << L"fff" << std::endl;
                break;
            }
            converti = converti.substr(pos + 1);
            //std::wcout << L"ggg" << std::endl;

        }
        else
            break;
    }
    /*std::vector<std::pair<std::wstring, std::wstring>> clevaleurs{};
    std::vector<std::wstring> items = lire_fichierTxt(nomFichier, { separeteur });

    if (items.size() % 2 != 0)
    {
        throw std::runtime_error("Le fichier '" + wstr_to_u8(nomFichier) + "' contient un nombre impair d'élément.");
    }

    for (int i = 0; i < items.size(); i += 2)
    {
        clevaleurs.push_back(std::make_pair(items[i], items[i + 1]));
    }*/

    return clevaleurs;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # lire_fichierTxt                                                                                                                                    #
// # const std::wstring lire_fichierTxt(std::wstring const& nomFichier)                                                                                 #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring lire_fichierTxt(std::wstring const& nomFichier)
{
    std::string contenuFichier{ u8"" };
    std::string ligneCourante{ u8"" };
    ifstream fichier{ nomFichier };
    if (!fichier)
    {
        throw std::runtime_error("Fichier impossible à ouvrir.");
    }

    while (getline(fichier, ligneCourante, u8'\n'))
    {
        contenuFichier += ligneCourante + u8'\n';
    }

    if (contenuFichier == u8"")
    {
        return L"";
        //throw std::runtime_error("Le fichier '" + wstr_to_u8(nomFichier) + "' est vide.");
    }
    //wstring_convert<codecvt_utf8_utf16<wchar_t>, wchar_t> convertiseur;
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> convertiseur;
    std::wstring converti = convertiseur.from_bytes(contenuFichier);
    rtrim(converti);
    return converti;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const bool afficher_Path_Exists(wstring& t)                                                                                                        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const bool afficher_Path_Exists(std::wstring& t)
{
#if afficher_Path_Exists_ == 1
    //wcout << L"::afficher_Path_Exists(" << t << L')' << endl;
    B.Ok_T(L"const bool afficher_Path_Exists(" + t + L") :");
#endif
    path p{ t };
    if (exists(p) == false)
    {
#if afficher_Path_Exists_ == 1
        //wcout << L"::afficher_Path_Exists(" << t << L") : Érreur" << endl;
        B.Ok_W(L"exists={false}");
#endif
        return false;
    }
#if afficher_Path_Exists_ == 1
    //wcout << L"::afficher_Path_Exists(" << t << L") : Ok !" << endl;
    B.Ok_W(L"exists={true}");
    B.Ok_T(L"const bool afficher_Path_Exists() : Ok !");
#endif
    return true;
}

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Audiodescription                                                                                                                          #
// # const void afficher_Audiodescription(std::wstring& a_filename, std::wstring const& nomFichier, std::wstring& audiodescription)                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################


const void afficher_Audiodescription(std::wstring& a_filename, std::wstring const& nomFichier, std::wstring& ad)
{
    assert((a_filename == createdBy_filename) && L"Erreur !!! Audiodescription (AD)... !");
    std::wstring a = lire_fichierTxt(nomFichier);
    std::size_t pos = a.find(L"Audiodescription");
    if (pos == std::wstring::npos)
        ;
    else
        a = a.substr(0, pos - 3);
    if (std::find(::Audiodescription.begin(), ::Audiodescription.end(), a) != ::Audiodescription.end())
        ad = a;
    assert((ad.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Avec                                                                                                                                               #
// # const int afficher_Avec(wstring a, wstring _T, vector<wstring>& Avec, vector<wstring>& Avec_role)                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Avec(std::wstring& a_filename, std::wstring const& nomFichier, std::vector<std::wstring>& Avec, std::vector<std::wstring>& Avec_role)
{
#if afficher_Avec_ == 1
    B.Ok_T(L"const int afficher_Avec(" + a_filename + L", " + nomFichier + L", std::vector<std::wstring>&Avec, std::vector<std::wstring>&Avec_role) :");
#endif

    assert((a_filename == createdBy_filename) && L"Erreur !!! Avec... !");
    std::vector<std::wstring>a = lire_fichierTxt(nomFichier, { L"\n" });
    assert((a.size() != 0));

    std::size_t pos;
    //pos = a_filename.length();
    std::vector<std::wstring>::iterator iter;// , iter2;
    for (iter = a.begin(); iter != a.end(); iter++)
    {
        *iter = replace_all(*iter, L",", L" -");
        *iter = replace_all(*iter, L"(", L"[");
        *iter = replace_all(*iter, L")", L"]");
    }
    for (iter = a.begin(); iter != a.end(); iter++)
    {
        if (*iter == L"…" || *iter == L"..." || *iter == L".")
            // … ou ... ou .
        {
            Avec.push_back(L"…");
            Avec_role.push_back(L"");
            break;
        }
        //
        pos = (*iter).find(L" : ");
        if (pos == std::wstring::npos)
            // Avec={XXX} et Avec_role={}
        {
            //std::wcout << L"Avec={" << *iter << L"} Avec_role{}" << std::endl;
            Avec.push_back(*iter);
            Avec_role.push_back(L"");
        }
        else if (pos == 0)
            // Avec={} et Avec_role={XXX}
        {
            //std::wcout << L"Avec={} Avec_role={" << (*iter).substr(3) << L"}" << std::endl;
            Avec.push_back(L"");
            Avec_role.push_back((*iter).substr(3));
        }
        else if (pos > 0)
            // Avec={XXX} et Avec_role={YYY}
        {
            //std::wcout << L"Avec={" << (*iter).substr(0, pos) << L"} Avec_role={" << (*iter).substr(pos + 3) << L"}" << std::endl;
            Avec.push_back((*iter).substr(0, pos));
            Avec_role.push_back((*iter).substr(pos + 3));
        }
        else
        {
            //std::wcout << L"Attention : {" << *iter << L'}' << std::endl;
        }
    }
#if afficher_Avec_ == 1
    B.Ok_T(L"const int afficher_Avec() : Ok !");
#endif
    return;
}

const void afficher_Avec(std::wstring& a_filename, const std::wstring& nomFichier, std::vector<std::pair<std::wstring, std::wstring>>& avec)
{
    assert((a_filename == createdBy_filename) && L"Erreur !!! Avec... !");
    //par = lire_fichierTxt(nomFichier, { L"\n", L", " });

    //std::vector<std::wstring> qqq = lire_fichierTxt(nomFichier, { L"\n", L", " });
    //std::wcout << L"avec :" << std::endl;
    avec = lire_paireCleValeur_depuisFichierTxt(nomFichier, L" : ");
    //std::wcout << L"avec : ok !" << std::endl;
    assert((avec.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int afficher_Disney_SJ(std::wstring& d, std::wstring const& _T, std::wstring& D_SJ)                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Disney_SJ(std::wstring& d, std::wstring const& nomFichier, std::wstring& d_sj)
{ // Netflix SJ : Catégorie d'âge
    assert((d == createdBy_filename) && L"Erreur !!! Disney+ SJ... !");
    d = lire_fichierTxt(nomFichier);
    try
    {
        if (d == L"6+" || d == L"12+" || d == L"14+" || d == L"16+" || d == L"18+" )//|| d == L"Tous publics")
        {
            d_sj = d;
        }
    }
    catch (runtime_error const& exception)
    {
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Genre                                                                                                                                     #
// # const void afficher_Genre(std::wstring& genre_filename,                                                                                            #
// #                           std::wstring const& nomFichier, std::vector<std::wstring>& genres_renvoyes,                                              #
// #                           const std::vector<std::wstring>&                                                                                         #
// #                           genres_valides)                                                                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Genre(std::wstring& genre_filename, std::wstring const& nomFichier, std::vector<std::wstring>& genres_renvoyes, const std::vector<std::wstring>& genres_valides)
{ // Genre
    assert((genre_filename == createdBy_filename) && L"Erreur Genre(s) !!!");
    std::vector<std::wstring>g;
    g = lire_fichierTxt(nomFichier, { L"\n", L", " });
    for (auto&& genre : g)
    {
        if (std::find(genres_valides.begin(), genres_valides.end(), genre) != genres_valides.end())
            genres_renvoyes.push_back(genre);
        else
        {
            assert((false) && "Attention genre non valide !!!");
        }
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Image                                                                                                                                              #
// # voit afficher_Image(wconst std::wstring& nomFichier, std::vector<std::wstring>& images)                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Image(const std::wstring& nomFichier, std::vector<std::wstring>& images)
{
    std::size_t pos_txt = nomFichier.find_last_of(L"\\");
#if afficher_Image_ == true
    B.Ok_T(L"const int Serie::afficher_Image(" + nomFichier + L") :");
    //B.Ok_W(L"Image={" + i + L'}');
#endif
    assert((pos_txt != std::wstring::npos) && L"Erreur Image(s) !!!");
    pos_txt++;
    images.push_back(nomFichier.substr(pos_txt));

    //std::wcout << L"image={" << nomFichier << L"}" << std::endl;
#if afficher_Image_ == true
    //wcout << B_T << L"const int Serie::afficher_Image(" << i << L") : Ok !" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_Image() : Ok !");
#endif
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const bool afficher_Min(wstring& t)                                                                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const bool afficher_Min(std::wstring& t)
{
#if afficher_Min_ == 1
    //wcout << B_T << L"const bool ::afficher_Min(" << t << L") :" << B_t << endl;
    B.Ok_T(L"const bool ::afficher_Min(" + t + L") :");
#endif
    if (
        //(t[0] == L'M' && t[1] == wstring::npos)
        //||
        //(t[0] == L'm' && t[1] == wstring::npos)
        //||
        (t[0] == L'M' && t[1] == L'I' && t[2] == L'N' /* && t[3] == wstring::npos*/)
        ||
        (t[0] == L'M' && t[1] == L'i' && t[2] == L'n' /* && t[3] == wstring::npos*/)
        ||
        (t[0] == L'm' && t[1] == L'i' && t[2] == L'n' /* && t[3] == wstring::npos*/)
        )
    {
#if afficher_Min_ == 1
        //wcout << L"    " << L"Min={" << true << L'}' << endl;
        B.Ok_W(L"Min={true}");
#endif
    }
    else
    {
#if afficher_Min_ == 1
        //wcout << L"    " << L"Min={" << false << L'}' << endl;
        B.Ok_W(L"Min={false}");
#endif
        return false;
    }
#if afficher_Min_ == 1
    //wcout << B_T << L"const bool ::afficher_Min() : Ok !" << B_t << endl;
    B.Ok_T(L"const bool ::afficher_Min() : Ok !");
#endif
    return true;
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Nationalite                                                                                                                               #
// # const void afficher_Nationalite(std::wstring& nationalite_filename,                                                                                #
// #                                 std::wstring const& nomFichier,                                                                                    #
// #                                 std::vector<std::wstring>& nationalites_renvoyes,                                                                  #
// #                                 const std::vector<std::wstring>& nationalites_valides)                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Nationalite(std::wstring& nationalite_filename,
    std::wstring const& nomFichier,
    std::vector<std::wstring>& nationalites_renvoyes,
    const std::vector<std::wstring>& nationalites_valides)
{ // Nationalite
    std::size_t pos_txt = nationalite_filename.find(L".txt");
    assert((pos_txt != std::wstring::npos) && L"Erreur Nationalite(s) !!!");
    //std::wstring radical = nationalite_filename.substr(0, pos_txt);
    std::vector<std::wstring>n;
    n = lire_fichierTxt(nomFichier, { L"\n", L", " });
    for (auto&& nationalite : n)
    {
        if (std::find(nationalites_valides.begin(), nationalites_valides.end(), nationalite) != nationalites_valides.end())
            nationalites_renvoyes.push_back(nationalite);
        else
        {
            assert((false) && "Attention nationalite non valide !!!");
        }
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int afficher_Netflix_SJ(std::wstring& n, std::wstring const& _T, std::wstring& N_SJ)                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Netflix_SJ(std::wstring& n, std::wstring const& nomFichier, std::wstring& n_sj)
{ // Netflix SJ : Catégorie d'âge
#if	afficher_Netflix_SJ_ == 1
    //wcout << B_T << L"const int afficher_Netflix(" << n << L", wstring _T, " << N_SJ << L") :" << B_t << endl;
    B.Ok_T(L"const void afficher_Netflix_SJ(" + n + L", " + nomFichier + L", wstring &n_sj) :");
#endif
    assert((n == createdBy_filename) && L"Erreur !!! Netflix SJ... !");
    n = lire_fichierTxt(nomFichier);
    try
    {
        if (n == L"7+" || n == L"10+" || n == L"13+" || n == L"16+" || n == L"18+" || n == L"Tous publics")
        {
#if	afficher_Netflix_SJ_ == 1
            //wcout << L"    " << L"Netflix={" << n << L'}' << endl;
            B.Ok_W(L"netflix={" + n + L'}');
#endif
            n_sj = n;
        }
    }
    catch (runtime_error const& exception)
    {
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
#if	afficher_Netflix_SJ_ == 1
    //wcout << B_T << L"const int afficher_Netflix( , , " << N_SJ << L") : Ok !" << B_t << endl;
    B.Ok_T(L"const void afficher_Netflix_SJ() : Ok !");
#endif
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # SJ                                                       #
// #                                                                                                                                                    #
// ######################################################################################################################################################
// Cinéma et serie
const void afficher_SJ(std::wstring& s, const std::wstring& nomFichier, std::wstring& sj)
{ // SJ
    assert((s == createdBy_filename) && L"Erreur !!! SJ... !");
    s = lire_fichierTxt(nomFichier);
    try
    {
        if (s == L"-7" || s == L"-10" || s == L"-12" || s == L"-16" || s == L"-18")
            sj = s;
    }
    catch (runtime_error const& exception)
    {
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int afficher_Sous_Genre(std::wstring& s_g)                                                                                                   #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int afficher_Sous_Genre(std::wstring& s_g)
{ // Sous_Genre
#if afficher_Sous_Genre_ == 1
    B.Ok_T(L"const int afficher_Sous_Genre(" + s_g + L") :");
#endif
    bool s_g_ = false;
    if (std::find(::Sous_Genre.begin(), ::Sous_Genre.end(), s_g) != ::Sous_Genre.end())
        s_g_ = true;
    else
    {
#if afficher_Sous_Genre_ == 1
        //wcout << L"    " << L"Mm=[" << mm << L"] érreur !!!" << endl;
        //wcout << B_T << L"const wstring afficher_Mm(" << mm << L", " << Mm << L") : érreur !!!" << B_t << endl;
        B.Ok_W(L"Sous_Genre={" + s_g + L"} erreur !!!");
#endif
        E.afficher_X(-1, s_g, s_g + L" erreur (" + s_g + L") !!!");
        return EXIT_FAILURE;
    }
#if afficher_Sous_Genre_ == 1
    B.Ok_W(L"sous_genre={" + s_g + L'}');
#endif
    B.Ok_T(L"const int afficher_Sous_Genre() : Ok !");
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Sur                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Sur(std::wstring& s)
{ // Sur
#if afficher_Sur_ == 1
    //wcout << B_T << L"const wstring ::afficher_Sur(" << s << L") :" << B_t << endl;
    B.Ok_T(L"const int afficher_Sur(" + s + L") :");
#endif
    bool sur = false;
    if (std::find(::Sur.begin(), ::Sur.end(), s) != ::Sur.end())
    {
        sur = true;
        // netflix_ok_ou_non
    }
    else
    {
#if afficher_Sur_ == 1
        //wcout << L"    " << L"Sur={" << s << L"} érreur !!!" << endl;
        B.Ok_W(L"Sur={" + s + L"} erreur !!!");
        //wcout << L"    " << L"const wstring ::afficher_Sur(" << s << L", " << sur << L") : Érreur !!!" << endl;
        B.Ok_T(L"const int afficher_Sur() : Erreur !!!");
#endif
        E.afficher_X(-1, s, s + L" erreur (" + s + L") !!!");
        return;
    }
#if afficher_Sur_ == 1
    //wcout << L"    " << L"Sur={" << s << L'}' << endl;
    B.Ok_W(L"sur={" + s + L'}');
    //wcout << B_T << L"const wstring ::afficher_Sur() : Ok !" << B_t << endl;
    B.Ok_T(L"const int afficher_Sur() : Ok !");
#endif
    return;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int afficher_T123(wstring t, wstring& t1, wstring& t2, wstring& t3)                                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int afficher_T123(std::wstring t, std::wstring& t1, std::wstring& t2, std::wstring& t3)
{
#if afficher_T123_ == 1
    B.Ok_T(L"const int afficher_T123(" + t + L", std::wstring& t1, std::wstring& t2, std::wstring& t3) :");
#endif
    std::size_t pos;
    bool t_ = false;





    //if(t != L"" &&)
    pos = t.find(L" - ");
    if (pos != std::wstring::npos && t_ == false)
    {
        t1 = t.substr(0, pos);
        t2 = L" : ";
        t3 = t.substr(pos + 3);
        t_ = true;
    }
    pos = t.find(L" : ");
    if (pos != std::wstring::npos && t_ == false)
    {
        t1 = t.substr(0, pos);
        t2 = L" : ";
        t3 = t.substr(pos + 3);
        t_ = true;
    }
    pos = t.find(L": ");
    if (pos != std::wstring::npos && t_ == false)
    {
        t1 = t.substr(0, pos);
        t2 = L": ";
        t3 = t.substr(pos + 2);
        t_ = true;
    }
    pos = t.find(L'/');
    if (pos != std::wstring::npos && t_ == false)
    {
        t1 = t.substr(0, pos);
        t2 = L"/";
        t3 = t.substr(pos + 1);
        t_ = true;
    }
    if (pos == std::wstring::npos && t_ == false)
    {
        //wcout << L"t={" << t << L'}' << endl;
        t1 = t;
        t2 = L"";
        t3 = L"";
        t_ = true;
        //wcout << L"[...] ok !" << endl;
    }
    if (t_ == false)
    {
#if afficher_T123_ == 1
        B.Ok_W(L"t123_=={false} : Erreur (" + t + L") !!!");
#endif
        E.afficher_X(-1, L"t123_=={false}", L"Erreur (" + t + L") !!!");
        return EXIT_FAILURE;
    }
#if afficher_T123_ == 1
    B.Ok_W(L"t123_=={true} !");
    B.Ok_T(L"const int ::afficher_T123() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Temps                                                                                                                                     #
// # const bool afficher_Temps(wstring T)                                                                                                               #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const bool afficher_Temps(std::wstring ttt)
// "_h__min" ou "_h __min" ou "_ h __ min" ou "__min" ou "___min" ou "__ min" ou "___ min"
{
    static const basic_string <char>::size_type npos = -1;
    std::wstring t = ttt;
    std::size_t length = t.length();
    bool h = false;
    bool ok = false;
    bool w1 = false;
    // 1
    if (t[0] == npos)
        return false;
    if (std::isdigit(t[0]))
        w1 = true; // oui w1
    else
        return false;
    // 2
    t = t.substr(1);
    if (t[0] == std::wstring::npos)
        return false;
    bool w2 = false;
    bool espace1 = false;
    if (!ok)
    {
        if (w1 && afficher_Min(t))
            return true; // "_min"
        if (w1 && !espace1 && t[0] == L' ')
            espace1 = true;
        if (w1 && !w2 && std::isdigit(t[0]))
            w2 = true; // Oui w2
        if (w1 && !h && (t[0] == L'h' || t[0] == L'H'))
            h = true;
        if (w1 && (!espace1 && t[0] == L' '))
            espace1 = true;
    }
    // 3
    t = t.substr(1);
    if (t[0] == std::wstring::npos)
        return false;
    bool w3 = false;
    if (!ok)
    {
        if (w1 && espace1 && !w2 && afficher_Min(t))
            return true;
        if (w1 == true && w2 == true && afficher_Min(t))
            return true;
        if (w1 && w2 && (!espace1 && t[0] == L' '))
            espace1 = true;
        if (w1 && w2 && !w3 && std::isdigit(t[0]))
            w3 = true;
        if (w1 && h && std::isdigit(t[0]))
            w3 = true;
        if (w1 && h && (!espace1 && t[0] == L' '))
            espace1 = true;
        if (w1 && espace1 && !h && (t[0] == L'h' || t[0] == L'H'))
            h = true;
    }
    // 4
    t = t.substr(1);
    if (t[0] == std::wstring::npos)
        return false;
    bool w4 = false;
    bool espace2 = false;
    if (!ok)
    {
        if (w1 && w2 && espace1 && !w3 && afficher_Min(t))
            return true;
        if (w1 && w2 && w3 && afficher_Min(t))
        {
            if (ttt[0] == L'1')
                return true;
            else
                return false;
        }
        if (w1 && w2 && w3 && (!espace1 && t[0] == L' '))
            espace1 = true;
        if (w1 && h && w3 && std::isdigit(t[0]))
            w4 = true;
        if (w1 && h && espace1 && !w4 && std::isdigit(t[0]))
            w4 = true;
        if (w1 && espace1 && h && (!espace2 && t[0] == L' '))
            espace2 = true;
    }
    // 5
    t = t.substr(1);
    if (t[0] == std::wstring::npos)
        return false;
    bool w5 = false;
 
    if (!ok)
    {
        if (w1 && w2 && w3 && espace1 && afficher_Min(t))
        {
            if (ttt[0] == L'1')
                return true;
            else
                return false;
        }
        if (w1 == true && h == true && w3 == true && w4 == true && afficher_Min(t))
        {
            if (ttt[2] == L'6' || ttt[2] == L'7' || ttt[2] == L'8' || ttt[2] == L'9')
                return false;
            else
                return true;
        }
        if (w1 == true && h == true && espace1 == true && w4 == true && w5 == false && std::isdigit(t[0]))
            w5 = true;
        if (w1 == true && espace1 == true && h == true && espace2 == true && w5 == false && std::isdigit(t[0]))
            w5 = true;
    }
    // 6
    t = t.substr(1);
    if (t[0] == std::wstring::npos)
        return false;
    bool w6 = false;
    if (!ok)
    {
        if (w1 && h && espace1 && w4 && w5 && afficher_Min(t))
        {
            if (ttt[3] == L'6' || ttt[3] == L'7' || ttt[3] == L'8' || ttt[3] == L'9')
                return false;
            else
                return true;
        }
        if (w1 && espace1 && h && espace2 && w5 && !w6 && std::isdigit(t[0]))
            w6 = true;
    }
    // 7
    t = t.substr(1);
    if (t[0] == std::wstring::npos)
        return false;
    bool espace3 = false;
    if (!ok)
    {
        if (w1 && espace1 && h && espace2 && w5 && w6 && (!espace3 && t[0] == L' '))
            espace3 = true;
    }
    // 8
    t = t.substr(1);
    if (!ok)
    {
        if (w1 && espace1 && h && espace2 && w5 && w6 && espace3 && afficher_Min(t))
        {
            if (ttt[4] == L'6' || ttt[4] == L'7' || ttt[4] == L'8' || ttt[4] == L'9')
                return false;
            else
                return true;
        }
    }
    return false;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int afficher_Temps(wstring t, tm& Temps)                                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int afficher_Temps(std::wstring t, std::tm& Temps)
// "_h __min.txt" ou "_h __min" (afficher_Date_1())
{
    //tm Temps;
#if afficher_Temps_1_ == 1
    //wcout << B_T << L"const int ::afficher_Temps(" << t << L", tm& Temps) :" << B_t << endl;
    B.Ok_T(L"const int ::afficher_Temps(" + t + L", tm& Temps) :");
#endif
    std::size_t pos;
    static const basic_string <wchar_t>::size_type npos = -1;
    //pos = t.length();
    //if (t[8] == L'.' && t[9] == L't' && t[10] == L'x' && t[11] == L't')
    //    t = t.substr(0, pos - 4);
    pos = t.find(L".txt");
    if (pos != npos)
        t = t.substr(0, pos);
    bool t_ = afficher_Temps(t);
    if (t_ == true)
        ;
    else
        return 0;
    int heu = 0, min = 0;
    if (t[1] == L'h')
        heu = std::stoi(t);
    else
        heu = 0;
    // min
    if (t[1] == L'h')
        t = t.substr(2);
    min = std::stoi(t);
    Temps.tm_hour = heu;
    Temps.tm_min = min;
    //wcout << L"hour=[" << Temps.tm_hour << L") min=[" << Temps.tm_min << L']' << endl;
#if afficher_Temps_1_ == 1
    std::wcout << L"::afficher_Temps(" << Temps.tm_hour << L"h " << Temps.tm_min << L"min)" << std::endl;
    B.Ok_W(L"Temps={" + std::to_wstring(Temps.tm_hour) + L"h " + std::to_wstring(Temps.tm_min) + L"min}");
    //wcout << L"::afficher_Temps(" << T.tm_hour << L"h " << T.tm_min << L')' << endl;
    //wcout << B_T << L"const int ::afficher_Temps() : Ok !" << B_t << endl;
    B.Ok_T(L"qqqq  const int afficher_Temps) : Ok !");
#endif
    //Temps_ = 1;
    return EXIT_SUCCESS;
}

const void afficher_Temps(std::tm& ttt)
{
    int t = ttt.tm_min;
    //T.tm_min = 0;
    ttt.tm_hour = t / 60;
    ttt.tm_min = t % 60;
}

// ############################################################
// #                                                                                                                                                    #
// # Temps_OK                                                 #
// #                                                                                                                                                    #
// ############################################################

const void afficher_Temps_OK(std::wstring& v, bool v_)
{
#if afficher_Temps_OK_ == 1
    wcout << L"::afficher_Temps_OK(" << v << L", " << v_ << L")" << endl;
#endif
    // _ h __ min
    if (v_ == 0)
    {
        if (v[1] == L' ' && (v[2] == L'h' || v[2] == L'H'))
        {
            v = v[0] + v.substr(2);
        }
        //if (v[1] == ::_C_H_)
        //    ;
        //else
        //    v[1] = ::_H_[0];
    }
#if afficher_Temps_OK_ == 1
    wcout << L"v=[" << v << L']' << endl;
#endif
    //
    /*basic_string <wchar_t>::size_type pos = 0;
    if (v_ == true)
    {
        wstring m = to_wstring(stoi(v));
        wstring M = S.S_MIN;
        //
        v = m;
        if (S.S_Espace == true)
            v += L' ';
        v += M;
    }*/
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int afficher_Titre(wstring t, vector<wstring>& titre, bool& titre_)                                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int afficher_Titre(std::wstring t, std::vector<std::wstring>& titre, bool& titre_)
{
#if afficher_Titre_ == 1
    //wcout << B_T << L"const int ::afficher_Titre(" << t << L", vector<wstring>&titre, bool& titre) :" << B_t << endl;
    B.Ok_T(L"const int afficher_Titre(" + t + L", vector<wstring>&titre, bool& titre) :");
#endif
    if (titre_ == true)
    {
        E.afficher_X(-1, L"::afficher_Titre(wstring t, vector<wstring>& titre, bool titre_ = false)", L"Érreur !!!");
        return -1;
    }
    std::size_t pos = 0;
    pos = t.find(L" - ");
    if (pos != wstring::npos && titre_ == false)
    {
        titre.push_back(t.substr(0, pos));
        titre.push_back(L" : ");
        titre.push_back(t.substr(pos + 3, t.length()));
        titre_ = true;
    }
    pos = t.find(L"- ");
    if (pos != wstring::npos && titre_ == false)
    {
        titre.push_back(t.substr(0, pos));
        titre.push_back(L": ");
        titre.push_back(t.substr(pos + 2, t.length()));
        titre_ = true;
    }


    // //////////////////////////////////////////////////////////////////////////////////
    pos = t.find(L'¬'); // ???
    // //////////////////////////////////////////////////////////////////////////////////
    if (pos != wstring::npos && titre_ == false)
    {
        titre.push_back(t.substr(0, pos));
        titre.push_back(L"/");
        titre.push_back(t.substr(pos + 1, t.length()));
        titre_ = true;
    }

    if (pos == wstring::npos && titre_ == false)
    {
        titre.push_back(t);
        titre.push_back(L"");
        titre.push_back(L"");
        titre_ = true;
    }
#if afficher_Titre_ == 1
    /*wcout << L"    " << L"1 : [" << titre[0] << L']' << endl;
    wcout << L"    " << L"2 : [" << titre[1] << L']' << endl;
    wcout << L"    " << L"3 : [" << titre[2] << L']' << endl;
    wcout << L"    " << L"Titre_ = ";
    if (titre_ == true)
        wcout << L"true";
    else
        wcout << L"false";
    wcout << endl;*/
    B.Ok_W(L"1={" + titre[0] + L'}');
    B.Ok_W(L"2={" + titre[1] + L'}');
    B.Ok_W(L"3={" + titre[2] + L'}');
    B.Ok_W(L"Titre_={" + std::to_wstring(titre_) + L'}');
#endif
#if afficher_Titre_ == 1
    //wcout << B_T << L"const int ::afficher_Titre() : Ok !" << B_t << endl;
    B.Ok_T(L"const int :afficher_Titre() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const void afficher_Titre(wstring t, vector<wstring>& Titre)                                                                                       #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Titre(std::wstring t, std::vector<std::wstring>& Titre)
{
#if afficher_Titre_1_ == 1
    //wcout << B_T << L"const void ::afficher_Titre(vector<wstring>& Titre, " << t << L") :" << B_t << endl;
    B.Ok_T(L"const void afficher_Titre(" + t + L", vector<wstring>&Titre) :");
#endif
    std::size_t pos;
    pos = t.find(L" : ");
    static const basic_string <wchar_t>::size_type npos = -1;
    if (pos != npos)
    {
        Titre[0] = t.substr(0, pos);
        Titre[1] = L" : ";
        Titre[2] = t.substr(pos + 3, t.length());
#if	afficher_Titre_1_ == 1
        //wcout << L"    " << L'{' << Titre[0] << L" : " << Titre[2] << L'}' << endl;
        B.Ok_W(L'{' + Titre[0] + L" : " + Titre[2] + L'}');
        B.Ok_T(L"const void afficher_Titre() : Ok !");
#endif
        return;
    }
    pos = t.find(L": ");
    if (pos != npos)
    {
        Titre[0] = t.substr(0, pos);
        Titre[1] = L": ";
        Titre[2] = t.substr(pos + 2, t.length());
#if	afficher_Titre_1_ == 1
        //wcout << L"    " << L'{' << Titre[0] << L": " << Titre[2] << L'}' << endl;
        B.Ok_W(L'{' + Titre[0] + L": " + Titre[2] + L'}');
        B.Ok_T(L"const void afficher_Titre() : Ok !");
#endif
        return;
    }
    pos = t.find(L'/');
    if (pos != npos)
    {
        Titre[0] = t.substr(0, pos);
        Titre[1] = L'/';
        Titre[2] = t.substr(pos + 1, t.length());
#if	afficher_Titre_1_ == 1
        //wcout << L"    " << L'{' << Titre[0] << L'/' << Titre[2] << L'}' << endl;
        B.Ok_W(L'{' + Titre[0] + L"/" + Titre[2] + L'}');
        B.Ok_T(L"const void afficher_Titre() : Ok !");
#endif
        return;
    }
    else
    {
        Titre[0] = t;
        Titre[1] = L"";
        Titre[2] = L"";
#if	afficher_Titre_1_ == 1
        //wcout << L"    " << L'{' << Titre[0] << L'}' << endl;
        B.Ok_W(L'{' + Titre[0] + L'}');
#endif
    }
#if	afficher_Titre_1_ == 1
    //wcout << B_T << L"const void ::afficher_Titre() : Ok !" << B_t << endl;
    B.Ok_T(L"const void afficher_Titre() : Ok !");
#endif
    return;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Titre_Original                                                                                                                            #
// # const void afficher_Titre_Original(std::wstring& to_filename, std::wstring const& nomFichier, std::vector<std::wstring>& t_o)                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void afficher_Titre_Original(std::wstring& to_filename, std::wstring const& nomFichier, std::vector<std::wstring>& t_o)
{
    assert((to_filename == createdBy_filename) && L"Erreur !!! Titre Original... !");
    std::wstring wstr = lire_fichierTxt(nomFichier);
    assert((wstr.size() != 0));


    /*if (t == L"Titre original.txt")
    {
        //t = ::afficher_fichier_lire(t, nomFichier);
        t = ::lire_fichierTxt(nomFichier);
        if (t == L"")
        {
            E.afficher_X(-1, L"const int ::afficher_Titre_Original()", L"Erreur pas de... !!!");
            return EXIT_FAILURE;
        }
    }
    else
    {
        E.afficher_X(-1, L"const int ::afficher_Titre_Original()", L"Erreur pas de... !!!");
        return EXIT_FAILURE;
    }*/

    size_t pos;
    bool found = false;
    pos = wstr.find(L" : ", 1);
    if (pos != wstring::npos)
    {
        t_o.push_back(wstr.substr(0, pos));
        t_o.push_back(L" : ");
        t_o.push_back(wstr.substr(pos + 3));
        found = true;
    }
    pos = wstr.find(L": ");
    if (pos != wstring::npos && !found)
    {
        t_o.push_back(wstr.substr(0, pos));
        t_o.push_back(L": ");
        t_o.push_back(wstr.substr(pos + 2));
        found = true;
    }
    pos = wstr.find(L'/');
    if (pos != wstring::npos && !found)
    {
        t_o.push_back(wstr.substr(0, pos));
        t_o.push_back(L"/");
        t_o.push_back(wstr.substr(pos + 1));
        found = true;
    }
    if (pos == wstring::npos && !found)
    {
        t_o.push_back(wstr);
        t_o.push_back(L"");
        t_o.push_back(L"");
        found = true;
    }
    if(!found)
    {
        E.afficher_X(-1, L"const int ::afficher_Titre_Original()", L"Erreur !!! Titre Original... !");
        return;
    }

    return;
}


// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int Compare_Path(int rc, path p1, path p2)                                                                                                   #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Compare_Path(int rc, path p1, path p2)
{
    if (rc < 0)
        return -1;
    else if (rc > 0)
        return 1;
    return 0;
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int Console_Lire_txt(wstring lire)                                                                                                           #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Console_Lire_txt(std::wstring lire)
{
    std::size_t i = X / lire.length();
    int j = X % lire.length();
    int k;
    for (k = 0; k < i; k++)
        std::wcout << lire;
    k = 0;
    while (k < j)
    {
        std::wcout << (wchar_t)lire[k];
        k++;
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const int Console_Lire_txt(wstring Textes, int x1, int x2)                                                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

inline std::wstring space(int i, wchar_t espace)
{
    std::wstring wstr = L"";
    //for (auto ===> Pas trouvé !!!)
    for(int j = 0; j < i; j++)
        wstr += espace;
    return wstr;
}

const int Console_Lire_txt(std::wstring Textes, int x1, int x2)
{
#if Console_Lire_txt_OK_ == 1
    std::wcout << L"const int Console_Lire_txt(" << Textes << L", " << x1 << L", " << x2 << L") : " << std::endl;
#endif

    if (Textes == L"" && X == 0)
        return 0;
    rtrim(Textes);
    //
    bool ligne_vide = false;
    bool retrait = false;
    wchar_t entree = L'\n';

    int I, x;
    int i, j, k, n = 0;
    int l, m;
    std::size_t N;
    // // // //  //
    Textes += entree;
    // // // //  //
    int p = 0;
    std::vector<std::wstring> P;
    std::vector<int> PP;
    std::wstring o;
    int oo = 0;
    N = Textes.length();
    i = 0;
    while (i < N)
    {
        if (Textes[i] == L'\x1b')
        {
            j = i;
            o = L'\x1b';
            j++;
            while (Textes[j] != L'm' || j >= N)
            {
                o += Textes[j];
                j++;
            }
            if (j >= N)
            {
                E.afficher_X(-1, L"::Console_Lire_txt()", L"j >= N !!!");
                //return -1;
                return EXIT_FAILURE;
            }
            o += L'm';
            P.push_back(o);
            PP.push_back(i);
            Textes = Textes.replace(i, o.length(), L"");
            p++;
            N = Textes.length();
        }
        i++;
    }
    std::vector <std::wstring>::iterator iter;
    std::wstring wstr;
    x = x1;
    I = X - x;
    j = 0;
    if (I < N)
        n = I;
    else
        n = (int)N;
    std::vector <int>::iterator iter2;
    iter = P.begin();
    iter2 = PP.begin();
    oo = 0;
    while (j < N)
    {
        // Ok
        if (Textes[j] == entree && retrait)
        {
            ligne_vide = true;
        }
        else
        {
            // Ok
#if Console_Lire_txt_ == 1
            std::wcout << space(x, L'_');
#else
            std::wcout << space(x, L' ');
#endif
            // Ok
            while (Textes[j] == L' ')
            {
                j++;
                n++;
                if (n > N)
                    n = (int)N;
            }
            // Ok
            k = j;
            for (j = k; k < n; k++)
            {
                if (Textes[k] == entree)
                {
                    break;
                }
            }
            if (k != n)
            {
                retrait = true;
                n = k;
            }
            else
            { // ???
                ligne_vide = false;
                retrait = false;
                while (Textes[n] != L' ')
                {
                    n--;
                }
            }
            // Ok
            k = j;
            l = 0;
            for (j = k; k < n; k++)
            {
                if (p != 0 && k == *iter2)
                {
                    o = *iter;
                    std::wcout << o;
                    wstr = o;
                    iter++;
                    iter2++;
                    oo++;
                }
                std::wcout << Textes[k];
                l++;
            }
            // Ok
            j = k;
            m = X - (x + l);
#if Console_Lire_txt_ == 1
            std::wcout << space(m, L'¯');
#else
            std::wcout << space(m, L' ');
#endif
        }
        // Ok
        if (ligne_vide && retrait)
        {
            ligne_vide = false;
            j++;
            n++;
            if (n > N)
                n = (int)N;
            x = x1;
            continue;
        }
        else if (!ligne_vide && retrait)
        {
            retrait = false;
            x = x1;
        }
        else
        {
            ligne_vide = false;
            retrait = false;
            x = x2;
        }
        j = n;
        if (p != 0
            &&
            j == *iter2)
        {
            o = *iter;
            std::wcout << o;
            wstr = o;
            iter++;
            iter2++;
            oo++;
        }
        j++;
        // x ?
        n += (X - x);
        if (n > N)
        {
            n = (int)N;
        }
        }
    if (p != 0 && PP.back() <= N)
    {
        std::wcout << P.back() << endl;
        wstr = P.back();
    }
#if Console_Lire_txt_OK_ == 1
    std::wcout << L"const int Console_Lire_txt() : Ok !" << std::endl;
#endif
    return EXIT_SUCCESS;
}

const void Console_Lire(std::wstring wstr, int x1, int x2)
{
    rtrim(wstr);
    //
    bool ligne_vide = false;
    bool retrait = false;
    wchar_t entree = L'\n'; // windows = L"\r\n", Unix = L'\n' ??? 

    int I, x;
    int i, j, k, n = 0;
    int l, m;
    std::size_t N;
    // // // //  //
    wstr += entree;
    // // // //  //
    int p = 0;
    std::vector<std::pair <std::wstring, int>> P;
    std::wstring keycolor;
    N = wstr.length();
    i = 0;
    while (i < N)
    {
        if (wstr[i] == L'\x1b')
        {
            j = i;
            keycolor = L'\x1b';
            j++;
            while (wstr[j] != L'm' || j >= N)
            {
                keycolor += wstr[j];
                j++;
            }
            keycolor += L'm';
            P.push_back(make_pair(keycolor, i));
            if (i != 0)
                wstr = wstr.substr(0, i) + wstr.substr(j + 1);
            else
                wstr = wstr.substr(j + 1);
            p++;
            N = wstr.length();
        }
        i++;
    }
    std::vector<std::pair<std::wstring, int>>::iterator iter;
    //std::wstring wstr2;
    //i = 0;
    //for (iter = P.begin(); iter != P.end(); iter++)
    //{
    //    wstr2 = L"\\x1b" + iter->first.substr(1);
    //    std::wcout << i << L" P["
    //        << iter->second << L"] [" << wstr2 << L"] = " << iter->first.length()
    //        << L" " << iter->first[iter->first.length() - 1]
    //        << std::endl;
     //   i++;
    //}

    x = x1;
    I = X - x;
    j = 0;
    if (I < N)
        n = I;
    else
        n = (int)N;
    iter = P.begin();
    while (j < N)
    {
        // Ok
        if (wstr[j] == entree && retrait)
            ligne_vide = true;
        else
        {
            // Ok
#if Console_Lire_txt_ == 1
            std::wcout << space(x, L'_');
#else
            std::wcout << space(x, L' ');
#endif
            // Ok
            while (wstr[j] == L' ')
            {
                j++;
                n++;
                if (n > N)
                    n = (int)N;
            }
            // Ok
            k = j;
            for (j = k; k < n; k++)
            {
                if (wstr[k] == entree)
                    break;
            }
            if (k != n)
            {
                retrait = true;
                n = k;
            }
            else
            { // ???
                ligne_vide = false;
                retrait = false;
                while (wstr[n] != L' ')
                    n--;
            }
            // Ok
            k = j;
            l = 0;
            for (j = k; k < n; k++)
            {
                if (p != 0 && k == iter->second)
                {
                    std::wcout << iter->first;
                    iter++;
                }
                std::wcout << wstr[k];
                l++;
            }
            // Ok
            j = k;
            m = X - (x + l);
#if Console_Lire_txt_ == 1
            std::wcout << space(m, L'¯');
#else
            std::wcout << space(m, L' ');
#endif
        }
        // Ok
        if (ligne_vide && retrait)
        {
            ligne_vide = false;
            j++;
            n++;
            if (n > N)
                n = (int)N;
            x = x1;
            continue;
        }
        else if (!ligne_vide && retrait)
        {
            retrait = false;
            x = x1;
        }
        else
        {
            ligne_vide = false;
            retrait = false;
            x = x2;
        }
        j = n;
        if (p != 0
            &&
            j == iter->second
            )
        {
            std::wcout << iter->first;
            iter++;
        }
        j++;
        // x ?
        n += (X - x);
        if (n > N)
            n = (int)N;
    }
    if (p != 0 && P.back().second <= N)
    {
        std::wcout << P.back().first;
    }
    return;
}

//DWORD dwMode = 0;
//BOOL res = WriteFile(hOut, &str[0], (DWORD)(str.size() * sizeof(wchar_t)), &dwMode, NULL);
//assert(res == TRUE);


const int Console_Lire_txt2(std::wstring Textes, int x1, int x2)
{
#if Console_Lire_txt_OK_ == 1
    std::wcout << L"const int Console_Lire_txt(" << Textes << L", " << x1 << L", " << x2 << L") : " << std::endl;
#endif

    if (Textes == L"" && X == 0)
        return 0;
    rtrim(Textes);
    //
    bool ligne_vide = false;
    bool retrait = false;
    std::wstring entree = L"\r\n";

    int I, x;
    int i, j, k, n = 0;
    int l, m;
    std::size_t N;
    // // // //  //
    Textes += entree;
    // // // //  //
    int p = 0;
    std::vector<std::wstring> P;
    std::vector<int> PP;
    std::wstring o;
    int oo = 0;
    N = Textes.length();
    i = 0;
    while (i < N)
    {
        if (Textes[i] == L'\x1b')
        {
            j = i;
            o = L'\x1b';
            j++;
            while (Textes[j] != L'm' || j >= N)
            {
                o += Textes[j];
                j++;
            }
            if (j >= N)
            {
                E.afficher_X(-1, L"::Console_Lire_txt()", L"j >= N !!!");
                //return -1;
                return EXIT_FAILURE;
            }
            o += L'm';
            P.push_back(o);
            PP.push_back(i);
            Textes = Textes.replace(i, o.length(), L"");
            p++;
            N = Textes.length();
        }
        i++;
    }
    std::vector <std::wstring>::iterator iter;
    std::wstring wstr;
    x = x1;
    I = X - x;
    j = 0;
    if (I < N)
        n = I;
    else
        n = (int)N;
    std::vector <int>::iterator iter2;
    iter = P.begin();
    iter2 = PP.begin();
    oo = 0;
    while (j < N)
    {
        // Ok
        if ((entree[0] == Textes[j] && entree[1] == Textes[j + 1]) && retrait == true)
        {
            ligne_vide = true;
            //retrait = true;
            goto _ok_;
        }
        // Ok
        for (i = 0; i < x; i++)
#if Console_Lire_txt_ == 1
            std::wcout << L'_';
#else
            std::wcout << L' ';
#endif
        //converti = converti.substr(pos_found + sep_found.length());
        // std::wcout << 




        // Ok
        while (Textes[j] == L' ')
        {
            j++;
            n++;
            if (n > N)
                n = (int)N;
        }
        // Ok
        k = j;
        for (j = k; k < n; k++)
        {
            if (entree[0] == Textes[k] /* && entree[1] == Textes[k + 1]*/)
            {
                //if (j <= n - 1)
                //{
                //    E.afficher_X(-1, L"::Console_Lire_txt()", L"wwwwww !!!");
                //    //return EXIT_FAILURE;
                //}
                break;
            }
        }
        if (k != n)
        {
            retrait = true;
            n = k;
        }
        else
        { // ???
            ligne_vide = false;
            retrait = false;
            while (Textes[n] != L' ')
            {
                n--;
            }
        }
        // Ok
        k = j;
        l = 0;
        for (j = k; k < n; k++)
        {
            if (p != 0 && k == *iter2)
            {
                o = *iter;
                std::wcout << o;
                wstr = o;
                iter++;
                iter2++;
                oo++;
            }
            std::wcout << Textes[k];
            l++;
        }
        // Ok
        j = k;
        m = X - (x + l);
        for (i = 0; i < m; i++)
        {
#if Console_Lire_txt_ == 1
            std::wcout << L'¯';
#else
            std::wcout << L' ';
#endif
        }
        // Ok
    _ok_:
        if (ligne_vide && retrait)
        {
            ligne_vide = false;
            j++;
            n++;
            if (n > N)
                n = (int)N;
            x = x1;
            continue;
        }
        else if (!ligne_vide && retrait)
        {
            retrait = false;
            x = x1;
        }
        else
        {
            ligne_vide = false;
            retrait = false;
            x = x2;
        }
        j = n;
        if (p != 0
            &&
            j == *iter2)
        {
            o = *iter;
            std::wcout << o;
            wstr = o;
            iter++;
            iter2++;
            oo++;
        }
        j++;
        // x ?
        n += (X - x);
        if (n > N)
        {
            n = (int)N;
        }
    }
    if (p != 0 && PP.back() <= N)
    {
        std::wcout << P.back() << endl;
        wstr = P.back();
    }
#if Console_Lire_txt_OK_ == 1
    std::wcout << L"const int Console_Lire_txt() : Ok !" << std::endl;
#endif
    return EXIT_SUCCESS;
}



// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintStringW                                                                                                                                       #
// # void PrintStringW(HANDLE hOut, const std::wstring& str)                                                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

/*void PrintStringW(HANDLE hOut, const std::wstring& str)
{
#if PrintStringW_ == 1
    B.Ok_T(L"void PrintStringW(HANDLE hOut, const std::wstring& str) :");
#endif
    DWORD dwMode = 0;

    BOOL res = WriteFile(
        hOut,
        &str[0],
        (DWORD)(str.size() * sizeof(wchar_t)),
        &dwMode,
        NULL);
    assert(res == TRUE);
#if PrintStringW_ == 1
    B.Ok_T(L"void PrintStringW() : Ok !");
#endif
}*/


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # static inline void rtrim(wstring& s)                                                                                                               #
// #                                                                                                                                                    #
// ######################################################################################################################################################
// trim from end (in place)
static inline void rtrim(std::wstring& s)
{
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch)
        {
            return !isspace(ch);
        }).base(), s.end());
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace)                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace)
{
    size_t pos = 0;
    // function find return string::npos if not found.
    while ((pos = subject.find(search, pos)) != wstring::npos)
    {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # std::wstring you_substr(std::wstring t)                                                                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

std::wstring you_substr(std::wstring t)
{
    //t = replace_all(t, L"\n", L"");
    t = replace_all(t, L"\r\n", L"");
    t = replace_all(t, L"\"", L"");
    size_t c = t.length();
    //t[c--];
    if (t[c - 1] == ' ' || t[c - 1] == '\t')
    {
        return L" ";
    }
#if you_substr_ == 1
    std::wcout << "t=[" << t << "], size=[" << t.size() << "] length=[" << t.length() << "]" << endl;
#endif
    return t;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # bool checkdate(int m, int d, int y)                                                                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

bool checkdate(int m, int d, int y)
{
    //gregorian dates started in 1582
    if (!(1582 <= y))//comment these 2 lines out if it bothers you
        return false;
    if (!(1 <= m && m <= 12))
        return false;
    if (!(1 <= d && d <= 31))
        return false;
    if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
        return false;
    if ((d == 30) && (m == 2))
        return false;
    if ((m == 2) && (d == 29) && (y % 4 != 0))
        return false;
    if ((m == 2) && (d == 29) && (y % 400 == 0))
        return true;
    if ((m == 2) && (d == 29) && (y % 100 == 0))
        return false;
    if ((m == 2) && (d == 29) && (y % 4 == 0))
        return true;

    return true;
}

// year[i] + month[j] + day[k]

/*bool checkyear(int y)
{
    if (!(1582 <= y))//comment these 2 lines out if it bothers you
        return false;
    return true;
}*/
bool checkyear(int y)
{
    return 1582 <= y;
}

int ParseYear(int y)
{
    if (checkyear(y))
        return y;
    return 0;
}

/*bool checkmonth(int m)
{
    if (!(1 <= m && m <= 12))
        return false;
    return true;
}*/
bool checkmonth(int m)
{
    return (1 <= m && m <= 12);
}

int ParseMonth(int m)
{
    if (checkmonth(m))
        return m;
    return 0;
}

bool checkday(int m, int d, int y)
{
    if (!(1 <= d && d <= 31))
        return false;
    if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
        return false;
    if ((d == 30) && (m == 2))
        return false;
    if ((m == 2) && (d == 29) && (y % 4 != 0))
        return false;
    if ((m == 2) && (d == 29) && (y % 400 == 0))
        return true;
    if ((m == 2) && (d == 29) && (y % 100 == 0))
        return false;
    if ((m == 2) && (d == 29) && (y % 4 == 0))
        return true;
    return true;
}

int ParseDay(int m, int d, int y)
{
    if (checkday(m, d, y))
        return d;
    return 0;
}



void test_date_year(int& year)
{
    if (year <= 1900 || year >= 3001)
    {
        throw exception_date_year();
    }
    return;
}

void test_date_month(int& month)
{
    if (month <= 0 || month >= 13)
    {
        throw exception_date_month();
    }
    return;
}

void test_date_day(int& day)
{
    if (day <= 0 || day >= 32)
    {
        throw exception_date_day();
    }
    return;
}

void test_date_tire(wchar_t d)
{
    if (d != L'-')
    {
        throw exception_date_tiret();
    }
    return;
}

void test_date_tiret_sp_etc(wchar_t d)
{
    if (d != L'-' && d != L'/' && d != L'.' && d != L' ')
    {
        throw exception_date_tiret_sp_etc();
    }
    return;
}

void test_sp_et_npos_ou_pas_isblank(wchar_t sp, bool t)
{
    if (sp != L' ' && t)
    {
        throw exception_test_sp_et_npos_ou_pas_isblank();
    }
    return;
}



// ######################################################################################################################################################
// #                                                                                                                                                    #
// # std::tm ParseDate(std::wstring& str)                                                                                                               #
// #                                                                                                                                                    #
// ######################################################################################################################################################

std::tm ParseDate(std::wstring& str)
{
    //le seul truc non trivial est l'utilisation d'une expression régulière, Google est notre ami.
    std::wregex date_regex(L"(\\d{4})(?:/|\\-|\\.|\\s)(\\d{2})(?:/|\\-|\\.|\\s)(\\d{2})");
    std::wsmatch matches;

    if (std::regex_search(str, matches, date_regex))
    {
        int year = std::stoi(matches[1].str());
        int month = std::stoi(matches[2].str());
        int day = std::stoi(matches[3].str());

        if (checkdate(month, day, year))
        {
            std::tm date;
            date.tm_year = year - 1900;
            date.tm_mon = month - 1;
            date.tm_mday = day;

            return date;
        }
        else
        {
            throw std::invalid_argument("Cinema::ParseDate : La date passée en argument n'est pas valide.");
        }
    }
    else
    {
        throw std::invalid_argument("Cinema::ParseDate : Le format de l'argument n'est pas valide.");
    }
}

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Printaudiodescription                                                                                                                              #
// # const void Printaudiodescription(const std::wstring& audiodescription, bool affichage_audiodescription_actif,                                      #
// #                                  std::wstring& keyColor, std::wstring& valuesColor)                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void PrintAudiodescription(const std::wstring& audiodescription, bool affichage_audiodescription_actif, std::wstring& keyColor, std::wstring& valuesColor)
{
    if (affichage_audiodescription_actif && audiodescription.size() > 0)
    {
        std::wstring audiodescription_str = keyColor + L"Audiodescription : " + valuesColor + audiodescription + L"\r\n";
        //PrintStringW(m_hOut, creee_par_str, 0);
        //PrintStringW(HANDLE hOut, creee_par_str);
        int i = Console_Lire_txt(audiodescription_str, 0, 0);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintGenres                                                                                                                                        #
// # void PrintGenres(const std::vector<std::wstring>& genres, bool affichage_genres_actif,                                                             #
// #                  const std::wstring& sous_genre, bool affichage_sous_genre_actif,                                                                  #
// #                  std::wstring& keyColor, std::wstring& valuesColor)                                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

/*void PrintGenres(const std::vector<std::wstring>& genres, bool affichage_genres_actif, const std::wstring& sous_genre, bool affichage_sous_genre_actif, std::wstring& keyColor, std::wstring& valuesColor)
{
    if (affichage_genres_actif && genres.size() > 0)
    {
        std::wstring genre_str = keyColor + L"Genre" + ((genres.size() > 1) ? L"s" : L"") + L" : " + valuesColor;

        bool first = true;
        for (auto&& genre : genres)
        {
            if (!first)
            {
                genre_str += keyColor + L", " + valuesColor;
            }
            genre_str += genre;
            first = false;
        }
        if (affichage_sous_genre_actif && sous_genre.size() != 0)
            genre_str += keyColor + L" et " + valuesColor + sous_genre;
        genre_str += L"\r\n";

        //PrintStringW(m_hOut, genre_str, 0);
        int i = Console_Lire_txt(genre_str, 0, 0);
    }
}*/
void PrintGenres(const std::vector<std::wstring>& genres, bool affichage_genres_actif, const std::wstring& sous_genre, bool affichage_sous_genre_actif, std::wstring& keyColor, std::wstring& valuesColor)
{
    if (affichage_genres_actif && genres.size() > 0)
    {
        std::wstring genre_str = keyColor + L"Genre" + ((genres.size() > 1) ? L"s" : L"") + L" : " + valuesColor;

        bool first = true;
        for (auto&& genre : genres)
        {
            if (!first)
            {
                genre_str += keyColor + L", " + valuesColor;
            }
            genre_str += genre;
            first = false;
        }
        genre_str += L"\r\n";
        //int i = Console_Lire_txt(genre_str, 0, 0);
        Console_Lire(genre_str, 0, 0);
        if (affichage_sous_genre_actif && sous_genre.size() != 0)
        {
            genre_str = keyColor + L"Sous-genre : " +  valuesColor + sous_genre + L"\r\n";
            Console_Lire(genre_str, 0, 0);
        }
        //PrintStringW(m_hOut, genre_str, 0);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintImages                                                                                                                                        #
// # const void PrintImages(const std::vector<std::wstring>& images, bool affichage_image_actif, std::wstring& keyColor, std::string& valuesColor)      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void PrintImages(const std::vector<std::wstring>& images, bool affichage_image_actif, std::wstring& keyColor, std::wstring& valuesColor, int x1, int y1, int x2, int y2)
{
    if (affichage_image_actif && images.size() /*> 0*/ != 0)
    {
        std::wstring image_str = keyColor + L"Image" + ((images.size() > 1) ? L"s" : L"") + L" : [" + valuesColor;
        bool first = true;
        for (auto&& i : images)
        {
            if (!first)
            {
                image_str += keyColor + L"], [" + valuesColor;
            }
            image_str += i;
            first = false;
        }
        image_str += keyColor + L']' + valuesColor + L"\r\n";
        //PrintStringW(m_hOut, image_str, x1);
        int i = Console_Lire_txt(image_str, x1, 0);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintNationalites                                                                                                                                  #
// # const void PrintNationalites(const std::vector<std::wstring>& nationalites, bool affichage_nationalite_actif                                       #                                                                                                    #
// #                        std::wstring& keyColor, std::wstring& valuesColor)                                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void PrintNationalites(const std::vector<std::wstring>& nationalites, bool affichage_nationalite_actif, std::wstring& keyColor, std::wstring& valuesColor)
{
    if (affichage_nationalite_actif && nationalites.size() > 0)
    {
        std::wstring nationalite_str = keyColor + L"Nationalite" + ((nationalites.size() > 1) ? L"s" : L"") + L" : " + valuesColor;

        bool first = true;
        for (auto&& nationalite : nationalites)
        {
            if (!first)
            {
                nationalite_str += keyColor + L", " + valuesColor;
            }
            nationalite_str += nationalite;
            first = false;
        }
        nationalite_str += L"\r\n";

        //PrintStringW(m_hOut, genre_str, 0);
        int i = Console_Lire_txt(nationalite_str, 0, 0);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintNetflixokounon                                                                                                                                #
// # const void PrintImages(const std::vector<std::wstring>& images, bool affichage_image_actif, std::wstring& keyColor, std::string& valuesColor)      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void PrintNetflixokounon(bool netflix_ok_ou_non, bool affichage_sur_actif, std::wstring& keyColor, std::wstring& valuesColor)
{
    if (affichage_sur_actif)
        if (!netflix_ok_ou_non)
            int i = Console_Lire_txt(keyColor + L"Netflix : " + valuesColor + L"Oui" + keyColor + L" !" + valuesColor, 0, 10);
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintPrintTitreOriginal                                                                                                                            #
// # const void PrintNationalites(const std::vector<std::wstring>& titre_original, bool affichage_titre_original_actif,                                 #
// #                              std::wstring& keyColor, std::wstring& valuesColor, std::wstring& keyColor2, std::wstring& valuesColor2)               #                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void PrintTitreOriginal(const std::vector<std::wstring>& titre_original, bool affichage_titre_original_actif, std::wstring& keyColor, std::wstring& valuesColor, std::wstring& keyColor2, std::wstring& valuesColor2)
{
    if (affichage_titre_original_actif && titre_original.size() > 0)
    {
        //Titre_Original.begin();
        std::wstring titre_original_str = keyColor + L"Titre original : " + valuesColor + titre_original[0];
        if (titre_original[2] != L"")
        {
            titre_original_str += keyColor2 + titre_original[1] + valuesColor2;
            titre_original_str += titre_original[2];
        }
        int i = Console_Lire_txt(titre_original_str, 0, 17);
    }
}





/*
//bool _F_, _f_;
//wstring::iterator iter;
//vector <wchar_t>::iterator iter2;
//wchar_t _f_;

    if (p.begin() == p.end())
    {
        _F_ = false;
        _f_ = false;
    }
    else
    {
        _F_ = true;
        iter2 = p.begin();
        if (Page[0] == *iter2)
            _f_ = true;
        else
            _f_ = false;
    }*/

namespace Utils
{
    /**
    * FUNCTION: getFilePath
    * USE: Returns the path from a given file path
    * @param path: The path of the file
    * @return: The path from the given file path
    */
    wstring getFilePath(const wstring& path)
    {
        auto pathEnd = path.find_last_of(L"/\\");
        auto pathName = pathEnd == wstring::npos ? path : path.substr(0, pathEnd);
        return pathName;
    }

    /**
    * FUNCTION: getFileName
    * USE: Returns the file name from a given file path
    * @param path: The path of the file
    * @return: The file name from the given file path
    */
    wstring getFileName(const wstring& path)
    {
        auto fileNameStart = path.find_last_of(L"/\\");
        auto fileName = fileNameStart == wstring::npos ? path : path.substr(fileNameStart + 1);
        return fileName;
    }

    /**
    * FUNCTION: getFileExtension
    * USE: Returns the file extension from a given file path
    * @param path: The path of the file
    * @return: The file extension from the given file path
    */
    wstring getFileExtension(const wstring& path)
    {
        auto fileName = getFileName(path);
        auto extStart = fileName.find_last_of(L'.');
        auto ext = extStart == wstring::npos ? L"" : fileName.substr(extStart + 1);
        transform(ext.begin(), ext.end(), ext.begin(), [](wchar_t c)
            {
                return static_cast<wchar_t>(tolower(c));
            });
        return ext;
    }

    /*auto getFilesInDirectory(const wstring& directory, bool topDirectoryOnly = true)
    {
        //namespace fs = std::filesystem;
        vector<directory_entry> results;
        auto fill = [&results](const auto& iter)
        {
            for (const directory_entry& entry : iter)
            {
                if (!entry.is_regular_file())
                {
                    continue;
                }
                results.push_back(entry);
            }
        };
        if (topDirectoryOnly)
        {
            fill(directory_iterator(directory));
        }
        else {
            fill(recursive_directory_iterator(directory));
        }
        return results;

    }*/
}// 

int Ee()
{
    //wstring d = L"d:\\Films\\Azertyuiop.(2021-06-02 VOD).Manga\\De - Sun-hee Jo.txt";
    wstring l = L"2021-07-28, 2021-07-28, 2021-07-28, 2021-07-29";
    wcout << L"[" << l << L"]" << endl;
    l = l.append(L", ");
    basic_string <wchar_t>::size_type idx = 0;
    basic_string <wchar_t>::size_type idx2 = 12, o = l.length();
    o = 12 / o;
    int comp;
    const wchar_t* m = &l[idx2];
    wchar_t n = 0;

    wcout << L"n=[" << (int)n << L"]" << endl;

    do
        //   while(idx2 < o)
    {
        comp = l.compare(idx, 10, m, 10);
        if (comp == 0)
        {
            n++;
            if (n == 1)
            {
                wcout << L"eeeeeeeeeeee" << endl;
                wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
                l = l.replace(idx + 10, 14, L" (1)(2), ");
                wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
                idx2 = idx2 + 7;
                m = &l[idx2];
                wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
                n++;
            }
            else
            {
                wcout << L"fffffffff" << endl;
                wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
                l = l.replace(idx + 17, 10, L"(3), ", 0, 5);
                wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
                l = l.substr(idx, idx + 17 + 5) + l.substr(idx + 17 + 5 + 4);
                wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
                idx2 = idx2 + 12;
                m = &l[idx2];
                wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
                n++;
            }
        }
        else if (comp > 0)
        {
            wcout << L"ggggggggggg" << endl;
            wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
            idx = idx2;
            idx2 = idx2 + 12;
            n = 0;
            wcout << L"[" << l << L"] idx=[" << idx << L"] (" << l[(wchar_t)idx] << L") idx2 = [" << idx2 << L"] (" << l[(wchar_t)idx2] << L")" << endl;
        }
        else
        {
            wcout << L"\nErreur !!!";
            idx2 = wstring::npos;
            //return -1;
        }
        if (idx2 == wstring::npos)
            break;
    } while (idx2 != wstring::npos /* || idx2 < o*/);


    idx = l.length();
    l = l.substr(0, idx - 2);
    wcout << L"replace() : [";
    wcout << l;
    wcout << L"]" << endl;
    return 0;
}

int Ff()
{
    string original8 = u8"¿ Quién Mató a Sara ?";

    wstring original16 = L"¿ Quién Mató a Sara ?";

    //C++11 format converter
    wstring_convert<codecvt_utf8_utf16<wchar_t>> convert;

    //convert to UTF8 and std::string
    string utf8NativeString = convert.to_bytes(original16);

    wstring utf16NativeString = convert.from_bytes(original8);

    assert(utf8NativeString == original8);
    assert(utf16NativeString == original16);

    //return 0;

    //wcout << L"[" << p << L"]" << endl;

    cout << utf8NativeString << endl;
    wcout << utf16NativeString << endl;
    return 0;
}


/*template <typename T>
string toUTF8(const basic_string<T, char_traits<T>, allocator<T>>& source)
{
    string result;

    wstring_convert<codecvt_utf8_utf16<T>, T> convertor;
    result = convertor.to_bytes(source);

    return result;
}

template <typename T>
void fromUTF8(const string& source, basic_string<T, char_traits<T>, allocator<T>>& result)
{
    wstring_convert<codecvt_utf8_utf16<T>, T> convertor;
    result = convertor.from_bytes(source);
}*/

/*unique_ptr<char16_t[]> ToUTF16(const char* utf8String)
{
    auto end_ptr = utf8String + char_traits<char>::length(utf8String);
    codecvt_utf8_utf16<char16_t> converter;
    codecvt_utf8_utf16<char16_t>::state_type state;

    array<char16_t, buffer_size> buffer;
    vector<char16_t> storage;

    auto curr_in_ptr = utf8String;
    auto out_loc = buffer.begin();

    do
    {
        codecvt_base::result rslt = converter.in(state,
            curr_in_ptr, end_ptr, curr_in_ptr,
            buffer.begin(), buffer.end(), out_loc);

        storage.insert(storage.end(), buffer.begin(), out_loc);
    } while (curr_in_ptr != end_ptr);

    //+1 for NUL terminator.
    unique_ptr<char16_t[]> ret(new char16_t[storage.size() + 1]);
    copy(storage.begin(), storage.end(), ret.get());
    ret.get()[storage.size()] = char16_t();
    return ret;
}*/


//UTF-8 to UTF-16 
//string source;
//... 
//wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert;
//u16string dest = convert.from_bytes(source);

//UTF-16 to UTF-8 
//u16string source;
//... 
//wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert;
//string dest = convert.to_bytes(source);



//std::u16string u16_conv = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes(u8);

// MultibyteToWideChar


/*wstring string2wString(const string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    wstring r(buf);
    delete[] buf;
    return r;
}*/



/*
0 	Default 	Retourne tous les attributs à l’état par défaut avant la modification
1 	Mise en gras/couleur brillante 	Applique l’indicateur de luminosité/intensité à la couleur de premier plan
22 	Aucune mise en gras/couleur brillante 	Supprime l’indicateur de luminosité/intensité de la couleur de premier plan
4 	Souligner 	Ajoute un soulignement
24 	Pas de soulignement 	Supprime le soulignement
7 	Négatif 	Permute les couleurs de premier plan et d’arrière-plan
27 	Image positive (non négative) 	Rétablit le premier plan et l’arrière-plan à l’état normal
30 	Premier plan en noir 	Applique la couleur noir brillant sans mise en gras au premier plan
31 	Premier plan en rouge 	Applique la couleur rouge vif sans mise en gras au premier plan
32 	Premier plan en vert 	Applique la couleur vert clair sans mise en gras au premier plan
33 	Premier plan en jaune 	Applique la couleur jaune vif sans mise en gras au premier plan
34 	Premier plan en bleu 	Applique la couleur bleu brillant sans mise en gras au premier plan
35 	Premier plan en magenta 	Applique la couleur magenta brillant sans mise en gras au premier plan
36 	Premier plan en cyan 	Applique la couleur cyan brillant sans mise en gras au premier plan
37 	Premier plan en blanc 	Applique la couleur blanc brillant sans mise en gras au premier plan
38 	Premier plan avec valeur de couleur étendue 	Applique la valeur de couleur étendue au premier plan (voir les détails ci-dessous).
39 	Définition par défaut du premier plan 	Applique uniquement la partie du premier plan des valeurs par défaut (voir 0).
40 	Arrière-plan en noir 	Applique la couleur noir brillant sans mise en gras à l’arrière-plan
41 	Arrière-plan en rouge 	Applique la couleur rouge vif sans mise en gras à l’arrière-plan
42 	Arrière-plan en vert 	Applique la couleur vert clair sans mise en gras à l’arrière-plan
43 	Arrière-plan en jaune 	Applique la couleur jaune vif sans mise en gras à l’arrière-plan
44 	Arrière-plan en bleu 	Applique la couleur bleu brillant sans mise en gras à l’arrière-plan
45 	Arrière-plan en magenta 	Applique la couleur magenta brillant sans mise en gras à l’arrière-plan
46 	Arrière-plan en cyan 	Applique la couleur cyan brillant sans mise en gras à l’arrière-plan
47 	Arrière-plan en blanc 	Applique la couleur blanc brillant sans mise en gras à l’arrière-plan
48 	Arrière-plan avec valeur de couleur étendue 	Applique une valeur de couleur étendue à l’arrière-plan (voir les détails ci-dessous).
49 	Définition par défaut de l’arrière-plan 	Applique uniquement la partie de l’arrière-plan des valeurs par défaut (voir 0).
90 	Premier plan en noir brillant 	Applique la couleur noir brillant avec mise en gras au premier plan
91 	Premier plan en rouge vif 	Applique la couleur rouge vif avec mise en gras au premier plan
92 	Premier plan en vert clair 	Applique la couleur vert clair avec mise en gras au premier plan
93 	Premier plan en jaune vif 	Applique la couleur jaune vif avec mise en gras au premier plan
94 	Premier plan en bleu brillant 	Applique la couleur bleu brillant avec mise en gras au premier plan
95 	Premier plan en magenta brillant 	Applique la couleur magenta brillant avec mise en gras au premier plan
96 	Premier plan en cyan brillant 	Applique la couleur cyan brillant avec mise en gras au premier plan
97 	Premier plan en blanc brillant 	Applique la couleur blanc brillant avec mise en gras au premier plan
100 	Arrière-plan en noir brillant 	Applique la couleur noir brillant avec mise en gras à l’arrière-plan
101 	Arrière-plan en rouge vif 	Applique la couleur rouge vif avec mise en gras à l’arrière-plan
102 	Arrière-plan en vert clair 	Applique la couleur vert clair avec mise en gras à l’arrière-plan
103 	Arrière-plan en jaune vif 	Applique la couleur jaune vif avec mise en gras à l’arrière-plan
104 	Arrière-plan en bleu brillant 	Applique la couleur bleu brillant avec mise en gras à l’arrière-plan
105 	Arrière-plan en magenta brillant 	Applique la couleur magenta brillant avec mise en gras à l’arrière-plan
106 	Arrière-plan en cyan brillant 	Applique la couleur cyan brillant avec mise en gras à l’arrière-plan
107 	Arrière-plan en blanc brillant 	Applique la couleur blanc brillant avec mise en gras à l’arrière-plan
*/


