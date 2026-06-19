/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Fonctions d'affichage du Carnet
*/

#include "../../include/types.hpp"

void afficherContact(int index, const Contact& c)
{
    std::cout << "[" << index << "] "
              << c.prenom << " " << c.nom
              << " | Tel : "   << c.telephone
              << " | Email : " << c.email
              << "\n";
}

void afficherTousContacts()
{
    if (contacts.empty()) {
        std::cout << "Carnet vide.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(contacts.size()); i++)
        afficherContact(i + 1, contacts[i]);
}

void afficherMenuCarnet()
{
    std::cout << "\n=== CARNET D'ADRESSES ===\n";
    std::cout << "1. Ajouter un contact\n";
    std::cout << "2. Afficher tous les contacts\n";
    std::cout << "3. Rechercher par nom\n";
    std::cout << "4. Modifier un contact\n";
    std::cout << "5. Supprimer un contact\n";
    std::cout << "6. Quitter\n";
}
