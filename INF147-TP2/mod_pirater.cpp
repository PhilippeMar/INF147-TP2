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

void PIRATER_calculer_frequences(double* tab_frequences, const unsigned char* message, const unsigned int taille)
{
	//variables du calcul de frequence
	//nombre de lettre pour la division de fréquence
	unsigned int nbr_lettre = 0;
	
	unsigned int i = 0;
	unsigned int j = 0;

	while (i < taille)
	{
		if (isalpha(message[i]) != 0)
		{
			tab_frequences[message[i] - ASCII_a]++;
			nbr_lettre++;
		}
		i++;
	}

	while (j < TAILLE_ALPHABET)
	{
		tab_frequences[j] /= nbr_lettre;
		j++;
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
void PIRATER_dechiffrer_cesar(unsigned char* message, const unsigned int taille)
{
	//initiation d'un tableau de deffrichage
	double deffrichage[TAILLE_ALPHABET] = { 0.0 };

	PIRATER_calculer_frequences(deffrichage, message, taille);
	unsigned int decalage = OUTILS_obtenir_position_max_dbl(deffrichage, TAILLE_ALPHABET) - (ASCII_e - ASCII_a);
	CESAR_decrypter(message, taille, decalage);

}

// Genere l'alphabet trie en ordre decroissant de frequences d'apparition.
void PIRATER_generer_alphabet_reference(unsigned char* tab_alphabet_ref)
{
	// TODO
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
	// TODO
}

// Implemente une attaque basee sur l'analyse frequentielle.
void PIRATER_attaque_frequences(unsigned char* message,
								const unsigned int taille)
{
	// TODO
}

// Remplace une lettre par une autre et vice-versa dans un message.
void PIRATER_permuter_lettres(unsigned char* message,
							  const unsigned int  taille,
							  const unsigned char premiere_lettre,
							  const unsigned char deuxieme_lettre)
{
	// TODO
}

// Extrait la cle par analyse frequentielle et l'insere dans un tableau recu en parametre.
void PIRATER_extraire_cle_vigenere(unsigned char* message,
								   const unsigned int taille_message,
								   unsigned char* cle,
								   const unsigned int taille_cle)
{
	//variables de la procedure
	//initiation du tableau de deffrichage
	double deffrichage[TAILLE_ALPHABET];
	
	//nombre de lettre pour la division de fréquence
	unsigned int nbr_lettre;
	//compte les lettres de la cle avant la réinitialisation
	unsigned int compte_lettre;
	
	unsigned int i;
	unsigned int j;

	for (int duration = 0; duration < taille_cle; duration++)
	{
		for (int reset_deffrichage = 0; reset_deffrichage < TAILLE_ALPHABET; reset_deffrichage++)
		{
			deffrichage[reset_deffrichage] = { 0.0 };
		}

		i = 0;
		j = 0;
		nbr_lettre = 0;
		compte_lettre = 0;

		while (i < taille_message)
		{
			if (isalpha(message[i]) != 0)
			{
				if (compte_lettre % taille_cle == 0)
				{
					deffrichage[message[i+duration] - ASCII_a]++;
					nbr_lettre++;
				}
					compte_lettre++;			
			}
				i++;
		}
		while (j < TAILLE_ALPHABET)
		{
			deffrichage[j] /= nbr_lettre;
			j++;
		}

		unsigned int cle_courante = OUTILS_obtenir_position_max_dbl(deffrichage, TAILLE_ALPHABET) - (ASCII_e - ASCII_a);

		cle[duration] = ASCII_a + cle_courante;
	}
}
