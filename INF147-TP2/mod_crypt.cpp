/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

--Description

On y retrouve les sous-programmes suivants :
	- 
*****************************************************************************************/

#include "mod_crypt.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Genere un tableau qui contient les codes ASCII de l'alphabet en minuscules.
void CRYPT_generer_alphabet(unsigned char* tab_alphabet)
{
    for (int i = 0; i < TAILLE_ALPHABET; i++) {
        tab_alphabet[i]=ASCII_a+i;
    }
}

// Procedure de test pour CRYPT_GENERER_ALPHABET.
void test_CRYPT_generer_alphabet(void)
{

	unsigned char tab_alphabet[TAILLE_ALPHABET];
	CRYPT_generer_alphabet(tab_alphabet);

}

// Genere une cle aleatoire pour l'encodage.
void CRYPT_generer_cle(unsigned char* cle)
{
    CRYPT_generer_alphabet(cle);
    OUTILS_melanger(cle,TAILLE_ALPHABET);
}

// Encode un message a partir d'une cle recue.
void CRYPT_encrypter(unsigned char* message,
					 const unsigned int taille,
					 const unsigned char* cle)
{
    for (int i = 0; i < taille; i++)
        if(message[i] != ' ')
            message[i] = message[i] < ASCII_a ? cle[message[i]-ASCII_A]-DELTA_ASCII : cle[message[i]-ASCII_a];
}

// Decode un message a partir d'une cle recue.
void CRYPT_decrypter(unsigned char* message,
	const unsigned int taille,
	const unsigned char* cle)
{
    for (int i = 0; i < taille; i++) {
        if(message[i] != ' ') {
            bool est_majuscule = false;
            unsigned char val;
            if (message[i] < ASCII_a){
                val = message[i]+DELTA_ASCII;
                est_majuscule = true;
            } else
                val = message[i];
            unsigned int j = 0;
            bool est_trouve = false;
            while (!est_trouve && j<TAILLE_ALPHABET){
                if(cle[j] == val){
                    if (est_majuscule)
                        message[i] = j+ASCII_A;
                    else
                        message[i] = j+ASCII_a;
                    est_trouve = true;
                }
                j++;
            }
        }
    }
}