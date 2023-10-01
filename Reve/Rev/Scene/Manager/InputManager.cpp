#include "InputManager.h"
#include<DxLib.h>
#include<cassert>

InputManager::InputManager()
{
    //¶•Ó‚ªƒQ[ƒ€‚Ì–½—ß(•¶Žš—ñ)
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
                        { InputType::keyboard,KEY_INPUT_SPACE },
                        { InputType::gamepad,PAD_INPUT_A },
    };

    inputTable_["attack"] = {
                    { InputType::mouse,MOUSE_INPUT_LEFT },
                    { InputType::gamepad,PAD_INPUT_C },
    };

    inputTable_["keyconfig"] = {
                { InputType::keyboard,KEY_INPUT_K },
    };

    inputTable_["up"] = {
                    { InputType::keyboard,KEY_INPUT_W },
                    { InputType::gamepad,PAD_INPUT_UP },
    };

    inputTable_["down"] = {
                    { InputType::keyboard,KEY_INPUT_S },
                    { InputType::gamepad,PAD_INPUT_DOWN },
    };

    inputTable_["left"] = {
                    { InputType::keyboard,KEY_INPUT_A },
                    { InputType::gamepad,PAD_INPUT_LEFT },
    };

    inputTable_["right"] = {
                    { InputType::keyboard,KEY_INPUT_D },
                    { InputType::gamepad,PAD_INPUT_RIGHT },
    };

    currentState.clear();
    for (const auto& record : inputTable_)
    {
        currentState[record.first] = false;
    }
}

void InputManager::Update()
{
    char keycode[256];
    GetHitKeyStateAll(keycode);
    int padInfo = GetJoypadInputState(DX_INPUT_PAD1);
    int mouseInfo = GetMouseInput();

    lastState = currentState;

    //‚·‚×‚Ä‚Ì“o˜^Ï‚Ý‚Ì“ü—Í‚ðƒ`ƒFƒbƒN‚·‚éB
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
            if (pressed)//‚±ª‚±«‘åŽ–
            {
              break;
            }
         }
        currentState[record.first] = pressed;
    }
}


bool InputManager::IsTriggered(const std::string& str) const
{
    return !GetLastInput(str) && GetCurrentInput(str);
}

bool InputManager::IsPressed(const std::string& str) const
{

    return !GetLastInput(str) && GetCurrentInput(str);
}

void InputManager::RewriteInput(const std::string& key, const InputInfo& inputInfo)
{
    auto it = inputTable_.find(key);

    if (it == inputTable_.end())
    {
        assert(0 && "‚»‚ñ‚È–½—ß“o˜^‚³‚ê‚Ä‚Ü‚¹‚ñ");
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
    //V‹K“o˜^
    it->second.push_back(inputInfo);
}

const InputTable_t&
InputManager::GetInputTable() const
{
    return inputTable_;
}

bool InputManager::GetCurrentInput(const std::string& Input) const
{
    auto it = currentState.find(Input);
    if (it == currentState.end())
    {
        return false;
    }
    return it->second;
}

bool InputManager::GetLastInput(const std::string& Input) const
{
    auto it = lastState.find(Input);
    if (it == lastState.end())
    {
        return false;
    }
    return it->second;
}


