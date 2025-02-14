#include "gravity_calculator.h"

#include <godot_cpp/core/class_db.hpp>


void GravityCalculator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_accel", "pos1", "pos2", "mass"), &GravityCalculator::get_accel);
    ClassDB::bind_method(D_METHOD("set_G", "G_p"), &GravityCalculator::set_G);
    ClassDB::bind_method(D_METHOD("get_G"), &GravityCalculator::get_G);
    ClassDB::bind_method(D_METHOD("apply_accel", "body", "delta"), &GravityCalculator::apply_accel);
    ClassDB::bind_method(D_METHOD("apply_accel_to_all", "delta"), &GravityCalculator::apply_accel_to_all);

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

void GravityCalculator::apply_accel(Node* p_body, double delta) {
    size_t l = get_child_count();

    CharacterBody2D* body = Object::cast_to<CharacterBody2D>(p_body);
    Vector2 velocity = (*body).get_velocity();

    for (size_t i = 0; i < l; i++) {
        Node* child_node = get_child(i);
        CharacterBody2D* child_body = Object::cast_to<CharacterBody2D>(child_node);
        velocity += get_accel((*body).get_global_position(), (*child_body).get_global_position(), 1) * delta;
    }
    (*body).set_velocity(velocity);
}

void GravityCalculator::apply_accel_to_all(double delta) {
    size_t l = get_child_count();
    for (size_t j = 0; j < l; j++) {
        Node* child_node = get_child(j);
        apply_accel(child_node, delta);

        CharacterBody2D* child_body = Object::cast_to<CharacterBody2D>(child_node);
        (*child_body).move_and_collide((*child_body).get_velocity());
    }
}

GravityCalculator::GravityCalculator() {
    G = 1;
}

void GravityCalculator::_physics_process(double delta) {

    
    apply_accel_to_all(delta);

}