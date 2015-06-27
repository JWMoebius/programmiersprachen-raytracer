#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include "glm/vec3.hpp"/*~~~~~~~SPHERE~~~~~~~~~~~~*/
#include <cmath>/*~~~~~~~SPHERE~~~~~~~~~~~~*/
#include "color.hpp"
#include <string>

class Shape{
	public:
	Shape():
	name_(""),color_(0,0,0)
	{}

	Shape(std::string name, Color color):
	name_(name),color_(color)
	{}
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
class Sphere : public Shape {
	public:
	Sphere()
	: radius_{0}, middle_{0,0,0}
	{}
	Sphere(std::string name, Color color,	float const& radius, glm::vec3 const& middle)
	: Shape{name,color},radius_{radius}, middle_{middle}
	{}

	/*virtual*/ float area() const override{
		float i = 4*pow(radius_, 2.0)*M_PI;
		return i;
	}
		
	/*virtual*/  float volume() const override{
		float p = 4*pow(radius_, 3.0)*M_PI/3;
		return p;		
	}
	glm::vec3 get_middle() const{
		return middle_;
	}
		float get_radius() const{
		return radius_;
	}
	/* virtual*/ std::ostream& print(std::ostream&  os)const override{
		os << this->get_name() << "/" <<this->get_color() << "/"<< this->get_radius()<<"/";	
		os << middle_.x<<"/"<<middle_.y;
		return os;
	}
	private:
	float radius_;
	glm::vec3 middle_;
};
/*~~~~~~~SPHERE~~~~~~~~~~~~*/

/*~~~~~~~BOX~~~~~~~~~~~~*/
/*
  
class Box: public Shape{
	public:
	Box()
	:Shape{name_,color_}, minimum_{0,0,0}, maximum_{0,0,0}
	{}
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum)
	:Shape{name_,color_}, minimum_{minimum}, maximum_{maximum}
	{}
	virtual float area() const override{
		float i = 8;
		return i;
	}
		
	 float volume() const override{
				float i = 8;
		return i;		
	}
	glm::vec3 get_min() const{
		return minimum_;
	}
	glm::vec3	get_max() const{
		return maximum_;
	}
	 virtual/ std::ostream& print(std::ostream&  os)const override{
		os << this->get_name() << "/" <<this->get_color() << "/"<< minimum_.x()<<"/";	
		os << minimum_.x()<<"/";
		return os;
	}
	private:
	glm::vec3 minimum_;
	glm::vec3 maximum_;
};*/
/*~~~~~~~BOX~~~~~~~~~~~~*/

//Aufgabe 4
std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	s.print(os);
	return os;
}
#endif //#define BUW_LIST_HPP

