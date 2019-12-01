#include <string>
#include "user.entity.h"

UserEntity::UserEntity(std::string username, int age) {
    this->_username = username;
    this->_age = age;
    this->_balance = 0;
}

Ctx UserEntity::getCtx() {
    Ctx ctx;
    ctx.age = this->_age;
    ctx.balance = this->_balance;
    ctx.id = 1;
    // std::string result = "User: " + this->_username + "\nage: " + this->_age + "\nbalance: " + this->_balance;
    return ctx;

    // const UserService::User user = {
    //     age: 10,
    //     firstName: "Oleh"
    // };
};


double UserEntity::getBalance() {
    return this->_balance;
}

double UserEntity::addBalance(double price) {
    this->_balance += price;
    return this->_balance;
}

double UserEntity::removeBalance(double price) {
    this->_balance -= price;
    return this->_balance;
}

int UserEntity::getAge() {
    return this->_age;
}

int UserEntity::addAge(int age) {
    this->_age += age;
    return this->_age;
}
