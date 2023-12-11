#include <gtest/gtest.h>
#include "../CalcApplication/BerechnungRC.cpp"
#include "../CalcApplication/BerechnungRC.h"

TEST(TestBerechnungRC, TestBerechnungRC_testDefaultCtor_Test)
{
  ASSERT_EQ((BerechnungRC::getImpedanz(100, 50, 0.0001)), 104.94385087476);
  ASSERT_EQ(1, 1.2);
}
