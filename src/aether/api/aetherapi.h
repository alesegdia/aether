#pragma once

#include "../core/iscreen.h"
#include <aether/platform.h>

#define DLLEXPORT __declspec(dllexport)

extern "C" {int DLLEXPORT janio(); }

int aether_run_app(int argc, char** argv);
std::shared_ptr<aether::core::IScreen> aether_boot_screen();
