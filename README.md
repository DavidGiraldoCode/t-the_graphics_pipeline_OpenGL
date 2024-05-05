# Graphics Pipeline with OpenGL

The graphics pipeline is the process of transforming (mapping) 3D data into a 2D coordinate system to be displayed into a screen.
The vertex is the single unit, wich holds attributes that allow the piple lo render it: 3D coordinates, color values, normals, etc.

## Over simplification of the process
flowchart LR
   Z[Vextex data] --> 
   A[Vextex Shader] --> 
   B[Rasterization] --> 
   C[Fagment Shader] -->
   D[Render Pixels]

## References
[1] De Vries J.Learn OpenGL. Recover 2024 https://learnopengl.com/ 