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
	: Shape{},radius_{1}, middle_{0,0,0}
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
		os << this->get_name() << "/" <<this->get_color() << "/"<< 
		this->get_radius()<<"/ Middle("<< middle_.x<<"/"<<middle_.y<<"/"<<
		middle_.z<<")";
		return os;		
	}
	float intersect(Ray test) const{
			float distance=0;
			glm::vec3 tempvec = glm::normalize(test.direction);
			glm::intersectRaySphere(test.origin, tempvec,
			this->middle_,this->radius_,distance);			
			return distance;
	}
	private:
	float radius_;
	glm::vec3 middle_;
};
/*~~~~~~~SPHERE~~~~~~~~~~~~*/

/*~~~~~~~BOX~~~~~~~~~~~~*/  
class Box : public Shape {
	public:
	Box()
	:Shape{name_, color_}, minimum_{0,0,0}, maximum_{0,0,0}
	{}
	Box(std::string name, Color color, glm::vec3 const& minimum, glm::vec3 const& maximum)
	:Shape{name, color}, minimum_{minimum}, maximum_{maximum}
	{}
	/*virtual*/ float area() const override{
		float a =maximum_.x-minimum_.x;
		float b =maximum_.y-minimum_.y;
		float c =maximum_.z-minimum_.z;
		float ground = a*c;
		float side =b*c;
		float front =a*b;
		return 2*(ground+side+front);
	}
	/*virtual*/ float volume() const override{
		float a =maximum_.x-minimum_.x;
		float b =maximum_.y-minimum_.y;
		float c =maximum_.z-minimum_.z;
		return a*b*c;
	}	
		
	glm::vec3 get_min() const{
		return minimum_;
	}
	glm::vec3	get_max() const{
		return maximum_;
	}
	/* virtual*/ std::ostream& print(std::ostream&  os)const override{
		os << this->get_name() << "/" <<this->get_color() << "/ min("<< 
		minimum_.x<<"/"<<minimum_.y<<"/"<<	minimum_.z << ") / max(" <<
		maximum_.x<<"/"	<<maximum_.y<<"/"<<maximum_.z<<")";
		return os;
	}
	private:
	glm::vec3 minimum_;
	glm::vec3 maximum_;
};
/*~~~~~~~BOX~~~~~~~~~~~~*/

//Aufgabe 4
std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	s.print(os);
	return os;
}
#endif //#define BUW_LIST_HPP

