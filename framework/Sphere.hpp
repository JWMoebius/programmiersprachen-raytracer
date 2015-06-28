#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "Shape.hpp"

/*~~~~~~~SPHERE~~~~~~~~~~~~*/
class Sphere : public Shape {
	public:
	Sphere();
	Sphere(std::string name, Color color,	float const& radius, glm::vec3 const& middle);
	~Sphere();
	/*virtual*/ float area() const override;
		
	/*virtual*/  float volume() const override;
	glm::vec3 get_middle() const;
	float get_radius() const;
	/* virtual*/ std::ostream& print(std::ostream&  os)const override;

	bool intersect(Ray const& test, float& distance);
	private:
	float radius_;
	glm::vec3 middle_;
};
	
	






#endif //#define BUW_LIST_HPP
