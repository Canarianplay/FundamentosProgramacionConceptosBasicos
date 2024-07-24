#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

using namespace std;

//Interfaz para el polimorfismo
class Drawable
{
public:
	virtual void draw()const = 0;
	virtual ~Drawable() {};
};
#endif // !DRAWABLE_HPP
