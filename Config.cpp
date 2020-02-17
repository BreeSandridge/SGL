#include "Config.h"

config::config() {



	RECT rectWork = { 0 };
	if (SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWork, 0)) {
		//gets the current res
		current_resolution_width = rectWork.right - rectWork.left;
		current_resolution_height = rectWork.bottom - rectWork.top;
	}


}
