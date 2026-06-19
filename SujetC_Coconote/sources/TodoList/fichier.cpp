/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Gestion d'écriture/lecture des tâches (To-Do List)
*/

#include "../../include/types.hpp"

void chargerTaches()
{
    std::ifstream f(FICHIER_TACHES);

    if (!f.is_open())
        return;

    std::string ligne;
    std::getline(f, ligne);

    while (std::getline(f, ligne)) {
        if (ligne.empty()) continue;
        std::stringstream ss(ligne);
        Tache t;
        std::string pStr, sStr;

        std::getline(ss, t.titre,        ',');
        std::getline(ss, pStr,            ',');
        std::getline(ss, sStr,            ',');
        std::getline(ss, t.dateCreation,  ',');

        if (!pStr.empty()) t.priorite = static_cast<Priorite>(std::stoi(pStr));
        if (!sStr.empty()) t.statut   = static_cast<Statut>(std::stoi(sStr));

        taches.push_back(t);
    }
}

void sauvegarderTaches()
{
    std::ofstream f(FICHIER_TACHES);

    f << "Titre,Priorite,Statut,DateCreation\n";

    for (const Tache& t : taches) {
        f << t.titre << ","
          << static_cast<int>(t.priorite) << ","
          << static_cast<int>(t.statut)   << ","
          << t.dateCreation << "\n";
    }
}
