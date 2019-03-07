#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "voiture.h"

using namespace testing;

TEST(TestVoitureConstructor, Default) //on change defautlt par intermédiaire, complet, ... en fonciton du constructeur que l'on veut tester.
{
    Voiture voiture;
    EXPECT_EQ(voiture.modele(), "");
    EXPECT_EQ(voiture.kilometrage(), 0);
    EXPECT_EQ(voiture.jaugeCarburant(), 0);
    //ASSERT_THAT(0, Eq(0));
}

TEST(TestVoitureConstructor, Complet) //on change defautlt par intermédiaire, complet, ... en fonciton du constructeur que l'on veut tester.
{
    QString modele = "Ferrari F40";
    int km = 20000;
    int jauge = 5000;
    Voiture voiture(modele, km, jauge);
    EXPECT_EQ(voiture.modele(), modele);  // basé sur ==
    EXPECT_EQ(voiture.kilometrage(), km);
    EXPECT_EQ(voiture.jaugeCarburant(), jauge);
    //ASSERT_THAT(0, Eq(0));
}


