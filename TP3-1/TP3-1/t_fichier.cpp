/*### T_FICHIER ###############################################################

	INF145 - A2015 - �cole de Technologie Sup�rieure

	Pierre Goyette
	Vincent Bachand-Dion
	Jean-Claude Donnou
	�tienne B�gin-Simard
#############################################################################*/

#include "t_fichier.h"


/*########## NOUVEAU_FICHIER ##################################################
	Strat�gie:
  Retourne un fichier du bon nombre de paquets avec l'id fourni.
  Aucun paquet re�u encore.
*/
t_fichier nouveau_fichier(int nb_paquets, const char id[MAX_CAR_ID])
{
	//Le titre du tableau cr�e est nouveau_fichier
	t_fichier nouveau_fichier;

	//Allocation du nombre de paquets selon le param�tre re�u
	nouveau_fichier.tab = (const t_paquet**)malloc(nb_paquets * sizeof(const t_paquet*));

	//On transf�re les param�tres aux espaces r�serv�s pour ceux-ci dans 
	//l'enregistrement.
	nouveau_fichier.nb_paquets = 0; 
	nouveau_fichier.id[MAX_CAR_ID] = id[MAX_CAR_ID];

	// On retourne le nouveau fichier
	return nouveau_fichier;
}



/*########## PLACER_PAQUET ####################################################
	Strat�gie:
  Place le paquet selon son num_paquet dans le tableau de paquets
*/
void placer_paquet(t_fichier* fichier, const  t_paquet* paquet)
{
	fichier->tab[(paquet->num_paquet)] = paquet;
	fichier->nb_paquets++;
}


/*########## ECRIRE_FICHIER ###################################################
	Strat�gie:
  Reproduit le fichier sur disque au nom de l'identifiant en y �crivant tous 
  les octets de tous les paquets.
*/
void ecrire_fichier(t_fichier* fichier)
{
	int i;		//It�rateur

	//Ouverture du fichier ayant le nom compris dans fichier->id
	FILE * fic_binaire = fopen(fichier->id,"wb") ; 

	//Boucle qui va �crire chaque partie du paquet dans le fichier
	for (i = 0; i < fichier->nb_paquets; i++)

		//�criture de la partie buffer dans le fichier fichier
		fwrite(fichier->tab[i]->buffer, fichier->tab[i]->taille_paquet,
		NB_PAQUET_ECRITURE, fic_binaire);

	//Fermeture du fichier 
	fclose(fic_binaire);
}


/*########## LIBERER_PAQUETS ##################################################
	Strat�gie:
	Lib�re le fichier en m�moire et ses paquets (free((void*)t_paquet*)) +
	free(fichier).
	Le tableau est mis � NULL.
	*/
void liberer_paquets(t_fichier* fichier)
{
	free((void*)fichier->tab);
	free(fichier);
	fichier->tab = NULL;
}


/*########## FICHIER_EST_ENVOYE ###############################################
	Strat�gie:
		V�rifier si le fichier est complet � partir des informations
		disponibles dans le fichier.
*/
int fichier_est_envoye(const t_fichier* fichier)
{
	return fichier->nb_paquets == fichier->tab[INDICE_VERIF]->nb_total_paquet;
}