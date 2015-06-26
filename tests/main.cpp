#define CATCH_CONFIG_RUNNER
#include "../framework/Shape.hpp"
#include "../framework/catch.hpp"

TEST_CASE("AREA","[Aufgabe2area]")
{
	Sphere m(7, glm::vec3(0));
	float m_area =m.area();
	float m_volume =m.volume();
	REQUIRE(m_volume==Approx(1436.75504));
	REQUIRE(m_area==Approx(615.7521601));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
