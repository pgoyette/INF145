/*### T_PROCESSEUR ############################################################

INF145 - A2015 - École de Technologie Supérieure

Pierre Goyette
Vincent Bachand-Dion
Jean-Claude Donnou
Étienne Bégin-Simard
#############################################################################*/

#include "t_processeur.h"


/*########## TRAITER_PAQUET ###################################################
	Stratégie:
	Début
		Initialiser à 0 une variable pour le nombre de fichier écrit.
		Décrémenter de 1 le temps restant du processus.
		Si le temps restant est à 0
			Placer le paquet du processeur dans le fichier.
			Si le nombre de paquets placés est égal au nombre total de paquets du fichier
				Écrire le fichier sur disque.
				Libère la mémoire des paquets du fichier.
				Incrémenter le nombre de fichiers écrits.
			Fin Si

			Le processeur est à nouveau disponible.
		Fin Si
	Fin
	Retourner le nombre de fichiers écrits.
*/
int traiter_paquet(t_processeur* processeur, t_fichier* fichier)
{

}