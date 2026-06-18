/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** fonction
*/

#include "../include/types.hpp"

std::string prioriteStr(Priorite p)
{
    switch (p) {
        case Priorite::HAUTE: return "Haute";
        case Priorite::NORMALE: return "Normale";
        default: return "Basse";
    }
}

std::string statutStr(Statut s)
{
    switch (s) {
        case Statut::A_FAIRE: return "A faire";
        case Statut::EN_COURS: return "En cours";
        default: return "Terminer";
    }
}

std::string dateAujourdhui()
{
    time_t t = time(nullptr);
    tm* tm_info = localtime(&t);
    char buf[11];

    strftime(buf, sizeof(buf), "%d/%m/%Y", tm_info);
    return std::string(buf);
}

int lireEntier(const std::string& invite)
{
    int valeur;
    bool valide = false;

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
