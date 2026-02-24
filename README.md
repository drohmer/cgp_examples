# CGP library example codes

This repository describes a set of code examples for the [CGP Library](https://imagecomputing.net/cgp/).

* [Examples Website](https://imagecomputing.net/cgp/documentation/07_examples/index.html)

## Examples

| Directory | Description |
|-----------|-------------|
| `examples/01_transparent_billboards` | Transparent billboards — shader-based partly transparent textures (foliage) |
| `examples/02_marching_cubes/01_marching_cube_simple` | Marching Cubes (simple static version) |
| `examples/02_marching_cubes/02_marching_cube_dynamic` | Marching Cubes (interactive/dynamic version) |
| `examples/03_shaders/01_deformation` | Shader-based mesh deformation |
| `examples/03_shaders/02_multi_texture` | Multiple textures in a single shader |
| `examples/04_sketch/02_2d_curve` | 2D curve sketch |
| `examples/05_environment_map/01_skybox` | Skybox rendering |
| `examples/05_environment_map/02_environment_map` | Environment mapping / reflections |
| `examples/06_multipass/01_image_filter` | Image filter (multipass rendering) |
| `examples/06_multipass/02_image_filter_basic_effects` | Basic image filter effects |
| `examples/06_multipass/03_image_filters_chain` | Chained image filter pipeline |
| `examples/06_multipass/04_shadow_mapping` | Shadow mapping |
| `examples/07_camera/01_camera_fly_mode` | Fly-mode camera navigation (arrow keys) |
| `examples/07_camera/02_camera_2d_displacement` | 2D displacement camera mode |
| `examples/07_camera/03_multiple_cameras` | Multiple cameras in the same scene |
| `examples/08_instancing/01_instancing_position` | Instancing — large quantity of shapes by position |
| `examples/08_instancing/02_instancing_procedural` | Instancing — procedurally placed shapes |
| `examples/09_mesh_loading` | Advanced OBJ mesh loading (tinyobjloader) |

## Compilation

Each example is an independent project located in its own directory. Navigate into the example you want to build before following the instructions below.

### Linux / macOS — CMake


```bash
cd examples/01_transparent_billboards
mkdir build && cd build
cmake ..
make
cd ..
./project
```

### Linux / macOS — Makefile


```bash
cd examples/01_transparent_billboards

make        # build
make run    # build and run
make clean  # remove build artefacts
```

### Windows — Visual Studio (CMake)

**Prerequisites:** [CMake](https://cmake.org/) and Visual Studio (any recent version).

1. Open a file explorer and navigate into the example directory.
2. Double-click **`scripts/visual-studio-generate.bat`** (or run it from a terminal).
   The script will:
   - Create a `build/` directory if it does not already exist.
   - Run `cmake ..` inside `build/` to generate a Visual Studio solution.
3. Open the `.sln` file produced inside `build/`.
4. Build and run the project from Visual Studio.

> To target a specific Visual Studio version you can edit the `.bat` file and replace the `cmake ..` call with `cmake -G "Visual Studio 17 2022" ..` (adjust the year/version as needed).
