#include "aetherapi.h"
#include "../platform.h"
#include <iostream>
#include "../core/applicationbase.h"


using namespace aether::core;

static std::shared_ptr<ApplicationBase> app = nullptr;

int aether_run_app(int argc, char** argv)
{
	app = aether_create_app();
	CommandLineArguments args(argc, argv);
	auto retcode = app->Initialize(args);
	if (retcode != 0) return retcode;
	app->SetScreen(aether_boot_screen(args));
	app->Run();
	app->Deinitialize();
	return 0;
}

