/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Main
*/

#include "include/types.hpp"

std::vector<Contact>    contacts;
const std::string       FICHIER = "contacts.csv";

int main()
{
    chargerCSV();

    int choix;

    do {
        afficherMenu();
        choix = lireEntier("Choix : ");

        switch (choix) {
            case 1: ajouterContact();    break;
            case 2: afficherTous();      break;
            case 3: rechercherContact(); break;
            case 4: modifierContact();   break;
            case 5: supprimerContact();  break;
            case 6: std::cout << "Au revoir !\n"; break;
            default: std::cout << "Choix invalide.\n";
        }
    } while (choix != 6);

    return 0;
}
