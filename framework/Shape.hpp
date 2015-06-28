#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include "glm/vec3.hpp"/*~~~~~~~SPHERE~~~~~~~~~~~~*/
#include <cmath>/*~~~~~~~SPHERE~~~~~~~~~~~~*/
#include "color.hpp"
#include "../framework/Ray.hpp"
#include <string>
/*~~~~~~~SPHERE~~~~~~~~~~~~*/
#include "glm/glm.hpp"
#include "glm/gtx/intersect.hpp"

class Shape{
	public:
	Shape():
	name_(""),color_(0,0,0)
	{std::cout<<"Constructor Basic Class"<< std::endl;}

	Shape(std::string name, Color color):
	name_(name),color_(color)
	{std::cout<<"Constructor Basic Class"<< std::endl;}
	virtual ~Shape(){std::cout<<"Destructor Basic Class"<< std::endl;}
	
	virtual float area()const=0;
	virtual float volume()const=0;
	std::string get_name() const{					//Getter
		return name_;
	}
	Color get_color() const{							//^
		return color_;
	}
	virtual std::ostream& print(std::ostream& os) const{
		
		os << this->get_name() << "/" <<this->get_color() ;	
		return os;
	}
	std::string name_;
	Color color_;
};
/*~~~~~~~SPHERE~~~~~~~~~~~~*/

/*~~~~~~~SPHERE~~~~~~~~~~~~*/


/*~~~~~~~BOX~~~~~~~~~~~~*/

//Aufgabe 4
std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	s.print(os);
	return os;
}
#endif //#define BUW_LIST_HPP

