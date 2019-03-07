#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "voiture.h"

using namespace testing;

//TEST(TestVoitureRouler, OldCar)
//{
//    //given : an old car
//    QString modele = "Ferrari F40";
//    int km = 150000;
//    int jauge = 2000;
//    int distance = 100;
//    Voiture voiture("modele", km, jauge);

//    //when
//    voiture.rouler(distance);
//    //then
//    EXPECT_EQ(voiture.kilometrage(), km + distance) << "Kilomerage incorrect";
//    EXPECT_EQ(voiture.jaugeCarburant(), jauge - distance * 10) << "Jauge carburant incorrect";
//}

class TestOldVoitureRouler: public Test {
protected: //je veux que personne ne vienne trifouiller la dedand.
    //Les fonctions protected sont accessibles aux classes filles.
    int kmStart;
    int jaugeStart;
    Voiture oldCar;

    void SetUp() override {  // Ce que l'on fait en début de test.
        kmStart = 160000;
        jaugeStart = 1500;
        oldCar.setKilometrage(kmStart);
        oldCar.setJaugeCarburant(jaugeStart);
        oldCar.setModele("Ford Mustang 1967"); //just for fun
    }
    void TearDown() override {  // Effectué à la fin de chaque test. A faire si on fait de l'allocation dynamique.
        qDebug() << "Do some cleaning";
    }
};

TEST_F(TestOldVoitureRouler, OK) //le nom du test doit être le même que celui de la classe mère.
{
    //given : a
    int distance = 100;
    //when
    oldCar.rouler(distance);
    //then
    EXPECT_EQ(oldCar.kilometrage(), kmStart + distance) << "Kilomerage incorrect";
    EXPECT_EQ(oldCar.jaugeCarburant(), jaugeStart - distance * 10) << "Jauge carburant incorrect";
}

TEST_F (TestOldVoitureRouler, PasAssezEssence)
{
    int distance = 500;
    //when
    //voiture.rouler(distance); //on ne doit pas appeler la fonction car elle va échouer (de manière contrôlée)
    //then
    //EXPECT_THAT(jauge, Ge(distance * 5))
    EXPECT_THROW(oldCar.rouler(distance), std::invalid_argument);
    EXPECT_THAT(oldCar.kilometrage(), Eq(kmStart));
    EXPECT_THAT(oldCar.jaugeCarburant(), Eq(jaugeStart));
}

TEST(TestVoitureRouler, NewCar)
{
    //given : an recent car
    QString modele = "Ferrari F40";
    int km = 10200;
    int jauge = 1500;
    int distance = 100;
    
    Voiture voiture("modele", km, jauge);
    //when
    voiture.rouler(distance);
    //then
    EXPECT_THAT(voiture.kilometrage(), Eq(km + distance))
            << "Kilomerage incorrect";
    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jauge - distance * 10))
            << "Jauge carburant incorrect";
}

class TestVoiturerRecentRouler: public TestWithParam<int> {

};

TEST_P(TestVoiturerRecentRouler, Range)
{
    //given : an recent car
    QString modele = "Ferrari F40";
    int km = GetParam();
    int jauge = 500;
    int distance = 100;

    Voiture voiture("modele", km, jauge);
    //when
    voiture.rouler(distance);
    //then
    EXPECT_THAT(voiture.kilometrage(), Eq(km + distance))
            << "Kilomerage incorrect";
    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jauge - distance * 10))
            << "Jauge carburant incorrect";
}

INSTANTIATE_TEST_SUITE_P(GroupeVoitureRecent,
                         TestVoiturerRecentRouler,
                         //Values(0, 10000, 14999, 150000, 150001));
                         Range (0, 150000, 10000));

TEST (TestVoitureRouler, PasAssezEssence)
{
    //given : an recent car & une trop grande distance
    QString modele = "Ferrari F40";
    int km = 15200;
    int jauge = 2000;
    int distance = 1000;
    
    Voiture voiture("modele", km, jauge);
    
    //when
    //voiture.rouler(distance); //on ne doit pas appeler la fonction car elle va échouer (de manière contrôlée)
    
    //then
    //EXPECT_THAT(jauge, Ge(distance * 5))
    EXPECT_THROW(voiture.rouler(distance), std::invalid_argument);
    
}
