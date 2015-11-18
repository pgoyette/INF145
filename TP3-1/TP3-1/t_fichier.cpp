/*### T_FICHIER ###############################################################

	INF145 - A2015 - École de Technologie Supérieure

	Pierre Goyette
	Vincent Bachand-Dion
	Jean-Claude Donnou
	Étienne Bégin-Simard
#############################################################################*/

#include "t_fichier.h"


/*########## NOUVEAU_FICHIER ##################################################
	Stratégie:
  Retourne un fichier du bon nombre de paquets avec l'id fourni.
  Aucun paquet reçu encore.
*/
t_fichier nouveau_fichier(int nb_paquets, const char id[MAX_CAR_ID])
{
	//Le titre du tableau crée est nouveau_fichier
	t_fichier nouveau_fichier;

	//Allocation du nombre de paquets selon le paramètre reçu
	nouveau_fichier.tab = (const t_paquet**)malloc(nb_paquets * sizeof(const t_paquet*));

	//On transfère les paramètres aux espaces réservés pour ceux-ci dans 
	//l'enregistrement.
	nouveau_fichier.nb_paquets = 0; 
	nouveau_fichier.id[MAX_CAR_ID] = id[MAX_CAR_ID];

	// On retourne le nouveau fichier
	return nouveau_fichier;
}



/*########## PLACER_PAQUET ####################################################
	Stratégie:
  Place le paquet selon son num_paquet dans le tableau de paquets
*/
void placer_paquet(t_fichier* fichier, const  t_paquet* paquet)
{
	fichier->tab[(paquet->num_paquet)] = paquet;
	fichier->nb_paquets++;
}


/*########## ECRIRE_FICHIER ###################################################
	Stratégie:
  Reproduit le fichier sur disque au nom de l'identifiant en y écrivant tous 
  les octets de tous les paquets.
*/
void ecrire_fichier(t_fichier* fichier)
{
	int i;		//Itérateur

	//Ouverture du fichier ayant le nom compris dans fichier->id
	FILE * fic_binaire = fopen(fichier->id,"wb") ; 

	//Boucle qui va écrire chaque partie du paquet dans le fichier
	for (i = 0; i < fichier->nb_paquets; i++)

		//Écriture de la partie buffer dans le fichier fichier
		fwrite(fichier->tab[i]->buffer, fichier->tab[i]->taille_paquet,
		NB_PAQUET_ECRITURE, fic_binaire);

	//Fermeture du fichier 
	fclose(fic_binaire);
}


/*########## LIBERER_PAQUETS ##################################################
	Stratégie:
	Libère le fichier en mémoire et ses paquets (free((void*)t_paquet*)) +
	free(fichier).
	Le tableau est mis à NULL.
	*/
void liberer_paquets(t_fichier* fichier)
{
	free((void*)fichier->tab);
	free(fichier);
	fichier->tab = NULL;
}


/*########## FICHIER_EST_ENVOYE ###############################################
	Stratégie:
		Vérifier si le fichier est complet à partir des informations
		disponibles dans le fichier.
*/
int fichier_est_envoye(const t_fichier* fichier)
{
	return fichier->nb_paquets == fichier->tab[INDICE_VERIF]->nb_total_paquet;
}