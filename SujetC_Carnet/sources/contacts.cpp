/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** contacts.cpp — Logique métier
*/

#include "types.hpp"

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
    sauvegarderCSV();
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
    afficherTous();
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

    sauvegarderCSV();
    std::cout << "Contact modifie et sauvegarde.\n";
}

void supprimerContact()
{
    afficherTous();
    if (contacts.empty())
        return;

    int n = lireEntier("Numero a supprimer : ");

    if (n < 1 || n > static_cast<int>(contacts.size())) {
        std::cout << "Numero invalide.\n";
        return;
    }

    contacts.erase(contacts.begin() + n - 1);
    sauvegarderCSV();
    std::cout << "Contact supprime.\n";
}
