#pragma once



#include <memory>

#include "aether/math/rect.h"
#include "aether/core/time.h"

#include "aether/core/ModuleObject.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace aether::render {

	enum class ProjectionMode
	{
		Orthographic,
		Perspective
	};

class Camera : public core::ModuleObject
{
public:

	Camera( core::ModuleObject* o, const glm::fvec2& viewport, ProjectionMode projectionMode )
	    : core::ModuleObject(o)
	{
		Reset(viewport, projectionMode);
    }

	const glm::fmat4& GetViewProjectionMatrix()
	{
		ResolveDirty();
		return m_viewProjectionMatrix;
	}

	void SetProjectionMode(ProjectionMode mode)
	{
		m_projectionMode = mode;
		switch (mode)
		{
		case ProjectionMode::Orthographic:
			m_near = -1.f;
			m_far = 1.f;
			break;
		case ProjectionMode::Perspective:
			m_near = 0.1f;
			m_far = 1000.f;
		}
		SetProjectionDirty();
	}

	void SetPosition(const glm::fvec3& new_position)
	{
		m_position = new_position;
		SetViewDirty();
	}

	void SetPosition(float x, float y, float z)
	{
		m_position = { x, y, z };
		SetViewDirty();
	}

	void Move(float dx, float dy, float dz = 0)
	{
		m_position.x += dx;
		m_position.y += dy;
		m_position.z += dz;
		SetViewDirty();
	}

	void SetScale(float x, float y, float z)
	{
		m_scale = { x, y, z };
		SetViewDirty();
	}

	void SetXRotation(float x)
	{
		rotation.x = x;
		SetViewDirty();
	}

	void SetYRotation(float y)
	{
		rotation.y = y;
		SetViewDirty();
	}

	void SetZRotation(float z)
	{
		rotation.z = z;
		SetViewDirty();
	}

	const glm::fvec3& GetScale() const
	{
		return m_scale;
	}

    const glm::fvec2& GetViewport() const
	{
		return m_viewport;
	}

	aether::math::Rectf GetBoundary() const
	{
		return aether::math::Rectf(m_position.x, m_position.y, m_viewport.x, m_viewport.y);
	}

	glm::fvec3 GetPosition() const
	{
		return m_position;
	}

	float GetXRotation() const
	{
		return rotation.x;
	}

	float GetYRotation() const
	{
		return rotation.y;
	}

	float GetZRotation() const
	{
		return rotation.z;
	}

	void Reset(const glm::fvec2& viewport, ProjectionMode projectionMode)
	{
		m_scale				= { 1.f, 1.f, 1.f };
		m_position			= { 0.f, 0.f, 0.f };
		rotation			= { 0.f, 0.f, 0.f };
		m_viewport			= viewport;
		m_projectionDirty	= true;
		m_viewDirty			= true;
		m_fov				= 45.f;
		m_projectionMatrix	= glm::fmat4(1.f);
		
		SetProjectionMode(projectionMode);
		ResolveDirty();
	}

private:
	void SetProjectionDirty()
	{
		m_projectionDirty = true;
	}

	void SetViewDirty()
	{
		m_viewDirty = true;
	}

	void ResolveDirty()
	{
		bool anyDirty = m_projectionDirty || m_viewDirty;
		ResolveProjectionDirty();
		ResolveViewDirty();
		if (anyDirty)
		{
			m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
		}
	}

	void ResolveViewDirty()
	{
		if (m_viewDirty)
		{
			m_viewMatrix = glm::fmat4(1.f);
			m_viewMatrix = glm::translate(m_viewMatrix, m_position);
			m_viewMatrix = glm::scale(m_viewMatrix, m_scale);
			m_viewMatrix = glm::rotate(m_viewMatrix, rotation.x, glm::fvec3(1.f, 0.f, 0.f));
			m_viewMatrix = glm::rotate(m_viewMatrix, rotation.y, glm::fvec3(0.f, 1.f, 0.f));
			m_viewMatrix = glm::rotate(m_viewMatrix, rotation.z, glm::fvec3(0.f, 0.f, 1.f));
			m_viewDirty = false;
		}
	}

	void ResolveProjectionDirty()
	{
		if (m_projectionDirty)
		{
			m_projectionMatrix = glm::fmat4(1.f);
			if (m_projectionMode == ProjectionMode::Orthographic)
			{
				m_projectionMatrix = glm::ortho(0.f, m_viewport.x, m_viewport.y, 0.f, m_near, m_far);
			}
			else
			{
				m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_viewport.x / m_viewport.y, m_near, m_far);
			}
			m_projectionDirty = false;
		}
	}

	ProjectionMode m_projectionMode = ProjectionMode::Orthographic;

	// cache last (position, scale) if performance issues
	glm::fvec3 m_scale = { 1.f, 1.f, 1.f };
	glm::fvec3 m_position = { 0.f, 0.f, 0.f };
	glm::fvec3 rotation = { 0.f, 0.f, 0.f };

	glm::fvec2 m_viewport;

	glm::fmat4 m_projectionMatrix;
	glm::fmat4 m_viewMatrix;
	glm::fmat4 m_viewProjectionMatrix;

	float m_near = 0.1f;
	float m_far = 1000.f;

	float m_fov = 45.f;

	bool m_projectionDirty = true;
	bool m_viewDirty = true;


};


}
