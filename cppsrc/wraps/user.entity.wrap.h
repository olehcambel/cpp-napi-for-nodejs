#include <napi.h>
#include "../services/user.entity.h"

class UserEntityWrap: public Napi::ObjectWrap<UserEntityWrap> {
    public: static Napi::Object Init(Napi::Env env, Napi::Object exports);
    UserEntityWrap(const Napi::CallbackInfo &info);

    private: static Napi::FunctionReference constructor;

    Napi::Value GetCtx(const Napi::CallbackInfo &info);
    Napi::Value GetBalance(const Napi::CallbackInfo &info);
    Napi::Value AddBalance(const Napi::CallbackInfo &info);
    Napi::Value RemoveBalance(const Napi::CallbackInfo &info);

    Napi::Value GetAge(const Napi::CallbackInfo &info);
    Napi::Value AddAge(const Napi::CallbackInfo &info);

    UserEntity *_userEntity;
};
