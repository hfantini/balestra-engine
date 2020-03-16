// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == DEFINITIONS
// =====================================================

// == VIDEO ============================================

// VALUES BETWEEN 0X00001500 ~ 0X00001999

// -- V-MODE -------------------------------------------

// -- RESOLUTION ---------------------------------------
#define BVIDEO_WIN32_DIRECT2D_1 0x00001500
#define BVIDEO_WIN32_DIRECT3D_11 0x00001501
#define BVIDEO_WIN32_DIRECT2D3D 0x00001502
#define BVIDEO_WIN32_OPENGL 0x00001503
#define BVIDEO_WIN32_RESOLUTION_DEFAULT 0x00001504

// -- WINDOW -------------------------------------------

#define WINDOW_DEFAULT_X 0
#define WINDOW_DEFAULT_Y 0
#define WINDOW_DEFAULT_WIDTH 0
#define WINDOW_DEFAULT_HEIGHT 0

// == AUDIO ============================================

// VALUES BETWEEN 0X00002500 ~ 0X00002999

#define BAUDIO_WIN32_NO_SOUND 0x00002500
#define BAUDIO_WIN32_XAUDIO2 0x00002501

// == INPUT ============================================

// VALUES BETWEEN 0X00003500 ~ 0X00003999
#define BINPUT_WIN32_PLATFORM 0x00003500
#define BINPUT_WIN32_DIRECTINPUT 0x00003501

// == PLATFORM =========================================

// VALUES BETWEEN 0X00004500 ~ 0X00004999
#define BPLATFORM_DEFAULT_ICON 0
#define BPLATFORM_OS_UNSUPORTED 0x00004500
#define BPLATFORM_OS_XP 0x00004501
#define BPLATFORM_OS_XP_SP1 0x00004502
#define BPLATFORM_OS_XP_SP2 0x00004503
#define BPLATFORM_OS_XP_SP3 0x00004504
#define BPLATFORM_OS_VISTA 0x00004505
#define BPLATFORM_OS_VISTA_SP1 0x00004506
#define BPLATFORM_OS_VISTA_SP2 0x00004507
#define BPLATFORM_OS_WIN7 0x00004508
#define BPLATFORM_OS_WIN7_SP1 0x00004509
#define BPLATFORM_OS_WIN8 0x00004510
#define BPLATFORM_OS_WIN8_1 0x00004511

// == DECODERS =========================================

// VALUES BETWEEN 0X00005500 ~ 0X00005999
#define BIMAGEDECODER_MS_WIC 0x00005500
#define BIMAGEDECODER_DEVIL 0X00005501