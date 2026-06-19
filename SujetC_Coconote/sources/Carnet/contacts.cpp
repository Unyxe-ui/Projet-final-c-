/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Logique métier du Carnet d'adresses
*/

#include "../../include/types.hpp"

void ajouterContact()
{
    Contact c;

    std::cout << "Prenom : ";
    std::getline(std::cin, c.prenom);

    std::cout << "Nom : ";
    std::getline(std::cin, c.nom);

    std::cout << "Telephone : ";
    std::getline(std::cin, c.telephone);

    std::cout << "Email : ";
    std::getline(std::cin, c.email);

    contacts.push_back(c);
    sauvegarderContacts();
    std::cout << "Contact ajoute et sauvegarde.\n";
}

void rechercherContact()
{
    std::string terme;

    std::cout << "Recherche par nom : ";
    std::getline(std::cin, terme);

    std::string termeLow = toLower(terme);
    bool        trouve   = false;

    for (int i = 0; i < static_cast<int>(contacts.size()); i++) {
        bool nomMatch    = toLower(contacts[i].nom).find(termeLow)    != std::string::npos;
        bool prenomMatch = toLower(contacts[i].prenom).find(termeLow) != std::string::npos;

        if (nomMatch || prenomMatch) {
            afficherContact(i + 1, contacts[i]);
            trouve = true;
        }
    }

    if (!trouve)
        std::cout << "Aucun contact trouve.\n";
}

void modifierContact()
{
    afficherTousContacts();
    if (contacts.empty())
        return;

    int n = lireEntier("Numero a modifier : ");

    if (n < 1 || n > static_cast<int>(contacts.size())) {
        std::cout << "Numero invalide.\n";
        return;
    }

    Contact&    c   = contacts[n - 1];
    std::string tmp;

    std::cout << "Nouveau prenom (" << c.prenom << ") : ";
    std::getline(std::cin, tmp);
    if (!tmp.empty()) c.prenom = tmp;

    std::cout << "Nouveau nom (" << c.nom << ") : ";
    std::getline(std::cin, tmp);
    if (!tmp.empty()) c.nom = tmp;

    std::cout << "Nouveau telephone (" << c.telephone << ") : ";
    std::getline(std::cin, tmp);
    if (!tmp.empty()) c.telephone = tmp;

    std::cout << "Nouvel email (" << c.email << ") : ";
    std::getline(std::cin, tmp);
    if (!tmp.empty()) c.email = tmp;

    sauvegarderContacts();
    std::cout << "Contact modifie et sauvegarde.\n";
}

void supprimerContact()
{
    afficherTousContacts();
    if (contacts.empty())
        return;

    int n = lireEntier("Numero a supprimer : ");

    if (n < 1 || n > static_cast<int>(contacts.size())) {
        std::cout << "Numero invalide.\n";
        return;
    }

    contacts.erase(contacts.begin() + n - 1);
    sauvegarderContacts();
    std::cout << "Contact supprime.\n";
}

void menuCarnet()
{
    int choix;
    do {
        afficherMenuCarnet();
        choix = lireEntier("Choix : ");

        switch (choix) {
            case 1: ajouterContact(); break;
            case 2: afficherTousContacts(); break;
            case 3: rechercherContact(); break;
            case 4: modifierContact(); break;
            case 5: supprimerContact(); break;
            case 6: std::cout << "Retour au menu principal.\n"; break;
            default: std::cout << "Choix invalide.\n";
        }
    } while (choix != 6);
}
