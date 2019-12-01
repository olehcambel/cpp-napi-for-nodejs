#include <napi.h>
#include "services/user.service.h"
#include "wraps/user.entity.wrap.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    UserService::Init(env, exports);
    return UserEntityWrap::Init(env, exports);
    // return (env, exports);
}

NODE_API_MODULE(napiMedium, InitAll)
