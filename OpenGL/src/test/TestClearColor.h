//
//  TestClearColor.h
//  OpenGL
//
//  Created by 张逸凡 on 2022/1/13.
//

#pragma once

#include "Test.h"

namespace test {

	class TestClearColor : public Test
	{
	public:
		TestClearColor();
		~TestClearColor();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		float m_ClearColor[4];
	};

}
