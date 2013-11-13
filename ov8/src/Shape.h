#ifndef SHAPE_H
#define SHAPE_H

#import "Image.cpp"

class Shape {
private:
	Color color;
public:
	Shape(Color color) {
		this->color = color;
	};

	virtual void Draw();
	virtual void ~Draw();
};

/* ----------How can we get color when it is private?----------
 *
 * Thought 1: Make variable friendly?
 * Thought 2: Implement setters and getters for private variable.
 *
 *
 * -----What does it mean that a function is pure virtual?-----
 *
 * A pure virtual function is a function can be thought of as a
 * function implementation requirement. A function without any
 * body. A virual function is only in a abstract class.
 * Other classes that extends/inherits an abstract class with
 * have to implement all virtual functions since they are
 * required. Otherwise, the compiler will give an compiler
 * error when it tries to build an executeable file.
 *
 *
 * ---------What can't we do with abstract classes?------------
 *
 * Due to virtual functions not having function bodies is fair
 * to say that these classes cannot be initialized as objects,
 * which is also the case. Abstract classes are used as base
 * class for many common proporties. In this case, a shape
 * would be a base class for a line, a triangle, a square and
 * so forth. Just as "Human" is a baseclass for scandinavian,
 * asians, africans and so forth. You wouldnt be able to
 * initialize a human because simply it is an unfinished class.
 */


#endif
