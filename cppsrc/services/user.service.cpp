#include "user.service.h"

std::string UserService::getFullname(std::string firstName, std::string lastName) {
    return firstName + " " + lastName;
}

int UserService::getUser() {
    const UserService::User user = {
        age: 10,
        firstName: "Oleh"
    };

    return user.age;
}

Napi::String UserService::getFullnameWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2 || !info[0].IsString() || !info[1].IsString()) {
        Napi::TypeError::New(env, "String expected__!").ThrowAsJavaScriptException();
    }

    Napi::String first = info[0].As<Napi::String>();
    Napi::String second = info[1].As<Napi::String>();

    std::string returnValue = UserService::getFullname(first.Utf8Value(), second);

    return Napi::String::New(env, returnValue);
}

Napi::Number UserService::GetUserWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Number returnValue = Napi::Number::New(env, UserService::getUser());

    return returnValue;
}

Napi::Object UserService::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("getUser", Napi::Function::New(env, UserService::GetUserWrapped));
    exports.Set("getFullname", Napi::Function::New(env, UserService::getFullnameWrapped));

    return exports;
}
