/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Main
*/

#include "include/types.hpp"

std::vector<Tache> tache;
const std::string FICHIER = "taches.txt";

int main()
{
    chargerFichier();

    int choix;

    do {
        afficherMenu();
        choix = lireEntier("Choix : ");

        switch (choix) {
            case 1: ajouterTache();         break;
            case 2: afficherToutes(taches); break;
            case 3: filtrer();              break;
            case 4: modifierStatut();       break;
            case 5: supprimerTache();       break;
            case 6: std::cout << "Au revoir !\n"; break;
            default: std::cout << "Choix invalide.\n";
        }
    } while (choix != 6);

    return 0;
}
