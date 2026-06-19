/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Main
*/

#include "include/types.hpp"

std::vector<Contact>    contacts;
const std::string       FICHIER_CONTACTS = "contacts.csv";

std::vector<Tache>      taches;
const std::string       FICHIER_TACHES   = "taches.txt";

int main()
{
    chargerContacts();
    chargerTaches();

    int choix;

    do {
        std::cout << "\n========================================\n";
        std::cout << "        GESTIONNAIRE PERSONNEL\n";
        std::cout << "========================================\n";
        std::cout << "1. Carnet d'adresses (" << contacts.size() << " contact(s))\n";
        std::cout << "2. To-Do List ("         << taches.size()   << " tache(s))\n";
        std::cout << "3. Quitter\n";
        choix = lireEntier("Choix : ");

        switch (choix) {
            case 1: menuCarnet(); break;
            case 2: menuTodo();   break;
            case 3: std::cout << "Au revoir !\n"; break;
            default: std::cout << "Choix invalide.\n";
        }
    } while (choix != 3);

    return 0;
}
