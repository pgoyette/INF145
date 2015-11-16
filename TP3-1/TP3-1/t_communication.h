#ifndef _T_communication__
#define _T_communication__

#include <time.h>

#include "t_liste.h"
#include "t_fichier.h"
#include "m_emission.h"
#include "m_traitement.h"

/*
* La communication de reconstruction de fichiers par un processeur 
* 
*/
typedef struct
{
	//Le processeur (alloué dynamiquement)
	t_processeur processeur;

	//La file associé au processeur  (alloué dynamiquement)
	t_file file;

	//Les fichier à reconstituer(t_paquet[] ou t_paquet*)
	t_fichier fichier;

	//Pour fin statistiques
	int nb_fic_envoye;

    //Les temps de reconstitution des fichiers
	clock_t debut;
	clock_t fin;

}t_communication;

//Prépare la communication selon le module de traitement inclus
void init_communication(t_communication* communication);

//Obtient les paquets en provenance du module t_emission
//les distribue et les traite.
void demarrer_communication(t_communication* communication);


#endif