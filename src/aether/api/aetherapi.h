#pragma once

#include "../core/iscreen.h"
#include <aether/platform.h>

#define DLLEXPORT __declspec(dllexport)

int aether_run_app(int argc, char** argv);

std::shared_ptr<aether::core::Application> aether_create_app();
std::shared_ptr<aether::core::IScreen> aether_boot_screen(const aether::core::CommandLineArguments& args);

