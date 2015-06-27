#include "../framework/glm/glm.hpp"
#include "../framework/glm/gtx/intersect.hpp"

struct Ray
{
	Ray(glm::vec3 first, glm::vec3 second):
	origin{first}, direction{second}
	{}
	glm::vec3 origin;
	glm::vec3 direction;
};
