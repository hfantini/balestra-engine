// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_SCENARIO

#define _INC_SCENARIO

	namespace BalestraEngine
	{
		class BalestraWorld;
		class BalestraImageLoader;
		class BalestraRenderGear;
		class Balestra2DSprite;
		class BalestraImage;
		class BalestraAnimationSequence;

		class Scenario
		{
			public:

				Scenario();
				~Scenario();
				void loadContent(BalestraWorld* world, BalestraImageLoader* loader);
				void unloadCotent();
				void draw(BalestraRenderGear* renderGear);

			private:
			protected:

				//SPRITES
				BalestraImage* imgWalkSeq1;
				BalestraImage* imgBrickSeq1;
				BalestraAnimationSequence* seqWalkPlatform;
				BalestraAnimationSequence* seqBrick;

				float tileX = 25;
				float tileY = 3;
				float marginY = 0;

				Balestra2DSprite* spriteArray[25][3];
		};
	}

#endif