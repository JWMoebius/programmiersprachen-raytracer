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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
