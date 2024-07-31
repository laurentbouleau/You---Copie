
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
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale>

extern int X;

extern /*const */class Erreur E;
extern /*const*/ class Bug B;


extern const bool afficher_Path_Exists(std::wstring&);
extern const std::wstring lire_fichierTxt(std::wstring const& t);
extern std::wstring you_substr(std::wstring);
extern std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace);
//extern const int Console_Lire_txt(std::wstring, int, int);

// // // // // // // // // //
extern struct P_FS P_film, P_serie, P_film_VOD, P_film_DVD, & P_fs;
// // // // // // // // // //

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt                                                                                                                                            #
// # const int You_txt(int v)                                                                                                                           #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt(int& v)
{
#if You_txt_ == 1
    B.Ok_T(L"const int You_txt(" + std::to_wstring(v) + L") :");
#endif
    switch (v)
    {
    case 0:
#if You_txt_ == 1
        B.Ok_W(L"== " + std::to_wstring(v) + L" ==");
#endif
        You_txt_OK();
        break;
    default:
        break;
    }
#if You_txt_ == 1
    B.Ok_T(L"const int You_txt() : Ok !");
#endif
    return 0;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt_fs                                                                                                                                         #
// # const int You_txt_fs(wstring& t, wstring& p1)                                                                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt_fs(std::wstring& t, std::wstring& p1)
{
#if You_txt_cs_ == 1
    B.Ok_T(L"const int You_txt_fs(wstring& t, " + p1 + L") :");
#endif
    int v;
    std::wstring p2, p3, p4;
    p4 = p1;
    size_t pos = 0;
    if (p1 == L"<Film>")
    {
        p2 = L"</Film>";
        p3 = L"Film=";
    }
    else if (p1 == L"<Série>")
    {
        p2 = L"</Série>";
        p3 = L"Série=";
    }
    else if (p1 == L"<Film VOD>")
    {
        p2 = L"</Film VOD>";
        p3 = L"Film-VOD=";
    }
    else if (p1 == L"<Film DVD>")
    {
        p2 = L"</Film DVD>";
        p3 = L"Film-DVD=";
    }
    else
    {
#if You_txt_fs_ == 1
        Console_Lire_txt(L"Impossible de pas (" + p1 + L") !", 4, 4);
#endif
        //wcerr << L"Impossible pas de note (" << cs << L") !" << endl;
        E.afficher_X(-3, L"Impossible de pas (" + p1 + L") !", L"Erreur (" + p1 + L") !!!");
        return -3;
    }
    pos = t.find(L'\n');
    t = t.substr(pos + 1);
    while (t != L"")
    {
        pos = t.find(L'\n');
        p1 = t.substr(0, pos);
        p1 = you_substr(p1);
        if (p1 == p2)
            // </Film> ou </Serie> ou </Film VOD> ou </Film DVD>
        {
#if You_txt_fs_ == 1
            //wcout << L'{' << p2 << L'}' << endl;
            Console_Lire_txt(L'{' + p2 + L'}', 4, 4);
            B.Ok_T(L"const int You_txt_fs() : Ok !");
#endif
            //t = t.substr(pos + 1);
            p2 = L"";
            return 0;
        }
        else if (p1.substr(0, 5) == L"Film=" || p1.substr(0, 6) == L"Série=" || p1.substr(0, 9) == L"Film-VOD=" || p1.substr(0, 9) == L"Film-DVD=")
            // Film= ou Série= ou Film-VOD ou Film-DVD
        {
            size_t pos2 = 0;
            pos2 = p1.find(L"=");
            P_fs.fs = p1.substr(pos2 + 1);
#if You_txt_fs_ == 1
            //wcout << L'{' << p1.substr(0, pos2 + 1) << L'[' << P_cs.cs << L"]}" << endl;
            Console_Lire_txt(L'{' + p1.substr(0, pos2 + 1) + L'[' + P_cs.cs + L"]}", 4, 4);
#endif
            p3 = L"";
            t = t.substr(pos + 1);
            //wcout << L">> continue;" << endl;
            continue;
        }
        else if (p1.substr(0, 5) == L"Note[" && p1.substr(6, 2) == L"]=")// p1[6] == L']' && p1[7] == L'=')
            // Note[0-5]=
        {
            v = std::stoi(p1.substr(5, 1));
            if (v >= 0 && v <= 5)
            {
                P_fs.note[v] = p1.substr(8);
#if You_txt_cs_ == 1
                //wcout << L"{Note[" << v << L"]=[" << P_cs.note[v] << L"]}" << endl;
                Console_Lire_txt(L"{Note[" + to_wstring(v) + L"]=[" + P_cs.note[v] + L"]}", 4, 4);
#endif
                t = t.substr(pos + 1);
                continue;
            }
            else
            {
#if You_txt_fs_ == 1
                B.Ok_W(L"Impossible pas de note (0-5) !");
                B.Ok_T(L"const int You_txt_cs() : Attention !!!");
#endif
                E.afficher_X(-5, L"Impossible pas de note (0-5) !", L"Erreur (" + p1 + L") !!!");
                return -5;
            }
        }
        else
        {
            if (p1[0] == L' ' || p1[0] == '\t')
            {
#if You_txt_cs_ == 1
                B.Ok_W(L"Impossible pas de '' '' et/ou ''\n'' !");
                B.Ok_T(L"const int You_txt_cs() : Attention !!!");
#endif
                E.afficher_X(-3, L"Impossible " + p4 + L" ou \"Note[0-5]=\", pas de ' ' ou '\t' !", L"Erreur (" + p1 + L") !!!");
                return -3;
            }
            //wcerr << L"Impossible (</Cinéma>) (2) !" << endl;
            //E.afficher_X(-3, L"Impossible (</Cinéma>) (2) !", L"Érreur (" + p1 + L") !!!");
            //return -3;
        }
        t = t.substr(pos + 1);
    }
#if You_txt_fs_ == 1
    //wcout << L"::You_txt_cs() : Ok !" << endl;
    B.Ok_T(L"int You_txt_cs() : Ok !");
#endif
    return 0;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt_is_directory                                                                                                                               #
// # const int You_txt_is_directory(wstring& t)                                                                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt_is_directory(std::wstring& t)
{
#if You_txt_is_directory_ == 1
    B.Ok_T(L"const int You_txt_is_directory(" + t + L") :");
#endif
    if (!afficher_Path_Exists(P_fs.fs))
    {
#if You_txt_is_directory_ == 1
        B.Ok_T(L"const int You_txt_is_directory(" + t + L") : Erreur !!!");
#endif
        E.afficher_X(-8, t + L" pas de " + P_fs.fs + L" !", L"Erreur !!!");
        return -8;
    }

    if (is_directory(P_fs.fs))
    {
        int i;
        for (i = 0; i < 6; i++)
        {
#if You_txt_is_directory_ == 1
            Console_Lire_txt(L"{Note[" + std::to_wstring(i) + L"]=[" + P_cs.note[i] + L"] !}", 4, 4);
#endif
            if (P_fs.note[i] == L"")
                continue;
            else
            {
                //path canonical(const std::filesystem::path & p);

                /*std::filesystem::path fpath{"fname"};
                if (std::error_code ec{}; !std::filesystem::exists(fpath, ec)) {
                    std::cerr << "File system returned the following for \"" << fpath.string() << "\":\nError: " << ec.value() << "\nMessage: " << ec.message();
                }*/
                path p{ P_fs.note[i] };
                //if (error_code ec{}; !/*filesystem::*/exists(p, ec))
                if (error_code ec{}; experimental::filesystem::v1::exists(p, ec))
                {
                    std::wcout << L"iiiii" << std::endl;
                    //wcerr << L"File system returned the following for \"" << p.wstring() << L"\":\nError: " << ec.value() << L"\nMessage: " << ec.message() << endl;
#if You_txt_is_directory_ == 1
                    B.Ok_W(L"Le système de fichiers a renvoyé ce qui suit pour [" + p.wstring() + L']' + L" {" + P_cs.cs + L'}');
#endif
                    E.afficher_X(-6, L"Le système de fichiers a renvoyé ce qui suit pour [" + p.wstring() + L']' + L" {" + P_fs.fs + L'}', L"Erreur !!!");
                    //E.afficher_X(-6, L"Le système de fichiers a renvoyé ce qui suit pour [" + p.wstring() + L']' + L" {" + P_cs.cs + L'}', L"Érreur !!!", L"ddddddd");
                    exit(6);
                }

                if (is_directory(P_fs.note[i]))
                {
                    continue;
                }
                if (is_directory(P_fs.fs + P_fs.note[i]))
                {
                    P_fs.note[i] = P_fs.fs + P_fs.note[i];
                    continue;
                }
                if (is_directory(P_fs.fs + L'\\' + P_fs.note[i]))
                {
                    P_fs.note[i] = P_fs.fs + L'\\' + P_fs.note[i];
                    continue;
                }
                /*if (is_directory(P_cs.cs + L'\\' + P_cs.note[i]))
                {
                    P_cs.note[i] = P_cs.cs + L'\\' + P_cs.note[i];
                    continue;
                }*/
                else
                {
#if You_txt_is_directory_ == 1
                    //Console_Lire_txt(t + L" pas de Note[" + to_wstring(i) + L"]=[" + P_cs.note[i] + L']', 4, 4);
                    B.Ok_W(t + L" pas de Note[" + to_wstring(i) + L"]=[" + P_cs.note[i] + L']');
                    B.Ok_T(L"const int You_txt_is_directory(" + t + L") : Erreur !!!");
#endif
                    E.afficher_X(-6, t + L" pas de Note[" + std::to_wstring(i) + L"]=[" + P_fs.note[i] + L']', L"Erreur !!!");
                    return -6;
                }
            }

        }
    }
    else
    {
#if You_txt_is_directory_ == 1
        Console_Lire_txt(t + L" pas de " + P_fs.fs + L" ! Erreur !!!", 4, 4);
#endif
        E.afficher_X(-6, t + L" pas de " + P_fs.fs + L" !", L"Erreur !!!");
        return -6;
    }
#if You_txt_is_directory_ == 1
    B.Ok_T(L"const int You_txt_is_directory() : Ok !");
#endif
    return 0;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt_OK                                                                                                                                         #
// # const int You_txt_OK()                                                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt_OK()
{
#if You_txt_OK_ == 1
    B.Ok_T(L"const int You_txt_OK() :");
#endif
    const wchar_t* p{ L"../../" };
    path filePath(p);

    filePath /= L"you.txt";
    std::wstring t;
    try
    {
        // Dans le try, on est assuré que toute exception levée
        // pourra être traitée dans le bloc catch situé après.
        //t = lire_fichierTxt(L"you.txt");
        t = lire_fichierTxt(filePath);
    }
    // Notez qu'une exception s'attrape par référence constante.
    catch (runtime_error const& exception)
    {
        // On affiche la cause de l'exception.
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
    //#if You_txt_OK_ == 1
//    wcout << L"t={" << endl;
//    wcout << t << endl;
 //   wcout << L'}' << endl;
//#endif
    t += L'\n';
    size_t pos = 0;
    int i{ 0 }, j{ 0 };
    std::wstring t1 = L"", temps = L"";
    while (t != L"")
    {
        pos = t.find(L'\n');
        t1 = t.substr(0, pos);
        t1 = you_substr(t1);
        if (t1 == L"")
        {
            i = 0;
            t = t.substr(pos + 1);
            continue;
        }

        if (t1 == L"<Film>" || t1 == L"<Série>" || t1 == L"<Film DVD>" || t1 == L"<Film VOD>")
        {
#if You_txt_OK_ == 1
            //wcout << L"    " << L'{' + t1 + L'}' << endl;
            B.Ok_W(L"{" + t1 + L'}');
#endif
            if (t1 == L"<Film>")
                P_fs = P_film;
            else if (t1 == L"<Série>")
                P_fs = P_serie;
            else if (t1 == L"<Film VOD>")
                P_fs = P_film_VOD;
            else if (t1 == L"<Film DVD>")
                P_fs = P_film_DVD;
            else
            {
                E.afficher_X(-6, L"!!!", t1 + L" erreur [" + t1 + L"] !!!");
                return -6;
            }
            //
            P_fs.fs_++;
            //
            if (P_fs.fs_ > 1)
            {
                E.afficher_X(-5, L"Trouvez de " + t1 + L" !", t1 + L" erreur [" + P_fs.fs + +L"] !!!");
                return -5;
            }
            i = -1;
            temps = t1;
            j = You_txt_fs(t, temps);//, 1);
            if (j != 0)
            {
                E.afficher_X(-7, L"Impossible pas de hhhhhhhhh !!!", t1 + L" erreur (" + t1 + L") !!!");
                return j;
            }
            //i = You_txt_is_directory(temps);
            i = You_txt_is_directory(t1);
            if (i != 0)
            {
                E.afficher_X(-7, L"Impossible pas de " + t1 + L" !!!", t1 + L" erreur (" + t1 + L") !!!");
                return -7;
            }
            if (j == 0 && t1 == L"<Film>")
                P_film = P_fs;
            else if (j == 0 && t1 == L"<Série>")
                P_serie = P_fs;
            else if (j == 0 && t1 == L"<Film VOD>")
                P_film_VOD = P_fs;
            else if (j == 0 && t1 == L"<Film DVD>")
                P_film_DVD = P_fs;
            else
            {
                //
                E.afficher_X(-7, L"Impossible pas de qqqqqq !!!", t1 + L" erreur (" + t1 + L") !!!");
                return -7;
            }
            P_fs.fs_ = 0;
            i = 0;
        }
        else
        {
            /*i = -5;
            wcerr << L"Impossible pas de phrase !" << endl;
            E.afficher_X(-5, L"Impossible pas de phrase !", L"Érreur (" + t1 + L") !!!");
            return i;*/
        }
        //
        t = t.substr(pos + 1);
    }
#if You_txt_OK_ == 1
    if (P_film.fs != L"")
    {
        std::wcout << L"    " << L"Film = [" << P_film.fs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_film.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_film.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_film.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_film.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_film.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_film.note[5] << L"]."
            << std::endl;
    }
    if (P_serie.fs != L"")
    {
        std::wcout << L"    " << L"Série=[" << P_serie.fs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_serie.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_serie.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_serie.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_serie.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_serie.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_serie.note[5] << L"]."
            << std::endl;
    }
    if (P_film_VOD.fs != L"")
    {
        std::wcout << L"    " << L"Film VOD=[" << P_film_VOD.fs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_film_VOD.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_film_VOD.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_film_VOD.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_film_VOD.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_film_VOD.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_film_VOD.note[5] << L"]."
            << std::endl;
    }
    if (P_film_DVD.fs != L"")
    {
        std::wcout << L"    " << L"Film DVD=[" << P_film_DVD.fs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_film_DVD.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_film_DVD.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_film_DVD.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_film_DVD.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_film_DVD.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_film_DVD.note[5] << L"]."
            << std::endl;
    }
#endif
#if You_txt_OK_ == 1
    //wcout << L"::You_txt_OK() : Ok !" << endl;
    B.Ok_T(L"const int You_txt_OK() : Ok !");
#endif
    return 0;
}
