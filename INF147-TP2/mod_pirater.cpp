/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Novembre 2022
--Description
	Ce module est utilise pour pirater les divers type d'encryption
On y retrouve les sous-programmes suivants :
	- PIRATER_calculer_frequences
	- test_PIRATER_calculer_frequences
	- PIRATER_dechiffrer_cesar
	- PIRATER_generer_alphabet_reference
	- test_PIRATER_generer_alphabet_reference
	- PIRATER_extraire_cle
	- PIRATER_attaque_frequences
	- PIRATER_permuter_lettres
	- PIRATER_extraire_cle_vigenere
*****************************************************************************************/

#include "mod_pirater.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Calculer les frequences d'apparition relatives des lettres de l'alphabet dans un message encode.
void PIRATER_calculer_frequences(double* tab_frequences,
	const unsigned char* message,
	const unsigned int taille)
{
	unsigned int nb_lettre = 0;
	for (unsigned int i = 0; i < taille; i++)
	{
		if (isalpha(message[i]))
		{
			// Lettre minuscule ou majuscule 
			unsigned char offset_maj = (message[i] >= ASCII_a) ? 0 : 32;
			// Incrementer le compteur de frequence du charactere et le nombre de lettre
			tab_frequences[message[i] - 'a' + offset_maj]++;
			nb_lettre++;
		}
	}

	for (unsigned int i = 0; i < TAILLE_ALPHABET; i++)
	{
		tab_frequences[i] /= (double)nb_lettre;
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
	// Calculer la table de frequences
	double tab_frequences[TAILLE_ALPHABET] = { 0.0 };
	PIRATER_calculer_frequences(tab_frequences, message, taille);

	// Definir le decalage selon la table de frequences
	int decalage = ((int)OUTILS_obtenir_position_max_dbl(tab_frequences, TAILLE_ALPHABET) - ('e' - ASCII_a)) % TAILLE_ALPHABET;
	if (decalage < 0) decalage += TAILLE_ALPHABET;

	// Decrypter le message
	CESAR_decrypter(message, taille, decalage);
}

// Genere l'alphabet trie en ordre decroissant de frequences d'apparition.
void PIRATER_generer_alphabet_reference(unsigned char* tab_alphabet_ref)
{
	unsigned int alphabet_ref[TAILLE_ALPHABET] = { 'e','a','s','i','n','t','r','l','u','o','d','c','m','p','g','v','b','f','q','h','x','j','y','k','w','z' };
	for (unsigned int i = 0; i < TAILLE_ALPHABET; i++)
	{
		tab_alphabet_ref[i] = alphabet_ref[i];
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
	// Calculer la table de frequences
	double tab_frequences[TAILLE_ALPHABET] = { 0.0 };
	PIRATER_calculer_frequences(tab_frequences, message, taille);

	// Generation tableau alphabet
	unsigned char tab_alphabet[TAILLE_ALPHABET];
	CRYPT_generer_alphabet(tab_alphabet);

	// Trier en fonction du tableau de frequences
	OUTILS_tri_decroissant_etendu_dbl_uchar(tab_frequences, tab_alphabet, TAILLE_ALPHABET);

	// On retourne la cle
	for (unsigned int i = 0; i < TAILLE_ALPHABET; i++)
	{
		cle[i] = tab_alphabet[i];
	}
}

// Implemente une attaque basee sur l'analyse frequentielle.
void PIRATER_attaque_frequences(unsigned char* message,
	const unsigned int taille)
{
	//Extraire la cle
	unsigned char cle[TAILLE_ALPHABET];
	PIRATER_extraire_cle(cle, message, taille);

	// Importer alphabet de reference
	unsigned char tab_alphabet_ref[TAILLE_ALPHABET];
	PIRATER_generer_alphabet_reference(tab_alphabet_ref);

	// Substitution des lettres
	for (unsigned int i = 0; i < taille; i++)
	{
		// Decryption du message avec la cle obtenue
		for (unsigned int j = 0; j < TAILLE_ALPHABET; j++)
		{
			if (message[i] == cle[j])
			{
				message[i] = tab_alphabet_ref[j];
				break;
			}
		}
	}
}

// Remplace une lettre par une autre et vice-versa dans un message.
void PIRATER_permuter_lettres(unsigned char* message,
	const unsigned int  taille,
	const unsigned char premiere_lettre,
	const unsigned char deuxieme_lettre)
{
	for (unsigned int i = 0; i < taille; i++)
	{
		// Permute la premiere lettre avec la deuxieme
		if (message[i] == premiere_lettre)
			message[i] = deuxieme_lettre;
		// Permute la deuxieme lettre avec la premiere
		else if (message[i] == deuxieme_lettre)
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

	// Boucle principal selon la taille de la cle
	for (int i = 0; i < taille_cle; i++)
	{
		// Initialisation des fréqnences
		for (int j = 0; j < TAILLE_ALPHABET; j++)
		{
			frequence[j] = { 0. };
		}

		//nombre de lettre pour la division de fréquence
		unsigned int nombre_lettre_frequence = 0;

		//compte les lettres de la cle avant la réinitialisation
		unsigned int nombre_lettre_total = 0;

		// Calcul du nombre d'occurence de chaque lettre
		for (int j = 0; j < taille_message; j++) {
			if (isalpha(message[j]) != 0) {
				if (nombre_lettre_total % taille_cle == 0)
				{
					frequence[message[i + j] - ASCII_a]++;
					nombre_lettre_frequence++;
				}
				nombre_lettre_total++;
			}
		}

		// On divise par le nombre de lettre total pour avoir un pourcentage (une frequence) d'apparition
		for (int j = 0; j < TAILLE_ALPHABET; j++)
		{
			frequence[j] /= nombre_lettre_frequence;
		}

		// Calcul du décalage
		int decalage = (int)OUTILS_obtenir_position_max_dbl(frequence, TAILLE_ALPHABET) - (ASCII_e - ASCII_a);
		cle[i] = (ASCII_a + decalage);
	}
}
