#include <raylib.h>

#include <stdio.h>

#include "../texture.h"
#include "../../core/handledresourcemanager.h"

namespace aether {
namespace graphics {

core::HandledResourceManager<Texture2D> texture_manager;

void Texture::Load(const char *path)
{
    assert(IsNotValid());
    Texture2D bitmap = LoadTexture(path);
    SetHandle(texture_manager.createNewHandle(bitmap));
}

static Texture2D fetch(int handle)
{
    Texture2D texture = texture_manager.fetchPresentHandle(handle);
    return texture;
}

int Texture::GetWidth() const
{
    return fetch(GetHandle()).width;
}

int Texture::GetHeight() const
{
	return fetch(GetHandle()).height;
}

void Texture::Destroy()
{
    UnloadTexture(fetch(GetHandle()));
    Invalidate();
}

void Texture::Draw(
	float x, float y,
    float rx, float ry,
    float rw, float rh,
    aether::graphics::Color color,
    bool xflip, bool yflip,
    float centerx, float centery,
    float angle,
    float xscale, float yscale) const
{
    if(xflip)
    {
        xscale *= -1;
    }
	DrawTextureTiled(
		fetch(GetHandle()),
        { rx, ry, rw, rh },
		{ x, y, rw, rh },
		{ centerx, centery }, angle, xscale, { color.r, color.g, color.b });
}


void Texture::Draw(float x, float y) const
{
    DrawTexture(fetch(GetHandle()), x, y, {255,255,255,255});
}

/*
void Texture::draw(float x, float y, float alpha)
{
    al_draw_tinted_bitmap(fetch(handle()), al_map_rgba_f(alpha, alpha, alpha, alpha), x, y, 0);
}
*/

void Texture::DrawScaledCentered(float x, float y,
    float rx, float ry, float rw, float rh,
    aether::graphics::Color color,
    bool xflip, bool yflip,
    float centerx, float centery, float angle, float xscale, float yscale) const
{

}


}
}
