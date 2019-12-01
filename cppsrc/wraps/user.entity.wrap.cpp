#include "user.entity.wrap.h"

Napi::FunctionReference UserEntityWrap::constructor;

Napi::Object UserEntityWrap::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "User", {
        // InstanceMethod("getCtx", &UserEntityWrap::GetCtx),
        InstanceMethod("getBalance", &UserEntityWrap::GetBalance),
        InstanceMethod("addBalance", &UserEntityWrap::AddBalance),
        InstanceMethod("removeBalance", &UserEntityWrap::RemoveBalance),
        InstanceMethod("addAge", &UserEntityWrap::AddAge),
        InstanceMethod("addAge", &UserEntityWrap::AddAge),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("UserEntityWrap", func);
    return exports;
}

UserEntityWrap::UserEntityWrap(const Napi::CallbackInfo &info): Napi::ObjectWrap<UserEntityWrap>(info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();

    if (length != 2) {
        Napi::TypeError::New(env, "2 args expected__!").ThrowAsJavaScriptException();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "String expected__!").ThrowAsJavaScriptException();
    }

    if (!info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected__!").ThrowAsJavaScriptException();
    }

    Napi::String username = info[0].As<Napi::String>();

    Napi::Number balance = info[1].As<Napi::Number>();
    this->_userEntity = new UserEntity(username, balance.DoubleValue());
}

Napi::Value UserEntityWrap::GetAge(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int num = this->_userEntity->getAge();
    return Napi::Number::New(env, num);
}

Napi::Value UserEntityWrap::AddAge(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();

    if (length != 1) {
        Napi::TypeError::New(env, "1 arg expected__!").ThrowAsJavaScriptException();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Number expected__!").ThrowAsJavaScriptException();
    }

    Napi::Number toAdd = info[0].As<Napi::Number>();

    int result = this->_userEntity->addAge(toAdd);
    return Napi::Number::New(env, result);
}

Napi::Value UserEntityWrap::AddBalance(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();

    if (length != 1) {
        Napi::TypeError::New(env, "1 arg expected__!").ThrowAsJavaScriptException();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Number expected__!").ThrowAsJavaScriptException();
    }

    Napi::Number toAdd = info[0].As<Napi::Number>();

    double result = this->_userEntity->addBalance(toAdd.DoubleValue());
    return Napi::Number::New(env, result);
}

Napi::Value UserEntityWrap::RemoveBalance(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();

    if (length != 1) {
        Napi::TypeError::New(env, "1 arg expected__!").ThrowAsJavaScriptException();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Number expected__!").ThrowAsJavaScriptException();
    }

    Napi::Number toRemove = info[0].As<Napi::Number>();

    double result = this->_userEntity->removeBalance(toRemove.DoubleValue());
    return Napi::Number::New(env, result);
}

Napi::Value UserEntityWrap::GetBalance(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    double num = this->_userEntity->getBalance();
    return Napi::Number::New(env, num);
}

// Napi::Value UserEntityWrap::GetCtx(const Napi::CallbackInfo &info) {
//     Napi::Env env = info.Env();
//     Napi::HandleScope scope(env);

//     // TODO: how to return Object?
//     Ctx ctx = this->_userEntity->getCtx();

//     // return Napi::Object::New(env).From(env, ctx);
// }
// Napi::ObjectWrap<Ctx>