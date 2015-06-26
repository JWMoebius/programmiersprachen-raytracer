#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Shape.hpp"
#include <iterator>
#include <vector>
#include <ctime>

TEST_CASE("LIST1","[aufgabe1]")
{
	int i = 3;
	List<int> thost;
	REQUIRE(i==3);
	REQUIRE(thost.size()==0);
}




int main(int argc, char* argv [])
{
	return Catch::Session().run(argc, argv);
}
