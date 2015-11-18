/*### T_PROCESSEUR ############################################################

INF145 - A2015 - �cole de Technologie Sup�rieure

Pierre Goyette
Vincent Bachand-Dion
Jean-Claude Donnou
�tienne B�gin-Simard
#############################################################################*/

#include "t_processeur.h"


/*########## TRAITER_PAQUET ###################################################
	Strat�gie:
	D�but
		Initialiser � 0 une variable pour le nombre de fichier �crit.
		D�cr�menter de 1 le temps restant du processus.
		Si le temps restant est � 0
			Placer le paquet du processeur dans le fichier.
			Si le nombre de paquets plac�s est �gal au nombre total de paquets du fichier
				�crire le fichier sur disque.
				Lib�re la m�moire des paquets du fichier.
				Incr�menter le nombre de fichiers �crits.
			Fin Si

			Le processeur est � nouveau disponible.
		Fin Si
	Fin
	Retourner le nombre de fichiers �crits.
*/
int traiter_paquet(t_processeur* processeur, t_fichier* fichier)
{

}