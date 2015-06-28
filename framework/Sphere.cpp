#define CATCH_CONFIG_RUNNER
#include "Sphere.hpp"


	Sphere::Sphere()
	: Shape{},radius_{1}, middle_{0,0,0}
	{std::cout<<"Constructor SHAPE Class"<< std::endl;}
	Sphere::Sphere(std::string name, Color color,	float const& radius, glm::vec3 const& middle)
	: Shape{name,color},radius_{radius}, middle_{middle}
	{std::cout<<"Constructor SHAPE Class"<< std::endl;}
	Sphere::~Sphere(){std::cout<<"Destructor SHAPE Class"<< std::endl;} 
	/*virtual*/ float Sphere::area() const {
		float i = 4*pow(radius_, 2.0)*M_PI;
		return i;
	}
		
	/*virtual*/  float Sphere::volume() const {
		float p = 4*pow(radius_, 3.0)*M_PI/3;
		return p;		
	}
	glm::vec3 Sphere::get_middle() const{
		return middle_;
	}
	float Sphere::get_radius() const{
		return radius_;
	}
	/* virtual*/ std::ostream& Sphere::print(std::ostream&  os)const{
		os << this->get_name() << "/" <<this->get_color() << "/"<< 
		this->get_radius()<<"/ Middle("<< middle_.x<<"/"<<middle_.y<<"/"<<
		middle_.z<<")"<<std::endl;
		return os;		
	}

	bool Sphere::intersect(Ray const& test, float& distance){
		distance =-1;
		glm::vec3 tempvec = glm::normalize(test.direction);
		glm::intersectRaySphere(test.origin, tempvec,
		this->middle_,this->radius_, distance);			
		if (distance == -1){return false;}
		return true;
	}

