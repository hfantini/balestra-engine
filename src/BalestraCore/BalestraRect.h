// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BRECT

#define _INC_BRECT

namespace BalestraEngine
{
	class BRect
	{
		public:

			BRect();
			BRect(float X, float Y, float width, float height);

			// == GETTERS AND SETTERS ==========================
			float getX();
			float getY();
			float getWidth();
			float getHeight();
			void setX(float X);
			void setY(float Y);
			void setWidth(float width);
			void setHeight(float height);

		private:

			// == VAR & CONST ===================================
			float X;
			float Y;
			float width;
			float height;

		protected:
	};
}

#endif