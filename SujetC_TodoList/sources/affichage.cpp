/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Fonction d'affichage
*/

#include "../include/types.hpp"

void affichageTache(int index, const Tache& t)
{
    std::cout << "[" << index << "] "
              << t.titre
              << " | Priorite: " << prioriteStr(t.priorite)
              << " | Statut: "   << statutStr(t.statut)
              << " | Cree le: "  << t.dateCreation
              << "\n";
}

void afficherToutes(const std::vector<Tache>& liste)
{
    if (liste.empty()) {
        std::cout << "Aucune tache.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(liste.size()); i++)
        afficherTache(i + 1, liste[i]);
}

void afficherMenu()
{
    std::cout << "\n=== TO-DO LIST ===\n";
    std::cout << "1. Ajouter une tache\n";
    std::cout << "2. Afficher toutes les taches\n";
    std::cout << "3. Filtrer par statut ou priorite\n";
    std::cout << "4. Modifier le statut d'une tache\n";
    std::cout << "5. Supprimer une tache\n";
    std::cout << "6. Quitter\n";
}
