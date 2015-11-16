#ifndef _T_TRIAGE__
#define _T_TRIAGE__

/*
* Le centre de traitement d'un paquet pour l'instant.  
* Ce module sera d'une importance capitale dans la deuxi�me partie.
*/

#include "t_paquet.h"
#include "m_emission.h"
#include "t_processeur.h"
#include "t_file.h"
#include "t_fichier.h"

//Cr�e et Initialise le processeur et initialise la file 
//d'attente pour traiter les paquets.  La cat�gorie 
//du processeur est g�n�r� al�atoirement et il est disponible.
//La file est vide.
void init_traitement(t_processeur* processeur,  t_file* file);


//Distribue le paquet dans la file si elle n'est pas pleine.
//Retourne si le paquet a �t� enfil�.
int traiter_arrivee_paquet(const t_paquet* paquet,  t_file* file);

//Si le processeur est disponible, il re�oit un paquet en t�te de file 
//(si elle n�est pas vide).
void distribuer_paquet(t_file* file, t_processeur* processeur);

//Le processeur traite son paquet pour un tour.  Un processeur a 
//termin� lorsque le paquet en traitement est mis dans son fichier 
//et potentiellement �crit sur disque. Retourne le nombre de fichiers
//�mis lors du service (un seul pour l�instant).
int servir_prochain_paquet(t_processeur* processeur, t_fichier* fichier);


#endif