/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** header
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <limits>

enum class Priorite {
    HAUTE = 0,
    Normal = 1,
    BASSE = 2
};

enum class Statut {
    A_FAIRE = 0,
    EN_COURS = 1,
    TERMINER = 2
};

struct Tache {
    std::string titre;
    Priorite priorite;
    Statut statut;
    std::string dateCreation;
};

extern std::vector<Tache> taches;
extern const std::string FICHIER;

std::string prioriteStr(Priorite p);
std::string statutStr(Statut s);
std::string dateAujourdhui();
int lireEntier(const std::string& invite);
int clamp (int valeur, int min, int max);

void chargerFichier();
void sauvegarder();
void afficherTache(int index, const Tache& t);
void afficherToutes(const std::vector<Tache>& liste);
void afficherMenu();
void ajouterTache();
void filtrer();
void modifierStatut();
void supprimerTache();
