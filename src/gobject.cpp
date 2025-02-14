#include "gobject.h"

#include <godot_cpp/core/class_db.hpp>

void Gobject::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_mass", "p_mass"), &Gobject::set_mass);
    ClassDB::bind_method(D_METHOD("get_mass"), &Gobject::get_mass);
    ClassDB::bind_method(D_METHOD("set_density", "p_density"), &Gobject::set_density);
    ClassDB::bind_method(D_METHOD("get_density"), &Gobject::get_density);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mass"), "set_mass", "get_mass");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "density"), "set_density", "get_density");

};

void Gobject::set_mass(double p_mass) {
    mass = p_mass;
};
double Gobject::get_mass() {
    return mass;
};

void Gobject::set_density(double p_density) {
    density = p_density;
};
double Gobject::get_density() {
    return density;
};

Gobject::Gobject() {
    mass = 1;
    density = 1;
};
Gobject::~Gobject() {};