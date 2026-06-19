/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Fonctions utilitaires partagees
*/

#include "../include/types.hpp"

std::string toLower(const std::string& s)
{
    std::string r = s;

    for (char& c : r)
        c = std::tolower(c);
    return r;
}

int lireEntier(const std::string& invite)
{
    int     valeur;
    bool    valide = false;

    while (!valide) {
        std::cout << invite;
        std::cin >> valeur;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entree invalide. Veuillez entrer un nombre.\n";
        } else {
            std::cin.ignore();
            valide = true;
        }
    }
    return valeur;
}

int clamp(int valeur, int min, int max)
{
    return std::max(min, std::min(max, valeur));
}
