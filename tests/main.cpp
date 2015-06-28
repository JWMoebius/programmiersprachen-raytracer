#define CATCH_CONFIG_RUNNER
#include "../framework/Shape.hpp"
#include "../framework/catch.hpp"
#include <string>
#include "../framework/Box.cpp"
#include "../framework/Sphere.cpp"

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
			std::cout<< " DISTANCE:" << distance << std::endl;
	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("intersectRaySphere_ANOTHER", "[intersect_ANOTHER]"){
		Ray test_ray({0,0,0},{0,8,0});
		Ray badtest_ray({0,0,0},{1,0,0});
		Sphere s_five("hase", Color(9,9,9), 1, glm::vec3(0,4,0));
		float j_distance = 0;
		float badj_distance = 0;
		
		bool j=s_five.intersect(test_ray, j_distance);
		bool bad_j=s_five.intersect(badtest_ray, badj_distance);
		REQUIRE(j_distance==3.0f);
		REQUIRE(j==true);
		REQUIRE(bad_j==false);
}

TEST_CASE("ConDestructor", "[Aufgabe8]"){
		std::cout<<"TESTCASE ORDER"<<std::endl;
		Color red(255, 0, 0);
		glm::vec3 position(0);
		
		Sphere* s1 = new Sphere("sphere01", red, 1.2, position);
		Shape* s2 = new Sphere("sphere1", red, 1.2, position);
		s1->print(std::cout);
		s2->print(std::cout);
		delete s1;
		delete s2;
		int i = 3;
		std::cout<<"#########Aufgabe8 End #########"<<std::endl;
		REQUIRE(i==3);
}

TEST_CASE("intersectRayCube", "[intersect_Cube]"){
		Ray test_ray({0,1,2},{3,1,0});
		Box b_bx("Box_bx", Color(4,5,9), glm::vec3(1,0,1), glm::vec3(3,2,3));
		float i=b_bx.intersect(test_ray);
		REQUIRE(i==3.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
