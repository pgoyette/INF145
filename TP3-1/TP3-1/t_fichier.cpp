/* T_FICHIER 

	INF145 - A2015 - École de Technologie Supérieure

	Pierre Goyette
	Vincent Bachand-Dion
	Jean-Claude Donnou
	Étienne Bégin-Simard
*/

#include "t_fichier.h"


//Retourne un fichier du bon nombre de paquets avec l'id fourni.
//Aucun paquet reçu encore.
t_fichier nouveau_fichier(int nb_paquets, const char id[MAX_CAR_ID])
{
	int i;

	//le titre du tableau crée est nouveau_fichier
	t_fichier nouveau_fichier;

	//allocation du nombre de paquets selon le paramètre reçu
	nouveau_fichier.tab = (t_paquet**)malloc(nb_paquets * sizeof(char*));


	//On parcourt chaque case de la ligne
	for (i = 0; i < nb_paquets; i++)
	{
		//Allocation du nombre de case pour chaque case de la ligne 
		nouveau_fichier.tab[i] = (t_paquet*)malloc(nb_paquets * sizeof(char));
	}

	//On transfère les paramètres aux espaces réservés pour ceux-ci dans l'enregistrement.
	nouveau_fichier.nb_paquets = nb_paquets;
	nouveau_fichier.id[MAX_CAR_ID] = id[MAX_CAR_ID];

	// On retourne la carte prospection de la taille de 
	//"taille_ligne" par "taille colone
	return nouveau_fichier;
}