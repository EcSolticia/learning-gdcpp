#include "gravity_calculator.h"

#include <godot_cpp/core/class_db.hpp>

void GravityCalculator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_accel", "pos1", "pos2", "mass"), &GravityCalculator::get_accel);
    ClassDB::bind_method(D_METHOD("set_G", "G_p"), &GravityCalculator::set_G);
    ClassDB::bind_method(D_METHOD("get_G"), &GravityCalculator::get_G);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "G"), "set_G", "get_G");
}

Vector2 GravityCalculator::get_accel(Vector2 pos1, Vector2 pos2, double mass) {
    Vector2 final = Vector2();
    Vector2 r_vec = pos2 - pos1;
    double r = r_vec.length();
    if (r == 0) {return Vector2();}

    double Gm_w = G * mass;

    return Gm_w * (1/pow(r, 3)) * r_vec;
}

void GravityCalculator::set_G(double G_p) {
    G = G_p;
}
double GravityCalculator::get_G() {
    return G;
}

GravityCalculator::GravityCalculator() {
    G = 1;
}