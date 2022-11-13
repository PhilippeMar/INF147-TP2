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
		for (int i = 0; i < TAILLE_TABLE_VIGENERE; i++)
	{
		//variable utiliser pour remplir le tableau apres la diagonale de z
		int apres_z = 0;

		for (int j = 0; j < TAILLE_TABLE_VIGENERE; j++)
		{
			if (ASCII_z >= ASCII_a + i + j)
			{
				table_vigenere[i][j] = ASCII_a + i + j;
			}
			else
			{
				table_vigenere[i][j] = ASCII_a + apres_z;
				apres_z++;
			}
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
	//initialisation du tableau pour le chiffrement
	unsigned char table_de_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];
	VIGENERE_remplir_table_vigenere(table_de_vigenere);

		int k = 0;
		//compteur de lettre de la cle
		//On réinitialise rendu au dernier charactère de la cle
		int compte_lettre = 0;

		while (k < taille_message)
		{
			if (isalpha(message[k]) != 0)
			{
				if (compte_lettre>=taille_cle)
				{
					compte_lettre = 0;
				}
				message[k] = table_de_vigenere[cle[compte_lettre] - ASCII_a][message[k] - ASCII_a];
				compte_lettre++;
			}
			k++;
		}
}

// Decode un message encode avec le chiffre de Vigenere a partir de sa cle.
void VIGENERE_decrypter(unsigned char* message,
						const unsigned int taille_messsage,
						unsigned char* cle,
						const unsigned int taille_cle)
{
	//initialisation du tableau pour le chiffrement
	unsigned char table_de_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];
	VIGENERE_remplir_table_vigenere(table_de_vigenere);

	int k = 0;
	//compteur de lettre de la cle
	//On réinitialise rendu au dernier charactère de la cle
	int compte_lettre = 0;

	while (k < taille_messsage)
	{
		if (isalpha(message[k]) != 0)
		{
			int l = 0;
			if (compte_lettre >= taille_cle)
			{
				compte_lettre = 0;
			}
			while (message[k] != table_de_vigenere[cle[compte_lettre] - ASCII_a][l])
			{
				l++;
			}
			message[k] = table_de_vigenere[0][l];
			compte_lettre++;
		}
		k++;
	}
}
