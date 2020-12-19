#pragma once

#include "../core/applicationbase.h"

#define DLLEXPORT __declspec(dllexport)

extern "C" {int DLLEXPORT janio(); }

aether::core::ApplicationBase* aether_create_app(int width, int height);

int aether_run_app(int argc, char** argv);
void aether_boot_app();
