#pragma once

#include "RenderCommandQueue.h"
#include "RendererAPI.h"

namespace Real {

	class REAL_API Renderer
	{
	public:
		typedef void(*RenderCommandFn)(void*);

		// Commands
		static void Clear();
		static void Clear(float r, float g, float b, float a = 1.0f);
		static void SetClearColor(float r, float g, float b, float a);

		static void DrawIndexed(unsigned int count, bool depthTest = true);

		static void ClearMagenta();

		static void Init();

		static void* Submit(RenderCommandFn fn, unsigned int size)
		{
			return s_Instance->m_CommandQueue.Allocate(fn, size);
		}

		void WaitAndRender();

		inline static Renderer& Get() { return *s_Instance; }
	private:
		static Renderer* s_Instance;

		RenderCommandQueue m_CommandQueue;
	};

}

#define RE_RENDER_PASTE2(a, b) a ## b
#define RE_RENDER_PASTE(a, b) RE_RENDER_PASTE2(a, b)
#define RE_RENDER_UNIQUE(x) RE_RENDER_PASTE(x, __LINE__)

#define RE_RENDER(code) \
    struct RE_RENDER_UNIQUE(RERenderCommand) \
    {\
        static void Execute(void*)\
        {\
            code\
        }\
    };\
	{\
		auto mem = ::Real::Renderer::Submit(RE_RENDER_UNIQUE(RERenderCommand)::Execute, sizeof(RE_RENDER_UNIQUE(RERenderCommand)));\
		new (mem) RE_RENDER_UNIQUE(RERenderCommand)();\
	}\

#define RE_RENDER_1(arg0, code) \
	do {\
    struct RE_RENDER_UNIQUE(RERenderCommand) \
    {\
		RE_RENDER_UNIQUE(RERenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0) \
		: arg0(arg0) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg0;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
    };\
	{\
		auto mem = ::Real::Renderer::Submit(RE_RENDER_UNIQUE(RERenderCommand)::Execute, sizeof(RE_RENDER_UNIQUE(RERenderCommand)));\
		new (mem) RE_RENDER_UNIQUE(RERenderCommand)(arg0);\
	} } while(0)

#define RE_RENDER_2(arg0, arg1, code) \
    struct RE_RENDER_UNIQUE(RERenderCommand) \
    {\
		RE_RENDER_UNIQUE(RERenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1) \
		: arg0(arg0), arg1(arg1) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg0;\
			auto& arg1 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg1;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1;\
    };\
	{\
		auto mem = ::Real::Renderer::Submit(RE_RENDER_UNIQUE(RERenderCommand)::Execute, sizeof(RE_RENDER_UNIQUE(RERenderCommand)));\
		new (mem) RE_RENDER_UNIQUE(RERenderCommand)(arg0, arg1);\
	}\

#define RE_RENDER_3(arg0, arg1, arg2, code) \
    struct RE_RENDER_UNIQUE(RERenderCommand) \
    {\
		RE_RENDER_UNIQUE(RERenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2) \
		: arg0(arg0), arg1(arg1), arg2(arg2) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg0;\
			auto& arg1 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg1;\
			auto& arg2 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg2;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2;\
    };\
	{\
		auto mem = ::Real::Renderer::Submit(RE_RENDER_UNIQUE(RERenderCommand)::Execute, sizeof(RE_RENDER_UNIQUE(RERenderCommand)));\
		new (mem) RE_RENDER_UNIQUE(RERenderCommand)(arg0, arg1, arg2);\
	}\

#define RE_RENDER_4(arg0, arg1, arg2, arg3, code) \
    struct RE_RENDER_UNIQUE(RERenderCommand) \
    {\
		RE_RENDER_UNIQUE(RERenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg3)>::type>::type arg3)\
		: arg0(arg0), arg1(arg1), arg2(arg2), arg3(arg3) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg0;\
			auto& arg1 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg1;\
			auto& arg2 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg2;\
			auto& arg3 = ((RE_RENDER_UNIQUE(RERenderCommand)*)argBuffer)->arg3;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg3)>::type>::type arg3;\
    };\
	{\
		auto mem = Renderer::Submit(RE_RENDER_UNIQUE(RERenderCommand)::Execute, sizeof(RE_RENDER_UNIQUE(RERenderCommand)));\
		new (mem) RE_RENDER_UNIQUE(RERenderCommand)(arg0, arg1, arg2, arg3);\
	}

#define RE_RENDER_S(code) auto self = this;\
	RE_RENDER_1(self, code)

#define RE_RENDER_S1(arg0, code) auto self = this;\
	RE_RENDER_2(self, arg0, code)

#define RE_RENDER_S2(arg0, arg1, code) auto self = this;\
	RE_RENDER_3(self, arg0, arg1, code)

#define RE_RENDER_S3(arg0, arg1, arg2, code) auto self = this;\
	RE_RENDER_4(self, arg0, arg1, arg2, code)