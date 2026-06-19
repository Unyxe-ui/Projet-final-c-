/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Fonctions d'affichage de la To-Do List
*/

#include "../../include/types.hpp"

std::string prioriteStr(Priorite p)
{
    switch (p) {
        case Priorite::HAUTE:   return "Haute";
        case Priorite::NORMALE: return "Normale";
        case Priorite::BASSE:   return "Basse";
    }
    return "Inconnue";
}

std::string statutStr(Statut s)
{
    switch (s) {
        case Statut::A_FAIRE:  return "A faire";
        case Statut::EN_COURS: return "En cours";
        case Statut::TERMINE:  return "Termine";
    }
    return "Inconnu";
}

std::string dateAujourdhui()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%d/%m/%Y", now);
    return std::string(buf);
}

void afficherTache(int index, const Tache& t)
{
    std::cout << "[" << index << "] " << t.titre
              << " | Priorite : " << prioriteStr(t.priorite)
              << " | Statut : " << statutStr(t.statut)
              << " | Cree le : " << t.dateCreation << "\n";
}

void afficherToutesTaches(const std::vector<Tache>& liste)
{
    if (liste.empty()) {
        std::cout << "Aucune tache trouvee.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(liste.size()); i++)
        afficherTache(i + 1, liste[i]);
}

void afficherMenuTodo()
{
    std::cout << "\n=== TO-DO LIST ===\n";
    std::cout << "1. Ajouter une tache\n";
    std::cout << "2. Afficher toutes les taches\n";
    std::cout << "3. Filtrer les taches\n";
    std::cout << "4. Modifier le statut d'une tache\n";
    std::cout << "5. Supprimer une tache\n";
    std::cout << "6. Quitter\n";
}
