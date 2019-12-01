#include <napi.h>

namespace UserService {
    struct User {
        int age;
        std::string firstName;
    };

    std::string getFullname(std::string firstName, std::string lastName);
    Napi::String getFullnameWrapped(const Napi::CallbackInfo& info);

    int getUser();
    Napi::Number GetUserWrapped(const Napi::CallbackInfo& info);

    Napi::Object Init(Napi::Env env, Napi::Object exports);
}
