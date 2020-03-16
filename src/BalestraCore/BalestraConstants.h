// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == DEFINITIONS
// =====================================================

// == GAME TIME ========================================

// VALUES BETWEEN 0X00000500 ~ 0X00001000

#define GAMETIME_FREE_RUN                     0X00000500
#define GAMETIME_FIXED_TIME_STEP              0X00000501
#define GAMETIME_DEFAULT_TARGET_FPS           60
#define GAMETIME_DEFAULT_MAX_FRAMESKIP        5

// == VIDEO ============================================

// VALUES BETWEEN 0X00001000 ~ 0X00001499

// -- RESOLUTION ---------------------------------------
#define RESOLUTION_DEFAULT_WIDTH  0
#define RESOLUTION_DEFAULT_HEIGHT 0

#define BVIDEO_MODE_FULLSCREEN                0X00001051 
#define BVIDEO_MODE_WINDOWED                  0X00001052
#define BVIDEO_MODE_WINDOWED_FS               0X00001053

#define BVIDEO_ONRESIZE_STRETCH               0x00001100
#define BVIDEO_ONRESIZE_RESIZE                0x00001101

// == AUDIO ============================================

// VALUES BETWEEN 0X00002000 ~ 0X00002499

// == INPUT ============================================

// VALUES BETWEEN 0X00003000 ~ 0X00003499

#define BINPUT_TYPE_KEYBOARD_MOUSE 0x0003000
#define BINPUT_TYPE_TOUCHSCREEN 0x0003001
#define BINPUT_TYPE_360GAMEPAD 0x0003002
#define BMOUSE_BUTTON_DOWN 0x00003011
#define BMOUSE_BUTTON_UP 0x00003012
#define BMOUSE_BUTTON_RELEASED 0x00003013
#define BKEYBOARD_KEY_DOWN 0x00003016
#define BKEYBOARD_KEY_UP 0x00003017

// == PLATFORM =========================================

// VALUES BETWEEN 0X00004000 ~ 0X00004499

// == EXCEPTION ========================================

// VALUES BETWEEN 0X00005000 ~ 0X00005499

// == OBJECT ===========================================

// VALUES BETWEEN 0X00006000 ~ 0X00006499

#define OBJ_SIZE_MODE_AUTO                    0x00006000
#define OBJ_SIZE_MODE_CUSTOM                  0x00006001
#define ANIMATION_PLAY_STATE                  0x00006002
#define ANIMATION_STOP_STATE                  0x00006003
#define ANIMATION_PAUSE_STATE                 0x00006004
#define ANIMATION_PLAY_SENSE_NORMAL           0x00006005
#define ANIMATION_PLAY_SENSE_REVERSE          0x00006006
#define OBJ_2D_ORIGIN_CUSTOM                  0x00006007
#define OBJ_2D_ORIGIN_UP_LEFT                 0x00006008
#define OBJ_2D_ORIGIN_UP_CENTER               0x00006009
#define OBJ_2D_ORIGIN_UP_RIGHT                0x00006010
#define OBJ_2D_ORIGIN_CENTER_LEFT             0x00006011
#define OBJ_2D_ORIGIN_CENTER_CENTER           0x00006012
#define OBJ_2D_ORIGIN_CENTER_RIGHT            0x00006013
#define OBJ_2D_ORIGIN_BOTTOM_LEFT             0x00006014
#define OBJ_2D_ORIGIN_BOTTOM_CENTER           0x00006015
#define OBJ_2D_ORIGIN_BOTTOM_RIGHT            0x00006016

// == DATA =============================================

// VALUES BETWEEN 0X00007000 ~ 0X00007499

#define DATA_IMAGE_FORMAT_AUTO                0x00007000
#define DATA_IMAGE_FORMAT_BMP                 0x00007001
#define DATA_IMAGE_FORMAT_PNG                 0x00007002
#define DATA_IMAGE_FORMAT_JPG                 0x00007003

#define DATA_SOUND_FORMAT_AUTO                0x00007030
#define DATA_SOUND_FORMAT_WAV                 0x00007031
#define DATA_SOUND_FORMAT_MP3                 0x00007032
#define DATA_SOUND_FORMAT_MIDI                0x00007033
#define DATA_SOUND_FORMAT_OGG                 0x00007034

// == MATH =============================================

#define BALESTRA_PI 3.14159265