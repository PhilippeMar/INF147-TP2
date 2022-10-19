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

#include "mod_vigenere.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Insere les valeurs de la table de vigenere dans un tableau 26 x 26 recu en parametres.
void VIGENERE_remplir_table_vigenere(unsigned char[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE])
{
	// TODO
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
	// TODO
}

// Decode un message encode avec le chiffre de Vigenere a partir de sa cle.
void VIGENERE_decrypter(unsigned char* message,
						const unsigned int taille_messsage,
						unsigned char* cle,
						const unsigned int taille_cle)
{
	// TODO
}