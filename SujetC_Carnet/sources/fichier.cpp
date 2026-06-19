/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** fichier.cpp — Gestion de la persistance CSV
*/

#include "types.hpp"

void chargerCSV()
{
    std::ifstream f(FICHIER);

    if (!f.is_open())
        return;

    std::string ligne;
    std::getline(f, ligne); // skip header

    while (std::getline(f, ligne)) {
        std::stringstream ss(ligne);
        Contact c;

        std::getline(ss, c.prenom,     ',');
        std::getline(ss, c.nom,        ',');
        std::getline(ss, c.telephone,  ',');
        std::getline(ss, c.email,      ',');

        contacts.push_back(c);
    }
}

void sauvegarderCSV()
{
    std::ofstream f(FICHIER);

    f << "Prenom,Nom,Telephone,Email\n";

    for (const Contact& c : contacts) {
        f << c.prenom    << ","
          << c.nom       << ","
          << c.telephone << ","
          << c.email     << "\n";
    }
}
