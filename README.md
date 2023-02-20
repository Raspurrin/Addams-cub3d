# Escape Addam's cub3d

### Index:

+ [Description](#description) 
+ [Controls](#controls) 
+ [Currently featuring](#currently-featuring)
+ [Future additions](#future-additions)
+ [Input](#input)

## Description
This is a raycasting engine. It is pretty bare bones, I don't have enough time to make it amazing atm,
BUT this will eventually become a Addam's family themed escape room! :D


## Controls
- WASD for walking around.
- arrow keys or mouse for looking around. With the mouse you can control the speed of rotation.
- Spacebar for pausing the game and unlocking the cursor to be used freely.


## Currently featuring
- Smoothment! You can press multiple movement keys at the same time with no delay!

https://user-images.githubusercontent.com/13866954/220087668-fa7b8233-d96a-4956-a566-6f538ef558c1.mp4

## Input
To run the game type: 
```
make
./cub3d maps/rave.cub
``` 

The input map has to start with a legenda, which gives a path to textures used for North, South, West and East, seperately 
and colours for the ceiling and the roof.
Afterwards a map is given where: 1 = wall, 0 = empty tile, N = player facing north (and S, W and E in the same manner)
This can be in any shape as long as the map is enclosed by walls.

You can find more maps in the map folder, including wrong ones to showcase possible errors.

## Future additions
- Minimap
- Animated sprites
- Doors
- Audio
- HUD
