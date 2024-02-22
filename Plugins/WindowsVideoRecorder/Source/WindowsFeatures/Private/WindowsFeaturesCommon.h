// Copyright 2023,Obitodaitu. All Rights Reserved.

#pragma once

/**
 * Used enable/disable optimization for the entire module.
 *
 */
#if UE_BUILD_SHIPPING
	#define WINDOWSFEATURES_DEBUG 0
#else
	#define WINDOWSFEATURES_DEBUG 0
#endif

#if WINDOWSFEATURES_DEBUG
	#define WINDOWSFEATURES_START PRAGMA_DISABLE_OPTIMIZATION
	#define WINDOWSFEATURES_END PRAGMA_ENABLE_OPTIMIZATION
#else
	#define WINDOWSFEATURES_START 
	#define WINDOWSFEATURES_END 
#endif
