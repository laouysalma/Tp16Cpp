#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    string chemin;
    string utilisateur;
    string motDePasse;

    Configuration() {
        chemin = "config.txt";
        utilisateur = "admin";
        motDePasse = "0000";
    }

    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

public:
    static Configuration* getInstance() {
        static Configuration instance;
        return &instance;
    }

    void afficherParametres() {
        cout << "Chemin: " << chemin << "\n";
        cout << "Utilisateur: " << utilisateur << "\n";
        cout << "Mot de passe: " << motDePasse << "\n";
    }
};

int main() {
    Configuration* config = Configuration::getInstance();
    config->afficherParametres();
    return 0;
}
