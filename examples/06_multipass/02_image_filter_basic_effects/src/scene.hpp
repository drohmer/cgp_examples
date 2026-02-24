#pragma once

#include "cgp/cgp.hpp"
#include "environment.hpp"

#include "multipass_structure/multipass_structure.hpp"
#include "scene_elements/scene_elements.hpp"

using cgp::mesh_drawable;

struct gui_parameters {
	bool display_frame = true;
	bool display_wireframe = false;
};

// The structure of the custom scene
struct scene_structure : cgp::scene_inputs_generic {

	// ****************************** //
	// Standard Functions
	// ****************************** //

	void initialize();
	void display_frame();
	void display_gui();

	void display_info();

	// ****************************** //
	// Context
	// ****************************** //

	environment_structure environment;   // Standard environment controler
	window_structure window;
	input_devices inputs;                // Storage for inputs status (mouse, keyboard, window dimension)
	gui_parameters gui;                  // Standard GUI element storage

	// ****************************** //
	// Camera controler
	// ****************************** //

	camera_controller_orbit_euler camera_control;
	camera_projection_perspective camera_projection;

	// ****************************** //
	// Elements and shapes of the scene
	// ****************************** //

	mesh_drawable global_frame;          // The standard global frame

	timer_basic timer;

	scene_elements_structure scene_elements;

	cgp::skybox_drawable skybox;

	multipass_structure multipass_rendering;

	// ****************************** //
	// Callback functions
	// ****************************** //

	void mouse_move_event();
	void mouse_click_event();
	void keyboard_event();
	void idle_frame();

};
