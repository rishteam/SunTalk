#include "sol.hpp"

#include <bits/stdc++.h>
#include "assert.hpp"

class Point{
public:
    
    Point() = default;
    Point(float x, float y){
        m_x = x;
        m_y = y;
    }
    
    void setPos(float x, float y) {
        m_x = x;
        m_y = y;
    }

    void printPos(){
        std::cout << m_x << " " << m_y << std::endl;
    }

    float getX(){
        return m_x;
    }
    float getY(){
        return m_y;
    }

private:
    float m_x,m_y;

};

void Point_Lua(sol::state &lua){

    lua.new_usertype<Point>("Point",
                            sol::constructors<Point(),Point(float,float)>(),
                            "setPos", &Point::setPos,
                            "printPos", &Point::printPos,
                            "getX", &Point::getX,
                            "getY", &Point::getY);
};

class Body{

public:

    Body() = default;
    Body(Point center){
        m_center = center;
    }

    void setCenter(Point center){
        m_center = center;
    }

    virtual void TestVirtual(){
        std::cout << "Body Class\n"; 
    }

protected:
    Point m_center;

};

void Body_Lua(sol::state &lua){

    lua.new_usertype<Body>("Body",
                           sol::constructors<Body(), Body(Point)>(),
                           "setCenter", &Body::setCenter,
                            "TestVirtual", &Body::TestVirtual);
}

class Rect: public Body{

public:

    Rect() = default;
    Rect(Point center, float width, float height){
        m_center = center;
        m_width = width;
        m_height = height;
    }

    virtual void TestVirtual() override{
        std::cout << "Rect Class\n";
    }

    void printData(){
        m_center.printPos();
        std::cout << m_width << " " << m_height << std::endl;
    }

private:
    float m_width,m_height;

};

void Rect_Lua(sol::state &lua){

    lua.new_usertype<Rect>("Rect",
                           sol::constructors<Rect(), Rect(Point, float, float)>(),
                           "setCenter", &Body::setCenter,
                           "TestVirtual", &Rect::TestVirtual,
                           "TestVirtualBody", &Body::TestVirtual,
                           "printData", &Rect::printData);
}

void showTable(sol::table T){

    if( !T.valid() || T.empty() )
        return;

    for(auto& kv : T){
        sol::object key = kv.first;
        sol::object val = kv.second;
        printf("key type : %d, val type : %d\n", key.get_type(), val.get_type());
        switch (key.get_type()){
            case sol::type::number:
                break;
            case sol::type::string:
                break;
        }

        switch (val.get_type()){
            case sol::type::number:
                break;
            case sol::type::string:
                break;
            case sol::type::table:
                break;
        }
    }

}

int main(){

    sol::state lua;

    lua.open_libraries(sol::lib::base);
    lua.open_libraries(sol::lib::package);

    Point_Lua(lua);
    Body_Lua(lua);
    Rect_Lua(lua);

    lua.set_function("showTable", showTable);

    // lua.script_file("test_sol2.lua");

    lua.script("A = {1,2,3,4}");
    lua.script("B = {a = 1, b = 2}");
    lua.script("showTable(A)");
    lua.script("showTable(B)");

    enum Color{
        RED,
        BLUE,
        GREEN
    };
    
    lua["Color"] = lua.create_table_with("RED", RED, "GREEN", GREEN, "BLUE", BLUE);
    lua.script("A = Color.GREEN"); 
    int A = lua["A"];

    std::cout << A << std::endl;

    return 0;
}