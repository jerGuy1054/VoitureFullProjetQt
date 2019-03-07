#include "voiture.h"

Voiture::Voiture():Voiture("", 0, 0)
{

}

Voiture::Voiture(QString modele) :Voiture(modele, 0, 0)
{

}

Voiture::Voiture(QString modele, int kilometrage, int jaugeCarburant):
    mModele(modele), mKilometrage(kilometrage), mJaugeCarburant(jaugeCarburant)
{

}

Voiture::~Voiture()
{

}

QString Voiture::modele() const
{
    return mModele;
}

void Voiture::setModele(const QString &modele)
{
    mModele = modele;
}

int Voiture::kilometrage() const
{
    return mKilometrage;
}

void Voiture::setKilometrage(int kilometrage)
{
    mKilometrage = kilometrage;
}

int Voiture::jaugeCarburant() const
{
    return mJaugeCarburant;
}

void Voiture::setJaugeCarburant(int jaugeCarburant)
{
    mJaugeCarburant = jaugeCarburant;
}

bool Voiture::rouler(int distance)
{
    int conso = (mKilometrage < 150000) ? distance * 5 : distance * 10;
    if (mJaugeCarburant < conso)
        throw std::invalid_argument("Pas assez d'essence");
    mKilometrage +=distance;
    mJaugeCarburant -=distance*10;
}
