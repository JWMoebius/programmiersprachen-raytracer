#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Box.hpp"




	Box::Box()
	:Shape{get_name(), get_color()}, minimum_{0,0,0}, maximum_{0,0,0}
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
			g.y= maximum_.y; //--> passt
			g.z= maximum_.z; //--> passt
		glm::vec3 h = maximum_;	// hinten rechts oben
		
		//unten	Richtungsvektor
		glm::vec3 ab = b-a;
		glm::vec3 ac = c-a;
		glm::vec3 bottom = glm::cross(ab, ac);
		glm::vec3 bottom_orig = minimum_;
		//oben Richtungsvektor
		glm::vec3 hg = g-h;
		glm::vec3 hf = f-h;
		glm::vec3 top	= glm::cross(hg, hf);
		glm::vec3 top_orig = maximum_;
		//vorne Richtungsvektor
			//ab
		glm::vec3 ae = e-a;
		glm::vec3 front = glm::cross(ab, ae);		
		glm::vec3 front_orig = minimum_;
		//hinten Richtungsvektor
			//hg
		glm::vec3 hd = d-h;
		glm::vec3 back = glm::cross(hg, hd);
		glm::vec3 back_orig = maximum_;
		//links Richtungsvektor
			//ac
			//ae

		glm::vec3 left = glm::cross(ac, ae);
		glm::vec3 left_orig = minimum_;
		//rechts Richtungsvektor	
			//hd
			//hf
		glm::vec3 right = glm::cross(hd, hf);
		glm::vec3 right_orig = maximum_;

		//Normalize:
	/*	bottom = glm::normalize(bottom);
		top = glm::normalize(top);
		front = glm::normalize(front);
		back = glm::normalize(back);
		left = glm::normalize(left);
		right = glm::normalize(right);
		*/
		//Intersection BOTTOM
		glm::intersectRayPlane(test.origin, tempvec,
		bottom_orig, bottom, temp);	
		shortest_distance = temp;
		if (temp>-9223372036854775807&&temp<9223372036854775807){is_intersected = true;}		
		//Intersection TOP
		glm::intersectRayPlane(test.origin, tempvec,
		top_orig, top, temp);
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;	
		}
		//Intersection FRONT
		glm::intersectRayPlane(test.origin, tempvec,
		front_orig, front, temp);
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;
		}
		//Intersection BACK
		glm::intersectRayPlane(test.origin, tempvec,
		back_orig, back, temp);	
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;			
		}	

		//Intersection LEFT
		glm::intersectRayPlane(test.origin, tempvec,
		left_orig, left, temp);		
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;	
			is_intersected = true;
		}			

		//Intersection RIGHT
		glm::intersectRayPlane(test.origin, tempvec,
		right_orig, right, temp);		
		if (temp<shortest_distance&&temp>-9223372036854775807&&temp<9223372036854775807){
			shortest_distance = temp;
			is_intersected = true;	
		}	

		return is_intersected;

	}




		


/*~~~~~~~BOX~~~~~~~~~~~~*/
	
