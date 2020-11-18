# fdf : A 42 Silicon Valley Wireframe Rasterizer

![screenshot](/screenshots/42.png?raw=true)

A program that reads a topographic map structured as a text file (examples in /maps/) and produces an interactive 3D wireframe model.

This is the first project in the graphics branch of the old (pre-2020) curriculum at 42 Silicon Valley. It's built using the `minilibx` C library (as per the assignment's instructions) which provides very basic graphics functions, like opening a window and drawing a pixel in that window. View the assignment [here](https://github.com/jakemgilfix/ft_fdf-Wireframe-Rasterizer/blob/master/fdf.en.pdf).

As with all 42 Silicon Valley projects, all code must comply with [42's style guide or 'Norme'](https://github.com/jakemgilfix/ft_fdf-Wireframe-Rasterizer/blob/master/norme.en.pdf). I would be remiss not to mention that this style guide is extremely dated and forces arbitrary constraints (e.g., 25 lines per function, 5 functions per file) that, however well-intended, often result in sub-optimal code.

## Features (required for project)
* Only C Standard Library functions allowed are: `open()`, `read()`, `write()`, `close()`, `malloc()`, `free()`, `perror()`, `strerror()`, `exit()`, and all of the functions within the `math` library.
* 2 built-in projection types: parallel and iso

## Bonus Features (implemented for extra credit)
* Camera controls: rotation in 3D, translation, and zoom
* Simple keybindings for camera controls (shown in sidebar)
* Pretty gradient coloring

## Compiling and Running
Currently only tested on MacOS 10.13+.

Run `make` in the root directory to compile the project, leaving an executable which will be named `fdf`.

After compiling, simply run `./fdf <path_to_map_file>`. Sample maps are provided in the /maps/ directory. Controls will be shown on the sidebar of the main window.
