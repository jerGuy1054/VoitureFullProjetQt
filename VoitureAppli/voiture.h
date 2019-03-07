#ifndef VOITURE_H
#define VOITURE_H

#include <QString>
#include <exception>
#include <QDebug>

class Voiture
{
public:
    Voiture();
    Voiture(QString modele);
    Voiture(QString modele, int kilometrage, int jaugeCarburant);

    virtual ~Voiture();
    QString modele() const;
    void setModele(const QString &modele);

    int kilometrage() const;
    void setKilometrage(int kilometrage);

    int jaugeCarburant() const;
    void setJaugeCarburant(int jaugeCarburant);

    bool rouler(int kilometre);

private:
    QString mModele; //le constructeur par défaut de la qstring est une chaine vide
    int mKilometrage; //le constructeur par défaut d'un type numérique est 0.
    int mJaugeCarburant; //On prefere utiliser des entiers, du coup on utilise par exemple les centilitress
};

#endif // VOITURE_H
