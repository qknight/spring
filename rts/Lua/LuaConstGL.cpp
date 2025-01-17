/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaConstGL.h"

#include "LuaInclude.h"

#include "LuaUtils.h"
#include "Rendering/GL/myGL.h"


/******************************************************************************/
/******************************************************************************/

bool LuaConstGL::PushEntries(lua_State* L)
{
#define PUSH_GL(cmd) LuaPushNamedNumber(L, #cmd, GL_ ## cmd)

	// Drawing Primitives
	PUSH_GL(POINTS);
	PUSH_GL(LINES);
	PUSH_GL(LINE_LOOP);
	PUSH_GL(LINE_STRIP);
	PUSH_GL(TRIANGLES);
	PUSH_GL(TRIANGLE_STRIP);
	PUSH_GL(TRIANGLE_FAN);
	PUSH_GL(QUADS);
	PUSH_GL(QUAD_STRIP);
	PUSH_GL(POLYGON);

	PUSH_GL(LINE_STRIP_ADJACENCY);
	PUSH_GL(LINES_ADJACENCY);
	PUSH_GL(TRIANGLE_STRIP_ADJACENCY);
	PUSH_GL(TRIANGLES_ADJACENCY);
	PUSH_GL(PATCHES);

	// BlendingFactorDest
	PUSH_GL(ZERO);
	PUSH_GL(ONE);
	PUSH_GL(SRC_COLOR);
	PUSH_GL(ONE_MINUS_SRC_COLOR);
	PUSH_GL(SRC_ALPHA);
	PUSH_GL(ONE_MINUS_SRC_ALPHA);
	PUSH_GL(DST_ALPHA);
	PUSH_GL(ONE_MINUS_DST_ALPHA);

	// BlendingFactorSrc
	// GL_ZERO
	// GL_ONE
	PUSH_GL(DST_COLOR);
	PUSH_GL(ONE_MINUS_DST_COLOR);
	PUSH_GL(SRC_ALPHA_SATURATE);

	// AlphaFunction and  DepthFunction
	PUSH_GL(NEVER);
	PUSH_GL(LESS);
	PUSH_GL(EQUAL);
	PUSH_GL(LEQUAL);
	PUSH_GL(GREATER);
	PUSH_GL(NOTEQUAL);
	PUSH_GL(GEQUAL);
	PUSH_GL(ALWAYS);

	// LogicOp
	PUSH_GL(CLEAR);
	PUSH_GL(AND);
	PUSH_GL(AND_REVERSE);
	PUSH_GL(COPY);
	PUSH_GL(AND_INVERTED);
	PUSH_GL(NOOP);
	PUSH_GL(XOR);
	PUSH_GL(OR);
	PUSH_GL(NOR);
	PUSH_GL(EQUIV);
	PUSH_GL(INVERT);
	PUSH_GL(OR_REVERSE);
	PUSH_GL(COPY_INVERTED);
	PUSH_GL(OR_INVERTED);
	PUSH_GL(NAND);
	PUSH_GL(SET);

	// Culling
	PUSH_GL(BACK);
	PUSH_GL(FRONT);
	PUSH_GL(FRONT_AND_BACK);

	// PolygonMode
	PUSH_GL(POINT);
	PUSH_GL(LINE);
	PUSH_GL(FILL);

	// Clear Bits
	PUSH_GL(DEPTH_BUFFER_BIT);
	PUSH_GL(ACCUM_BUFFER_BIT);
	PUSH_GL(STENCIL_BUFFER_BIT);
	PUSH_GL(COLOR_BUFFER_BIT);

	// ShadeModel
	PUSH_GL(FLAT);
	PUSH_GL(SMOOTH);

	// MatrixMode
	PUSH_GL(MODELVIEW);
	PUSH_GL(PROJECTION);
	PUSH_GL(TEXTURE);

	// Texture Filtering
	PUSH_GL(NEAREST);
	PUSH_GL(LINEAR);
	PUSH_GL(NEAREST_MIPMAP_NEAREST);
	PUSH_GL(LINEAR_MIPMAP_NEAREST);
	PUSH_GL(NEAREST_MIPMAP_LINEAR);
	PUSH_GL(LINEAR_MIPMAP_LINEAR);

	// Texture Clamping
	PUSH_GL(REPEAT);
	PUSH_GL(MIRRORED_REPEAT);
	PUSH_GL(CLAMP);
	PUSH_GL(CLAMP_TO_EDGE);
	PUSH_GL(CLAMP_TO_BORDER);

	// Texture Environment
	PUSH_GL(TEXTURE_ENV);
	PUSH_GL(TEXTURE_ENV_MODE);
	PUSH_GL(TEXTURE_ENV_COLOR);
	PUSH_GL(MODULATE);
	PUSH_GL(DECAL);
	PUSH_GL(BLEND);
	PUSH_GL(REPLACE);
	PUSH_GL(TEXTURE_FILTER_CONTROL);
	PUSH_GL(TEXTURE_LOD_BIAS);

	// Texture Generation
	PUSH_GL(TEXTURE_GEN_MODE);
	PUSH_GL(EYE_PLANE);
	PUSH_GL(OBJECT_PLANE);
	PUSH_GL(EYE_LINEAR);
	PUSH_GL(OBJECT_LINEAR);
	PUSH_GL(SPHERE_MAP);
	PUSH_GL(NORMAL_MAP);
	PUSH_GL(REFLECTION_MAP);
	PUSH_GL(S);
	PUSH_GL(T);
	PUSH_GL(R);
	PUSH_GL(Q);

	// glPushAttrib() bits
	PUSH_GL(CURRENT_BIT);
	PUSH_GL(POINT_BIT);
	PUSH_GL(LINE_BIT);
	PUSH_GL(POLYGON_BIT);
	PUSH_GL(POLYGON_STIPPLE_BIT);
	PUSH_GL(PIXEL_MODE_BIT);
	PUSH_GL(LIGHTING_BIT);
	PUSH_GL(FOG_BIT);
	PUSH_GL(DEPTH_BUFFER_BIT);
	PUSH_GL(ACCUM_BUFFER_BIT);
	PUSH_GL(STENCIL_BUFFER_BIT);
	PUSH_GL(VIEWPORT_BIT);
	PUSH_GL(TRANSFORM_BIT);
	PUSH_GL(ENABLE_BIT);
	PUSH_GL(COLOR_BUFFER_BIT);
	PUSH_GL(HINT_BIT);
	PUSH_GL(EVAL_BIT);
	PUSH_GL(LIST_BIT);
	PUSH_GL(TEXTURE_BIT);
	PUSH_GL(SCISSOR_BIT);
	//PUSH_GL(ALL_ATTRIB_BITS);  // floating point clip
	LuaPushNamedNumber(L, "ALL_ATTRIB_BITS", -1.0f);

	// glHint() targets
	PUSH_GL(FOG_HINT);
	PUSH_GL(PERSPECTIVE_CORRECTION_HINT);
	// glHint() modes
	PUSH_GL(DONT_CARE);
	PUSH_GL(FASTEST);
	PUSH_GL(NICEST);

	// Light Specification
	PUSH_GL(AMBIENT);
	PUSH_GL(DIFFUSE);
	PUSH_GL(SPECULAR);
	PUSH_GL(POSITION);
	PUSH_GL(SPOT_DIRECTION);
	PUSH_GL(SPOT_EXPONENT);
	PUSH_GL(SPOT_CUTOFF);
	PUSH_GL(CONSTANT_ATTENUATION);
	PUSH_GL(LINEAR_ATTENUATION);
	PUSH_GL(QUADRATIC_ATTENUATION);

	// Shader types
	PUSH_GL(VERTEX_SHADER);
	PUSH_GL(TESS_CONTROL_SHADER);
	PUSH_GL(TESS_EVALUATION_SHADER);
	PUSH_GL(GEOMETRY_SHADER_EXT);
	PUSH_GL(FRAGMENT_SHADER);

	// Geometry shader parameters
	PUSH_GL(GEOMETRY_INPUT_TYPE_EXT);
	PUSH_GL(GEOMETRY_OUTPUT_TYPE_EXT);
	PUSH_GL(GEOMETRY_VERTICES_OUT_EXT);
	// Tesselation control shader parameters
	PUSH_GL(PATCH_VERTICES);
	PUSH_GL(PATCH_DEFAULT_OUTER_LEVEL);
	PUSH_GL(PATCH_DEFAULT_INNER_LEVEL);

	// Modern OpenGL data types
	PUSH_GL(BYTE);
	PUSH_GL(UNSIGNED_BYTE);
	PUSH_GL(SHORT);
	PUSH_GL(UNSIGNED_SHORT);
	PUSH_GL(INT);
	PUSH_GL(UNSIGNED_INT);
	PUSH_GL(FLOAT);
	PUSH_GL(FLOAT_VEC4);
	PUSH_GL(INT_VEC4);
	PUSH_GL(UNSIGNED_INT_VEC4);
	PUSH_GL(FLOAT_MAT4);

	//Modern OpenGL buffer types
	PUSH_GL(ELEMENT_ARRAY_BUFFER);
	PUSH_GL(ARRAY_BUFFER);
	PUSH_GL(UNIFORM_BUFFER);
	PUSH_GL(SHADER_STORAGE_BUFFER);

	//Texture targets
	PUSH_GL(TEXTURE_1D);
	PUSH_GL(TEXTURE_2D);
	PUSH_GL(TEXTURE_3D);
	PUSH_GL(TEXTURE_CUBE_MAP);
	PUSH_GL(TEXTURE_2D_MULTISAMPLE);

	//Image formats
	PUSH_GL(RGBA32F);
	PUSH_GL(RGBA16F);
	PUSH_GL(RG32F);
	PUSH_GL(RG16F);
	PUSH_GL(R11F_G11F_B10F);
	PUSH_GL(R32F);
	PUSH_GL(R16F);
	PUSH_GL(RGBA32UI);
	PUSH_GL(RGBA16UI);
	PUSH_GL(RGB10_A2UI);
	PUSH_GL(RGBA8UI);
	PUSH_GL(RG32UI);
	PUSH_GL(RG16UI);
	PUSH_GL(RG8UI);
	PUSH_GL(R32UI);
	PUSH_GL(R16UI);
	PUSH_GL(R8UI);
	PUSH_GL(RGBA32I);
	PUSH_GL(RGBA16I);
	PUSH_GL(RGBA8I);
	PUSH_GL(RG32I);
	PUSH_GL(RG16I);
	PUSH_GL(RG8I);
	PUSH_GL(R32I);
	PUSH_GL(R16I);
	PUSH_GL(R8I);
	PUSH_GL(RGBA16);
	PUSH_GL(RGB10_A2);
	PUSH_GL(RGBA8);
	PUSH_GL(RG16);
	PUSH_GL(RG8);
	PUSH_GL(R16);
	PUSH_GL(R8);
	PUSH_GL(RGBA16_SNORM);
	PUSH_GL(RGBA8_SNORM);
	PUSH_GL(RG16_SNORM);
	PUSH_GL(RG8_SNORM);
	PUSH_GL(R16_SNORM);
	PUSH_GL(R8_SNORM);

	//access specifiers
	PUSH_GL(READ_ONLY);
	PUSH_GL(WRITE_ONLY);
	PUSH_GL(READ_WRITE);

	//memory barrier bits
	PUSH_GL(VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
	PUSH_GL(ELEMENT_ARRAY_BARRIER_BIT);
	PUSH_GL(UNIFORM_BARRIER_BIT);
	PUSH_GL(TEXTURE_FETCH_BARRIER_BIT);
	PUSH_GL(SHADER_IMAGE_ACCESS_BARRIER_BIT);
	PUSH_GL(COMMAND_BARRIER_BIT);
	PUSH_GL(PIXEL_BUFFER_BARRIER_BIT);
	PUSH_GL(TEXTURE_UPDATE_BARRIER_BIT);
	PUSH_GL(BUFFER_UPDATE_BARRIER_BIT);
	PUSH_GL(FRAMEBUFFER_BARRIER_BIT);
	PUSH_GL(TRANSFORM_FEEDBACK_BARRIER_BIT);
	PUSH_GL(ATOMIC_COUNTER_BARRIER_BIT);
	PUSH_GL(SHADER_STORAGE_BARRIER_BIT);
	PUSH_GL(ALL_BARRIER_BITS);

	//GL_XXXX_ATTACHMENT
	PUSH_GL(COLOR_ATTACHMENT0);
	PUSH_GL(COLOR_ATTACHMENT1);
	PUSH_GL(COLOR_ATTACHMENT2);
	PUSH_GL(COLOR_ATTACHMENT3);
	PUSH_GL(COLOR_ATTACHMENT4);
	PUSH_GL(COLOR_ATTACHMENT5);
	PUSH_GL(COLOR_ATTACHMENT6);
	PUSH_GL(COLOR_ATTACHMENT7);
	PUSH_GL(COLOR_ATTACHMENT8);
	PUSH_GL(COLOR_ATTACHMENT9);
	PUSH_GL(COLOR_ATTACHMENT10);
	PUSH_GL(COLOR_ATTACHMENT11);
	PUSH_GL(COLOR_ATTACHMENT12);
	PUSH_GL(COLOR_ATTACHMENT13);
	PUSH_GL(COLOR_ATTACHMENT14);
	PUSH_GL(COLOR_ATTACHMENT15);
	PUSH_GL(DEPTH_ATTACHMENT);
	PUSH_GL(STENCIL_ATTACHMENT);
	PUSH_GL(COLOR_ATTACHMENT0_EXT);
	PUSH_GL(COLOR_ATTACHMENT1_EXT);
	PUSH_GL(COLOR_ATTACHMENT2_EXT);
	PUSH_GL(COLOR_ATTACHMENT3_EXT);
	PUSH_GL(COLOR_ATTACHMENT4_EXT);
	PUSH_GL(COLOR_ATTACHMENT5_EXT);
	PUSH_GL(COLOR_ATTACHMENT6_EXT);
	PUSH_GL(COLOR_ATTACHMENT7_EXT);
	PUSH_GL(COLOR_ATTACHMENT8_EXT);
	PUSH_GL(COLOR_ATTACHMENT9_EXT);
	PUSH_GL(COLOR_ATTACHMENT10_EXT);
	PUSH_GL(COLOR_ATTACHMENT11_EXT);
	PUSH_GL(COLOR_ATTACHMENT12_EXT);
	PUSH_GL(COLOR_ATTACHMENT13_EXT);
	PUSH_GL(COLOR_ATTACHMENT14_EXT);
	PUSH_GL(COLOR_ATTACHMENT15_EXT);
	PUSH_GL(DEPTH_ATTACHMENT_EXT);
	PUSH_GL(STENCIL_ATTACHMENT_EXT);

	return true;
}


/******************************************************************************/
/******************************************************************************/
