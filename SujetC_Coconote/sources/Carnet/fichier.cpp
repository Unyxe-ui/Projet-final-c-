/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Gestion d'écriture/lecture CSV du Carnet
*/

#include "../../include/types.hpp"

void chargerContacts()
{
    std::ifstream f(FICHIER_CONTACTS);

    if (!f.is_open())
        return;

    std::string ligne;
    std::getline(f, ligne);

    while (std::getline(f, ligne)) {
        if (ligne.empty()) continue;
        std::stringstream ss(ligne);
        Contact c;

        std::getline(ss, c.prenom,     ',');
        std::getline(ss, c.nom,        ',');
        std::getline(ss, c.telephone,  ',');
        std::getline(ss, c.email,      ',');

        contacts.push_back(c);
    }
}

void sauvegarderContacts()
{
    std::ofstream f(FICHIER_CONTACTS);

    f << "Prenom,Nom,Telephone,Email\n";

    for (const Contact& c : contacts) {
        f << c.prenom    << ","
          << c.nom       << ","
          << c.telephone << ","
          << c.email     << "\n";
    }
}
