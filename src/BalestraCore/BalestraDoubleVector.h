// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BALESTRA_DOUBLE_VECTOR

#define _INC_BALESTRA_DOUBLE_VECTOR

namespace BalestraEngine
{
	class BDoubleVector
	{
		public:

			BDoubleVector();
			BDoubleVector(float X, float Y);

			// == GETTERS AND SETTERS ==========================
			float getX();
			float getY();
			void setX(float X);
			void setY(float Y);
			void incrementX(float value);
			void incrementY(float value);
			void decrementX(float value);
			void decrementY(float value);

		private:

			// == VAR & CONST ===================================
			float X;
			float Y;

		protected:
	};
}

#endif
