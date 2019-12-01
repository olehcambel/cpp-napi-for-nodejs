struct Ctx {
    int id;
    std::string username;
    int age;
    double balance;
};

class UserEntity {
    public:
        UserEntity(std::string username, int age);

    private:
        double _balance;
        std::string _username;

    public:
        Ctx getCtx();
        double getBalance();
        double addBalance(double price);
        double removeBalance(double price);

        int getAge();
        int addAge(int toAdd);

    private:
        int _age;
};
