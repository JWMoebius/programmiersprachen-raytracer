#define CATCH_CONFIG_RUNNER
#include "../framework/Shape.hpp"
#include "../framework/catch.hpp"

TEST_CASE("AREA","[Aufgabe2area]")
{
	Sphere m(7, glm::vec3(0));
	float m_area =m.area();
	REQUIRE(m_area==7);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
