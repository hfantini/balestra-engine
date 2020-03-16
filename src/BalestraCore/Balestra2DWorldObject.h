// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================


#ifndef _INC_BWORLD_OBJECT

#define _INC_BWORLD_OBJECT

#include "BalestraPrecompiledHeader.h"
#include "BalestraConstants.h"
#include "BalestraDataTypes.h"
#include "BalestraDoubleVector.h"
#include "Balestra32ARGBColorFloat.h"
#include "BalestraAngle.h"

namespace BalestraEngine
{
	class BalestraGameTime;
	class BalestraRenderGear;
	class BalestraWorld;
	class BRect;

	class Balestra2DWorldObject
	{
		public:

			// == METHODS ======================================
			Balestra2DWorldObject();
			~Balestra2DWorldObject();

			virtual void loadContent(BalestraWorld* world);
			virtual void unloadContent(BalestraWorld* world);
			virtual void update(BalestraGameTime* gameTime);
			virtual void draw(BalestraRenderGear* renderGear);
	
			// == GETTERS AND SETTERS ==========================
			BDoubleVector* getPosition();
			void setPosition(BDoubleVector pos);
			BDoubleVector* getSize();
			void setSize(BDoubleVector size);
			BDoubleVector* getOrigin();
			void setOrigin(BDoubleVector origin);
			BDoubleVector* getScale();
			void setScale(BDoubleVector scale);
			int getOriginMethod();
			void setOriginMethod(int originMethod);
			B32ARGBColorFloat* getColor();
			void setColor(B32ARGBColorFloat color);
			BRect getRect();
			BRect getRect(BDoubleVector position);
			B_BOOL getFlipX();
			void setFlipX(B_BOOL value);
			B_BOOL getFlipY();
			void setFlipY(B_BOOL value);
			BAngle* getRotationAngle();
			void setRotationAngle(BAngle angle);
			BalestraWorld* getCurrentWorld();

		private:

		protected:

			// == VAR & CONST ===================================
			int originMethod = OBJ_2D_ORIGIN_CUSTOM;
			B_BOOL flipX = B_FALSE;
			B_BOOL flipY = B_FALSE;
			BalestraWorld* currentWorld;
			BDoubleVector origin = BDoubleVector(0, 0);
			BDoubleVector position = BDoubleVector(0,0);
			BDoubleVector size = BDoubleVector(0,0);
			BDoubleVector scale = BDoubleVector(1, 1);
			BAngle rotationAngle = BAngle(0.f);
			B32ARGBColorFloat color = B32ARGBColorFloat(1,0,0,0);

			// == METHODS =======================================
			void updateOriginPoint();
	};
}

#endif