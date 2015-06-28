#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Box.hpp"




	Box::Box()
	:Shape{name_, color_}, minimum_{0,0,0}, maximum_{0,0,0}
	{}
	Box::Box(std::string name, Color color, glm::vec3 const& minimum, glm::vec3 const& maximum)
	:Shape{name, color}, minimum_{minimum}, maximum_{maximum}
	{}
	Box::~Box(){}
	/*virtual*/ float Box::area()  const {
		float a =maximum_.x-minimum_.x;
		float b =maximum_.y-minimum_.y;
		float c =maximum_.z-minimum_.z;
		float ground = a*c;
		float side =b*c;
		float front =a*b;
		return 2*(ground+side+front);
	}
	/*virtual*/ float Box::volume() const {
		float a =maximum_.x-minimum_.x;
		float b =maximum_.y-minimum_.y;
		float c =maximum_.z-minimum_.z;
		return a*b*c;
	}	
		
	glm::vec3 Box::get_min() const{
		return minimum_;
	}
	glm::vec3	Box::get_max() const{
		return maximum_;
	}
	/* virtual*/ std::ostream& Box::print(std::ostream&  os)const{
		os << this->get_name() << "/" <<this->get_color() << "/ min("<< 
		minimum_.x<<"/"<<minimum_.y<<"/"<<	minimum_.z << ") / max(" <<
		maximum_.x<<"/"	<<maximum_.y<<"/"<<maximum_.z<<")"<<std::endl;
		return os;
	}
	float Box::intersect(Ray test) const{
		//MIN AB Plane
		glm::vec3 minab_org = minimum_;				
		glm::vec3 minab_dir = minimum_;
		minab_dir.x = maximum_.x;
		minab_dir.y = maximum_.y;
		glm::vec3 minab_normal = glm::normalize(minab_dir);
		//MIN AC Plane
		glm::vec3 minac_org = minimum_;				
		glm::vec3 minac_dir = minimum_;
		minac_dir.x = maximum_.x;
		minac_dir.z = maximum_.z;
		glm::vec3 minac_normal = glm::normalize(minac_dir);
		//MIN BC Plane
		glm::vec3 minbc_org = minimum_;				
		glm::vec3 minbc_dir = minimum_;
		minbc_dir.y = maximum_.y;
		minbc_dir.z = maximum_.z;
		glm::vec3 minbc_normal = glm::normalize(minbc_dir);				
		//MAX AB Plane
		glm::vec3 maxab_org = maximum_;				
		glm::vec3 maxab_dir = maximum_;
		maxab_dir.x = minimum_.x;
		maxab_dir.y = minimum_.y;
		glm::vec3 maxab_normal = glm::normalize(maxab_dir);
		//MAX AC Plane
		glm::vec3 maxac_org = maximum_;				
		glm::vec3 maxac_dir = maximum_;
		maxac_dir.x = minimum_.x;
		maxac_dir.z = minimum_.z;
		glm::vec3 maxac_normal = glm::normalize(maxac_dir);
		//MAX BC Plane
		glm::vec3 maxbc_org = maximum_;				
		glm::vec3 maxbc_dir = maximum_;
		maxbc_dir.y = minimum_.y;
		maxbc_dir.z = minimum_.z;
		glm::vec3 maxbc_normal = glm::normalize(maxbc_dir);				
		
		//Intersection
		float shortest_distance =0;		
		float temp=3;		
		glm::vec3 tempvec = glm::normalize(test.direction);
/*		std::cout<<"Direction normalized:"<<tempvec.x<<tempvec.y<<tempvec.z<< "end"<<temp<<std::endl;
			std::cout<<" MinABaktualisiermal: "<<minab_dir.x<< minab_dir.y<< 
			minab_dir.z<<std::endl;
			std::cout<<" MinACaktualisiermal: "<<minac_dir.x<< minac_dir.y<< 
			minac_dir.z<<std::endl;
			std::cout<<" MinBCaktualisiermal: "<<minbc_dir.x<< minbc_dir.y<< 
			minbc_dir.z<<std::endl;
			std::cout<<" MaxABaktualisiermal: "<<maxab_dir.x<< maxab_dir.y<< 
			maxab_dir.z<<std::endl;
			std::cout<<" MaxACaktualisiermal: "<<maxac_dir.x<< maxac_dir.y<< 
			maxac_dir.z<<std::endl;
			std::cout<<" MaxBCaktualisiermal: "<<maxbc_dir.x<< maxbc_dir.y<< 
			maxbc_dir.z<<std::endl;
*/

		//Intersetion MINab
		glm::intersectRayPlane(test.origin, tempvec,
		minab_org, minab_normal, temp);	
		std::cout<<temp<< std::endl;
		shortest_distance = temp;
		std::cout<<temp<<std::endl;			
		//Intersetion MINac
		glm::intersectRayPlane(test.origin, tempvec,
		minac_org, minac_normal, temp);
		if (temp<shortest_distance){
			shortest_distance = temp;		
		}
		std::cout<<temp<<std::endl;
		//Intersetion MINbc
		glm::intersectRayPlane(test.origin, tempvec,
		minbc_org, minbc_normal, temp);
		if (temp<shortest_distance){
			shortest_distance = temp;	
		}
		std::cout<<temp<<std::endl;
		//Intersetion MAXab
		glm::intersectRayPlane(test.origin, tempvec,
		maxab_org, maxab_normal, temp);	
		if (temp<shortest_distance){
			shortest_distance = temp;	
		}	
		std::cout<<temp<<std::endl;
		//Intersetion MAXac
		glm::intersectRayPlane(test.origin, tempvec,
		maxac_org, maxac_normal, temp);		
		if (temp<shortest_distance){
			shortest_distance = temp;	
		}			
		std::cout<<temp<<std::endl;
		//Intersetion MAXbc
		glm::intersectRayPlane(test.origin, tempvec,
		maxbc_org, maxbc_normal, temp);		
		if (temp<shortest_distance){
			shortest_distance = temp;	
		}	
		std::cout<<temp<<std::endl;
		
		return shortest_distance;

	}

/*~~~~~~~BOX~~~~~~~~~~~~*/
	
