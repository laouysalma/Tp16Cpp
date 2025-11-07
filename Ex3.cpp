#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Observateur {
public:
    virtual void mettreAJour(float temp, float humidite, float pression) = 0;
    virtual ~Observateur() {}
};

class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;
    vector<Observateur*> observateurs;

public:
    void ajouterObservateur(Observateur* obs) {
        observateurs.push_back(obs);
    }

    void supprimerObservateur(Observateur* obs) {
        for (size_t i = 0; i < observateurs.size(); i++) {
            if (observateurs[i] == obs) {
                observateurs.erase(observateurs.begin() + i);
                break;
            }
        }
    }

    void notifier() {
        for (auto obs : observateurs) {
            obs->mettreAJour(temperature, humidite, pression);
        }
    }

    void setDonnees(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        notifier();
    }
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float temp, float, float) {
        cout << "Température: " << temp << " °C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float, float humidite, float) {
        cout << "Humidité: " << humidite << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float, float, float pression) {
        cout << "Pression: " << pression << " hPa" << endl;
    }
};

int main() {
    StationMeteo station;

    AffichageTemperature temp;
    AffichageHumidite hum;
    AffichagePression pres;

    station.ajouterObservateur(&temp);
    station.ajouterObservateur(&hum);
    station.ajouterObservateur(&pres);

    station.setDonnees(2.5, 67.0, 1011.2);
    station.setDonnees(30.0, 13.0, 1010.8);

    return 0;
}
