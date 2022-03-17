
# 42 So Long
![Language](https://img.shields.io/static/v1?label=language&message=c&color=blue) ![Licence](https://img.shields.io/badge/license-MIT-green) ![Score](https://42-project-badge.glitch.me/users/rpinto-r/project/so-long) [![norminette](https://github.com/ricardoreves/42-Project-Template/actions/workflows/norminette.yml/badge.svg)](https://github.com/ricardoreves/42-so-long/actions/workflows/norminette.yml) 

## 🪧 Overview
This project is a very small 2D game with [minilibx](https://harm-smits.github.io/42docs/libs/minilibx). Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

## 📷 Preview
![preview](imgs/preview.png)

## 🚀 Getting Started

### Prerequisites

MiniLibX for Linux requires xorg, x11 and zlib, therefore you will need to install the following dependencies: xorg, libxext-dev and zlib1g-dev. Installing these dependencies on Ubuntu can be done as follows:
```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Installation
1. Clone the project.
```
git clone git@github.com:ricardoreves/42-so-long.git
```
2. Navigate to the project directory.
```
cd 42-so-long
```
3. Compile the game. (You can ignore the Minilibx compilation warning)
```
make
```

## 🕹 Usage
1. Start the game with a [map](maps/).
```
./so_long maps/42.ber
```
2. Move the player and collect objects, then go to the exit.
 
| Key | Action     |
| --- | ---------- |
| W   | Move Up    |
| A   | Move Left  |
| S   | Move Down  |
| D   | Move Right |
| R   | Reset Game |
| ESC | Quit Game  |

## 📚 References
- [Github.com](https://harm-smits.github.io/42docs/libs/minilibx) - Minilibx documentation
- [Github.com](https://github.com/S-LucasSerrano/miniLibX_sample) - Sample Minilibx project
- [Github.com](https://gontjarow.github.io/MiniLibX/) - Introduction to Minilibx
- [Github.com](https://github.com/keuhdall/images_example) - Implementation of images with Minilibx
- [Itch.io](https://itch.io/game-assets) - Platform that host game assets. 

## 🧰 Tools
- [Anyconv.com](https://anyconv.com/xpm-converter/) - Online tool to convert images PNG to XPM
- [Ezgif.com](https://ezgif.com/sprite-cutter/) - Online tool to cut sprite images
- [ImageMagick](https://imagemagick.org/) - Command-line tool to convert, edit, or compose digital images

## 📝 License
Distributed under the MIT License. See [LICENSE](LICENSE) for more information.


