#include "Config.h"

Config::Config() {



	RECT rectWork = { 0 };
	if (SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWork, 0)) {
		//gets the current res
		currentResolutionWidth = rectWork.right - rectWork.left;
		currentResolutionHeight = rectWork.bottom - rectWork.top;
	}


}
