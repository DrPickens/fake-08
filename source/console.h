#pragma once
#include <functional>

#include "cart.h"
#include "Input.h"

extern "C" {
  #include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
}

class Console {
    Cart* _loadedCart;
    Graphics* _graphics;
    lua_State* _luaState;
    Input* _input;

    uint8_t _targetFps;

    int _picoFrameCount;
    bool _hasUpdate;
    bool _hasDraw;

    public:
    Console();
    ~Console();

    void LoadCart(std::string filename);

    void UpdateAndDraw(
      uint64_t ticksSinceLastCall,
      std::function<void()> clearFbFunction,
      uint8_t kdown,
      uint8_t kheld,
      std::function<void(const char*)> profFunc);

    void FlipBuffer(
      uint8_t* fb,
      std::function<void()> postFlipFunction,
      std::function<void(const char*)> profFunc);

    void TurnOff();

    uint8_t GetTargetFps();

    int GetFrameCount();
};

