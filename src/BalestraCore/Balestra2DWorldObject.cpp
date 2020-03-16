// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DWorldObject.h"
#include "BalestraRect.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Balestra2DWorldObject::Balestra2DWorldObject()
	{

	}

	Balestra2DWorldObject::~Balestra2DWorldObject()
	{

	}

	void Balestra2DWorldObject::loadContent(BalestraWorld* world)
	{
		Balestra2DWorldObject::currentWorld = world;
	}

	void Balestra2DWorldObject::unloadContent(BalestraWorld* world)
	{

		Balestra2DWorldObject::currentWorld = { 0 };
	}

	void Balestra2DWorldObject::update(BalestraGameTime* gameTime)
	{

	}

	void Balestra2DWorldObject::draw(BalestraRenderGear* renderGear)
	{

	}

	void Balestra2DWorldObject::updateOriginPoint()
	{
		// -- CALCULATING THE ORIGIN POINT --
		switch (getOriginMethod())
		{
			case OBJ_2D_ORIGIN_UP_LEFT:
				setOrigin(BDoubleVector(0, 0));
				break;

			case OBJ_2D_ORIGIN_UP_CENTER:
				setOrigin(BDoubleVector((getSize()->getX() / 2), 0));
				break;

			case OBJ_2D_ORIGIN_UP_RIGHT:
				setOrigin(BDoubleVector((getSize()->getX()), 0));
				break;

			case OBJ_2D_ORIGIN_CENTER_LEFT:
				setOrigin(BDoubleVector(0, (getSize()->getY() / 2)));
				break;

			case OBJ_2D_ORIGIN_CENTER_CENTER:
				setOrigin(BDoubleVector((getSize()->getX() / 2), (getSize()->getY() / 2)));
				break;

			case OBJ_2D_ORIGIN_CENTER_RIGHT:
				setOrigin(BDoubleVector(getSize()->getX(), (getSize()->getY() / 2)));
				break;

			case OBJ_2D_ORIGIN_BOTTOM_LEFT:
				setOrigin(BDoubleVector(0, getSize()->getY()));
				break;

			case OBJ_2D_ORIGIN_BOTTOM_CENTER:
				setOrigin(BDoubleVector((getSize()->getX() / 2), getSize()->getY()));
				break;

			case OBJ_2D_ORIGIN_BOTTOM_RIGHT:
				setOrigin(BDoubleVector(getSize()->getX(), getSize()->getY()));
				break;

			default:
				break;
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BDoubleVector* Balestra2DWorldObject::getPosition()
	{
		return &position;
	}

	void Balestra2DWorldObject::setPosition(BDoubleVector position)
	{
		Balestra2DWorldObject::position = position;
	}

	BDoubleVector* Balestra2DWorldObject::getSize()
	{
		return &size;
	}

	void Balestra2DWorldObject::setSize(BDoubleVector size)
	{
		Balestra2DWorldObject::size = size;
	}

	BDoubleVector* Balestra2DWorldObject::getScale()
	{
		return &scale;
	}

	void Balestra2DWorldObject::setScale(BDoubleVector scale)
	{
		Balestra2DWorldObject::scale = scale;
	}

	BDoubleVector* Balestra2DWorldObject::getOrigin()
	{
		return &origin;
	}

	void Balestra2DWorldObject::setOrigin(BDoubleVector origin)
	{
		Balestra2DWorldObject::origin = origin;
	}

	int Balestra2DWorldObject::getOriginMethod()
	{
		return Balestra2DWorldObject::originMethod;
	}

	void Balestra2DWorldObject::setOriginMethod(int originMethod)
	{
		Balestra2DWorldObject::originMethod = originMethod;
	}

	B32ARGBColorFloat* Balestra2DWorldObject::getColor()
	{
		return &color;
	}

	void Balestra2DWorldObject::setColor(B32ARGBColorFloat color)
	{
		Balestra2DWorldObject::color = color;
	}

	BRect Balestra2DWorldObject::getRect()
	{
		float X = position.getX() - origin.getX();
		float Y = position.getY() - origin.getY();
		float W = (position.getX() + size.getX()) - origin.getX();
		float H = (position.getY() + size.getY()) - origin.getY();

		return BRect(X,Y,W,H);
	}

	BRect Balestra2DWorldObject::getRect(BDoubleVector position)
	{
		float X = position.getX() - origin.getX();
		float Y = position.getY() - origin.getY();
		float W = (position.getX() + size.getX()) - origin.getX();
		float H = (position.getY() + size.getY()) - origin.getY();

		return BRect(X, Y, W, H);
	}

	B_BOOL Balestra2DWorldObject::getFlipX()
	{
		return Balestra2DWorldObject::flipX;
	}

	void Balestra2DWorldObject::setFlipX(B_BOOL value)
	{
		Balestra2DWorldObject::flipX = value;
	}

	B_BOOL Balestra2DWorldObject::getFlipY()
	{
		return Balestra2DWorldObject::flipY;
	}

	void Balestra2DWorldObject::setFlipY(B_BOOL value)
	{
		Balestra2DWorldObject::flipY = value;
	}

	BAngle* Balestra2DWorldObject::getRotationAngle()
	{
		return &(Balestra2DWorldObject::rotationAngle);
	}

	void Balestra2DWorldObject::setRotationAngle(BAngle angle)
	{
		Balestra2DWorldObject::rotationAngle = angle;
	}

	BalestraWorld* Balestra2DWorldObject::getCurrentWorld()
	{
		return Balestra2DWorldObject::currentWorld;
	}
}