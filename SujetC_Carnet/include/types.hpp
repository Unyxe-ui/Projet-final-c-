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
#include <cctype>
#include <limits>

struct Contact {
    std::string prenom;
    std::string nom;
    std::string telephone;
    std::string email;
};

extern std::vector<Contact> contacts;
extern const std::string    FICHIER;

std::string toLower(const std::string& s);
int         lireEntier(const std::string& invite);

void chargerCSV();
void sauvegarderCSV();
void afficherContact(int index, const Contact& c);
void afficherTous();
void afficherMenu();
void ajouterContact();
void rechercherContact();
void modifierContact();
void supprimerContact();
