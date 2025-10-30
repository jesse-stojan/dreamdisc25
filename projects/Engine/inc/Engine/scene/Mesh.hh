// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_SCENE_MESH_HH
#define DD25_ENGINE_SCENE_MESH_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

// Include Third-Party Library Headers
#include <sh4zam/shz_sh4zam.hpp>

//================================================================

using Point2d			= shz::vec2;
using Point3d			= shz::vec3;
using Vertex			= shz::vec3;
using Vec2f				= shz::vec3;
using Vec3f				= shz::vec3;
using Vec4f				= shz::vec3;
using UV				= shz::vec2;
using ColorARGB			= shz::vec4;
using Matrix4			= shz::mat4x4;

//================================================================

class EntityTransform {
public:
	// Default Constructor
	EntityTransform();

	// Copy Constructor
	EntityTransform(const EntityTransform& other);

	// Move Constructor
	EntityTransform(EntityTransform&& other);

	// Destructor
	~EntityTransform() noexcept;

	// Copy Assignment Operator
	// EntityTransform operator=(const EntityTransform& rhs);

	// Move Assignment Operator
	// EntityTransform operator=(EntityTransform&& rhs);

	// translate();
	// rotate();
	// scale();
	// skew();

private:
	Vec3f		mPos;	// Position
	Vec3f		mRot;	// Rotation
	Vec3f		mSca;	// Scale
	Vec3f		mSkw;	// Skew
};

//================================================================

class Bone {
public:
	// Default Constructor
	Bone();

	// Destructor
	~Bone() noexcept;

private:
	EntityTransform		mXform;	// Transform
	Point3d				mPt[2];	// Start and End Points (3D)
	float				mMass;	// Mass in Kilograms
};

//================================================================

class Skeleton {
public:

private:

};

//================================================================

class Mesh {
public:
	// Default Constructor
	Mesh();

	// Destructor
	~Mesh() noexcept;

private:
	size_t		mLen;
	Vertex*		mVerts;
	shz_vec2*	mWeights;
	shz_vec3*	mNormals;
	UV*			mUVs;
	uint16_t*	mIDs;
	Matrix4 	mObjMatrix;
};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_SCENE_MESH_HH
//////////////////////////////////////////////////////////////////
