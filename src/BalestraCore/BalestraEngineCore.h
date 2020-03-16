
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================

// == CORE LIB (0.1A)
// Copyright (c) Henrique.F. All Rights Reserved.

/* 

	This file contains all headers that can be used to create platform specific 
	versions of Balestra Engine. The contents here are protected by intellectual 
	property and can't be used for any purposes before the consent of the creator 
	Henrique.F with the exception of academic projects without profit.

*/

#ifndef _INC_BALESTRA_ENGINE

#define _INC_BALESTRA_ENGINE
#define _BALESTRA_ENGINE_

// == EXCEPTION FILES
#include "BalestraException.h"
#include "BalestraGameTimeException.h"
#include "BalestraInputException.h"
#include "BalestraMathException.h"
#include "BalestraResourceException.h"
#include "BalestraVideoException.h"
#include "BalestraAnimationException.h"
#include "BalestraSoundException.h"

// == INTERFACE FILES

#include "IBalestraDevice.h"
#include "IBalestraAnimationEffect.h"

// == HEADER FILES

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DRect.h"
#include "Balestra2DSprite.h"
#include "Balestra2DText.h"
#include "Balestra2DWorldObject.h"
#include "Balestra32ARGBColorFloat.h"
#include "Balestra32ARGBColorUInt.h"
#include "BalestraAnimationController.h"
#include "BalestraAnimationSequence.h"
#include "BalestraAnimationEffectColor.h"
#include "BalestraColorUtil.h"
#include "BalestraConfiguration.h"
#include "BalestraConfigurationDebug.h"
#include "BalestraConfigurationDecoder.h"
#include "BalestraConfigurationGameTime.h"
#include "BalestraConfigurationInput.h"
#include "BalestraConfigurationPlatform.h"
#include "BalestraConfigurationSound.h"
#include "BalestraConfigurationVideo.h"
#include "BalestraConstants.h"
#include "BalestraDataTypes.h"
#include "BalestraDebugText.h"
#include "BalestraDoubleVector.h"
#include "BalestraEnvironment.h"
#include "BalestraEnvironmentInput.h"
#include "BalestraEnvironmentResource.h"
#include "BalestraEnvironmentSound.h"
#include "BalestraEnvironmentVideo.h"
#include "BalestraGameTime.h"
#include "BalestraImage.h"
#include "BalestraImageLoader.h"
#include "BalestraInputKeyboard.h"
#include "BalestraInputMouse.h"
#include "BalestraMath.h"
#include "BalestraRect.h"
#include "BalestraRenderGear.h"
#include "BalestraSound.h"
#include "BalestraSoundChannel.h"
#include "BalestraSoundLoader.h"
#include "BalestraUserCommunication.h"
#include "BalestraCamera.h"
#include "BalestraWorld.h"
#include "BalestraAngle.h"
#include "Balestra2DPhysics.h"
#include "BalestraTypeConverter.h"
#include "BalestraAnimationEffectDoubleVector.h"
#include "BalestraImageButton.h"
#include "BalestraFontLoader.h"
#include "BalestraFont.h"

#endif 