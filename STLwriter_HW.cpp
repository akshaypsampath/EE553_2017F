#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Shape {
    double x;
    double y;
    double z;
public:

    Shape(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}
    virtual void makeSTL(const char *)=0;
    
    double getX(){return x;}
    double getY(){return y;}
    double getZ(){return z;}
};

class Cylinder : public Shape{
private:
	double r, h;
	int facets;
public:
	Cylinder(double x, double y, double z, double r, double h, int facets): Shape(x,y,z), r(r), h(h), facets(facets) {}
        void makeSTL(const char * fileName)
        {
            double theta=360/facets;
            
            cout <<"CylinderMake"; //file<<"hello";
            cout <<"theta= " <<theta <<endl;
            fstream file(fileName, ofstream::app);
           
            
            for(int i=0; i<facets; i++)
            {
                file<<"  facet normal 0 0 -1" <<endl;
                file<<"    outer loop" <<endl;
                file<<"       vertex " <<getX() <<" " <<getY() <<" " <<getZ() <<endl;
                file<<"       vertex " <<getX()+r*cos(theta*(i+1)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i+1)*(3.14159/180)) <<" " <<getZ() <<endl;                
                file<<"       vertex " <<getX()+r*cos(theta*i*(3.14159/180)) <<" " <<getY()+r*sin(theta*i*(3.14159/180)) <<" " <<getZ() <<endl;                
                file<<"    endloop" <<endl;
                file<<"  endfacet" <<endl;
            }
            
            for(int i=facets-1; i>=0; i--)
            {
                file<<"  facet normal " <<cos((theta*i+(theta/2))*(3.14159/180)) <<" " <<sin((theta*(i-1)+(theta/2))*(3.14159/180)) <<" 0" <<endl;
                file<<"    outer loop" <<endl;
                file<<"       vertex " <<getX()+r*cos(theta*(i)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i)*(3.14159/180)) <<" " <<getZ() <<endl;
                file<<"       vertex " <<getX()+r*cos(theta*(i+1)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i+1)*(3.14159/180)) <<" " <<getZ() <<endl;
                file<<"       vertex " <<getX()+r*cos(theta*(i+1)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i+1)*(3.14159/180)) <<" " <<getZ()+h <<endl;
                file<<"    endloop" <<endl;
                file<<"  endfacet" <<endl;
                
                file<<"  facet normal " <<cos((theta*i+(theta/2))*(3.14159/180)) <<" " <<sin((theta*(i-1)+(theta/2))*(3.14159/180)) <<" 0" <<endl;
                file<<"    outer loop" <<endl;
                file<<"       vertex " <<getX()+r*cos(theta*(i+1)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i+1)*(3.14159/180)) <<" " <<getZ()+h <<endl; 
                file<<"       vertex " <<getX()+r*cos(theta*(i)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i)*(3.14159/180)) <<" " <<getZ()+h <<endl;
                file<<"       vertex " <<getX()+r*cos(theta*(i)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i)*(3.14159/180)) <<" " <<getZ() <<endl;
                file<<"    endloop" <<endl;
                file<<"  endfacet" <<endl;
            }
            
            for(int i=0; i<facets; i++)
            {
                file<<"  facet normal 0 0 -1" <<endl;
                file<<"    outer loop" <<endl;
                file<<"       vertex " <<getX() <<" " <<getY() <<" " <<getZ()+h <<endl;
                file<<"       vertex " <<getX()+r*cos(theta*(i+1)*(3.14159/180)) <<" " <<getY()+r*sin(theta*(i+1)*(3.14159/180)) <<" " <<getZ()+h <<endl;                
                file<<"       vertex " <<getX()+r*cos(theta*i*(3.14159/180)) <<" " <<getY()+r*sin(theta*i*(3.14159/180)) <<" " <<getZ()+h <<endl;                
                file<<"    endloop" <<endl;
                file<<"  endfacet" <<endl;
            }
           //file<<"solid Cylinder";
        }
};

class Cube: public Shape {
private:
	double size;

public:
	Cube(double x, double y, double z, double size) : Shape(x,y,z), size(size) {}
        
        void makeSTL(const char * fileName)
        {
            cout <<"CubeMake";
            
            fstream file(fileName, ofstream::app);
            
            //file<<"solid Cube" <<count <<'\n';

            
            file<<"  facet normal 0 0 -1" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ() <<endl;
            file<<"      vertex " <<getX() <<" " <<getY() <<" " <<getZ() <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY() <<" " <<getZ() <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            file<<"  facet normal 0 0 -1" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY() <<" " <<getZ() <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size <<" " <<getZ() <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ() <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            
            file<<"  facet normal 0 1 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size <<" " <<getZ() <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size <<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ() <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            file<<"  facet normal 0 1 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size <<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ() <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            
            file<<"  facet normal -1 0 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()<<" " <<getZ() <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ()<<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ()+size <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            file<<"  facet normal -1 0 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()<<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX() <<" " <<getY() <<" " <<getZ() <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            
            file<<"  facet normal 0 -1 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()<<" " <<getZ() <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()<<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY() <<" " <<getZ()+size <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            file<<"  facet normal 0 -1 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()<<" " <<getZ()<<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()<<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY() <<" " <<getZ() <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            
            file<<"  facet normal 1 0 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()<<" " <<getZ() <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY() <<" " <<getZ()+size<<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size <<" " <<getZ()<<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            file<<"  facet normal 1 0 0" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY() <<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size<<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size <<" " <<getZ() <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            
            file<<"  facet normal 0 0 1" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()+size <<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY()<<" " <<getZ()+size<<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size <<" " <<getZ()+size <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            file<<"  facet normal 0 0 1" <<endl;
            file<<"    outer loop" <<endl;
            file<<"      vertex " <<getX() <<" " <<getY() <<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX() <<" " <<getY()+size<<" " <<getZ()+size <<endl;
            file<<"      vertex " <<getX()+size <<" " <<getY() <<" " <<getZ()+size <<endl;
            file<<"    endloop" <<endl;
            file<<"  endfacet"<<endl;
            
            
            //file<<"endsolid Cube"<<count <<endl;
            
            //count++;
            file.close();
            
        }
};

class CAD {
private:
	vector<Shape*> shapes;
public:
    void add(Cube* s1)
    {
        shapes.push_back(s1);
        
    }
    void add(Cylinder* s1)
    {
        shapes.push_back(s1);
        
    }
    void write(const char* fileName)
    {
        ofstream file(fileName);

        file<<"solid Akshay" <<'\n';
        
        file.close();
        
        for(int i=0; i<shapes.size(); i++)
        {
            shapes[i]->makeSTL(fileName);
        }
        
        file.open(fileName, ofstream::app);

        file<<"endsolid Akshay" <<'\n';
        
        file.close();
        //ofstream file(fileName);
        
    }
};

//https://www.stratasysdirect.com/resources/how-to-prepare-stl-files/
//https://www.viewstl.com/
int main() {
    cout <<"h2y";
	CAD c;
	c.add(new Cube(0,0,0,10));
	c.add(new Cylinder(100,0,0,3, 10, 10));
        c.add(new Cube(20,20,20,10));
        c.write("test.stl");
  
  
  return 0;
}

