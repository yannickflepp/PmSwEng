#include <gtest/gtest.h>
//#include "../CalcApplication/BerechnungRL.cpp"
#include "../CalcApplication/BerechnungRL.h"

TEST(TestBerechnungRL, TestGetImpedanz)
{
  EXPECT_NEAR(BerechnungRL::getImpedanz(100, 50, 0.0001), 100.00000493,
              0.000001);
}
TEST(TestBerechnungRL, TestGetStrom)
{
  EXPECT_NEAR(
      BerechnungRL::getStrom(230, BerechnungRL::getImpedanz(100, 50, 0.0001)),
      2.29999989, 0.000001);
}
TEST(TestBerechnungRL, TestGetLeistung)
{
  EXPECT_NEAR(BerechnungRL::getLeistung(
                  100, BerechnungRL::getStrom(
                           230, BerechnungRL::getImpedanz(100, 50, 0.0001))),
              528.99994779, 0.000001);
}
TEST(TestBerechnungRL, TestGetBlindleistung)
{
  EXPECT_NEAR(BerechnungRL::getBlindLeistung(
                  50, 0.0001,
                  BerechnungRL::getStrom(
                      230, BerechnungRL::getImpedanz(100, 50, 0.0001))),
              0.16619023, 0.000001);
}
TEST(TestBerechnungRL, TestGetScheinleistung)
{
  EXPECT_NEAR(BerechnungRL::getScheinLeistung(
                  230, BerechnungRL::getStrom(
                           230, BerechnungRL::getImpedanz(100, 50, 0.0001))),
              528.99997389, 0.000001);
}
TEST(TestBerechnungRL, TestGetPhasenWinkel)
{
  EXPECT_NEAR(
      BerechnungRL::getPhasenWinkel(
          BerechnungRL::getLeistung(
              100, BerechnungRL::getStrom(
                       230, BerechnungRL::getImpedanz(100, 50, 0.0001))),
          BerechnungRL::getScheinLeistung(
              230, BerechnungRL::getStrom(
                       230, BerechnungRL::getImpedanz(100, 50, 0.0001)))),
      0.01799999, 0.000001);
}
