#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <string>

#include "vm.h"
#include "logger.h"
#include "host.h"
#include "hostVmShared.h"



int main(int argc, char* argv[])
{
	Logger::Initialize();

	Host *host = new Host();
	host->oneTimeSetup();

	Vm *vm = new Vm();
	Logger::Write("initialized Vm and host\n");

	Logger::Write("Setting cart list on vm\n");
	vm->SetCartList(host->listcarts());

	Logger::Write("Loading Bios cart\n");
	vm->LoadBiosCart();
	Logger::Write("Bios Cart Loaded\n");

	// Main loop
	Logger::Write("Starting main loop\n");

	while (host->mainLoop())
	{
		int targetFps = vm->GetTargetFps();
		host->setTargetFps(targetFps);

		host->waitForTargetFps();

		host->scanInput();

		if (host->shouldQuit()) break; // break in order to return to hbmenu

		host->changeStretch();

		uint8_t p8kDown = host->getKeysDown();
		uint8_t p8kHeld = host->getKeysHeld();

		vm->UpdateAndDraw(p8kDown, p8kHeld);

		uint8_t* picoFb = vm->GetPicoInteralFb();
		uint8_t* screenPaletteMap = vm->GetScreenPaletteMap();
		Color* paletteColors = vm->GetPaletteColors();

		host->drawFrame(picoFb, screenPaletteMap, paletteColors);

		if (host->shouldFillAudioBuff()) {
			vm->FillAudioBuffer(host->getAudioBufferPointer(), 0, host->getAudioBufferSize());

			host->playFilledAudioBuffer();
		}
	}


	Logger::Write("Turning off vm and exiting logger\n");
	vm->CloseCart();
	delete vm;
	
	Logger::Exit();

	host->oneTimeCleanup();
	delete host;

	return 0;
}


