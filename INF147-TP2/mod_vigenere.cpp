/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

--Description
	Ce fichier permet d'encrypter et decrypter par substitution polyalphabetique

On y retrouve les sous-programmes suivants :
	- VIGENERE_remplir_table_vigenere
	- test_VIGENERE_remplir_table_vigenere
	- VIGENERE_encrypter
	- VIGENERE_decrypter
*****************************************************************************************/

#include "mod_vigenere.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Insere les valeurs de la table de vigenere dans un tableau 26 x 26 recu en parametres.
void VIGENERE_remplir_table_vigenere(unsigned char table_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE])
{
	for (unsigned int i = 0; i < TAILLE_TABLE_VIGENERE; i++)
	{
		for (unsigned int j = 0; j < TAILLE_TABLE_VIGENERE; j++)
		{
			table_vigenere[i][j] = ASCII_a + ((i + j) % 26);
		}
	}
}

// Procedure de test pour VIGENERE_remplir_table_vigenere.
void test_VIGENERE_remplir_table_vigenere(void)
{

	unsigned char table_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];

	VIGENERE_remplir_table_vigenere(table_vigenere);

	for (int i = 0; i < TAILLE_TABLE_VIGENERE; i++)
	{
		for (int j = 0; j < TAILLE_TABLE_VIGENERE; j++)
		{
			printf("%-3u ", table_vigenere[i][j]);
		}
		printf("\n");
	}

}

// Encode un message avec le chiffre de Vigenere a partir d'une cle donnee.
void VIGENERE_encrypter(unsigned char* message,
                        const unsigned int taille_message,
                        unsigned char* cle,
                        const unsigned int taille_cle)
{
    // Genere table de Vigenere
    unsigned char table_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];
    VIGENERE_remplir_table_vigenere(table_vigenere);

    int j = 0;
    for (int i = 0; i < taille_message; i++)
    {
        // On encrypte seulement les charactere alphabetiques
        if (isalpha(message[i]) != 0)
        {
            unsigned int pos_lettre_message = message[i] - ASCII_a;
            unsigned int pos_lettre_cle = cle[j] - ASCII_a;

            // Encryption du charactere
            message[i] = table_vigenere[pos_lettre_cle][pos_lettre_message];

            j++;
            if (j == taille_cle)
                j = 0;
        }
    }
}

// Decode un message encode avec le chiffre de Vigenere a partir de sa cle.
void VIGENERE_decrypter(unsigned char* message,
                        const unsigned int taille_messsage,
                        unsigned char* cle,
                        const unsigned int taille_cle)
{
    // Genere table de Vigenere
    unsigned char table_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];
    VIGENERE_remplir_table_vigenere(table_vigenere);

    int j = 0;
    for (int i = 0; i < taille_messsage; i++)
    {
        // On decrypte seulement les charactere alphabetiques
        if (isalpha(message[i]) != 0)
        {
            unsigned int pos_lettre_message;
            unsigned int pos_lettre_cle = cle[j] - ASCII_a;

            // commentaire
            bool est_trouve = false;
            int k = 0;
            while (!est_trouve)
                if (table_vigenere[pos_lettre_cle][k] == message[i])
                {
                    pos_lettre_message = k;
                    est_trouve = true;
                }
                else
                    k++;

            message[i] = ASCII_a + pos_lettre_message;

            j++;
            if (j == taille_cle)
                j = 0;
        }
    }
}

