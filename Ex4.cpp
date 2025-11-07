#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class StrategieTri {
public:
    virtual void trier(vector<string>& data) = 0;
    virtual ~StrategieTri() {}
};

class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& data) {
        sort(data.begin(), data.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& data) {
        sort(data.rbegin(), data.rend());
    }
};

class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& data) {
        sort(data.begin(), data.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
    }
};

class GestionnaireTri {
private:
    StrategieTri* strategie;

public:
    GestionnaireTri(StrategieTri* s) : strategie(s) {}
    void setStrategie(StrategieTri* s) { strategie = s; }

    void trierDonnees(vector<string>& data) {
        if (strategie) strategie->trier(data);
    }
};

int main() {
    vector<string> mots = {"salma", "asma", "hind", "fouad"};

    TriCroissant croissant;
    TriDecroissant decroissant;
    TriParLongueur parLongueur;

    GestionnaireTri gestion(&croissant);
    gestion.trierDonnees(mots);
    for (auto& m : mots) cout << m << " ";
    cout << endl;

    gestion.setStrategie(&decroissant);
    gestion.trierDonnees(mots);
    for (auto& m : mots) cout << m << " ";
    cout << endl;

    gestion.setStrategie(&parLongueur);
    gestion.trierDonnees(mots);
    for (auto& m : mots) cout << m << " ";
    cout << endl;

    return 0;
}
