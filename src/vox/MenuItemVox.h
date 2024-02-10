#pragma once

#include <lib/Object.h>
#include <audio/AudioSample.h>
#include <vox/SampleCollection.h>

template<class TMenuItem>
class MenuItemVox : public Object
{
    TMenuItem _lastSelectedItem;
    AudioSample* _selectMenuItemSample;

public:
    MenuItemVox(TMenuItem initValue)
    {
        _lastSelectedItem = initValue;
        _selectMenuItemSample = nullptr;
    }

    void Init(SampleCollection& sampleCollection)
    {
        _selectMenuItemSample = &sampleCollection.SelectMenuItemSample;
    }

    void Voice(TMenuItem currentSelectedItem)
    {
        if (_lastSelectedItem != currentSelectedItem)
        {
            _selectMenuItemSample->Play();
            _lastSelectedItem = currentSelectedItem;
        }
    }
};
