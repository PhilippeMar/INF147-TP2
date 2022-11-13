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

#include "mod_pirater.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Calculer les frequences d'apparition relatives des lettres de l'alphabet dans un message encode.
//Issu du code de Teano
void PIRATER_calculer_frequences(double* tab_frequences,
								 const unsigned char* message,
								 const unsigned int taille)
{
    unsigned int nbr_lettre = 0;
    unsigned int lettre1 = 0;
    unsigned int lettre2 = 0;

    while (lettre1 < taille)
    {
        if (isalpha(message[lettre1]) != 0)
        {
            tab_frequences[message[lettre1] - ASCII_a]++;
            nbr_lettre++;
        }
        lettre1++;
    }

    while (lettre2 < TAILLE_ALPHABET)
    {
        tab_frequences[lettre2] /= nbr_lettre;
        lettre2++;
    }
}

// Procedure de test pour PIRATER_calculer_frequences.
void test_PIRATER_calculer_frequences(void)
{

	unsigned char message[] = "abracadabra! s'exclama-t-il";
	unsigned int taille = sizeof(message) / sizeof(char);

	double tab_frequences[TAILLE_ALPHABET] = { 0.0 };
	PIRATER_calculer_frequences(tab_frequences, message, taille);

	for (int i = 0; i < TAILLE_ALPHABET; i = i + 2)
	{
		printf("%c -> %.4lf\t%c -> %.4lf\n", 'a' + i, tab_frequences[i], 'a' + i + 1, tab_frequences[i + 1]);
	}

}

// Implemente une attaque basee sur l'analyse frequentielle sur le code de Cesar.
void PIRATER_dechiffrer_cesar(unsigned char* message,
							  const unsigned int taille)
{
	// TODO
}

// Genere l'alphabet trie en ordre decroissant de frequences d'apparition.
void PIRATER_generer_alphabet_reference(unsigned char* tab_alphabet_ref)
{
    unsigned char alphabet_reference[TAILLE_ALPHABET] = {'e', 'a', 's', 'i', 'n', 't', 'r', 'l', 'u', 'o', 'd', 'c','m','p','g','v','b','f','q','h','x','j','y','k','w','z'};
    for (int i = 0; i < TAILLE_ALPHABET; i++) {
        tab_alphabet_ref[i]=alphabet_reference[i];
    }
}

// Procedure de test pour PIRATER_generer_alphabet_reference
void test_PIRATER_generer_alphabet_reference(void)
{
	unsigned char tab_alphabet_ref[TAILLE_ALPHABET];
	PIRATER_generer_alphabet_reference(tab_alphabet_ref);
}

// Extrait la cle en utilisant l'analyse frequentielle et la preservation des rangs.
void PIRATER_extraire_cle(unsigned char* cle,
						  unsigned char* message,
						  const unsigned int taille)
{
	double freq_message[TAILLE_ALPHABET] = { 0. };
    PIRATER_calculer_frequences(freq_message, message, taille);
    CRYPT_generer_alphabet(cle);
    for (int i = 0; i < TAILLE_ALPHABET; i = i + 2)
    {
        printf("%c -> %.4lf\t%c -> %.4lf\n", 'a' + i, freq_message[i], 'a' + i + 1, freq_message[i + 1]);
    }

    OUTILS_tri_decroissant_etendu_dbl_uchar(freq_message, cle, TAILLE_ALPHABET);

}

// Implemente une attaque basee sur l'analyse frequentielle.
void PIRATER_attaque_frequences(unsigned char* message,
								const unsigned int taille)
{
    unsigned char cle[TAILLE_ALPHABET];
    PIRATER_extraire_cle(cle, message, taille);

    unsigned char alphabet_reference[TAILLE_ALPHABET];
    PIRATER_generer_alphabet_reference(alphabet_reference);

    for (int i = 0; i < TAILLE_ALPHABET; i = i + 2)
    {
        printf("%c -> %c\t%c -> %c\n", cle[i], alphabet_reference[i], cle[i + 1], alphabet_reference[i+1]);
    }

    for (int i = 0; i < taille; i++) {
        int j = 0;
        bool est_trouve = false;
        while (!est_trouve && j < TAILLE_ALPHABET) {
            if (message[i] == cle [j]){
                message[i] = alphabet_reference[j];
                est_trouve = true;
            }
            j++;
        }
    }
}

// Remplace une lettre par une autre et vice-versa dans un message.
void PIRATER_permuter_lettres(unsigned char* message,
							  const unsigned int  taille,
                              const unsigned char premiere_lettre,
                              const unsigned char deuxieme_lettre)
{
    for (int i = 0; i < taille; i++) {
        if(message[i] == premiere_lettre)
            message[i] = deuxieme_lettre;
        else if(message[i] == deuxieme_lettre)
            message[i] = premiere_lettre;
    }
}

// Extrait la cle par analyse frequentielle et l'insere dans un tableau recu en parametre.
void PIRATER_extraire_cle_vigenere(unsigned char* message,
								   const unsigned int taille_message,
								   unsigned char* cle,
								   const unsigned int taille_cle)
{
    double frequence[TAILLE_ALPHABET];

    for (int i = 0; i < taille_cle; i++) 
    {
        for (int j = 0; j < TAILLE_ALPHABET; j++)
        {
            frequence[j] = {0.};
        }

        unsigned int nombre_lettre_frequence = 0;
        unsigned int nombre_lettre_total = 0;
        for (int j = 0; j < taille_message; j++) {
            if (isalpha(message[j]) != 0){
                if(nombre_lettre_total % taille_cle == 0)
                {
                    frequence[message[i+j]-ASCII_a]++;
                    nombre_lettre_frequence++;
                }
                nombre_lettre_total++;
            }
        }

        for (int j = 0; j < TAILLE_ALPHABET; j++)
        {
            frequence[j] /= nombre_lettre_frequence;
        }

        int decalage =(int) OUTILS_obtenir_position_max_dbl(frequence, TAILLE_ALPHABET) - (ASCII_e - ASCII_a);
        cle[i] = (ASCII_a + decalage);
    }
}
