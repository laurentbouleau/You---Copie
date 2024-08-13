//#pragma warning(disable : 4834)
#include "pch.h"

// Audio : Français [VO]
// Sous-titres : Français [CC]

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
//#include <xstring>
#include <string>
//#include <algorithm>
#include <vector>
#include <iostream>
//#include <sstream>
//#include <ctime>
//#include <corecrt_wstring.h>
#include <codecvt>

extern int X;

extern class Erreur E;
extern class Bug B;

//extern const class Titre;

//extern tm;
//extern const int afficher_AD(std::wstring& a, std::wstring& ad, std::wstring const& nomFichier);

//extern int Titre::afficher_AD(std::wstring& a, std::wstring& ad, std::wstring const& nomFichier);

//extern const int afficher_Avec(std::wstring&, std::wstring const&, std::vector<std::wstring>&, std::vector<std::wstring>&);
extern const void afficher_Audiodescription(std::wstring& a, std::wstring const& nomFichier, std::wstring& audiodescription);
extern const void afficher_Avec(std::wstring& a_filename, const std::wstring& nomFichier, std::vector<std::pair<std::wstring, std::wstring>>& avec);
extern const void afficher_Disney_SJ(std::wstring& d, std::wstring const& nomFichier, std::wstring& d_sj);
extern const void afficher_Genre(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);
extern const void afficher_Image(const std::wstring& nomFichier, std::vector<std::wstring>& images);
extern const void afficher_Nationalite(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);
extern const void afficher_Netflix_SJ(std::wstring& d, std::wstring const& nomFichier, std::wstring& d_sj);

extern const void afficher_SJ(std::wstring&, const std::wstring&, std::wstring&);
extern const int afficher_T123(std::wstring t, std::wstring& t1, std::wstring& t2, std::wstring& t3);
extern const int afficher_Temps(std::wstring, tm&);
extern const bool afficher_Temps(std::wstring);
extern const void afficher_Temps(std::tm&);
extern const void afficher_Temps_OK(std::wstring&, bool);
extern const std::vector<std::wstring> afficher_Titre_Original(std::wstring, std::wstring);

extern const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs);
extern const std::wstring lire_fichierTxt(std::wstring const& nomFichier);

extern const void Console_Lire_txt(std::wstring);
extern const int Console_Lire_txt(std::wstring, int, int);
extern const int Console_Lire_txt2(std::wstring, int, int);
extern const void Console_Lire(std::wstring, int, int);
//extern const int Console_Lire_txt3(std::wstring, int, int);

extern std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace);

extern void PrintAudiodescription(const std::wstring& ad, bool ad_, std::wstring& titre_T, std::wstring& titre_t, int x);
extern void PrintGenres(const std::vector<std::wstring>& genres, bool genre_, const std::wstring& sous_genre, bool sous_genre_, std::wstring& titre_T, std::wstring& titre_t);
extern void PrintImages(const std::vector<std::wstring>& images, bool image_, std::wstring& titre_T, std::wstring& titre_t, int x1, int y1, int x2, int y2);
extern void PrintNationalites(const std::vector<std::wstring>& nationalites, bool nationalite_, std::wstring& titre_T, std::wstring& titre_t);
extern void PrintNetflixokounon(bool netflix_ok_ou_non, bool affichage_sur_actif, std::wstring& keyColor, std::wstring& valuesColor);
extern void PrintTitreOriginal(const std::vector<std::wstring>& titre_original, bool affichage_titre_original_actif, std::wstring& keyColor, std::wstring& valuesColor, std::wstring& keyColor2, std::wstring& valuesColor2);

//extern const std::vector<std::wstring> Sur;
//extern const std::vector<std::wstring> Sous_Genre;
//extern const std::vector<std::wstring> Gense;
//extern const std::vector<std::wstring> S_Nationalite;

extern const std::vector<std::wstring> AD;
//extern const wchar_t X;

//extern wstring utf8_to_wstring(string& str);
//extern const Titre titre;// C_S;
//const class Titre;

Serie::Serie()
{
    //std::vector<std::wstring>Titre{};
}

Serie::~Serie()
{
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_dossier                                                                                                                                   #
// # const int Serie::afficher_dossier(wstring const& t)                                                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_dossier(std::wstring const& t)
{
#if Serie_afficher_ == true
    B.Ok_T(L"const int Serie::afficher_dossier(" + t + L") :");
#endif

    if (affichage_titre_actif == false)
    {
#if Serie_afficher_dossier_ == true
        B.Ok_W(L"{" + t + L'}');

#endif
        int i = 0;
        int tm_year = 0, tm_mon = 0, tm_mday = 0;
        std::wstring date = L"";
        std::wstring t2;
        std::size_t idx, idx2 = 0;
        idx = t.find(L".[", 0);
        t2 = t.substr(0, idx);
        i = ::afficher_Titre(t2, titre, affichage_titre_actif);
        Titre__ = t2;
        idx = t.find_last_of(L"[");
        idx2 = t.find_last_of(L"]");
        if (idx2 - idx - 1 == 0)
            return -1;
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
#if Serie_afficher_dossier_ == true
                B.Ok_W(L"Pas de Sur={" + t2 + L"} !!!");
#endif
                E.afficher_X(-1, L"Pas de Sur={" + t2 + L"} !!!", L"Erreur (" + t2 + L") !!!");
                return EXIT_FAILURE;
            }
            else
            {
                sur = t2;
            }
            if (sur == L"Netflix")
                netflix_ok_ou_non = true;
            else if (sur == L"Disney+")
                disney_ok_ou_non = true;
            else
                ;
            std::wcout << L"Sur={" << sur << L"}" << std::endl;
            idx2 = idx3 - 2;
        }
        idx++;
        if (t.at(idx2) == L' ' || t.at(idx2) == L'-' ||
            t.at(idx2) == L'0' || t.at(idx2) == L'1' || t.at(idx2) == L'2' || t.at(idx2) == L'3' || t.at(idx2) == L'4' ||
            t.at(idx2) == L'5' || t.at(idx2) == L'6' || t.at(idx2) == L'7' || t.at(idx2) == L'8' || t.at(idx2) == L'9')
        { // Date
            t2 = t.substr(idx, idx2 - idx + 1);
            i = afficher_Date(t2);
#if Serie_afficher_dossier_ == 1
            B.Ok_W(L"afficher_Date={" + t2 + L'}');
#endif
        }
        idx = t.find(L"].");
        if (idx != std::wstring::npos)
        { // Sous_Genre
            idx += 2;
            sous_genre = t.substr(idx);
            //wstring sous_genre = L"";
            i = afficher_Sous_Genre(sous_genre);
            affichage_sous_genre_actif = true;
        }
        D_I = 0;
#if Serie_afficher_dossier_ == true
        //wcout << L"    " << L"t={" << t << L"}" << endl;
        B.Ok_W(L"t={" + t + L"}");
#endif
    }
    else
    {
        std::size_t pos;
        pos = t.length();
        pos--;
        std::wstring t2 = t.substr(0, pos);
        pos = t2.find_last_of(L"\\");
        t2 = t2.substr(++pos);
        D[D_I] = t;
        //
        if (
            (t2[4] == L'-' && t2[7] == L'-' /*&& pos == 11*/  /* && t[11] == wstring::npos*/)
            ||
            (t2[4] == std::wstring::npos)
            ||
            t2 == L"Nouveau dossier"
            )
            // XXXX-XX-XX ou xxxx ou "Nouveau dossier"
        {
            int i = afficher_Diffusee(D_I, t2);
            if (Date_Diffusee_a_partir_de_[D_I] == true)
            {
#if Serie_afficher_dossier_ == 1
                //wcout << L"    " << L"Date_Diffusee_a_partir_de_[" << Date_Diffusee_a_partir_de_[D_I] << L"] = ok !" << endl;
                B.Ok_W(L"Date_Diffusee_a_partir_de_={" + to_wstring(Date_Diffusee_a_partir_de_[D_I]) + L"} = ok !");
#endif
                //return 0;
            }
        }
        else
        {
#if Serie_afficher_dossier_ == 1
            //wcout << L"    " << L"Date_Diffusee_a_partir_de_[" << Date_Diffusee_a_partir_de_[D_I] << L"] = érreur !!!" << endl;
            B.Ok_W(L"Date_Diffusee_a_partir_de_[" + to_wstring(Date_Diffusee_a_partir_de_[D_I]) + L"} = erreur !!!");
#endif
            E.afficher_X(-1, t2, t + L" erreur XXXX-YY-ZZ !!!");
            return EXIT_FAILURE;
        }
        //D_J[_X2_]
        //wcout << L"*****" << endl;
#if Serie_afficher_dossier_ == 1
        //wcout << L"-----> D[" << D[D_I] << L"]=" << t << endl;
        B.Ok_W(L"-----> D[" + D[D_I] + L"]=" + t2);
#endif
        D_J[D_I] = 0;
        D_I++;
    }
#if Serie_afficher_dossier_ == true
    //wcout << B_T << L"const int Serie::afficher(" << t << L") : Ok !" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_dossier() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_fichier                                                                                                                                   #
