#include "aetherapi.h"
#include "../platform.h"
#include <iostream>
#include "../core/applicationbase.h"


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

int aether_run_app(int argc, char** argv)
{
	app = new Application(800, 600);
	auto retcode = app->initialize(argc, argv);
	if (retcode != 0) return retcode;
	app->setScreen(aether_boot_screen());
	app->run();
	app->deinitialize();
	return 0;
}

