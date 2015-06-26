#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include "glm/vec3.hpp"/*~~~~~~~SPHERE~~~~~~~~~~~~*/
#include <cmath>/*~~~~~~~SPHERE~~~~~~~~~~~~*/


class Shape{
	public:
	virtual float area()const=0;
	virtual float volume()const=0;
};
/*~~~~~~~SPHERE~~~~~~~~~~~~*/
class Sphere : public Shape {
	public:
	Sphere()
	: middle_{0,0,0}
	{}
	Sphere(float const& radius, glm::vec3 const& middle)
	: radius_{radius}, middle_{middle}
	{}

	/*virtual*/ float area() const override{
		float i = 4*pow(radius_, 2.0)*M_PI;
		return i;
	}
		
	/*virtual*/  float volume() const override{
		float p = 4*pow(radius_, 3.0)*M_PI/3;
		return p;		
	}
	glm::vec3 get_middle(){
		return middle_;
	}
	private:
	float radius_;
	glm::vec3 middle_;
};
/*~~~~~~~SPHERE~~~~~~~~~~~~*/

/*~~~~~~~BOX~~~~~~~~~~~~*/
class Box: public Shape{
	public:
	Box()
	: minimum_{0,0,0}, maximum_{0,0,0}
	{}
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum)
	: minimum_{minimum}, maximum_{maximum}
	{}
	/*virtual*/ float area() const override{
		float i = 8;
		return i;
	}
		
	/*virtual*/  float volume() const override{
				float i = 8;
		return i;		
	}
	glm::vec3 get_min(){
		return minimum_;
	}
	glm::vec3	get_max(){
		return maximum_;
	}
	private:
	glm::vec3 minimum_;
	glm::vec3 maximum_;
};
/*~~~~~~~BOX~~~~~~~~~~~~*/





#endif //#define BUW_LIST_HPP

