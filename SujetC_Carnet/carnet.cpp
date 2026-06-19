#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

struct Contact {
    std::string prenom;
    std::string nom;
    std::string telephone;
    std::string email;
};

std::vector<Contact> contacts;
const std::string FICHIER = "contacts.csv";

std::string toLower(const std::string& s) {
    std::string r = s;
    for (char& c : r) c = std::tolower(c);
    return r;
}

void chargerCSV() {
    std::ifstream f(FICHIER);
    if (!f.is_open()) return;
    std::string ligne;
    std::getline(f, ligne); // header
    while (std::getline(f, ligne)) {
        std::stringstream ss(ligne);
        Contact c;
        std::getline(ss, c.prenom, ',');
        std::getline(ss, c.nom, ',');
        std::getline(ss, c.telephone, ',');
        std::getline(ss, c.email, ',');
        contacts.push_back(c);
    }
}

void sauvegarderCSV() {
    std::ofstream f(FICHIER);
    f << "Prenom,Nom,Telephone,Email\n";
    for (const Contact& c : contacts)
        f << c.prenom << "," << c.nom << "," << c.telephone << "," << c.email << "\n";
}

void afficherContact(int i, const Contact& c) {
    std::cout << "[" << i << "] " << c.prenom << " " << c.nom
              << " | Tel : " << c.telephone
              << " | Email : " << c.email << "\n";
}

void afficherTous() {
    if (contacts.empty()) { std::cout << "Carnet vide.\n"; return; }
    for (int i = 0; i < (int)contacts.size(); i++)
        afficherContact(i + 1, contacts[i]);
}

void ajouterContact() {
    Contact c;
    std::cout << "Prenom : "; std::getline(std::cin, c.prenom);
    std::cout << "Nom : "; std::getline(std::cin, c.nom);
    std::cout << "Telephone : "; std::getline(std::cin, c.telephone);
    std::cout << "Email : "; std::getline(std::cin, c.email);
    contacts.push_back(c);
    sauvegarderCSV();
    std::cout << "Contact ajoute et sauvegarde.\n";
}

void rechercherContact() {
    std::string terme;
    std::cout << "Recherche par nom : ";
    std::getline(std::cin, terme);
    std::string termeLow = toLower(terme);
    bool trouve = false;
    for (int i = 0; i < (int)contacts.size(); i++) {
        if (toLower(contacts[i].nom).find(termeLow) != std::string::npos ||
            toLower(contacts[i].prenom).find(termeLow) != std::string::npos) {
            afficherContact(i + 1, contacts[i]);
            trouve = true;
        }
    }
    if (!trouve) std::cout << "Aucun contact trouve.\n";
}

void modifierContact() {
    afficherTous();
    if (contacts.empty()) return;
    std::cout << "Numero a modifier : ";
    int n; std::cin >> n; std::cin.ignore();
    if (n < 1 || n > (int)contacts.size()) { std::cout << "Numero invalide.\n"; return; }
    Contact& c = contacts[n - 1];
    std::cout << "Nouveau prenom (" << c.prenom << ") : ";
    std::string tmp; std::getline(std::cin, tmp);
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

void supprimerContact() {
    afficherTous();
    if (contacts.empty()) return;
    std::cout << "Numero a supprimer : ";
    int n; std::cin >> n; std::cin.ignore();
    if (n < 1 || n > (int)contacts.size()) { std::cout << "Numero invalide.\n"; return; }
    contacts.erase(contacts.begin() + n - 1);
    sauvegarderCSV();
    std::cout << "Contact supprime.\n";
}

int main() {
    chargerCSV();
    int choix;
    do {
        std::cout << "\n=== CARNET D'ADRESSES ===\n";
        std::cout << "1. Ajouter un contact\n";
        std::cout << "2. Afficher tous les contacts\n";
        std::cout << "3. Rechercher par nom\n";
        std::cout << "4. Modifier un contact\n";
        std::cout << "5. Supprimer un contact\n";
        std::cout << "6. Quitter\n";
        std::cout << "Choix : ";
        std::cin >> choix; std::cin.ignore();
        switch (choix) {
            case 1: ajouterContact(); break;
            case 2: afficherTous(); break;
            case 3: rechercherContact(); break;
            case 4: modifierContact(); break;
            case 5: supprimerContact(); break;
            case 6: std::cout << "Au revoir !\n"; break;
            default: std::cout << "Choix invalide.\n";
        }
    } while (choix != 6);
    return 0;
}
