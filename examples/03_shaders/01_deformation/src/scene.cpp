#include "scene.hpp"

using namespace cgp;

void scene_structure::initialize()
{
	camera_control.initialize(inputs, window);
	display_info(); // Give access to the inputs and window global state to the camera controler
	camera_control.set_rotation_axis_z();
	camera_control.look_at({ 3.0f, 2.0f, 2.0f }, {0,0,0}, {0,0,1});
	global_frame.initialize_data_on_gpu(mesh_primitive_frame());

	mesh mesh_grid = mesh_primitive_grid({ -1,-1,0 }, { 1,-1,0 }, { 1,1,0 }, { -1,1,0 }, 200, 200);
		
	surface.initialize_data_on_gpu(mesh_grid);	
	surface.material.color = { 0.8f, 0.95f, 1.0f };
	surface.material.texture_settings.two_sided=true;

	// Set the shader with animated deformation
	surface.shader.load(project::path + "shaders/mesh_deformation/mesh_deformation.vert.glsl", project::path + "shaders/mesh_deformation/mesh_deformation.frag.glsl");
}



void scene_structure::display_frame()
{
	camera_projection.aspect_ratio = window.aspect_ratio();
	environment.camera_projection = camera_projection.matrix();
	environment.camera_view = camera_control.camera_model.matrix_view();
	environment.light = camera_control.camera_model.position();
	
	if (gui.display_frame)
		draw(global_frame, environment);

	timer.update();

	// Send current time as a uniform value to the shader
	environment.uniform_generic.uniform_float["time"] = timer.t;

	// Standard draw call
	draw(surface, environment);
	if(gui.display_wireframe)
		draw_wireframe(surface, environment);

}

void scene_structure::display_gui()
{
	ImGui::Checkbox("Frame", &gui.display_frame);
	ImGui::Checkbox("Wireframe", &gui.display_wireframe);
}

void scene_structure::mouse_move_event()
{
	if (!inputs.keyboard.shift)
		camera_control.action_mouse_move();
}
void scene_structure::mouse_click_event()
{
	camera_control.action_mouse_click();
}
void scene_structure::keyboard_event()
{
	camera_control.action_keyboard();
}
void scene_structure::idle_frame()
{
	camera_control.idle_frame();
}

void scene_structure::display_info()
{
	std::cout << "\nCAMERA CONTROL:" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << camera_control.doc_usage() << std::endl;
	std::cout << "-----------------------------------------------\n" << std::endl;

	std::cout << "\nSCENE INFO:" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "This scene demonstrates animated surface deformation driven by a custom vertex shader that receives the current time as a uniform variable." << std::endl;
	std::cout << "-----------------------------------------------\n" << std::endl;
}
