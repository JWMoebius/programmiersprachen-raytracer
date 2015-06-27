#define CATCH_CONFIG_RUNNER
#include "../framework/Shape.hpp"
#include "../framework/catch.hpp"
#include <string>


TEST_CASE("AREA","[Aufgabe2area]")
{

	Sphere m("hase", Color(9,9,9), 7, glm::vec3(0,0,0));
	float m_area = m.area();
	float m_volume = m.volume();
	REQUIRE(m_volume==Approx(1436.75504));
	REQUIRE(m_area==Approx(615.7521601));
	Box bx("Box_bx", Color(4,5,9), glm::vec3(0), glm::vec3(9,4,2));
	float box_area = bx.area();
	float box_volume = bx.volume();
	REQUIRE(box_area==124);
	REQUIRE(box_volume==72);
}
TEST_CASE("Print","[Aufgabe5print]")
{
	Sphere s_five("hase", Color(9,9,9), 7, glm::vec3(0,0,0));
	Box b_bx("Box_bx", Color(4,5,9), glm::vec3(0), glm::vec3(9,4,2));
	std::cout<<"Werte der Kugel: "<<s_five << std::endl;
	std::cout<<"Werte des Quaders: "<<b_bx <<std::endl;
	int i = 3;
	REQUIRE(i==3);
}
TEST_CASE("intersectRaySphere", "[intersect]")
{
	// Ray
	glm::vec3 ray_origin (0.0, 0.0, 0.0);
	// ray direction has to be normalized !
	// you can use:
	//	v = glm:: normalize(some_vector)
	glm::vec3 ray_direction(0.0, 0.0, 1.0);
	//	Sphere
	glm::vec3 sphere_center(0.0, 0.0, 5.0);
	float sphere_radius(1.0);
	
	float distance(0.0);
	auto result = glm::intersectRaySphere(
			ray_origin, ray_direction,
			sphere_center, sphere_radius, distance);
	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE(){
		Ray test_ray({0,0,0},{0,8,0});
		Sphere s_five("hase", Color(9,9,9), 1, glm::vec3(0,4,0));
		float i=s_five.intersect(test_ray);
		REQUIRE(i==3.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
