# Sine Wave

Sine wave animation with OpenGL in C++

## Explanation

Algorithm is fairly simple actualy.

- *y = objects y position*

- *i = iteration*

- `y = sin i`

![Sine Graph](https://upload.wikimedia.org/wikipedia/commons/thumb/0/02/Simple_sine_wave.svg/1200px-Simple_sine_wave.svg.png "Sine Graph")

Sine trigonometric function follows same pattern.

```matlab
sin 0 = 0

sin 90 = 1

sin 180 = 0

sin 270 = -1
```

So the y position of object is gonna be the numbers between -1 and 1 and it will animate over it!

## Installation

First you must install `gl`, `glut` libraries and `build-essential` package. Then you can build and run with following commands.

```bash
# clone and enter directory
git clone https://github.com/Gl1tchs/sinewave.git
cd sinewave

# build files
make

# run executable
make run

# if you want to install globally
make install

# or remove from system
make uninstall
```
