
#include "screen/MainMenuScreen.h"


MainMenuScreen::MainMenuScreen()
{

}

int MainMenuScreen::Load()
{
	return 0;
}

void MainMenuScreen::Update(uint64_t delta)
{
	if (aether::core::is_key_down(aether::core::KeyCode::Escape))
	{
		RequestCloseApp();
	}
}

void MainMenuScreen::Render()
{
	aether::graphics::clear(1.f, 0.f, 1.f);
}

int MainMenuScreen::Unload()
{
	return 0;
}


