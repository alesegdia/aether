#include "aetherapi.h"
#include "../platform.h"
#include <iostream>

int DLLEXPORT janio()
{
/*
	aether_init_app(800, 600);
	while (true) {
		aether_step_app();
	}
	return phackmanGame->exec(0, nullptr);
*/
	std::cout << "meh" << std::endl;
	return -4;
}


using namespace aether::core;

static ApplicationBase* app = nullptr;

// Intended to be set from the game itself
void aether_init_app(int width, int height)
{
	assert(app == nullptr);
	app = new Application(width, height);
	assert(app != nullptr);
}

void aether_step_app()
{
	assert(app != nullptr);
	app->step();
}

bool aether_running_app()
{
	//app->
	return false;
}

int aether_run_app(int argc, char** argv)
{
	assert(app != nullptr);
	return app->exec(argc, argv);
}

void aether_boot_app()
{
	app = aether_create_app(800, 600);
}

