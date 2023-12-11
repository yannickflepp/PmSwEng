#include <gtest/gtest.h>
#include "../CalcApplication/BerechnungRC.cpp"
#include "../CalcApplication/BerechnungRC.h"

TEST(TestBerechnungRC, TestGetImpedanz)
{
  EXPECT_NEAR(BerechnungRC::getImpedanz(100, 50, 0.0001), 104.94385087476,
              0.000001);
}
TEST(TestBerechnungRC, TestGetStrom)
{
  EXPECT_NEAR(
      BerechnungRC::getStrom(230, BerechnungRC::getImpedanz(100, 50, 0.0001)),
      2.19164818, 0.000001);
}
TEST(TestBerechnungRC, TestGetLeistung)
{
  EXPECT_NEAR(BerechnungRC::getLeistung(
                  100, BerechnungRC::getStrom(
                           230, BerechnungRC::getImpedanz(100, 50, 0.0001))),
              480.33217544, 0.000001);
}
TEST(TestBerechnungRC, TestGetBlindleistung)
{
  EXPECT_NEAR(BerechnungRC::getBlindLeistung(
                  50, 0.0001,
                  BerechnungRC::getStrom(
                      230, BerechnungRC::getImpedanz(100, 50, 0.0001))),
              152.89448009, 0.000001);
}
TEST(TestBerechnungRC, TestGetScheinleistung)
{
  EXPECT_NEAR(BerechnungRC::getScheinLeistung(
                  230, BerechnungRC::getStrom(
                           230, BerechnungRC::getImpedanz(100, 50, 0.0001))),
              504.07908190, 0.000001);
}
TEST(TestBerechnungRC, TestGetPhasenWinkel)
{
  EXPECT_NEAR(
      BerechnungRC::getPhasenWinkel(
          BerechnungRC::getLeistung(
              100, BerechnungRC::getStrom(
                       230, BerechnungRC::getImpedanz(100, 50, 0.0001))),
          BerechnungRC::getScheinLeistung(
              230, BerechnungRC::getStrom(
                       230, BerechnungRC::getImpedanz(100, 50, 0.0001)))),
      17.65678715, 0.000001);
}
