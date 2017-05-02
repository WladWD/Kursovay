#pragma once

#include <glew.h>
#include <Windows.h>
#include <wglew.h>
#include <stdexcept>

#include <fstream>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>

#if defined(_WIN64) | defined(_WIN32)
#define JNIEnv unsigned char
#define jobject int
#else
#endif
