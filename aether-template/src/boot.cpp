#include <aether/aether.h>
#include <aether/platform.h>

#include "constants.h"
#include "screen/MainMenuScreen.h"

std::shared_ptr<aether::core::Application> aether_create_app()
{
	return std::make_shared<aether::core::Application>(Constants::WindowWidth, Constants::WindowHeight);
}

std::shared_ptr<aether::core::IScreen> aether_boot_screen()
{
	Assets::Initialize();
	return std::make_shared<MainMenuScreen>();
}
