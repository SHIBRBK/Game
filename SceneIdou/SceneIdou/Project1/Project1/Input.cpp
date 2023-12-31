#include "Input.h"
#include<DxLib.h>
#include<cassert>

Input::Input()
{
    //左辺がゲームの命令(文字列)
    inputTable_["next"] = {
                            { InputType::keyboard,KEY_INPUT_RETURN },
                            { InputType::gamepad,PAD_INPUT_R },
                            { InputType::mouse,MOUSE_INPUT_LEFT }
                          };

    inputTable_["pause"] = {
                            { InputType::keyboard,KEY_INPUT_P },
                            { InputType::gamepad,PAD_INPUT_L },
                           };

    inputTable_["jump"] = {
                        { InputType::keyboard,KEY_INPUT_Z },
                        { InputType::gamepad,PAD_INPUT_A },
    };

    inputTable_["attack"] = {
                    { InputType::keyboard,KEY_INPUT_X },
                    { InputType::gamepad,PAD_INPUT_C },
    };

    inputTable_["keyconfig"] = {
                { InputType::keyboard,KEY_INPUT_K },
    };

    inputTable_["up"] = {
                    { InputType::keyboard,KEY_INPUT_UP },
                    { InputType::gamepad,PAD_INPUT_UP },
    };

    inputTable_["down"] = {
                    { InputType::keyboard,KEY_INPUT_DOWN },
                    { InputType::gamepad,PAD_INPUT_DOWN },
    };

    inputTable_["left"] = {
                    { InputType::keyboard,KEY_INPUT_LEFT },
                    { InputType::gamepad,PAD_INPUT_LEFT },
    };

    inputTable_["right"] = {
                    { InputType::keyboard,KEY_INPUT_RIGHT },
                    { InputType::gamepad,PAD_INPUT_RIGHT },
    };

    currentState.clear();
    for (const auto& record : inputTable_)
    {
        currentState[record.first] = false;
    }
}

void Input::Update()
{
    char keycode[256];
    GetHitKeyStateAll(keycode);
    int padInfo = GetJoypadInputState(DX_INPUT_PAD1);
    int mouseInfo = GetMouseInput();

    lastState = currentState;

    //すべての登録済みの入力をチェックする。
    for (const auto& record : inputTable_)
    {
        bool pressed = false;
        for (const auto& InputInfo : record.second)
        {
            switch (InputInfo.type)
            {
            case InputType::keyboard:
                pressed = keycode[InputInfo.inputID];
                break;
            case InputType::gamepad:
                pressed = padInfo & InputInfo.inputID;
                break;
            case InputType::mouse:
                pressed = mouseInfo & InputInfo.inputID;
                break;
            }

            if (pressed)//こ↑こ↓大事
             {
                 break;
             }
         }
        currentState[record.first] = pressed;
    }
}


bool Input::IsTriggered(const std::string& str) const
{
    return !GetLastInput(str) && GetCurrentInput(str);
}

bool Input::IsPressed(const std::string& str) const
{
    
    return !GetLastInput(str)&&GetCurrentInput(str);
}

void Input::RewriteInput(const std::string& key, const InputInfo& inputInfo)
{
    auto it = inputTable_.find(key);

    if (it == inputTable_.end())
    {
        assert(0 && "そんな命令登録されてません。バーカバーカwwww");
        return;
    }
    
    //
    for (auto& record : it->second)
    {
        if (inputInfo.type == record.type)
        {
            record.inputID = inputInfo.inputID;
            return;
        }
    }
    //新規登録
    it->second.push_back(inputInfo);
}

const InputTable_t&
Input::GetInputTable() const
{
    return inputTable_;
}

bool Input::GetCurrentInput(const std::string& Input) const
{
    auto it = currentState.find(Input);
    if (it == currentState.end())
    {
        return false;
    }
    return it->second;
}

bool Input::GetLastInput(const std::string& Input) const
{
    auto it = lastState.find(Input);
    if (it == lastState.end())
    {
        return false;
    }
    return it->second;
}