// # const int Serie::afficher_fichier(std::wstring const& nomFichier, int const& nomImage = TXT_)                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_fichier(std::wstring const& nomFichier, int const& nomImage = TXT_)
{	
#if Serie_afficher_fichier_ == 1
    B.Ok_T(L"const int Serie::afficher_fichier(" + nomFichier + L", " + std::to_wstring(nomImage) + L") : ");
    B.Ok_W(L"{" + nomFichier + L"}");
#endif
    int i = 0;
    std::size_t pos;
    std::vector <wstring>::iterator iter;
    //::S_Nationalite;
    pos = nomFichier.find_last_of(L"\\");
    if (Ok == L"")
        Ok = nomFichier.substr(0, pos);
    pos++;
    std::wstring t = nomFichier.substr(pos);
    //if((t == (Titre__ + L".txt")) /* || L"Titre.txt"*/)
    //{
    //    wcout << L"rrrr" << endl;
    //    i = afficher_Titre(t, _T);
        /*if (t == L"Titre.txt")
        {
            wcout << L"www t={" << t << L"} : ok !" << endl;
            Ok = t;
        }*/
        //i ::
//#if Serie_afficher_1_ == 1
        //wcout << B_T << L"const int Serie::afficher(1)() : Ok !" << B_t << endl;
//        B.Ok_T(L"const int Serie::afficher() : Ok !");
//#endif
//        return EXIT_SUCCESS;
//    }
 //   else 
    if (nomImage == TXT_)
    {
        if (std::isdigit(t[0]))
        {
            /*          0 1 2 3 4 5 6 7 8 9                   */
            if (int j = std::stoi(t, 0))
            {
                std::wstring t_ = std::to_wstring(j);
                if (t == t_)
                {
#if Serie_afficher_fichier_ == 1
                    B.Ok_W(L"==" + t + L"==");
                    B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                    return EXIT_SUCCESS;
                }
            }
            // Temps
            if (std::isdigit(t[0]) && Temps_ == false)
            {
                i = /*::*/afficher_Temps(t, Temps);
                if (i == -1)
                    goto ok;
                if (Temps_ == false)
                {
                    if (Temps.tm_min > 60 && Temps.tm_min < 120 && Temps.tm_hour == 0)
                    {
                        ::afficher_Temps(Temps);
                    }
                    Temps_ = true;
#if Serie_afficher_fichier_ == 1
                    B.Ok_W(L"Temps={" + to_wstring(Temps.tm_hour) + L"h " + to_wstring(Temps.tm_min) + L"}");
                    B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                    return EXIT_SUCCESS;
                }
            }
        }
        else
        /*          A B C D E F G  H I J K L M N O P Q R S T U V W Y Z            */
        {
            // AD
            if (t == L"AD.txt")
            {
                afficher_Audiodescription(t, nomFichier, audiodescription);
#if Serie_afficher_fichier_ == 1
                B.Ok_W(L"AD={" + audiodescription + L"}");
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // Avec
            /*if (L"Avec.txt" == t && Avec_ == false)
            {
                i = ::afficher_Avec(t, nomFichier, Avec, Avec_role);
                if (i == -1)
                {
#if Serie_afficher_fichier_ == 1
                    //wcout << L"    " << L"Avec={} : Erreur !!!" << endl;
                    B.Ok_W(L"Avec={} : Erreur !!!");
#endif
                    E.afficher_X(-1, nomFichier, t + L"Avec={} : Erreur !!!");
                    return EXIT_FAILURE;
                }
                //Avec_ = 1;
                if (Avec_ == false)
                {
                    Avec_ = true;
#if Serie_afficher_fichier_ == 1
                    //wcout << L"    " << L"Avec={" << t << L"}" << endl;
                    B.Ok_W(L"Avec={" + t + L"}");
                    //wcout << B_T << L"const int Serie::afficher(1)() : Ok !" << B_t << endl;
                    B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                    return EXIT_SUCCESS;
                }
            }*/
            // Netflix
            if (t == L"Netflix.txt")
            {
                afficher_Netflix_SJ(t, nomFichier, netflix_sj);
#if Cinema_afficher_fichier_ == 1
                B.Ok_W(L"netflix={" + netflix_sj + L'}');
                B.Ok_T(L"const int Cinema::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // Chaîne d'origine
            if (t == L"Chaîne d'origine.txt")
            {
                afficher_Chaine(t, nomFichier, chaine);
#if Serie_afficher_fichier_ == 1
                B.Ok_W(L"Chaîne={" + chaine + L"}");
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // Créée par
            if (L"Créée par.txt" == t)
            {
                afficher_Creee_par(t, nomFichier, creee_par);
#if Serie_afficher_fichier_ == 1
                B.Ok_W(L"creee_par.size()={" + std::to_wstring(creee_par.size()) + L"} ok !");
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // Disney+
            if (t == L"Disney+.txt")
            {
                afficher_Disney_SJ(t, nomFichier, disney_sj);
                return EXIT_SUCCESS;
            }
            // En relation avec
            if (L"En relation avec.txt" == t)
            {
                afficher_En_relation_avec(t, nomFichier, en_relation_avec);
#if Serie_afficher_fichier_ == 1
                B.Ok_W(L"en_relation_avec.size()={" + std::to_wstring(en_relation_avec.size()) + L"} ok !");
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // Genre
            if (t == L"Genre.txt")
            {
                afficher_Genre(t, nomFichier, genre, ::Genre);
#if Serie_afficher_fichier_ == 1
                //wcout << L"    " << L"Gense={" << t << L"}" << endl;
                B.Ok_W(L"genre.size()={" + std::to_wstring(genre.size()) + L"}");
                //wcout << B_T << L"const int Serie::afficher(1)() : Ok !" << B_t << endl;
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // Nationalité
            if (t == L"Nationalité.txt")
            {
                afficher_Nationalite(t, nomFichier, nationalite, ::Nationalite);
#if Serie_afficher_fichier_ == 1
                B.Ok_W(L"nationalite={" + std::to_wstring(nationalite.size()) + L"}");
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // Netflix
            if (t == L"Netflix.txt")
            {
                afficher_Netflix_SJ(t, nomFichier, netflix_sj);
#if Cinema_afficher_fichier_ == 1
                B.Ok_W(L"netflix={" + netflix_sj + L'}');
                B.Ok_T(L"const int Cinema::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // SJ
            if (t == L"SJ.txt")
            {
                afficher_SJ(t, nomFichier, sj);
                return EXIT_SUCCESS;
            }
            // Titre
            if ((t == L"Titre.txt")
                && affichage_titre_actif)
            {
                i = afficher_Titre(t, nomFichier);
                {
#if Serie_afficher_fichier_ == 1
                    //wcout << L"    " << L"Titre={" << t << L"}" << endl;
                    //wcout << L"    " << L"Titre_=" << Titre_ << endl;
                    B.Ok_W(L"Titre={" + t + L"}");
                    B.Ok_W(L"Titre_={" + std::to_wstring(affichage_titre_actif) + L"}");
                    //wcout << B_T << L"const int Serie::afficher(1)() : Ok !" << B_t << endl;
                    B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                    Ok = t;
                    return EXIT_SUCCESS;
                }
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
#if Serie_afficher_fichier_ == 1
                //wcout << L"    " << L"www.nautiljon.com.txt" << endl;
                B.Ok_W(L"www.nautiljon.com.txt");
#endif
                return EXIT_SUCCESS;
            }
        }
    }
    else if (nomImage == JGP_ || nomImage == PNG_ || nomImage == WEBP_)
    {
        //i = afficher_Image(nomFichier, image);
        //afficher_Image(const std::wstring& nomFichier, std::vector<std::wstring>& images);




        ::afficher_Image(nomFichier, image);



#if Serie_afficher_fichier_ == 1
        //wcout << L"    " << L"Image={" << t << L"}" << endl;
        B.Ok_W(L"Image={" + t + L"}");
        //wcout << B_T << L"const int Serie::afficher(1)() : Ok !" << B_t << endl;
        B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
        return EXIT_SUCCESS;
    }
    else
    {
    //std::wcout << L"qqq qqq qqq" << std::endl;
        return EXIT_FAILURE;
    }
ok:
    if (t == L"Note.txt")
    {
#if Serie_afficher_fichier_ == 1
        B.Ok_W(L"Erreur !!! {Note.txt} ---> XXXX-XX-XX !");
#endif
        E.afficher_X(-2, nomFichier, L"Erreur !!!", L"Note.txt ---> XXXX-XX-XX !");
#if Serie_afficher_1_ == 1
        B.Ok_T(L"const int Serie::afficher_fichier() : Faux !!!");
#endif
    }
    else
    {
        std::wcout << L"sss sss sss" << std::endl;
        E.afficher_X(-1, nomFichier, L"Erreur {" + t + L"} !!!");
#if Serie_afficher_fichier_ == 1
        B.Ok_W(L"Erreur {" + t + L"} !!!");
        B.Ok_T(L"const int Serie::afficher_fichier() : Faux !!!");
#endif
    }
    //	wcout << L"qqqqqqqqqqq" << endl;
    return EXIT_FAILURE;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_fichie                                                                                                                                    #
// # const int Serie::afficher_fichier(int I, wstring const& _T, int const& _T_ = _TXT_)                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_fichier(int I, std::wstring const& nomFichier, int const& nomImage = TXT_)
{
    int i = 0;
    std::size_t pos;
#if Serie_afficher_fichier_2_ == 1
    B.Ok_T(L"const int Serie::afficher_fichier(" + std::to_wstring(I) + L", " + nomFichier + L", _T_ = _TXT_) :");
#endif
    pos = nomFichier.find_last_of(L"\\");
    pos++;
    std::wstring t = nomFichier.substr(pos);
    pos = t.length();
    std::wstring filename = t;
    t = t.substr(0, pos - 4);
    pos = pos - 4;
    if (!(std::isdigit(t[0])))
    {
        // AD
        if (filename == L"AD.txt")
        {
            afficher_Audiodescription(t, nomFichier, d_audiodescription[I]);
#if Serie_afficher_fichier_ == 1
            B.Ok_W(L"AD={" + audiodescription + L"}");
            B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
            return EXIT_SUCCESS;
        }
        // Avec
        if (filename == L"Avec.txt")
        {
            //i = afficher_Avec_2(I, filename, nomFichier);
//#if Serie_afficher_fichier_2_ == 1
            //wcout << L"    " << L"Avec ok" << endl;
//            B.Ok_W(L"Avec={Avec}");
            //wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
//            B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
//#endif
            //return i;


            afficher_Avec(t, nomFichier, avec[I]);
            return EXIT_SUCCESS;

        }
        // Chaîne d'origine -
        if (filename == L"Chaîne d'origine.txt")
        {
            //afficher_chaine(I, filename, nomFichier, D_Chaine[I]);
            afficher_Chaine(filename, nomFichier, d_chaine[I]);
#if Serie_afficher_fichier_ == 1
            B.Ok_W(L"Chaîne={" + chaine + L"}");
            B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
            return EXIT_SUCCESS;
        }
        // DVD
        if (filename == L"DVD.txt")
        {
#if Serie_afficher_fichier_2_ == 1
            //wcout << L"    " << L"DVD ok" << endl;
            B.Ok_W(L"DVD ok");
            //wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
            B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
            D_DVD[I] = true;
            return EXIT_SUCCESS;
        }
        // Netflix
        /*if (t == L"Netflix")
        {
#if Serie_afficher_2_ == 1
            wcout << L"    " << L"Netflix ok" << endl;
#endif
            D_Netflix[I] = true;
#if Serie_afficher_2_ == 1
            wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
#endif
            return 0;
        }*/
        // Note
        if (filename == L"Note.txt")
        {
            afficher_Note(t, nomFichier, I);
#if Serie_affiche_fichierr_2_ == 1
            //wcout << L"    " << L"D_Note : [" << D_Note[I] << L']' << endl;
            //B.Ok_W(L"D_Note[" + std::to_wstring(I) + L"]={" + std::to_wstring(D_Note[I]) + L'}');
            //wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
            //B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
            //D_Note_[I] = true;
            return EXIT_SUCCESS;
        }
        // Titre
        if (filename == L"Titre.txt")
        {
            i = afficher_Titre_3(I, filename, nomFichier);
            if (i == -1)
            {
                E.afficher_X(-1, L"Erreur", L"Titre : " + filename + L" !");
                return EXIT_FAILURE;
            }
#if Serie_afficher_fichier_2_ == 1
            //wcout << L"    " << L"Titre : [" << D_Titre[I] << L']' << endl;
            B.Ok_W(L"D_Titre[" + std::to_wstring(I) + L"]={" + D_Titre[I] + L'}');
            B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
            D_Titre_[I] = true;
            return EXIT_SUCCESS;
        }
        // Image
        if (nomImage == JGP_ || nomImage == PNG_ || nomImage == WEBP_)
        {
            //d_image[I]
            //i = afficher_Image(I, nomFichier);
            ::afficher_Image(nomFichier, d_image[I]);

#if Serie_afficher_fichier_2_ == 1
            //wcout << L"    " << L"Image={" << t << L"}" << endl;
            B.Ok_W(L"image={" + t + L'}');
            //wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
            B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
            return EXIT_SUCCESS;
        }
        // Erreur !
        if (t != L"")
        {
#if Serie_afficher_fichier_2_ == 1
            //wcout << L"    " << L"aaaaaaaaaaaa" << endl;
            B.Ok_W(L"Attention : Erreur de {" + t + L"} !!!");
            B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
            E.afficher_X(-1, nomFichier, L'{' + t + L".txt} !!!");
            return EXIT_FAILURE;
        }
    }
    else
    {
        //
        if (
            (t[0] == L'1' || t[0] == L'2' || t[0] == L'3' || t[0] == L'4' || t[0] == L'5' || t[0] == L'6' || t[0] == L'7' || t[0] == L'8' || t[0] == L'9')
            && t[1] == L'x'
            )
        {
            t = t.substr(2);
            //#if Series_afficher_2_ == 1
            //		wcout << L"j=[" << 1 << L"] t=[" << t << L"]" << endl;
            //#endif
            i = afficher_X_x(I, D_J[I], nomFichier, t);
            if (i == 0)
            {
                D_J[I]++;
#if Serie_afficher_fichier_2_ == 1
                //wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            else
            {
                E.afficher_X(-1, nomFichier, L'[' + t + L".txt] !!!");
#if Serie_afficher_fichier_2_ == 1
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_FAILURE;
            }
        }
        if (
            (t[0] == L'1' || t[0] == L'2' || t[0] == L'3' || t[0] == L'4' || t[0] == L'5' || t[0] == L'6' || t[0] == L'7' || t[0] == L'8' || t[0] == L'9')
            &&
            (std::isdigit(t[1]))
            && t[2] == L'x'
            )
        {
            t = t.substr(3);
#if Serie_afficher_fichier_2_ == 1
            //wcout << L"    " << L"j=[" << 2 << L"] t=[" << t << L"]" << endl;
            B.Ok_W(L"j={2} t={" + t + L'}');
#endif
            i = afficher_X_x(I, D_J[I], nomFichier, t);
            if (i == 0)
            {
                D_J[I]++;
#if Serie_afficher_fichier_2_ == 1
                //wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            else
            {
                E.afficher_X(-1, nomFichier, L'[' + t + L".txt] !!!");
#if Serie_afficher_fichier_2_ == 1
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_FAILURE;
            }
        }
        if (int j = std::stoi(t, 0))
        {
            //wstring t2 
            std::wstring t_ = std::to_wstring(j);
            if (t == t_)
            {
#if Serie_afficher_fichier_2_ == 1
                //wcout << L"    " << L"t == " << t << L" == " << endl;
                B.Ok_W(L"t== " + t + L" ==");
#endif
                i = afficher_Titre_2(I, t, nomFichier);
                //afficher_X(0, _T, t + L" ok !" + t2);
#if Serie_afficher_fichier_2_ == 1
                //wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            else
            {
                E.afficher_X(-1, nomFichier, L'[' + t + L".txt] !!!");
#if Serie_afficher_fichier_2_ == 1
                B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
                return EXIT_FAILURE;
            }
        }
//        D_J_[I] = true;

    }
    // Image
    if (t != L"" && filename != L"")
    {
        if(t != L"")
            E.afficher_X(-1, nomFichier, L"{" + t + L"} !!!");
        if (t != L"")
            E.afficher_X(-1, nomFichier, L"{" + filename + L" (filename)} !!!");
#if Serie_afficher_fichier_2_ == 1
        B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
        return EXIT_FAILURE;
    }
    //afficher_X(-1, _T, t + L" !!!");
#if Serie_afficher_fichier_2_ == 1
    //wcout << B_T << L"const int Serie::afficher() : Ok !" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_fichier() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Avec_2                                                                                                                                    #
// # const int Serie::afficher_Avec_2(int I, wstring a, wstring _T)                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

/*const int Serie::afficher_Avec_2(int I, std::wstring& filename, std::wstring const& nomFichier)
{
#if Serie_afficher_Avec_2_ == 1
    B.Ok_T(L"const int Serie::afficher_Avec_2(" + std::to_wstring(I) + L", " + filename + L", " + nomFichier + L") :");
#endif
    if (filename != L"Avec.txt")
    {
#if Serie_afficher_Avec_2_ == 1
        B.Ok_W(L"Avec : pas tous");
#endif
        E.afficher_X(1, nomFichier, filename);
        return EXIT_FAILURE;
    }
    //wstring p = ::afficher_fichier_lire(a, _T);
    std::wstring p;
    try
    {
        p = lire_fichierTxt(nomFichier);
    }
    catch (runtime_error const& exception)
    {
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }

    if (!p.empty())
    {
        p = p + L"\n";
        std::size_t pos;
        while (pos = p.find(L"\n"))
        {
            if (p[0] != p.length())
            {
                D_Avec_role[I].push_back(p.substr(0, pos));
                p = p.substr(pos + 1);
            }
            else
                break;
        }
#if Serie_afficher_Avec_2_ == 1
        //wcout << L"Avec_role[" << I << L"]=(";
        std::wstring wstr = L"Avec_role[" + std::to_wstring(I) + L"]={";
        std::vector <std::wstring>::iterator iter;
        int i;
        for (iter = D_Avec_role[I].begin(), i = 0; iter != D_Avec_role[I].end(); iter++, i++)
        {
            //wcout << *iter;
            wstr += *iter;
            if (i != D_Avec_role[I].size() - 1)
                //wcout << L", ";
                wstr += L", ";
        }
        //wcout << L')' << endl;
        B.Ok_W(wstr + L'}');
        B.Ok_T(L"const int Serie::afficher_Avec_2() : Ok !");
#endif
    }
    return EXIT_SUCCESS;
}*/

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Chaine                                                                                                                                    #
// # const void Serie::afficher_chaine(std::wstring c_filename, std::wstring const& nomFichier, std::wstring& chaine) const                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Serie::afficher_Chaine(std::wstring& c_filename, std::wstring const& nomFichier, std::wstring& chaine) const
{ // Chaîne
#if Serie_afficher_Chaine_ == 1
    B.Ok_T(L"const void Serie::afficher_Chaine(" + c_filename + L", " + nomFichier + L", " + chaine + L") :");
    B.Ok_W(L"t={" + c_filename + L'}');
#endif
    assert((c_filename == createdBy_filename) && L"Erreur !!! Chaîne d'origine... !");
    chaine = lire_fichierTxt(nomFichier);
    assert((chaine.size() != 0));
#if Serie_afficher_Chaine_ == 1
    B.Ok_W(L"chaine={" + chaine + L'}');
    B.Ok_T(L"const void Serie::afficher_Chaine() : Ok !");
#endif
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Creee_par                                                                                                                                          #
// # void Serie::afficher_Creee_par(std::wstring& c_filename, std::wstring const& nomFichier, std::vector<std::wstring>&c_p) const                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Serie::afficher_Creee_par(std::wstring& c_filename, std::wstring const& nomFichier, std::vector<std::wstring>& c_p) const
{
    assert((c_filename == createdBy_filename) && L"Erreur !!! Créée par... !");
    c_p = lire_fichierTxt(nomFichier, { L"\n", L", " });
    assert((c_p.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Date                                                                                                                                               #
// # const int Serie::afficher_Date(wstring d)                                                                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Date(std::wstring d)
{ // Date(s)
#if Serie_afficher_Date_ == 1
    //wcout << B_T << L"Serie_afficher_Date()" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_Date(" + d + L") :");
#endif
    if (Date_ == true)
    {
#if Serie_afficher_Date_ == 1
        //wcout << L"d=(" << d << L") erreur !!!" << endl;
        B.Ok_W(L"d={" + d + L"} erreur !!!");
#endif
        return EXIT_FAILURE;
    }
    std::wstring s_ = L"";
    std::size_t idx = 0;
    int year;
    std::wstring d_[_X_];
    int i = 0;
    while (d.length() != 0)
    {
        //year = 0;
        //idx = 0;
        if (
            //(d[0] == L'0' || d[0] == L'1' || d[0] == L'2' || d[0] == L'3' || d[0] == L'4' || d[0] == L'5' || d[0] == L'5' || d[0] == L'6' || d[0] == L'7' || d[0] == L'8' || d[0] == L'9') &&
            std::isdigit(d[0]) &&
            //(d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3' || d[1] == L'4' || d[1] == L'5' || d[1] == L'5' || d[1] == L'6' || d[1] == L'7' || d[1] == L'8' || d[1] == L'9') &&
            std::isdigit(d[1]) &&
            //(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9') &&
            isdigit(d[2]) &&
            //(d[3] == L'0' || d[3] == L'1' || d[3] == L'2' || d[3] == L'3' || d[3] == L'4' || d[3] == L'5' || d[3] == L'5' || d[3] == L'6' || d[3] == L'7' || d[3] == L'8' || d[3] == L'9')
            std::isdigit(d[3])
            )
        {
#if Serie_afficher_Date_ == 1
            //wcout << L"date=[" << d[0] << d[1] << d[2] << d[3] << L"]" << endl;
            B.Ok_W(L"date={" + d.substr(0, 4) + L'}');
#endif
            d_[i] = d.substr(0, 4);
            year = std::stoi(d_[i], &idx, 10);
            i++;
            d = d.substr(4);
            //continue;
        }
        if (d[0] == L'-')
        {
#if Serie_afficher_Date_ == 1
            //wcout << L'-' << d[0];
            //printf("-");
#endif
            d = d.substr(1);
            //continue;
            /*if (d[0] == L' ')
            {
                wcout << endl;
            }*/
        }
        if (d[0] == L' ')
        {
            d = d.substr(1);
            //break;
        }
    }
    //wcout << L"]" << endl;
    int j = i;
#if Serie_afficher_Date_ == 1
    //wcout << L"Date=[";
    std::wstring wstr = L"Date={";
    for (i = 0; i < j; i++)
    {
        //wcout << d_[i];
        wstr += d_[i];
        if (i != j - 1)
            //wcout << L' ';
            wstr += L' ';
    }
    //wcout << L"]" << endl;
    B.Ok_W(wstr + L'}');
    B.Ok_T(L"const int Serie::afficher_Date() : Ok !");
#endif
    Date_ = true;
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Diffusee                                                                                                                                           #
// # const int Serie::afficher_Diffusee(int I, wstring d)                                                                                               #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Diffusee(int& I, std::wstring const& d)
{
#if	Serie_afficher_Diffusee_ == 1
    //wcout << B_T << L"const int Serie_afficher_Diffusee(" << I + 1 << L", " << d << L") :" << B_t << endl;
    B.Ok_T(L"const int Serie_afficher_Diffusee(" + std::to_wstring(I) + L", " + d + L") :");
#endif
    if (d == L"")
    {
#if	Serie_afficher_Diffusee_ == 1
        //wcout << L"    " << L"Date_Diffusee_a_partir_de[" << I << L"] = 0 !!!" << endl;
        B.Ok_W(L"Date_Diffusee_a_partir_de[" + std::to_wstring(I) + L"} = 0 !!!");
#endif
        B.Ok_T(L"const int Serie_afficher_Diffusee() : Ok !");
        return EXIT_SUCCESS;
    }
    if (
        (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
        std::isdigit(d[1]) &&
        std::isdigit(d[2]) &&
        std::isdigit(d[3]))
    {
        goto stop;
    }
    E.afficher_X(-1, L"", d);
    return EXIT_FAILURE;
stop:
    int year = 0, mon = 0, mday = 0;
    // %d/%m/%Y
    std::tm D = { 0 };
    // year
    std::wstring x = d.substr(0, 4);
    year = std::stoi(x);
    if (
        (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
        //(d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3' || d[1] == L'4' || d[1] == L'5' || d[1] == L'5' || d[1] == L'6' || d[1] == L'7' || d[1] == L'8' || d[1] == L'9') &&
        //(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9') &&
        //(d[3] == L'0' || d[3] == L'1' || d[3] == L'2' || d[3] == L'3' || d[3] == L'4' || d[3] == L'5' || d[3] == L'5' || d[3] == L'6' || d[3] == L'7' || d[3] == L'8' || d[3] == L'9')
        std::isdigit(d[1]) &&
        std::isdigit(d[2]) &&
        std::isdigit(d[3])
        )
    {
        x = d.substr(0, 4);
        year = std::stoi(d);
        if (year <= 1900 || year >= 3001)
        { // Erreur year
#if Serie_afficher_Diffusee_ == 1
            //wcerr << L"    " << L"year=" << year << endl;
            B.Ok_W(L"year=" + std::to_wstring(year));
#endif
            return EXIT_FAILURE;
        }
    }
    else
    {
#if Serie_afficher_Diffusee_ == 1
        //wcout << L"    " << L"year=???" << endl;
        B.Ok_W(L"year=???");
#endif
        return EXIT_FAILURE;
    }
    if (
        (d[5] == L'0' || d[5] == L'1') &&
        //(d[6] == L'0' || d[6] == L'1' || d[6] == L'2' || d[6] == L'3' || d[6] == L'4' || d[6] == L'5' || d[6] == L'6' || d[6] == L'7' || d[6] == L'8' || d[6] == L'9')
        std::isdigit(d[6])
        )
    {
        x = d.substr(5, 2);
        mon = std::stoi(x);
        if (mon <= 0 || mon >= 13)
        { // Erreur mon
#if Serie_afficher_Diffusee_ == 1
            //wcerr << L"    " << L"mon=" << mon << endl;
            B.Ok_W(L"mon=" + std::to_wstring(mon));
#endif
            return EXIT_FAILURE;
        }
    }
    if (
        (d[8] == L'0' || d[8] == L'1' || d[8] == L'2' || d[8] == L'3') &&
        //(d[9] == L'0' || d[9] == L'1' || d[9] == L'2' || d[9] == L'3' || d[9] == L'4' || d[9] == L'5' || d[9] == L'6' || d[9] == L'7' || d[9] == L'8' || d[9] == L'9')
        std::isdigit(d[9])
        )
    {
        x = d.substr(8, 2);
        mday = std::stoi(x);
        if (mday <= 0 || mday >= 32)
        { // Erreur mday
#if Serie_afficher_Diffusee_ == 1
            //wcerr << L"    " << L"mday=" << mday << endl;
            B.Ok_W(L"mday=" + std::to_wstring(mday));
#endif
            return EXIT_FAILURE;
        }
    }
    D.tm_year = year - 1900;
    D.tm_mon = mon - 1;
    D.tm_mday = mday;
#if Serie_afficher_Diffusee_ == 1
    //wcout << L"    " << L"[" << year << L"/" << mon << L"/" << mday << L"]" << endl;
    B.Ok_W(L'{' + to_wstring(year) + L'/' + std::to_wstring(mon) + L'/' + to_wstring(mday) + L'}');
#endif
    Date_Diffusee_a_partir_de[I] = D;
    Date_Diffusee_a_partir_de_[I] = true;
#if	Serie_afficher_Diffusee_ == 1
    //wcout << B_T << L"const int Serie_afficher_Diffusee(" << I + 1 << L", " << d << L") : Ok !" << B_t << endl;
    B.Ok_T(L"const int Serie_afficher_Diffusee() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # En relation avec                                                                                                                                   #
// # const int Serie::afficher_En_relation_avec(std::wstring& e_filename, std::wstring const& nomFichier, std::vector<std::wstring>&e_r_a) const        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Serie::afficher_En_relation_avec(std::wstring& e_filename, std::wstring const& nomFichier, std::vector<std::wstring>&e_r_a) const
{
    assert((e_filename == createdBy_filename) && L"Erreur !!! En relation avec... !");
    e_r_a = lire_fichierTxt(nomFichier, { L"\n", L", " });
    assert((en_relation_avec.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Note                                                                                                                                      #
// # const void Serie::afficher_Note(std::wstring& n_filename, std::wstring const& nomFichier, int I)                                                   #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::afficher_Note(std::wstring& n_filename, std::wstring const& nomFichier, int I)
{ // 0...5 ou -1
    assert((n_filename == createdBy_filename) && L"Erreur !!! Note... !");
    std::wstring n = lire_fichierTxt(nomFichier);
    std::size_t pos = n.length();
#if	Serie_afficher_Note_ == 1
    B.Ok_T(L"const void Serie::afficher_Note(" + n + L", " + nomFichier + L", int& note, bool& note_) :");
#endif
    if (n == L"")
    {
        m_note.push_back(std::make_pair(I, -1.0));
#if	Serie_afficher_Note_ == 1
        B.Ok_T(L"const void Serie::afficher_Note() : Ok !");
#endif
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
    {
        
        m_note.push_back(make_pair(I, std::stod(n)));
#if	Serie_afficher_Note_ == 1
        //B.Ok_W(L"note=" + std::to_wstring(note));
        std::wcout << L"note={" << n << L"}" << std::endl;
#endif
    }
    else
    {
        if ((n[1] == L',' || n[1] == L'.') && iswdigit(n[2]) && pos == 3)
        {
            //
            n[1] = L',';
            //
#if	Serie_afficher_Note_ == 1
            //B.Ok_W(L"f=" + std::to_wstring(f));
#endif
            // Ok !!!
            m_note.push_back(make_pair(I, std::stod(n)));
#if	Serie_afficher_Note_ == 1
            //B.Ok_W(L"note=" + std::to_wstring(note));
            std::wcout << L"note={" << n << L"}" << std::endl;
#endif
        }
        else
        {
            E.afficher_X(-1, n, L"Pas de…");
        }
    }
#if	Serie_afficher_Note_ == 1
    B.Ok_T(L"const void Serie::afficher_Note() : Ok !");
#endif
    return;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # t123 temps                                                                                                                                         #
// # const int Serie::afficher_t123_temps(vector<wstring>& t, wstring& p, wstring& tt, wstring& _T)                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_t123_temps(std::vector<std::wstring>& t, std::wstring& p, std::wstring& tt, std::wstring& nomFichier)
{
#if Serie_afficher_t123_temps_ == 1
    B.Ok_T(L"const int Serie::afficher_t123_temps(vector<wstring>&t, wstring& p, " + tt + L", " + nomFichier + L") :");
    B.Ok_W(L"tt={" + tt + L'}');
#endif
    if (p == L"")
    {
        if(tt != L"")
            t.push_back(tt);  // tt
        else
            t.push_back(L"");  // tt={}
        t.push_back(L""); // t1
        t.push_back(L""); // t2
        t.push_back(L""); // t3
        t.push_back(L""); // temps
        t.push_back(L""); // p
#if Serie_afficher_t123_temps_ == 1
        if(tt != L"")
            B.Ok_W(L"tt   [0]={" + tt + L'}');
        else
            B.Ok_W(L"tt   [0]={}");
        B.Ok_W(L"t1   [1]={}");
        B.Ok_W(L"t2   [2]={}");
        B.Ok_W(L"t3   [3]={}");
        B.Ok_W(L"temps[4]={}");
        B.Ok_W(L"p    [5]={}");
        B.Ok_T(L"const int Serie::afficher_t123_temps() : Ok !");
#endif
        return EXIT_SUCCESS;
    }
    std::size_t pos = 0;
    std::wstring t1, t2, t3, temps;
    t1 = t2 = t3 = temps = L"";
    std::wstring v;
    bool t123_ = false, temps_ = false;
    p += L'\n';
    //
    pos = p.find(L'\n');
    v = p.substr(0, pos);
    //
    //wcout << L"v={" << v << L'}' << endl;
    //
    temps_ = afficher_Temps(v);
    if (temps_ == false)
    {
        int i = afficher_T123(v, t1, t2 = L"", t3 = L"");
        if (i == -1)
            E.afficher_X(0, L"t123_ == false", L"érreur (" + tt + L") !!!");
        else
        {
            p = p.substr(pos + 1);
            pos = p.find(L'\n');
            v = p.substr(0, pos);
            temps_ = ::afficher_Temps(v);
            if (temps_ == false)
            {
                E.afficher_X(0, L"temps={false}", L"érreur (" + tt + L") !!!");
            }
            else
            {
                temps = v;
                p = p.substr(pos + 1);
#if Serie_afficher_t123_temps_ == 1
                B.Ok_W(L"temps={" + temps + L'}');
#endif
            }
        }
    }
    else
    {
        int i = afficher_T123(tt, t1, t2 = L"", t3 = L"");
        temps_ = afficher_Temps(v);
        if (temps_ == false)
        {
            E.afficher_X(0, L"temps=", L"érreur (" + v + L") !!!");
        }
        else
        {
            temps = v;
            p = p.substr(pos + 1);
#if Serie_afficher_t123_temps_ == 1
            B.Ok_W(L"temps={" + temps + L'}');
#endif
        }       
    }
    //
    if (tt == L"" && t1 != L"")
    {
        tt = t1 + t2 + t3;
        std::wcout << L"tt == t1" << std::endl;
    }
    pos = p.length();
    p = p.substr(0, p.length() - 1);
    t.push_back(tt);
    t.push_back(t1);
    t.push_back(t2);
    t.push_back(t3);
    t.push_back(temps);
    t.push_back(p);
#if Serie_afficher_t123_temps_ == 1
    /*wcout << L"Titre={" << tt << L']' << endl;
    wcout << L"\t[0]=[" << t[0] << L']' << endl;
    wcout << L"\t[1]=[" << t[1] << L']' << endl;
    wcout << L"\t[2]=[" << t[2] << L']' << endl;
    wcout << L"\t[3]=[" << t[3] << L']' << endl;
    wcout << L"\t[4]=[" << t[4] << L']' << endl;
    wcout << L"\t[5]=[" << t[5] << L']' << endl;
    wcout << L'}' << endl;*/
    B.Ok_W(L"tt   [0]={" + tt + L'}');
    B.Ok_W(L"t1   [1]={" + t1 + L'}');
    B.Ok_W(L"t2   [2]={" + t2 + L'}');
    B.Ok_W(L"t3   [3]={" + t3 + L'}');
    B.Ok_W(L"temps[4]={" + temps + L'}');
    B.Ok_W(L"p    [5]={" + p + L'}');
    B.Ok_W(L"________");
#endif
    B.Ok_T(L"const int Serie::afficher_t123_temps() : Ok !");
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Titre                                                                                                                                              #
// # const int Serie::afficher_Titre(wstring t, wstring _T)                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Titre(std::wstring& t, std::wstring const& nomFichier)
{ // Titre_1
    //if (Titre_1_ == true)
    //    return 0;

    //wstring t_
#if Serie_afficher_Titre_ == 1
    //wcout << B_T << L"const int Serie::afficher_Titre(" << t << L", " << _T << L") :" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_Titre(" + t + L", " + nomFichier + L") :");
#endif
    if (titre.begin() == titre.end())
    {
#if Serie_afficher_Titre_ == 1
        //int i;
        //wcout << L"    " << B_W << L"const int Serie::afficher_Titre(" << t << L", " << _T << L") : erreur !!!" << B_w << endl;
        B.Ok_W(L"const int Serie::afficher_Titre(" + t + L", " + nomFichier + L") : erreur !!!");
        //wstring wstr;
        //wstr = B_W;
        //wstr += L"const int Serie::afficher_Titre(";
        //i = ::Console_Lire_txt(t + L", " + _T + L") :" + B_w, 0, 0, Y);
#endif
        E.afficher_X(-1, t, L"Titre.begin() == Titre.end()");
        return EXIT_FAILURE;
    }
    //Titre_1 = ::afficher_fichier_lire(t, _T);
    try
    {
        // Dans le try, on est assuré que toute exception levée
        // pourra être traitée dans le bloc catch situé après.
        Titre_1 = lire_fichierTxt(nomFichier);
    }
    // Notez qu'une exception s'attrape par référence constante.
    catch (runtime_error const& exception)
    {
        // On affiche la cause de l'exception.
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
    Titre_1 += L'\n';
    //
    std::vector<std::wstring> ti;
    std::wstring wstr = L"";
    std::size_t pos = 0;
    pos = Titre_1.find(L'\n');
    int y = 0;
    while (pos != std::wstring::npos)
    {
        //wcout << L"y=" << y << L" titre[" << y << L"] = [" << Titre_1.substr(0, pos) << L']' << endl;
        ti.push_back(Titre_1.substr(0, pos));
#if Serie_afficher_Titre_ == 1
        B.Ok_W(L"Titre={" + Titre_1.substr(0, pos) + L'}');
#endif
        Titre_1 = Titre_1.substr(pos + 1);
        pos = Titre_1.find(L'\n');
        y++;
    }
    // Titre[0] + Titre[1] + Titre[2]
    if (affichage_titre_actif && (titre[1] == L" : " || titre[1] == L": " || titre[1] == L"/" || titre[1] == L""))
    {
        //wcout << L"iiiiii" << endl;
        if (ti[0] == (titre[0] + titre[1] + titre[2] + L"\n"))
        {
            bool titre_ = false;
            //wcout << L"xxxxxxx" << endl;
            pos = ti[0].find(L" : ");
            if (pos != wstring::npos && titre_ == false)
            {
                titre[0] = ti[0].substr(0, pos);
                titre[1] = L" : ";
                titre[2] = t.substr(pos + 3, t.length());
                titre_ = true;
            }
            pos = ti[0].find(L": ");
            if (pos != wstring::npos && titre_ == false)
            {
                titre[0] = ti[0].substr(0, pos);
                titre[1] = L": ";
                titre[2] = t.substr(pos + 2, t.length());
                titre_ = true;
            }
            pos = ti[0].find(L"/");
            if (pos != wstring::npos && titre_ == false)
            {
                titre[0] = ti[0].substr(0, pos);
                titre[1] = L": ";
                titre[2] = t.substr(pos + 1, t.length());
                titre_ = true;
            }
            else
            {
                titre[0] = ti[0];
                titre[1] = L"";
                titre[2] = L"";
                titre_ = true;
            }
            if (titre_ == false)
            {
#if Serie_afficher_Titre_ == 1
                //wcout << L"    " << B_W << L"const int Serie::afficher_Titre(" << t << L", " << _T << L") : érreur !!!" << B_w << endl;
                B.Ok_W(L"const int Serie::afficher_Titre(" + t + L", " + nomFichier + L") : erreur !!!");
#endif
                E.afficher_X(-1, t, L"Titre_={false} !!!");
                return EXIT_FAILURE;
            }
        }
    }
    else
    {
#if Serie_afficher_Titre_ == 1
        //wcout << L"    " << B_W << L"const int Serie::afficher_Titre(" << t << L", " << _T << L") : érreur !!!" << B_w << endl;
        //wcout << L"yyyyy" << endl;
        B.Ok_W(L"const int Serie::afficher_Titre(" + t + L", " + nomFichier + L") : erreur !!!");
        B.Ok_W(L"yyyyy");
#endif
        E.afficher_X(-1, nomFichier, t);
        return EXIT_FAILURE;
    }
    //
    //wcout << L"ooooooo" << endl;
    if (y == 1)
    {
        //wcout << L"    " << B_W << L"const int Series::afficher_Titre(" << t << L", " << _T << L") : érreur !!!" << B_w << endl;
        B.Ok_W(L"const int Serie::afficher_Titre(" + t + L", " + nomFichier + L") : erreur !!!");
        E.afficher_X(-1, nomFichier, t);
        return EXIT_FAILURE;
    }
    //
    bool titre_, min_;
    titre_ = min_ = false;
    int i = 0;
    if (titre_ == false && min_ == false && i == 0)
    {
        //std::wcout << L"azertyuiop" << std::endl;
        min_ = ::afficher_Temps(ti[0]);
//std::wcout << L"azertyuiop" << std::endl;
        if (min_ == false)
        {
            min_ = ::afficher_Temps(ti[1]);
            if (min_ == false)
                titre.push_back(L""); // _h_min
            else
            {
                ::afficher_Titre(ti[0], titre);
                //i = ::afficher_Titre(wstring t, vector<wstring>&titre, bool& titre_);
                titre_ = true;
                titre.push_back(ti[1]);
                min_ = ::afficher_Temps(ti[1]);
                if (min_ == false)
                {
                    E.afficher_X(-1, ti[1], ti[1] + L" erreur (" + ti[1] + L") !!!");
                    return -1;
                }
                pos = ti[1].find(L' ');
                while (pos == wstring::npos)
                {
                    ti[1] = ti[1].substr(0, pos - 1) + ti[1].substr(pos + 1);
                    pos++;
                }
                Temps.tm_min = std::stoi(ti[1]);
                //wcout << L"eee" << endl;
                if (Temps_ == false)
                    Temps_ = true;
                ti.erase(ti.begin());
                ti.erase(ti.begin());
                //wcout << L"aaa y=" << titre.size() << endl;
            }
        }
        else
        {
            //wcout << L"qsdfghjklm" << endl;
            titre.push_back(ti[0]);
            //Temps.tm_hour = stoi(titre[0]);
            //Temps.tm_min = stoi(titre[0].substr(2));
            Temps.tm_min = stoi(ti[0]);
            if (Temps_ == false)
                Temps_ = true;
            ti.erase(ti.begin());
            min_ = true;
        }
    }
    else
    {
        titre.push_back(L""); // _min
    }
    for (int j = 0; j < y; j++)
    {
        //wcout << L"j=" << j << L" wstr=[" << wstr << L']' << endl;
        wstr += ti[j] + L'\n';
    }
    titre.push_back(wstr);
#if Serie_afficher_Titre_== 1
    std::vector <std::wstring>::iterator iter;
    for (iter = titre.begin(), i = 0; iter != titre.end(); iter++, i++)
        //wcout << L"    " << B_W << L"Titre[" << i << L"]={" << *iter << L'}' << B_w << endl;
        B.Ok_W(L"Titre[" + to_wstring(i) + L"]={" + *iter + L'}');
    //wcout << B_T << L"const int Serie::afficher_Titre() : Ok !" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_Titre() : Ok !");
    //i = ::Console_Lire_txt(B_T + L"const int Serie::afficher_Titre() : Ok !" + B_t, 0, 0, Y);
#endif
    Titre_1_ = true;
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Titre                                                                                                                                              #
// # const int Serie::afficher_Titre_2(int I, wstring t, wstring _T)                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Titre_2(int I, std::wstring t, std::wstring nomFichier)
{
#if Serie_afficher_Titre_2_ == 1
    //wcout << B_T << L"const int Serie::afficher_Titre_2(" << I << L", " << t << L", " << _T << L") :" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_Titre_2(" + std::to_wstring(I) + L", " + t + L", " + nomFichier + L") :");
#endif
    D_titre[I].push_back(t);
    //std::wstring t2 = ::afficher_fichier_lire(t, _T);
    std::wstring t2;
    try
    {
        t2 = lire_fichierTxt(nomFichier);
    }
    catch (runtime_error const& exception)
    {
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
    if (t2 == L"")
        ;
    else
    {
        std::size_t pos = 0;
        if (t2[0] == L'[')
        {
            pos = t2.find(L']');
            D_titre[I].push_back(t2.substr(1, pos - 1));
            t2 = t2.substr(pos + 1);
            while (t2[0] == L'\n' || t2[0] == L'\t' || t2[0] == L' ')
                t2 = t2.substr(1);
        }
        D_titre[I].push_back(t2);
    }
#if Serie_afficher_Titre_2_ == 1
    std::vector std::<wstring>::iterator iter;
    for (iter = D_titre[I].begin(); iter != D_titre[I].end(); iter++)
        //wcout << B_T << L"*iter : [" << *iter << L']' << B_t << endl;
        B.Ok_W(L"*iter : {" + *iter + L'}');
    //wcout << B_T << L"const int Series::afficher_Titre_2 (" << I << L", " << t << L", " << _T << L") : Ok !" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_Titre_2() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Titre                                                                                                                                              #
// # const int Serie::afficher_Titre_3(int I, wstring t, wstring _T)                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Titre_3(int I, std::wstring filename, std::wstring nomFichier)
{
#if Serie_afficher_Titre_3_ == 1
    B.Ok_T(L"const int Serie::afficher_Titre_3(" + std::to_wstring(I) + L", " + filename + L", " + _T + L") :");
#endif
    //D_Titre[I] = afficher_fichier_lire(t, nomFichier);
    D_Titre[I] = lire_fichierTxt(nomFichier);
    if (D_Titre[I] == L"")
    {
        E.afficher_X(0, nomFichier, filename);
        return EXIT_SUCCESS;
    }
#if Serie_afficher_Titre_3_ == 1
    //wcout << L"    " << L"D_Titre[" << I << L"]=[" << D_Titre[I] << L']' << endl;
    B.Ok_W(L"D_Titre[" + std::to_wstring(I) + L"]=[" + D_Titre[I] + L']');
    B.Ok_T(L"const int Serie::afficher_Titre_3() : Ok !");
#endif
    return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_X_x                                                                                                                                       #
// # const int Serie::afficher_X_x(int I, int J, wstring _T, wstring d)                                                                                 #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_X_x(int I, int J, std::wstring const& nomFichier, std::wstring& d)
{
#if Serie_afficher_X_x_ == 1
    B.Ok_T(L"const int Serie::afficher_X_x(" + std::to_wstring(I) + L", " + std::to_wstring(J) + L", " + nomFichier + L", " + d + L") :");
    B.Ok_W(L"{" + d + L'}');
#endif
    ///wcout << L'[' << d << L']' << endl;
    std::size_t pos = 0;
    pos = d.find(L'.');
    D_K_d[I][J] = std::stoi(d, &pos);
    //assert(d.substr(pos + 1) == L"");
    d = d.substr(pos + 1);
    bool texte_ = true;
    std::wstring tt = L"";
    if (texte_ == true &&
        (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
        (std::isdigit(d[1])) &&
        (std::isdigit(d[2])) &&
        (std::isdigit(d[3])) &&
        (d[4] == L'-') &&
        (d[5] == L'0' || d[5] == L'1') &&
        (std::isdigit(d[6])) &&
        (d[7] == L'-') &&
        (d[8] == L'0' || d[8] == L'1' || d[8] == L'2' || d[8] == L'3') &&
        (std::isdigit(d[9])) /* &&
        (d[10] == wstring::npos || d[10] == L'_')*/
        )
    {
        texte_ = false;
        //wcout << L"texte_ = false" << endl;
    }
    if (texte_ == true)
    {
        pos = d.find(L'.');
        tt = d.substr(0, pos);
        pos = d.find(L'.');
        d = d.substr(pos + 1);

        if (
            (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
            (std::isdigit(d[1])) &&
            (std::isdigit(d[2])) &&
            (std::isdigit(d[3])) &&
            (d[4] == L'-') &&
            (d[5] == L'0' || d[5] == L'1') &&
            (std::isdigit(d[6])) &&
            (d[7] == L'-') &&
            (d[8] == L'0' || d[8] == L'1' || d[8] == L'2' || d[8] == L'3') &&
            (std::isdigit(d[9]))
            // ???
            /* &&
            (d[10] == wstring::npos || d[10] == L'_')*/
            )
        {
        }
        else
        {
            E.afficher_X(-1, nomFichier, L"Erreur de date !");
            return EXIT_FAILURE;
        }
    }
    //wcout << L"tt={" << tt << L"}, d={" << d << L"}" << endl;
    //wstring p = ::afficher_fichier_lire(_T, _T);
    std::wstring p;
    try
    {
        // Dans le try, on est assuré que toute exception levée
        // pourra être traitée dans le bloc catch situé après.
        p = lire_fichierTxt(nomFichier);
    }
    // Notez qu'une exception s'attrape par référence constante.
    catch (runtime_error const& exception)
    {
        // On affiche la cause de l'exception.
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
    if (p == L"")
        std::wcout << L"------------- afficher_X_x ====> p=0" << std::endl;
    else
    {
        std::vector<std::wstring> titre;
        std::wstring titre_ = nomFichier;
        if (texte_ == false)
        {
            pos = p.find(L'\n');
            tt = p.substr(0, pos);
            //wcout << L"bbb texte_ = false, pp={" << tt << L"}" << endl;        pos = d.find(L'.');
        }
        //
        int i = afficher_t123_temps(titre, p, tt, titre_); // titre[6] = 7
        //wcout << L"www d={" << d << L"}" << endl;
        //
        if (i == -1)
        {
            E.afficher_X(-1, nomFichier, titre_);
            return EXIT_FAILURE;
        }
        D_t[I][J] = titre;
    }
    //
    int i = 0;
    int year[_x_] = { 0 }, month[_x_] = { 0 }, day[_x_] = { 0 };
    std::wstring d2 = L"";
    int w = 0;
    int j = 0, k = 0;
    int K = 0;
#if Serie_afficher_X_x_ == 1
    B.Ok_W(L"Date={" + d + L'}');
#endif
    while (
        d[0] != std::wstring::npos &&
        !(d[0] == L'_' && (pos = d.length()) == 1) &&
        !(d[0] == L'_' && d[1] == L' ' && (pos = d.length()) > 2) &&
        !(d[0] == L' ')
        )
    {
        if (
            (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
            (std::isdigit(d[1])) &&
            (std::isdigit(d[2])) &&
            (std::isdigit(d[3])) &&
            (d[4] == L'-') &&
            (d[5] == L'0' || d[5] == L'1') &&
            (std::isdigit(d[6])) &&
            (d[7] == L'-') &&
            (d[8] == L'0' || d[8] == L'1' || d[8] == L'2' || d[8] == L'3') &&
            (std::isdigit(d[9]))
            )
        {
            d2 = d.substr(0, 4);
            year[i] = std::stoi(d2, &pos);
            if (year[i] <= 1900 || year[i] >= 3001)
            { // Erreur
#if Serie_afficher_X_x_ == 1
                B.Ok_W(L"year[" + std::to_wstring(i) + L"]=" + std::to_wstring(year[i]) + L" erreur (1) !!!");
#endif
                E.afficher_X(i, nomFichier, L"year[" + std::to_wstring(i) +L"] = " + std::to_wstring(year[i]) + L" erreur (1) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(4);
            d = d.substr(1);
            d2 = d.substr(0, 2);
            month[j] = std::stoi(d2, &pos);
            if (month[j] <= 0 || month[j] >= 13)
            { // Erreur
#if Serie_afficher_X_x_ == 1
                B.Ok_W(L"month[" + std::to_wstring(j) + L"]=" + std::to_wstring(month[j]) + L" erreur (1) !!!");
#endif
                E.afficher_X(i, nomFichier, L"month[" + std::to_wstring(j) + L"] = " + std::to_wstring(month[j]) + L" erreur (1) !!!");
                return -1;
            }
            d = d.substr(2);
            d = d.substr(1);
            d2 = d.substr(0, 2);
            day[k] = std::stoi(d2, &pos);
            if (day[k] <= 0 || day[k] >= 32)
            { // Erreur
#if Serie_afficher_X_x_ == 1
                B.Ok_W(L"day[" + std::to_wstring(k) + L"]=" + std::to_wstring(day[k]) + L" erreur (1) !!!");
#endif
                E.afficher_X(i, nomFichier, L"day[" + std::to_wstring(k) + L"] = " + std::to_wstring(day[k]) + L" erreur (1) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
#if Serie_afficher_X_x_ == 1
            B.Ok_W(L"day[" + std::to_wstring(k) + L"]=" + std::to_wstring(day[k]));
#endif
            Date_X[I][J][K].tm_year = year[i] - 1900;
            Date_X[I][J][K].tm_mon = month[j] - 1;
            Date_X[I][J][K].tm_mday = day[k];
            K++;
            if ((pos = d.length()) == 0)
                goto stop;
        }
        // month[j] + day[k]
        if (
            d[0] == L'_' &&
            (d[1] == L'0' || d[1] == L'1') &&
            (std::isdigit(d[2])) &&
            d[3] == L'-' &&
            (d[4] == L'0' || d[4] == L'1' || d[4] == L'2' || d[4] == L'3') &&
            (std::isdigit(d[5]))
            )
        {
            j++;
            k = 0;
            d = d.substr(1);
            d2 = d.substr(0, 2);
            month[j] = stoi(d2, &pos);
            if (month[j] <= 0 || month[j] >= 13)
            { // Erreur
#if Serie_afficher_X_x_ == 1
                B.Ok_W(L"month[" + std::to_wstring(j) + L"]=" + std::to_wstring(month[j]) + L" erreur (2) !!!");
#endif
                E.afficher_X(i, nomFichier, L"month[" + std::to_wstring(j)+L"] = " + std::to_wstring(month[j]) + L" erreur (2) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
            d = d.substr(1);
            d2 = d.substr(0, 2);
            day[k] = std::stoi(d2, &pos);
            if (day[k] <= 0 || day[k] >= 32)
            { // Erreur
#if Serie_afficher_X_x_ == 1
                B.Ok_W(L"day[" + std::to_wstring(k) + L"]=" + std::to_wstring(day[k]) + L" erreur (2) !!!");
#endif
                E.afficher_X(i, nomFichier, L"day[" + std::to_wstring(k) + L"] = " + std::to_wstring(day[k]) + L" erreur (2) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
#if Serie_afficher_X_x_ == 1
            B.Ok_W(L"day[" + std::to_wstring(k) + L"]=" + std::to_wstring(day[k]));
#endif
            Date_X[I][J][K].tm_year = year[i] - 1900;
            Date_X[I][J][K].tm_mon = month[j] - 1;
            Date_X[I][J][K].tm_mday = day[k];
            K++;
            if ((pos = d.length()) == 0)
                goto stop;
        }
        // '_'
        if (
            d[0] == L'_' &&
            (d[1] == L'1' || d[1] == L'2' || d[1] == L'3') &&
            (std::isdigit(d[2])) &&
            (std::isdigit(d[3])) &&
            (std::isdigit(d[4]))
            )
        {
            i++;
            j = 0;
            k = 0;
            d = d.substr(1);
#if Serie_afficher_X_x_ == 1
            B.Ok_W(L"Date !!!");
#endif
            continue;
        }
        // day[k]
        if (
            d[0] == L'_' &&
            (d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3') &&
            (std::isdigit(d[2]))
            )
        {
            k++;
            d = d.substr(1);
            d2 = d.substr(0, 2);
            day[k] = stoi(d2, &pos);
            if (day[k] <= 0 || day[k] >= 32)
            { // Erreur
#if Serie_afficher_X_x_ == 1
                B.Ok_W(L"day[" + std::to_wstring(k) + L"]=" + std::to_wstring(day[k]) + L" erreur (3) !!!");
#endif
                E.afficher_X(-1, nomFichier, L"day[" + std::to_wstring(k)+L"] = " + std::to_wstring(day[k]) + L" erreur (3) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
#if Serie_afficher_X_x_ == 1
            B.Ok_W(L"day[" + std::to_wstring(k) + L"]=" + std::to_wstring(day[k]));
#endif
            Date_X[I][J][K].tm_year = year[i] - 1900;
            Date_X[I][J][K].tm_mon = month[j] - 1;
            Date_X[I][J][K].tm_mday = day[k];
            K++;
            if ((pos = d.length()) == 0)
                goto stop;
        }
    }
    // Ok !
stop:
    if (d[0] == L'_')
    {
        D_K_[I][J] = true;
        d = d.substr(1);
    }
    if (d[0] == L' ')
    {
        d = d.substr(1);
        D_t[I][J].push_back(d);
    }
    else
        D_t[I][J].push_back(L"");
#if Serie_afficher_X_x_ == 1
    if (p != L"" && D_t[I][J].size() == 7)
    {
        B.Ok_W(L"tt   [0]={" + D_t[I][J][0] + L'}');
        B.Ok_W(L"t1   [1]={" + D_t[I][J][1] + L'}');
        B.Ok_W(L"t2   [2]={" + D_t[I][J][2] + L'}');
        B.Ok_W(L"t3   [3]={" + D_t[I][J][3] + L'}');
        B.Ok_W(L"temps[4]={" + D_t[I][J][4] + L'}');
        B.Ok_W(L"p    [5]={" + D_t[I][J][5] + L'}');
        B.Ok_W(L"s    [6]={" + D_t[I][J][6] + L'}');
    }
    else
    {
#if Serie_afficher_X_x_ == 1
        B.Ok_W(L"Erreur D_t[" + std::to_wstring(I) + L"][" + std::to_wstring(J) + L"] !!!");
#endif
        E.afficher_X(-1, nomFichier, L"Erreur D_t[" + std::to_wstring(I) + L"][" + std::to_wstring(J) + L"] !!!");
        return EXIT_FAILURE;
    }
#endif
    wchar_t date_string[15];
#if Serie_afficher_X_x_ == 1
    //wcout << L"    " << L"(";
    std::wstring wstr = L"{";
    for (i = 0; i < K; i++)
    {
        wcsftime(date_string, 15, L"%d/%m/%Y", &Date_X[I][J][i]);
        wstr += date_string;
        if (i < K - 1 )
            wstr += L' ';
    }
    if (D_K_[I][J] == true)
        wstr += L"(_)";
    B.Ok_W(wstr + L'}');
#else
    for (i = 0; i < K; i++)
        wcsftime(date_string, 15, L"%d/%m/%Y", &Date_X[I][J][i]);
#endif
    D_K[I][J] = K - 1;
#if Serie_afficher_X_x_ == 1
    B.Ok_W(L"D_K[" + std::to_wstring(I) + L"][" + std::to_wstring(J) + L"]=[" + std::to_wstring(K - 1) + L']');
    B.Ok_T(L"const int Serie::afficher_X_x() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # pas de OK                                                                                                                                          #
// # const int Serie::afficher_pas_de_OK()                                                                                                              #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_pas_de_OK() const
{
    //int i;
#if Serie_afficher_pas_de_OK_ == 1
    B.Ok_T(L"const int Serie::afficher_pas_de_OK() :");
#endif
    if (!affichage_genres_actif)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de genne !!!");
#if Serie_afficher_pas_de_OK_ == 1
        B.Ok_W(L"Attention : Erreur de Genre !!!");
#endif
    }
    if (!affichage_nationalite_actif)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de Nationalité !!!");
#if Serie_afficher_pas_de_OK_ == 1
        B.Ok_W(L"Attention : Erreur de Nationalité !!!");
#endif
    }
    // Note
    /*if (Note_ == false)
    {
        E.afficher_X(-1, L"Attention !", L"Érreur de Note !!!");
#if Serie_afficher_pas_de_OK_ == 1
        B.Ok_W(L"Attention : Érreur de Note !!!");
#endif
    }*/
    /*bool j;
    j = false;
    for (i = 0; i < D_I ; i++)
    {
        if (D_Note[i] != -1)
        {
            j = true;
            break;
        }
    }
    if (j == false)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de Note !!!");
#if Serie_afficher_pas_de_OK_ == 1
        B.Ok_W(L"Attention : Erreur de Note !!!");
#endif
    }*/
    // Titre
    if (!affichage_titre_actif)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de Titre !!!");
#if Serie_afficher_pas_de_OK_ == 1
        B.Ok_W(L"Attention : Erreur de Titre !!!");
#endif
    }
#if Serie_afficher_pas_de_OK_ == 1
    B.Ok_T(L"const int Serie::afficher_pas_de_OK() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher                                                                                                                                           #
// # const int Serie::afficher()                                                                                                                        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher()
{ // OK !
    int i = 0, j, x = 4, I = 0;
#if Serie_afficher_OK_ == 1
    B.Ok_T(L"const int Serie::afficher_OK() :");
#endif
    std::vector <std::wstring>::iterator iter;
    std::size_t pos = 0;
    std::wstring wstr;
    std::wstring Textes;
    wchar_t date_string[22] = L"";
    //
#if Serie_afficher_OK_ == 1
    Console_Lire_txt(L"~~~~~~~~~~ ");
    if (Ok != L"Titre.txt")
        B.Ok_W(L'{' + Ok + L'}');
    else
    {
        std::wcout << L"    " << keyColor[0] << L'{' << valuesColor << titre[0];
        if (titre[1] != L"")
        {
            std::wcout << keyColor[1] << titre[1] << valuesColor;
            std::wcout << titre[2];
        }
        std::wcout << keyColor[0] << L'}' << valuesColor << std::endl;
    }
#endif
    Console_Lire_txt(L"~~~~~~~~~~ ");
    // Titre
    //PrintTitre();
    // Header
    PrintHeader();
    // Titre original
    PrintTitreOriginal(titre_original, affichage_titre_original_actif, keyColor[0], valuesColor, keyColor[1], valuesColor);
    // Chaîne
    PrintChaine(chaine);
    // Audiodescription
    PrintAudiodescription(audiodescription, affichage_audiodescription_actif, keyColor[0], valuesColor, 0);
    // Genre
//PrintGenres(genres, affichage_genres_actif, sous_genres, affichage_sous_genre_actif, keyColor, valuesColor)
    PrintGenres(genre, affichage_genres_actif, sous_genre, affichage_sous_genre_actif, keyColor[0], valuesColor);
    // Créée par
    PrintCreee_par(creee_par);
    //PrintCreee_par(creee_par, S_T, S_t, creee_par_);
    if (affichage_avec_actif)
    {


        // j ???


        /*td::vector<pair<std::wstring, std::wstring>>::iterator iter2;
        Textes = keyColor + L"Avec : " + valuesColor;
        for (iter2 = avec.begin(), j = 0; iter2 != avec.end(); iter2++)
        {
            if (
                (j < (avec.size() - 1)
                    &&
                    (*iter2).first != L"")
                )
            {
                Textes += (*iter2).first;
                j++;
            }
            if (j > 2)
                break;
            Textes += keyColor + L", " + valuesColor;
        }
        i = Console_Lire_txt(Textes, 0, 0);*/
    }
    // En relation avec
    PrintEn_relation_avec(en_relation_avec);
    // Nationalité(s)
    PrintNationalites(nationalite, affichage_nationalite_actif, keyColor[0], valuesColor);
    // Image
    PrintImages(image, affichage_image_actif, keyColor[0], valuesColor, 0, 0, 0, 0);
    // Netflix ?
    PrintNetflixokounon(netflix_ok_ou_non, affichage_sur_actif, keyColor[0], valuesColor);
    //
    Console_Lire_txt(L"~~~~~~~~~~ ");
    // 
    if (titre.size() == 5/*titre_ == true*/)
    { // Titre = 4
        //iter = Titre.begin();
        //iter += 3;
        i = Console_Lire_txt(titre[4], 4, 0);
        Console_Lire_txt(L"~~~~~~~~~~ ");
    }
    // Avec et Avec_role
    /*if (Avec_ == true && Avec_role.size() != 0)
    {
        i = Console_Lire_txt(keyColor + L"Avec :" + valuesColor, 0, 0);
        Textes = L"";
        std::wstring& avec = Avec.back();
        for (j = 0; j < Avec.size(); j++)
        {
            if (Avec[j] == avec && avec == L"…" && Avec_role[j] == L"")
            {
                Textes += avec;
                break;
            }
            if (Avec[j] != L"" && Avec_role[j] != L"")
                Textes += Avec[j] + L" " + keyColor2 + L"(" + valueColor2 + Avec_role[j] + keyColor2 + L")" + valueColor2;
            else if (Avec[j] == L"")
                Textes += keyColor2 + L"(" + valueColor2 + Avec_role[j] + keyColor2 + L")" + valueColor2;
            else
                Textes += Avec[j];
            if (Avec[j] != avec)
                Textes += keyColor + L", " + valuesColor;
            else
                Textes += keyColor + L'.' + valuesColor;
        }
        i = Console_Lire_txt(Textes, 4, 0);
        Console_Lire_txt(L"---------- ");
    }*/
    //
    // sort https://www-digitalocean-com.translate.goog/community/tutorials/sort-in-c-plus-plus?_x_tr_sl=en&_x_tr_tl=fr&_x_tr_hl=fr&_x_tr_pto=sc
    while (I < D_I)
    {
        Textes = L"";
        if (Date_Diffusee_a_partir_de_[I] == true)
        {
            wcsftime(date_string, 15, L"%d/%m/%Y", &Date_Diffusee_a_partir_de[I]);
            wstr = date_string;
            Textes += wstr.substr(0, 2) + keyColor[1] + L'/' + valuesColor + wstr.substr(3, 2) + keyColor[1] + L'/' + valuesColor + wstr.substr(6, 4);
        }
        else
        {
            break;
        }
        if (D_titre[I].begin() == D_titre[I].end())
        {
            wstr = L"D_titre[]";
            E.afficher_X(-1, wstr, L"Erreur !!!");
            break;
        }
        iter = D_titre[I].begin();
        wstr = *iter;
        if (D_Titre_[I] == true)
        {
            Textes += keyColor[1] + L" : " + valuesColor + keyColor[0] + D_Titre[I] + valuesColor;
        }
        iter++;
        Textes += keyColor[1] + L" : " + valuesColor;
        if (D_titre[I].size() == 2)
            Textes += *iter;
        else if (D_titre[I].size() == 3)
        {
            Textes += *iter;
            iter++;
            Textes += *iter;
        }
        if (D_titre[I].size() == 1)
            Textes += keyColor[1] + L'(' + valuesColor;
        else
            Textes += keyColor[1] + L" (" + valuesColor;
        Textes += wstr + keyColor[1] + L')' + valuesColor;
        i = Console_Lire_txt(Textes, 0, x);
        //
        std::size_t k;
        for (j = 0; j < D_J[I]; j++)
        {
            bool titre_chiffre_et_point = afficher_Titre_chiffre_et_point_ou_pas(D_t[I][j][1]);
            /*if (titre_chiffre_et_point)
                i = Console_Lire_txt(L"vrai\r\n", 0, 0);
            else
                i = Console_Lire_txt(L"faux\r\n", 0, 0);*/
            int c = 0;
            if (titre_chiffre_et_point)
            {
                wchar_t b[3];
                wstr = std::to_wstring(I + 1);
                Textes = wstr + keyColor[1] + L'x' + valuesColor;
                if (D_J[I] >= 100)
                {
                    swprintf_s(b, 3, L"%.3d", D_K_d[I][j]);
                    c = 3;
                }
                else if (D_J[I] >= 10)
                {
                    swprintf_s(b, 3, L"%.2d", D_K_d[I][j]);
                    c = 2;
                }
                else
                {
                    swprintf_s(b, 3, L"%d", D_K_d[I][j]);
                    c = 1;
                }
                wstr = b;
                Textes += wstr;

            }
            else
            {
                c = 0;
                wstr = L"";
                Textes = L"";
            }
            if (D_K[I][j] == 0)
            {
                //i = Console_Lire_txt(L"aaa D_K[" + std::to_wstring(I) + L"][" + std::to_wstring(j) + L"]==0", 0, 0);
                wcsftime(date_string, 15, L"%d/%m/%Y", &Date_X[I][j][0]);
                std::wstring wstr2 = date_string;
                wstr = wstr2.substr(0, 2) + keyColor[1] + L'/' + valuesColor + wstr2.substr(3, 2) + keyColor[1] + L'/' + valuesColor + wstr2.substr(6, 4);
            }
            else
            {
                //i = Console_Lire_txt(L"bbb D_K[" + std::to_wstring(I) + L"][" + std::to_wstring(j) + L"]==" + std::to_wstring(D_K[I][j]), 0, 0);
                wstr = L"";
                pos = 0;
                std::wstring m[10] = { L"" };
                for (k = 0; k < D_K[I][j] + 1; k++)
                {
                    wcsftime(date_string, 15, L"%d/%m/%Y", &Date_X[I][j][k]);
                    std::wstring wstr2 = date_string;
                    m[k] = wstr2.substr(0, 2) + keyColor[1] + L'/' + valuesColor + wstr2.substr(3, 2) + keyColor[1] + L'/' + valuesColor + wstr2.substr(6, 4);
                }
                std::wstring n = m[0];
                int o = 0, p = 0;
                for (k = 1; k < D_K[I][j] + 1; k++)
                {
                    if (n == m[k])
                    {
                        m[k] = L'(' + std::to_wstring(o + 2) + L')';
                        if (m[k - 1] == n && o == 0)
                            m[k - 1] += L" (1)";
                        o++;
                    }
                    else
                    {
                        n = m[k];
                        o = 0;
                    }
                }
                k = 1;
                p = 0;
                o = D_K[I][j] + 1;
                while (k < o)
                {
                    if (m[k][2] == L')')
                    {
                        m[p] += m[k];
                        m[k].clear();
                    }
                    else
                        p++;
                    k++;
                }
                k = 0;
                p = 0;
                std::wstring q[10] = { L"" };
                while (k < o)
                {
                    if (m[k] != L"")
                    {
                        q[p] = m[k];
                        p++;
                    }
                    k++;
                }
                o = p;
                p = 0;
                while (p < o)
                {
                    pos = q[p].find_last_of(L")(");
                    if (pos != std::wstring::npos)
                    {
                        q[p] = q[p].substr(0, pos - 2) + L" et " + q[p].substr(pos - 2);
                        wstr += q[p];
                    }
                    else
                        wstr += q[p];
                    if (p < o - 2)
                        wstr += L", ";
                    else if (p < o - 1)
                    {
                        if (pos != std::wstring::npos)
                        {
                            wstr += L", ";
                            pos = 0;
                        }
                        else
                            wstr += L" et ";
                    }
                    p++;
                }
                if (pos = wstr.find(L" et "))
                    wstr = replace_all(wstr, L" et ", keyColor[1] + L" et " + valuesColor);
                if (pos = wstr.find(L")("))
                    wstr = replace_all(wstr, L")(", keyColor[1] + L")(" + valuesColor);
                if (pos = wstr.find(L"("))
                    wstr = replace_all(wstr, L"(", keyColor[1] + L"(" + valuesColor);
                if (pos = wstr.find(L")"))
                    wstr = replace_all(wstr, L")", keyColor[1] + L")" + valuesColor);
                if (pos = wstr.find(L", "))
                    wstr = replace_all(wstr, L", ", keyColor[1] + L", " + valuesColor);
                wstr += L' ' + keyColor[1] + L'[' + valuesColor + L"pas-à-pas" + keyColor[1] + L']' + valuesColor;
            }
            if (D_K_[I][j] == true)
                wstr += L' ' + keyColor[1] + L'[' + valuesColor + L"à suivre" + keyColor[1] + L']' + valuesColor;
            if (D_t[I][j].size() == 7)
            {
                if (titre_chiffre_et_point)
                    i = afficher_OK_T(D_t[I][j], Textes, wstr, titre_chiffre_et_point, x, x + c + 5, x + c + 5);
                else
                    i = afficher_OK_T(D_t[I][j], Textes, wstr, titre_chiffre_et_point, x, x + /*c + */5, x + /*c +*/ 5);
            }
            else if (D_K[I][j] > 0)
                i = Console_Lire_txt(wstr, x + c + 5, x + c + 5);
            else
            {
                E.afficher_X(-1, L"", L"Erreur D_t[][] !!!");
                //return -1;
            }
        }
        // Netflix
        //if (D_Netflix[I] == true)
        //{
        //    wstr = L"Netflix";
        //    i = Console_Lire_txt(S_W + L'(' + S_w + wstr + S_W + L')' + S_w, y, y, Y);
        //}
        // DVD
        if (D_DVD[I] == true)
        {
            wstr = L"DVD";
            i = Console_Lire_txt(keyColor[1] + L'(' + valuesColor + wstr + keyColor[1] + L')' + valuesColor, x, x);
        }
        // Note
        PrintNote(I, x);
        // Image
        PrintImages(d_image[I], d_affichage_image_actif, keyColor[1], valuesColor, 4, 0, 8, 1);
        // Audiodescription
        PrintAudiodescription(d_audiodescription[I], affichage_audiodescription_actif, keyColor[1], valuesColor, x);
        // Avec
        PrintAvec(avec[I]);
        // Chaîne
        if (d_chaine[I] != L"" && d_chaine_[I] == true)
            i = Console_Lire_txt(keyColor[1] + L"Chaîne d'origine : " + valuesColor + d_chaine[I], x, x + 9);
        Console_Lire_txt(L"~~~~~~~~~~ ");
        // I
        I++;
    }

    // ???
    i = E.Ok();// ???


#if Serie_afficher_OK_ == 1
    //wcout << B_T << L"const int Serie::afficher_OK() : Ok !" << B_t << endl;
    B.Ok_T(L"const int Serie::afficher_OK() : Ok !");
#endif
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # OK Note                                                                                                                                            #
// # const wstring Serie::afficher_OK_Note()                                                                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring Serie::afficher_OK_Note()
{
    if (affichage_note_actif)
    {
        vector<double> d;
        if (m_note.size() != 0)
        {
            for (const auto& [cle, valeur] : m_note)
            {
                if (valeur >= 0.0 && valeur <= 5.0)
                    d.push_back(valeur);
            }
            if (d.size() != 0)
            {
                double n = std::accumulate(d.begin(), d.end(), 0.0) / d.size();
                std::wstring wstr = std::to_wstring(n);
                if (wstr[2] == L'0')
                    wstr = wstr[0];
                else if (wstr[3] == L'0')
                    wstr = wstr[0] + keyColor[0] + wstr[1] + valuesColor + wstr[2];
                else
                    wstr = wstr[0] + keyColor[0] + wstr[1] + valuesColor + wstr[2] + wstr[3];
                wstr = L' ' + wstr + keyColor[0] + L"/5" + valuesColor;
                return wstr;
            }
        }
        return L' ' + keyColor[0] + L'(' + valuesColor + L"pas de note !" + keyColor[0] + L')' + valuesColor;
    }
    return L"";
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Titre_chiffre_et_point_ou_pas                                                                                                             #
// # const bool Serie::afficher_Titre_chiffre_et_point_ou_pas(std::wstring& Textes)                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const bool Serie::afficher_Titre_chiffre_et_point_ou_pas(std::wstring& Textes)
{
    if (!std::isdigit(Textes[0]))
        return false;
    int i = 0;
    while (Textes[i] != std::wstring::npos)
    {
        if (std::isdigit(Textes[i]))
            ;
        else if (Textes[i] == L'.' && i > 0)
        {
            if (Textes[i + 1] != std::wstring::npos && Textes[i + 1] == L' ')
                break;
            else return false;
        }
        else
            return false;
        i++;
    }
    Textes = Textes.substr(i + 2);
    return true;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # OK T                                                                                                                                               #
// # const int Serie::afficher_OK_T(std::vector <std::wstring>& I,                                                                                      #
// #                                std::wstring& Textes,                                                                                               # 
// #                                std::wstring& Textes2,                                                                                              #
// #                                bool titre_chiffre_et_point,                                                                                        #
// #                                int x0, int x1, int x2)                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_OK_T(std::vector <std::wstring>& I, std::wstring& Textes, std::wstring& Textes2, bool titre_chiffre_et_point, int x0, int x1, int x2)
{
    std::wstring w_p, &w_t1 = I[1], &w_t2 = I[2], &w_t3 = I[3], &w_temps = I[4], &w_P = I[5], &w_s = I[6];
    int i;
    w_p = I[0];
    if (w_p == L"" && w_t1 == L"" && w_t2 == L"" && w_t3 == L"" && w_temps == L"" && w_P == L"")
    {
        if (w_s != L"")
            Textes += keyColor[1] + L" (" + valuesColor + w_s + keyColor[1] + L')' + valuesColor;
        i = Console_Lire_txt(Textes, x0, x2);
    }
    else if (w_p != L"" && w_t1 == L"" && w_t2 == L"" && w_t3 == L"" && w_temps == L"" && w_P == L"")
    {
        if (titre_chiffre_et_point)
            Textes += L" : " + keyColor[1] + w_p + valuesColor;
        else
            Textes += w_p;
        if (w_s != L"")
            Textes += keyColor[1] + L" (" + valuesColor + w_s + keyColor[1] + L')' + valuesColor;
        i = Console_Lire_txt(Textes, x0, x2);
    }
    else
    {
        if (w_p != L"" && w_t1 == L"" && w_t2 == L"" && w_t3 == L"")
        {
            if(titre_chiffre_et_point)
                Textes += keyColor[1] + L" : " + w_p + valuesColor;
            else
                Textes = keyColor[1] + w_p + valuesColor;
        }
        if (w_p != L"" && w_t1 != L"" && w_t2 == L"" && w_t3 == L"")
        {
            if (titre_chiffre_et_point)
                Textes += keyColor[1] + L" : " + w_t1 + valuesColor;
            else
                Textes += keyColor[1] + w_t1 + valuesColor;
        }
        else if (w_p != L"" && w_t1 != L"" && w_t3 != L"")
        {
            if (titre_chiffre_et_point)
                Textes += keyColor[1] + L" : " + valuesColor + keyColor[1] + w_t1 + valuesColor;
            else
                Textes += keyColor[1] + w_t1 + valuesColor;
            bool w_t2_ = false;
            if (w_t2 == L" : " && !w_t2_)
            {
                Textes += L" : ";
                w_t2_ = true;
            }
            else if (w_t2 == L": " && !w_t2_)
            {
                Textes += L": ";
                w_t2_ = true;
            }
            else if (w_t2 == L"/" && !w_t2_)
            {
                Textes += L'/';
                w_t2_ = true;
            }
            else
            {
                E.afficher_X(-1, L"", L"Erreur D_t[][] !!!");
                return -1;
            }
            if (w_t2_)
                Textes += keyColor[1] + w_t3 + valuesColor;
        }
        if (w_s != L"")
            Textes += keyColor[1] + L" (" + valuesColor + w_s + keyColor[1] + L')' + valuesColor;
        if (w_temps != L"")
        {
            Textes += keyColor[1] + L" (" + valuesColor + afficher_OK_Temps(w_temps, keyColor[1], valuesColor) + keyColor[1] + L") : " + valuesColor + Textes2;
        }
        i = Console_Lire_txt(Textes, x0, x2);
        i = Console_Lire_txt(w_P, x1, x2);
    }
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_OK_Temps                                                                                                                                  #
// # const wstring Serie::afficher_OK_Temps(wstring& t, wstring& S, wstring& s)                                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring Serie::afficher_OK_Temps(std::wstring& t, std::wstring& S, std::wstring& s)
{ // min
#if Serie_afficher_OK_Temps_ == 1
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(" << t << L", " << S << L", " << s << L") :" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps(" + t + L", " + S + L", " + s + L") :");
#endif
    std::wstring wstr = std::to_wstring(std::stoi(t));
    if (S_Espace == true)
        wstr += L' ';
    wstr += S + S_MIN + s;
#if Serie_afficher_OK_Temps_ == 1
    //wcout << L"    " << L"wstr=[" << wstr << L']' << endl;
    B.Ok_W(L"wstr=[" + wstr + L']');
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(" << t << L", " << S << L", " << s << L") : Ok !" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps() : Ok !");
#endif
    return wstr;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_OK_Temps                                                                                                                                  #
// # const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s)                                                                              #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring Serie::afficher_OK_Temps(std::tm &t, std::wstring &S, std::wstring &s)
{ // min
#if Serie_afficher_OK_Temps_ == 1
    // Attention !!!
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s) :" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s) :");
#endif
    int m = t.tm_hour * 1 + t.tm_min;
    std::wstring wstr = to_wstring(m);
    if (S_Espace == true)
        wstr += L' ';
    wstr += S + S_MIN + s;
#if Serie_afficher_OK_Temps_ == 1
    // Attention !!!
    B.Ok_W(L"wstr=[" + wstr + L']');
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s) : Ok !" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps() : Ok !");
#endif
    return wstr;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Ok S                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::Ok_S(bool P_S_Espace, std::wstring P_S_MIN, std::vector<std::wstring> S_keyColor, std::wstring S_valuesColor)
{
    S_Espace = P_S_Espace; // = false ou true;
    S_MIN = P_S_MIN; // = L"min";
    //keyColor.push_back(P_S_T);
    //keyColor.push_back(P_S_W);
    keyColor = S_keyColor;
    valuesColor = S_valuesColor;
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintAvec                                                                                                                                          #
// # const void Serie::PrintAvec(const std::vector<std::pair<std::wstring, std::wstring>> avec)                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintAvec(const std::vector<std::pair<std::wstring, std::wstring>> avec)
{
    if (affichage_avec_actif && avec.size())
    {
        std::wstring avec_str = keyColor[1] + L"Avec : " + valuesColor;
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
                avec_str += nom + L' ' + keyColor[1] + L'(' + valuesColor + role + keyColor[1] + L')' + valuesColor;
            }
            else if (nom == L"" && role != L"")
            {
                avec_str += keyColor[1] + L'(' + valuesColor + role + keyColor[1] + L')' + valuesColor;
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
        if (found)
            avec_str += L"...";
        int i = Console_Lire_txt(avec_str + L"\r\n", 4, 7);
        //int i = Console_Lire_txt(avec_str + L"\n", 4, 7);
        //Console_Lire(avec_str + L"\r\n", 4, 7);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintChaine                                                                                                                                        #
// # const void Serie::PrintChaine(const std::vector<std::wstring>&chaine)                                                                              #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintChaine(const std::wstring& chaine)
{
    if (chaine_ == true && chaine.size() > 0)
    {
        std::wstring chaine_str = keyColor[0] + L"Chaîne d'origine : " + valuesColor + chaine + L"\r\n";
        //PrintStringW(m_hOut, creee_par_str, 0);
        //PrintStringW(HANDLE hOut, creee_par_str);
        int i = Console_Lire_txt(chaine_str, 0, 0);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintCreee_par                                                                                                                                     #
// # const void Serie::PrintCreee_par(const std::vector<std::wstring>&creee_par)                                                                        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintCreee_par(const std::vector<std::wstring>& creee_par)
{
    if (affichage_creee_par_actif && creee_par.size() > 0)
    {
        std::wstring creee_par_str = keyColor[0] + L"Créée" + ((creee_par.size() > 1) ? L"s" : L"") + L" par : " + valuesColor;
        bool first = true;
        for (auto&& c : creee_par)
        {
            if (!first)
            {
                creee_par_str += keyColor[0] + L", " + valuesColor;
            }
            creee_par_str += c;
            first = false;
        }
        creee_par_str += L"\r\n";

        //PrintStringW(m_hOut, creee_par_str, 0);
        //PrintStringW(HANDLE hOut, creee_par_str);
        int i = Console_Lire_txt(creee_par_str, 0, 0);
        //Console::PrintStringW(creee_par_str, 0);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintEn_relation_avec                                                                                                                              #
// # const void Serie::PrintEn_relation_avec(const std::vector<std::wstring>&en_relation_avec)                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintEn_relation_avec(const std::vector<std::wstring>&en_relation_avec)
{
    if (en_relation_avec_ == true && en_relation_avec.size() > 0)
    {
        std::wstring en_relation_avec_str = keyColor[0] + L"En relation avec : " + valuesColor;
        bool first = true;
        for (auto&& e : en_relation_avec)
        {
            if (!first)
            {
                en_relation_avec_str += keyColor[0] + L", " + valuesColor;
            }
            en_relation_avec_str += e;
            first = false;
        }
        en_relation_avec_str += L"\r\n";

        //PrintStringW(m_hOut, creee_par_str, 0);
        //PrintStringW(HANDLE hOut, creee_par_str);
        int i = Console_Lire_txt(en_relation_avec_str, 0, 0);
    }
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # const void Serie::PrintHeader()                                                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintHeader()
{
    if (affichage_titre_actif)
    {
        std::wstring titres_str;
        std::wstring annees_str;
        std::wstring sur_str;
        std::wstring sj_str;
        std::wstring temps_str;
        std::wstring note_str;

        titres_str = keyColor[0] + L"Titre : " + valuesColor + titre[0];
        if (titre.size() > 1)
            titres_str += keyColor[1] + titre[1] + valuesColor + titre[2];
        // Année(s)
        if (affichage_annees_actif)
        {
            //annees_str = format_Annees();
            wchar_t date_string[22];
            wcsftime(date_string, 15, L"%Y", &Date_Diffusee_a_partir_de[0]);
            const std::wstring wstr = date_string;
            annees_str = keyColor[0] + L" [" + valuesColor + wstr;
            if (D_I > 1)
            {
                annees_str += keyColor[1] + L'-' + valuesColor;
                wcsftime(date_string, 15, L"%Y", &Date_Diffusee_a_partir_de[D_I - 1]);
                const std::wstring wstr2 = date_string;
                if (wstr != wstr2)
                {
                    annees_str += wstr2;
                }
            }
            annees_str += keyColor[0] + L']' + valuesColor;
        }
        // Sur
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
            temps_str += L' ' + afficher_OK_Temps(Temps, keyColor[0], valuesColor);
        // Note
        if (affichage_note_actif)
            //note_str += calcul_Note_Affichage();
            note_str += afficher_OK_Note();
        //std::wcout << titres_str << annees_str << sur_str << sj_str << temps_str << note_str << std::endl;
        int i = Console_Lire_txt(titres_str + annees_str + sur_str + sj_str + temps_str + note_str + L"\r\n", 0, 0);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintNote                                                                                                                                          #
// # const void Serie::PrintNote()                                                                                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintNote(int I, int x)
{
    if (affichage_note_actif)
    {
        std::wstring m_note_str;
        bool found = false;
        for (const auto& [cle, valeur] : m_note)
        {
            if (I == cle)
            {
                found = true;
                m_note_str = keyColor[1] + L"Note : " + valuesColor;
                if (valeur == -1.0)
                {
                    found = false;
                    break;
                }
                else if (valeur == 0 || valeur == 1 || valeur == 2 || valeur == 3 || valeur == 4 || valeur == 5)
                {
                    m_note_str += std::to_wstring(static_cast<int>(std::floor(valeur)));
                }
                else
                {
                    std::wstring wstr = std::to_wstring(valeur);
                    wstr = wstr[0] + keyColor[1] + wstr[1] + valuesColor + wstr[2];
                    m_note_str += wstr;
                }
                m_note_str += keyColor[1] + L"/5" + valuesColor;
                int i = Console_Lire_txt(m_note_str, x, x);
                break;
            }
        }
        if (!found)
            int i = Console_Lire_txt(keyColor[1] + L'(' + valuesColor + L"Pas de note !" + keyColor[1] + L')' + valuesColor, x, x);
    }
    return;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintTitre                                                                                                                                         #
// # const void Serie::PrintTitre()                                                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintTitre()
{
    if (affichage_titre_actif)
    {
        std::wstring titre_str;
        std::wstring wstr;
        bool titre_ = false;
        titre_str = keyColor[0] + L"Titre : " + valuesColor + titre[0];
        if (titre[2] != L"")
            titre_str += keyColor[1] + titre[1] + valuesColor + titre[2];
        if (Date_Diffusee_a_partir_de_[0] && Date_Diffusee_a_partir_de[0].tm_year != 0)
        {
             wchar_t date_string[22];
             wcsftime(date_string, 15, L"%Y", &Date_Diffusee_a_partir_de[0]);
             wstr = date_string;
             titre_str += keyColor[0] + L" (" + valuesColor + wstr + keyColor[0] + L')' + valuesColor;
        }
        // Sur
        if (affichage_sur_actif && sur != L"")
        {
            titre_str += keyColor[0] + L" (" + valuesColor + sur + keyColor[0] + L')' + valuesColor;
            // Disney+ SJ
            if (affichage_disney_sj_actif && disney_sj.length() != 0)
                titre_str += (keyColor[0] + L" [" + valuesColor + disney_sj + keyColor[0] + L']' + valuesColor);
            // Netflix SJ
            if (affichage_netflix_sj_actif && netflix_sj.length() != 0)
                titre_str += (keyColor[0] + L" [" + valuesColor + netflix_sj + keyColor[0] + L']' + valuesColor);
        }
        else
        {
            // Disney+ SJ
            if (affichage_disney_sj_actif && disney_sj.length() != 0)
                titre_str += keyColor[0] + L" (" + valuesColor + L"Disney+ : " + disney_sj + keyColor[0] + L')' + valuesColor;
            // Netflix SJ
            if (affichage_netflix_sj_actif && netflix_sj.length() != 0)
                titre_str += keyColor[0] + L" (" + valuesColor + L"Netflix : " + netflix_sj + keyColor[0] + L')' + valuesColor;
        }
        // La signalétique jeunesse
        if (affichage_sj_actif && sj.length() != 0)
            titre_str += keyColor[0] + L" (" + valuesColor + sj + keyColor[0] + L')' + valuesColor;
        if (affichage_temps_actif)
        {
            titre_str += L' ';
            wstr = afficher_OK_Temps(Temps, keyColor[0], valuesColor);
            titre_str += wstr;
        }
        // Note
        //wstr = PrintNote();
        wstr = afficher_OK_Note();
        titre_str += wstr;
        //int i = Console_Lire_txt(titre_str + wstr, 0, 0);
        int i = Console_Lire_txt(titre_str, 0, 0);
        //Console_Lire(titre_str + L'\n', 0, 0);
    }
}


