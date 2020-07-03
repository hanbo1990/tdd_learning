#include "Checkout.h"


Checkout::Checkout():total(0){

}

Checkout::~Checkout(){

}

void Checkout::addItemPrice(std::string name, int price){
    prices[name] = price;
}

void Checkout::addItem(std::string name){
    std::map<std::string, int>::iterator priceIter = prices.find(name);
    if(priceIter == prices.end()){
        throw std::invalid_argument("invalid item, no price");
    }

    items[name]++;
}

int Checkout::totalPrice(void){
    total = 0;

    for (std::map<std::string, int>::iterator itemIter = items.begin();
         itemIter != items.end(); itemIter++){
        std::string item = itemIter->first;
        int itemCnt = itemIter->second;
        calculateItem(item, itemCnt);
    }

    return total;
}

void Checkout::addDiscount(std::string name, int number, int discountPrice){
    Discount discount;
    discount.nrOfItems = number;
    discount.discountPrice = discountPrice;

    discounts[name] = discount;
}

void Checkout::calculateItem(std::string name, int itemCnt){
    std::map<std::string, Discount>::iterator discountIter;
    discountIter = discounts.find(name);
    if(discountIter != discounts.end()){
        Discount discount = discountIter->second;
        calculateDiscount(name, itemCnt, discount);
    }
    else{
        total += itemCnt * prices[name];
    }
}


void Checkout::calculateDiscount(std::string name, int itemCnt, Discount discount){
    if(itemCnt >= discount.nrOfItems){
        int nrOfDiscounts = itemCnt / discount.nrOfItems;
        total += nrOfDiscounts * discount.discountPrice;
        total += (itemCnt % discount.nrOfItems) * prices[name];
    }
    else{
        total += itemCnt * prices[name];
    }
}
