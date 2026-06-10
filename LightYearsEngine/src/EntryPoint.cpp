#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
	//Allocate Application on the heap using RAII
	auto app = GetApplication();
	app->Run();
}

