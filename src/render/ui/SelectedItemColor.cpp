#include <gl/opengl.h>
#include <render/ui/RenderConstants.h>
#include <render/ui/SelectedItemColor.h>

void SelectedItemColor::SetColorForSelectedItem(bool isSelected)
{
    if (isSelected)
    {
        glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, _selectedItemAlpha.GetAbsValue());
    }
    else
    {
        glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    }
}

void SelectedItemColor::Update()
{
    _selectedItemAlpha.UpdateBy(0.05f);
}
