#ifndef CHECKOUT_H_
#define CHECKOUT_H_

#include <string>
#include <map>

class Checkout{
public:
    Checkout();
    virtual ~Checkout();

    void addItemPrice(std::string name, int price);
    void addItem(std::string name);
    int totalPrice(void);
    void addDiscount(std::string name, int number, int discountPrice);

protected:
    struct Discount{
        int nrOfItems;
        int discountPrice;
    };

    std::map<std::string, int> prices;
    std::map<std::string, Discount> discounts;
    std::map<std::string, int> items;
    int total;

    void calculateItem(std::string name, int itemCnt);
    void calculateDiscount(std::string name, int itemCnt, Discount discount);
};

#endif