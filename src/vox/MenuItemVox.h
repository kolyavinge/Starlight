#pragma once

#include <lib/Object.h>
#include <audio/AudioSample.h>
#include <vox/SampleCollection.h>

template<class TMenuItem>
class MenuItemVox : public Object
{
    TMenuItem _lastSelectedItem;
    AudioSample* _selectMenuItem;

public:
    MenuItemVox(TMenuItem initValue)
    {
        _lastSelectedItem = initValue;
        _selectMenuItem = nullptr;
    }

    void Init(SampleCollection& sampleCollection)
    {
        _selectMenuItem = &sampleCollection.SelectMenuItem;
    }

    void Voice(TMenuItem currentSelectedItem)
    {
        if (_lastSelectedItem != currentSelectedItem)
        {
            _selectMenuItem->Play();
            _lastSelectedItem = currentSelectedItem;
        }
    }
};
