#pragma once

#include <lib/Object.h>
#include <audio/AudioSample.h>
#include <vox/common/AudioDataCollection.h>

template<class TMenuItem>
class MenuItemVox : public Object
{
    TMenuItem _lastSelectedItem;
    AudioSample _selectMenuItemSample;

public:
    MenuItemVox(TMenuItem initValue, AudioDataCollection& audioDataCollection) :
        _selectMenuItemSample(audioDataCollection.SelectMenuItemData)
    {
        _lastSelectedItem = initValue;
    }

    void Init(AudioDataCollection& audioDataCollection)
    {
        _selectMenuItemSample = &audioDataCollection.SelectMenuItemData;
    }

    void Voice(TMenuItem currentSelectedItem)
    {
        if (_lastSelectedItem != currentSelectedItem)
        {
            _selectMenuItemSample.Play();
            _lastSelectedItem = currentSelectedItem;
        }
    }
};
