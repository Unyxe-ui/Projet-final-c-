/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Logique métier
*/

#include "../include/types.hpp"

void ajouterTache()
{
    Tache t;

    std::cout << "Titre : ";
    std:: getline(std::cin, t.titre);

    int p = lireEntier("Priorite (0=Haute, 1=Normale, 2=Basse) : ");

    t.priorite     = static_cast<Priorite>(clamp(p, 0, 2));
    t.statut       = Statut::A_FAIRE;
    t.dateCreation = dateAujourdhui();

    taches.push_back(t);
    sauvegarder();
    std::cout << "Tache ajoutee.\n";
}

void filtrer()
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

    afficherToutes(resultat);
}

void modifierStatut()
{
    afficherToutes(taches);
    if (taches.empty())
        return;
    
    int n = lireEntier("Numero de la tache : ");

    if (n < 1 || n > static_cast<int>(taches.size())) {
        std::cout << "Numero invalide.\n";
        return;
    }

    int s = lireEntier("Nouveau statut (0=A faire, 1=En cours, 2=Termine) : ");

    taches[n - 1].statut = static_cast<Statut>(clamp(s, 0, 1));
    sauvegarder();
    std::cout << "Statut mis a jour.\n";
}

void supprimerTache()
{
    afficherToutes(taches);
    if (taches.empty())
        return;
    
    int n = lireEntier("Numero a supprimer : ");

    if (n < 1 || n > static_cast<int>(taches.size())) {
        std::cout << "Numero invalide.\n";
        return;
    }

    taches.erase(taches.begin() + n - 1);
    sauvegarder();
    std::cout << "Tache supprimee.\n";
}
