/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Logique métier de la To-Do List
*/

#include "../../include/types.hpp"

void ajouterTache()
{
    Tache t;

    std::cout << "Titre : ";
    std::getline(std::cin, t.titre);

    int p = lireEntier("Priorite (0=Haute, 1=Normale, 2=Basse) : ");

    t.priorite     = static_cast<Priorite>(clamp(p, 0, 2));
    t.statut       = Statut::A_FAIRE;
    t.dateCreation = dateAujourdhui();

    taches.push_back(t);
    sauvegarderTaches();
    std::cout << "Tache ajoutee.\n";
}

void filtrerTaches()
{
    int type = lireEntier("Filtrer par : 1=Statut 2=Priorite\n> ");

    std::vector<Tache> resultat;

    if (type == 1) {
        int s = lireEntier("Statut (0=A faire, 1=En cours, 2=Termine) : ");

        for (const Tache& t : taches)
            if (static_cast<int>(t.statut) == s)
                resultat.push_back(t);
    } else {
        int p = lireEntier("Priorite (0=Haute, 1=Normale, 2=Basse) : ");

        for (const Tache& t : taches)
            if (static_cast<int>(t.priorite) == p)
                resultat.push_back(t);
    }

    afficherToutesTaches(resultat);
}

void modifierStatut()
{
    afficherToutesTaches(taches);
    if (taches.empty())
        return;
    
    int n = lireEntier("Numero de la tache : ");

    if (n < 1 || n > static_cast<int>(taches.size())) {
        std::cout << "Numero invalide.\n";
        return;
    }

    int s = lireEntier("Nouveau statut (0=A faire, 1=En cours, 2=Termine) : ");

    taches[n - 1].statut = static_cast<Statut>(clamp(s, 0, 2));
    sauvegarderTaches();
    std::cout << "Statut mis a jour.\n";
}

void supprimerTache()
{
    afficherToutesTaches(taches);
    if (taches.empty())
        return;
    
    int n = lireEntier("Numero a supprimer : ");

    if (n < 1 || n > static_cast<int>(taches.size())) {
        std::cout << "Numero invalide.\n";
        return;
    }

    taches.erase(taches.begin() + n - 1);
    sauvegarderTaches();
    std::cout << "Tache supprimee.\n";
}

void menuTodo()
{
    int choix;
    do {
        afficherMenuTodo();
        choix = lireEntier("Choix : ");

        switch (choix) {
            case 1: ajouterTache(); break;
            case 2: afficherToutesTaches(taches); break;
            case 3: filtrerTaches(); break;
            case 4: modifierStatut(); break;
            case 5: supprimerTache(); break;
            case 6: std::cout << "Retour au menu principal.\n"; break;
            default: std::cout << "Choix invalide.\n";
        }
    } while (choix != 6);
}
