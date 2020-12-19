#include <aether/api/aetherapi.h>

int main(int argc, char** argv) {
	aether_boot_app();
	return aether_run_app(argc, argv);
}

