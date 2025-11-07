#include <iostream>
#include <string>
using namespace std;

class Forme {
public:
    virtual void afficher() = 0;
    virtual ~Forme() {}
};

class Cercle : public Forme {
public:
    void afficher() {
        cout << "C'est un  Cercle" << endl;
    }
};

class Carre : public Forme {
public:
    void afficher() {
        cout << "C'est un Carré" << endl;
    }
};

class Triangle : public Forme {
public:
    void afficher() {
        cout << "C'est un Triangle" << endl;
    }
};

class FabriqueForme {
public:
    static Forme* creerForme(const string& type) {
        if (type == "Cercle") return new Cercle();
        if (type == "Carre") return new Carre();
        if (type == "Triangle") return new Triangle();
        return nullptr;
    }
};

int main() {
    Forme* f1 = FabriqueForme::creerForme("Cercle");
    Forme* f2 = FabriqueForme::creerForme("Carre");
    Forme* f3 = FabriqueForme::creerForme("Triangle");

    if(f1) f1->afficher();
    if(f2) f2->afficher();
    if(f3) f3->afficher();

    delete f1;
    delete f2;
    delete f3;

    return 0;
}
