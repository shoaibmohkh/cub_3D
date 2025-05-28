🎮 cub3D — A Retro 3D Game Engine in C | 42 Amman

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
🧠 Project Overview  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

cub3D is a raycasting-based game engine written in C as part of the 42 curriculum.  
Inspired by early FPS games like *Wolfenstein 3D*, this project brings together low-level programming, graphics, and game development—all without external engines.

✨ Achievement: 105/100


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
📌 Objectives & Learning Outcomes  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

✔️ Develop a 3D rendering engine using raycasting  
✔️ Integrate MiniLibX for graphical rendering  
✔️ Apply vector math and trigonometry for projection  
✔️ Parse and validate a custom `.cub` map format  
✔️ Render textures and manage RGB-based color schemes  
✔️ Ensure robust memory management and Norminette compliance  


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
⚙️ Getting Started  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

📥 1. Clone the Repository:  
git clone git@github.com:shoaibmohkh/cub_3D.git  
cd cub_3D  

📦 2. Install Dependencies (Ubuntu/Debian):  
sudo apt update  
sudo apt install cmake libx11-dev libxext-dev libmlx5-dev \  
                 libglfw3 libglfw3-dev libopengl-dev  

💡 macOS users: Use Homebrew to install the equivalents.  

🏗️ 3. Build the Project:  
make  

🎮 4. Run the Game:  
./cub3D maps/good/subject_map.cub  


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
🗺️ Map Format Reference  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

Each `.cub` file contains:  

1️⃣ Texture Paths:  
NO ./textures/north.png  
SO ./textures/south.png  
EA ./textures/east.png  
WE ./textures/west.png  

2️⃣ Colors (R,G,B):  
F 128,128,0     # Floor  
C 255,255,255   # Ceiling  

3️⃣ 2D Grid Map:  
1 - Wall  
0 - Empty Space  
N/S/E/W - Player Spawn & Direction  

Example:  
111111  
100001  
10N001  
100001  
111111  


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
🕹️ Game Controls  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

Key           | Action  
--------------|---------------------  
W / A / S     | Move player  
← / →         | Rotate viewpoint  
ESC           | Quit the game  
Close Window  | Exit safely  


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
🔥 Features & Highlights  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

🎯 Real-time raycasting engine  
🎯 Directional texture mapping (N/S/E/W)  
🎯 Customizable wall textures and RGB floor/ceiling  
🎯 Interactive minimap overlay  
🎯 Smooth player movement and rotation  
🎯 Clean memory management with graceful shutdown  


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
📁 Project Layout  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

cub3D/  
├── inc/         # Header files  
├── libft/       # Custom utility library  
├── MLX42/       # MiniLibX graphics library  
├── maps/        # Sample `.cub` maps  
├── src/         # Core source code  
├── textures/    # Game textures  
├── obj/         # Build artifacts  
├── Makefile     # Build configuration  
├── .supp        # Leak suppressions for mlx42  
└── README.txt   # Project documentation  


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
👤 Author Info  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

Name: Shoaib Al-kawaldeh  
GitHub: https://github.com/shoaibmohkh  
Campus: 42 Amman  


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  
🌟 Like What You See?  
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  

⭐️ Star the repository if it inspired you!  
Happy coding and game building!
