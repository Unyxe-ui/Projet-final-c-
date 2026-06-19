/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Gestion de la lecture/écriture
*/

#include "../include/types.hpp"

void chargerFichier()
{
    std::ifstream f(FICHIER);

    if (!f.is_open())
        return;
    
    std::string ligne;

    while (std::getline(f, ligne)) {
        std::stringstream ss(ligne);
        Tache t;
        std::string p;
        std::string s;

        std::getline(ss, t.titre,        '|');
        std::getline(ss, p,              '|');
        std::getline(ss, s,              '|');
        std::getline(ss, t.dateCreation, '|');

        t.priorite = static_cast<Priorite>(std::stoi(p));
        t.statut = static_cast<Statut>(std::stoi(s));

        taches.push_back(t);
    }
}

void sauvegarder()
{
    std::ofstream f(FICHIER);

    for (const Tache& t : taches) {
        f << t.titre
          << "|" << static_cast<int>(t.priorite)
          << "|" << static_cast<int>(t.statut)
          << "|" << t.dateCreation
          << "\n";
    }
}
