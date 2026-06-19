/*
** YNOV PROJECT, 2026
** Ynov
** File description:
** Header
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <limits>

struct Contact {
    std::string prenom;
    std::string nom;
    std::string telephone;
    std::string email;
};

extern std::vector<Contact> contacts;
extern const std::string    FICHIER_CONTACTS;

enum class Priorite { HAUTE = 0, NORMALE = 1, BASSE = 2 };
enum class Statut   { A_FAIRE = 0, EN_COURS = 1, TERMINE = 2 };

struct Tache {
    std::string titre;
    Priorite    priorite;
    Statut      statut;
    std::string dateCreation;
};

extern std::vector<Tache>   taches;
extern const std::string    FICHIER_TACHES;

std::string toLower(const std::string& s);
int         lireEntier(const std::string& invite);
int         clamp(int valeur, int min, int max);

void chargerContacts();
void sauvegarderContacts();
void afficherContact(int index, const Contact& c);
void afficherTousContacts();
void afficherMenuCarnet();
void ajouterContact();
void rechercherContact();
void modifierContact();
void supprimerContact();
void menuCarnet();

std::string prioriteStr(Priorite p);
std::string statutStr(Statut s);
std::string dateAujourdhui();

void chargerTaches();
void sauvegarderTaches();
void afficherTache(int index, const Tache& t);
void afficherToutesTaches(const std::vector<Tache>& liste);
void afficherMenuTodo();
void ajouterTache();
void filtrerTaches();
void modifierStatut();
void supprimerTache();
void menuTodo();
