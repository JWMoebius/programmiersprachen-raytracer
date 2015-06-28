#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "Shape.hpp"

/*~~~~~~~BOX~~~~~~~~~~~~*/  
class Box : public Shape {
	public:
	Box();
	Box(std::string name, Color color, glm::vec3 const& minimum, glm::vec3 const& maximum);
	/*virtual*/ float area() const override;
	/*virtual*/ float volume() const override;
	~Box();
	glm::vec3 get_min() const;
	glm::vec3	get_max() const;
	/* virtual*/ std::ostream& print(std::ostream&  os)const override;
	bool intersect(Ray const& test, float& shortest_distance);
	private:
	glm::vec3 minimum_;
	glm::vec3 maximum_;
};
/*~~~~~~~BOX~~~~~~~~~~~~*/
	
	



#endif //#define BUW_LIST_HPP

