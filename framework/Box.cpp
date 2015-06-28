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
 bool Box::intersect(Ray const& test, float& shortest_distance){
		shortest_distance = 0;
		// fuer Intersection	
		float temp=9223372036854775807;		
		bool is_intersected = false;
		
		glm::vec3 tempvec = glm::normalize(test.direction);
		glm::vec3 a = minimum_; // vorne links unten	//--> passt
		glm::vec3 b = minimum_;	// vorne rechts unten
			b.x = maximum_.x; //--> passt
		glm::vec3 c = minimum_;	// hinten links unten
			c.z = maximum_.z; //-->passt
		glm::vec3 d = minimum_;	// hinten rechts unten
			d.x = maximum_.x;
			d.z = maximum_.z; //--> passt
		glm::vec3 e = minimum_;	// vorne links oben	
			e.y= maximum_.y; //--> passt
		glm::vec3 f = minimum_;	// vorne rechts oben
			f.x= maximum_.x; //--> passt
			f.y= maximum_.y; //--> passt
		glm::vec3 g = minimum_;	// hinten links oben
			e.y= maximum_.y; //--> passt
			e.z= maximum_.z; //--> passt
		glm::vec3 h = maximum_;	// hinten rechts oben
		

		//unten	Richtungsvektor
		glm::vec3 ab = b-a;
		glm::vec3 ac = c-a;
		glm::vec3 bottom = glm::cross(ab, ac);
		glm::vec3 bottom_orig = minimum_;
		
		//oben
		glm::vec3 hg = g-h;
		glm::vec3 hf = f-h;
		glm::vec3 top	= glm::cross(hg, hf);
		glm::vec3 top_orig = maximum_;
		//vorne
			//ab
		glm::vec3 ae = e-a;
		glm::vec3 front = glm::cross(ab, ae);		
		glm::vec3 front_orig = minimum_;
		//hinten
			//hg
		glm::vec3 hd = d-h;
		glm::vec3 back = glm::cross(hg, hd);
		glm::vec3 back_orig = maximum_;
		//links
			//ac
			//ae
		glm::vec3 left = glm::cross(ac, ae);
		glm::vec3 left_orig = minimum_;
		//rechts		
			//hd
			//hf
		glm::vec3 right = glm::cross(hd, hf);
		glm::vec3 right_orig = maximum_;
		
				//Normalize: glm::vec3 minab_normal = glm::normalize(minab_dir);
		bottom = glm::normalize(bottom);
		top = glm::normalize(top);
		front = glm::normalize(front);
		back = glm::normalize(back);
		left = glm::normalize(left);
		right = glm::normalize(right);
		



		//Intersetion MINab
		glm::intersectRayPlane(test.origin, tempvec,
		bottom_orig, bottom, temp);	
		std::cout<<temp<< std::endl;
		shortest_distance = temp;
		if (temp>-9223372036854775807&&temp<9223372036854775807){is_intersected = true;}
		std::cout<<temp<<std::endl;			
		//Intersetion MINac
		glm::intersectRayPlane(test.origin, tempvec,
		top_orig, top, temp);
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;	
		}
		std::cout<<temp<<std::endl;
		//Intersetion MINbc
		glm::intersectRayPlane(test.origin, tempvec,
		front_orig, front, temp);
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;
		}
		std::cout<<temp<<std::endl;
		//Intersetion MAXab
		glm::intersectRayPlane(test.origin, tempvec,
		back_orig, back, temp);	
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;
		}	
		std::cout<<temp<<std::endl;
		//Intersetion MAXac
		glm::intersectRayPlane(test.origin, tempvec,
		left_orig, left, temp);		
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;
		}			
		std::cout<<temp<<std::endl;
		//Intersetion MAXbc
		glm::intersectRayPlane(test.origin, tempvec,
		right_orig, right, temp);		
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;
			is_intersected = true;	
		}	
		std::cout<<temp<<std::endl;
		shortest_distance = temp;
		return is_intersected;

	}
	/*
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
		std::cout<<"Direction normalized:"<<tempvec.x<<tempvec.y<<tempvec.z<< "end"<<temp<<std::endl;
			std::cout<<" MinABaktualisiermal: "<<minab_normal.x<<" "<< minab_normal.y<< " "<<
			minab_normal.z<<std::endl;  
			std::cout<<" MinACaktualisiermal: "<<minac_normal.x<<" "<< minac_normal.y<<" "<< 
			minac_normal.z<<std::endl;
			std::cout<<" MinBCaktualisiermal: "<<minbc_normal.x<<" "<< minbc_normal.y<<" "<< 
			minbc_normal.z<<std::endl;
			std::cout<<" MaxABaktualisiermal: "<<maxab_normal.x<<" "<< maxab_normal.y<<" "<< 
			maxab_normal.z<<std::endl;
			std::cout<<" MaxACaktualisiermal: "<<maxac_normal.x<<" "<< maxac_normal.y<< " "<<
			maxac_normal.z<<std::endl;
			std::cout<<" MaxBCaktualisiermal: "<<maxbc_normal.x<<" "<< maxbc_normal.y<< " "<<
			maxbc_normal.z<<std::endl;


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
	* */

/*~~~~~~~BOX~~~~~~~~~~~~*/
	
