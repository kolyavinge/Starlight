#pragma once

#include <lib/String.h>

class GraphicResources
{
public:
    static String GetBackgroundTextureFilePath();
    static String GetShipMeshFilePath();
    static String GetStartGameMenuItemFilePath();
    static String GetExitMenuItemFilePath();
    static String GetSelectTrackMenuItemFilePath();
    static String GetRaceMenuItemFilePath();
    static String GetBackMenuItemFilePath();
    static String GetPauseItemFilePath();
    static String GetResumeMenuItemFilePath();
    static String GetStartMenuMenuItemFilePath();

    static String GetAlphabetFilePath();

    static String GetCountdown1ItemFilePath();
    static String GetCountdown2ItemFilePath();
    static String GetCountdown3ItemFilePath();
    static String GetGOItemFilePath();
};
