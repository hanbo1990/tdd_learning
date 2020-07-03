#include <iostream>
#include <gtest/gtest.h>

#include "Checkout.h"

using namespace std;

class CheckoutTests : public ::testing::Test {
public:

protected:
    Checkout checkOut;
};


TEST_F(CheckoutTests, CanReturnCurrentTotal){
    checkOut.addItemPrice("a", 1);
    checkOut.addItem("a");

    int totalPrice = checkOut.totalPrice();

    ASSERT_EQ(1, totalPrice);
}

TEST_F(CheckoutTests, CanAddMultipleAndGetTotal){
    checkOut.addItemPrice("a", 1);
    checkOut.addItemPrice("b", 2);
    checkOut.addItem("a");
    checkOut.addItem("b");

    int totalPrice = checkOut.totalPrice();

    ASSERT_EQ(3, totalPrice);
}

TEST_F(CheckoutTests, CanAddDiscount){
    checkOut.addDiscount("a", 3, 2);
}

TEST_F(CheckoutTests, CanCalTotalByDiscount){
    checkOut.addItemPrice("a", 1);
    checkOut.addDiscount("a", 3, 2);
    checkOut.addItem("a");
    checkOut.addItem("a");
    checkOut.addItem("a");

    int totalPrice = checkOut.totalPrice();

    ASSERT_EQ(2, totalPrice);
}

TEST_F(CheckoutTests, ItemWithoutPriceThrowsException){
    ASSERT_THROW(checkOut.addItem("a"), std::invalid_argument);
}