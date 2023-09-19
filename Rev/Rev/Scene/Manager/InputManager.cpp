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
                        { InputType::keyboard,KEY_INPUT_Z },
                        { InputType::gamepad,PAD_INPUT_A },
    };

    inputTable_["attack"] = {
                    { InputType::keyboard,KEY_INPUT_X },
                    { InputType::gamepad,PAD_INPUT_C },
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
            case InputType::gamepad:
                pressed = padInfo & InputInfo.inputID;
            case InputType::mouse:
                pressed = mouseInfo & InputInfo.inputID;
            default:
                break;
            }
        }

        if (pressed)//‚±ª‚±«‘åŽ–
        {
            break;
        }
        currentState[record.first] = pressed;
    }
}


bool InputManager::IsTriggered(const std::string& str) const
{

    auto it = inputTable_.find(str);
    if (it == inputTable_.end())
    {
        return false;
    }

    auto inputInfoes = it->second;

    for (const auto& info : inputInfoes)
    {

    }
    return false;
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


