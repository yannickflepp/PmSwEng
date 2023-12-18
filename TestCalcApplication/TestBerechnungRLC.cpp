#include <gtest/gtest.h>
//#include "../CalcApplication/BerechnungRLC.cpp"
#include "../CalcApplication/BerechnungRLC.h"

TEST(TestBerechnungRLC, TestGetBlindwiderstand)
{
  EXPECT_NEAR(BerechnungRLC::getBlindwiderstand(50, 0.0001, 0.0001),
              31.79957269, 0.000001);
}

TEST(TestBerechnungRLC, TestGetImpedanz)
{
  EXPECT_NEAR(BerechnungRLC::getImpedanz(
                  100, BerechnungRLC::getBlindwiderstand(50, 0.0001, 0.0001)),
              104.93432623, 0.000001);
}

TEST(TestBerechnungRLC, TestGetStrom)
{
  EXPECT_NEAR(
      BerechnungRLC::getStrom(
          230, BerechnungRLC::getImpedanz(
                   100, BerechnungRLC::getBlindwiderstand(50, 0.0001, 0.0001))),
      2.19184711, 0.000001);
}

TEST(TestBerechnungRLC, TestGetLeistung)
{
  EXPECT_NEAR(BerechnungRLC::getLeistung(
                  100, BerechnungRLC::getStrom(
                           230, BerechnungRLC::getImpedanz(
                                    100, BerechnungRLC::getBlindwiderstand(
                                             50, 0.0001, 0.0001)))),
              480.41937658, 0.000001);
}

TEST(TestBerechnungRLC, TestGetBlindleistung)
{
  EXPECT_NEAR(BerechnungRLC::getBlindLeistung(
                  BerechnungRLC::getBlindwiderstand(50, 0.0001, 0.0001),
                  BerechnungRLC::getStrom(
                      230, BerechnungRLC::getImpedanz(
                               100, BerechnungRLC::getBlindwiderstand(
                                        50, 0.0001, 0.0001)))),
              152.77130888, 0.000001);
}
TEST(TestBerechnungRLC, TestGetScheinleistung)
{
  EXPECT_NEAR(BerechnungRLC::getScheinLeistung(
                  230, BerechnungRLC::getStrom(
                           230, BerechnungRLC::getImpedanz(
                                    100, BerechnungRLC::getBlindwiderstand(
                                             50, 0.0001, 0.0001)))),
              504.12483593, 0.000001);
}
TEST(TestBerechnungRLC, TestGetPhasenWinkel)
{
  EXPECT_NEAR(BerechnungRLC::getPhasenWinkel(
                  BerechnungRLC::getLeistung(
                      100, BerechnungRLC::getStrom(
                               230, BerechnungRLC::getImpedanz(
                                        100, BerechnungRLC::getBlindwiderstand(
                                                 50, 0.0001, 0.0001)))),
                  BerechnungRLC::getScheinLeistung(
                      230, BerechnungRLC::getStrom(
                               230, BerechnungRLC::getImpedanz(
                                        100, BerechnungRLC::getBlindwiderstand(
                                                 50, 0.0001, 0.0001))))),
              17.64044166, 0.000001);
}
